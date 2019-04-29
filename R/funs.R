#' @import Rcpp
#' @import rstantools
#' @useDynLib BACTSO, .registration = TRUE
#' @importFrom stats pnorm
#' @importFrom stats rbinom
#' @importFrom stats rmultinom
#' @importFrom stats rnorm
#' @importFrom stats sd
#' @importFrom stats var
#' @importFrom ggplot2 ggplot
#' @importFrom ggplot2 aes
#' @importFrom ggplot2 geom_point
#' @importFrom ggplot2 geom_line
#' @importFrom ggplot2 geom_hline
#' @importFrom ggplot2 geom_density
#' @importFrom ggplot2 facet_grid
#' @importFrom ggplot2 scale_color_brewer
#' @importFrom ggplot2 scale_fill_brewer
#' @importFrom ggplot2 xlim
#' @importFrom ggplot2 ylim
#' @importFrom ggplot2 xlab
#' @importFrom ggplot2 ylab
#' @importFrom reshape2 melt
#' @importFrom dplyr %>%
#' @importFrom dplyr group_by
#' @importFrom dplyr summarise
#############################################################


S = function(t, alpha, theta) 1-stats::pweibull(t, alpha, exp(-theta/alpha))

#' Life expectancy difference -- nonproportional hazards
#'
#' @param t time to which life expectancy is calculated
#' @param alpha1 shape parameter for control
#' @param alpha2 shape parameter for treatment
#' @param theta1 scale parameter for control
#' @param theta2 scale parameter for treatment
#' @return life expectatncy difference
#'
#' @export
LED = function(t, alpha1, alpha2, theta1, theta2) {
  le1 = integrate(S, lower = 0, upper = t*30.346875, alpha = alpha1, theta = theta1)
  le2 = integrate(S, lower = 0, upper = t*30.346875, alpha = alpha2, theta = theta2)
  return(le2$value - le1$value)
}


#' Life expectancy difference -- proportional hazards
#'
#' @param t time to which life expectancy is calculated
#' @param alpha shape parameter for both arms
#' @param theta scale parameter for control
#' @param delta represents treatment effect; scale parameter for treatment is \code{theta + delta}
#' @return life expectatncy difference
#'
#' @export
LED1 = function(t, alpha, theta, delta) {
  le1 = integrate(S, lower = 0, upper = t*30.346875, alpha = alpha, theta = theta)
  le2 = integrate(S, lower = 0, upper = t*30.346875, alpha = alpha, theta = theta + delta)
  return(le2$value - le1$value)
}

#' Weibull model fitting -- proportional hazards
#'
#' @param data a data frame with three variables: survival time (named time), event (0=censored, 1=event), arm
#' @param t_LED time to which LED is calculated
#' @return data frame of posterior samples of model parameters as well as HR and LED
#'
#' @export
WPH = function(data, t_LED) {
  N = nrow(data)
  y = data$time*30.346875
  nu = data$event
  z = data$arm
  data0 = list(N = N, y = y, nu = nu, z = z)
  fit = rstan::sampling(Weibull_PH, data = data0, warmup = 500, iter = 1000, chains = 2)
  fit_ss = rstan::extract(fit)
  HR = exp(fit_ss$delta)
  led = mapply(LED1, fit_ss$alpha, fit_ss$theta, fit_ss$delta, t = t_LED)
  df = data.frame(alpha = fit_ss$alpha, theta = fit_ss$theta, delta = fit_ss$delta, HR = HR, LED = led/30.346875)
  return(df)
}

#' Weibull model fitting -- nonproportional hazards
#'
#' @param data a data frame with three variables: survival time (named time), event (0=censored, 1=event), arm
#' @param t_LED time to which LED is calculated
#' @return data frame of posterior samples of model parameters as well as HR and LED
#'
#' @export
WNPH = function(data, t_LED) {
  N = nrow(data)
  y = data$time*30.346875
  nu = data$event
  z = data$arm
  data0 = list(N = N, y = y, nu = nu, z = z)
  fit = rstan::sampling(Weibull_NPH, data = data0, warmup = 500, iter = 1000, chains = 2)
  fit_ss = rstan::extract(fit)
  led = mapply(LED, fit_ss$alpha1, fit_ss$alpha2, fit_ss$theta1, fit_ss$theta2, t = t_LED)
  df = data.frame(alpha1 = fit_ss$alpha1, alpha2 = fit_ss$alpha2, theta1 = fit_ss$theta1,
                  theta2 = fit_ss$theta2, LED = led/30.346875)
  return(df)
}

#' data sim function
#'
#' @param trial_time length of trial
#' @param enrollment_time time to which enrollment continues
#' @param N sample size (total)
#' @param p_lfu lost-to-follow-up rate
#' @param alpha1 shape parameter for control
#' @param alpha2 shape parameter for treatment
#' @param theta1 scale parameter for control
#' @param theta2 scale parameter for treatment
#' @return data frame of posterior samples of model parameters as well as HR and LED
#'
#' @export
sim_data = function(trial_time, enrollment_time, N, p_lfu,
                    alpha1, alpha2, theta1, theta2) {
  nu = rep(0, N)
  z = rbinom(N, 1, .5)
  lfu = c()
  lambda = c()
  t_surv = c()
  t_obs = c()
  t_trial = trial_time*30.346875
  t_enroll = enrollment_time*30.346875
  LEDt = LED(alpha1, alpha2, theta1, theta2, t = trial_time)
  
  for (n in 1:N) {
    alpha =  alpha1*(1-z[n]) + alpha2*z[n]
    lambda[n] = theta1*(1-z[n]) + z[n]*theta2
    et = runif(1, 0, t_enroll)
    t_surv[n] = stats::rweibull(1, alpha, exp(-lambda[n]/alpha))
    t_obs[n] = min(t_surv[n], t_trial - et)
    lfu[n] = rbinom(1, 1, p_lfu)
    if (lfu[n] == 0 & t_surv[n] <= t_trial - et) nu[n] = 1
  }
  data = data.frame(time = t_obs/30.346875, event = nu, arm = z)
  return(data)
}

