data{
  int N;
  real<lower = 0> y[N];
  real<lower = 0, upper = 1> z[N];
  int<lower = 0, upper = 1> nu[N];
}
parameters {
  real<lower = 0> alpha;
  real theta;
  real delta;
}
transformed parameters {
  real lambda[N];
  for (n in 1:N) lambda[n] = theta + z[n]*delta;
}
model {
  alpha ~ normal(0, 100);
  theta ~ normal(0, 100);
  for (n in 1:N) {
      if (nu[n]==1)
          y[n] ~ weibull(alpha, exp(-(lambda[n])/alpha));
      else
          target += weibull_lccdf(y[n] | alpha, exp(-(lambda[n])/alpha));
  }
}
