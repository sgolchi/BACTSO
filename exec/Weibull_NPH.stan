data{
  int N;
  real<lower = 0> y[N];
  real<lower = 0, upper = 1> z[N];
  int<lower = 0, upper = 1> nu[N];
}
parameters {
  real<lower = 0> alpha1;
  real<lower = 0> alpha2;
  real theta1;
  real theta2;
}
model {
  alpha1 ~ normal(0, 100);
  alpha2 ~ normal(0, 100);
  theta1 ~ normal(0, 100);
  theta2 ~ normal(0, 100);
  for (n in 1:N) {
    real alpha = (1-z[n])*alpha1 + z[n]*alpha2;
    real lambda = (1-z[n])*theta1 + z[n]*theta2;
      if (nu[n]==1)
          y[n] ~ weibull(alpha, exp(-(lambda)/alpha));
      else
          target += weibull_lccdf(y[n] | alpha, exp(-(lambda)/alpha));
  }
}
