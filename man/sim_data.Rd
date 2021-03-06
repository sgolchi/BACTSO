% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/funs.R
\name{sim_data}
\alias{sim_data}
\title{data sim function}
\usage{
sim_data(trial_time, enrollment_time, N, p_lfu, alpha1, alpha2, theta1,
  theta2)
}
\arguments{
\item{trial_time}{length of trial}

\item{enrollment_time}{time to which enrollment continues}

\item{N}{sample size (total)}

\item{p_lfu}{lost-to-follow-up rate}

\item{alpha1}{shape parameter for control}

\item{alpha2}{shape parameter for treatment}

\item{theta1}{scale parameter for control}

\item{theta2}{scale parameter for treatment}
}
\value{
data frame of posterior samples of model parameters as well as HR and LED
}
\description{
data sim function
}
