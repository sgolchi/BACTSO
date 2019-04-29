PH_est_table = function(HR, LED) {
  est0 = c(mean(HR), mean(LED))
  lower = c(quantile(HR, .025), quantile(LED, .025))
  upper = c(quantile(HR, .975), quantile(LED, .975))
  CI = paste("(", round(lower,2), ",", "", round(upper,2), ")", sep = ' ')
  out = data.frame(round(est0,2), CI)
  names(out) = c("Estimate", paste(95, "%", "CI", sep = ""))
  rownames(out) = c("HR", "LED (months)")
  return(out)
}

NPH_est_table = function(LED) {
  est0 = mean(LED)
  lower = quantile(LED, .025)
  upper = quantile(LED, .975)
  CI = paste("(", round(lower,2), ",", "", round(upper,2), ")", sep = ' ')
  out = data.frame(round(est0,2), CI)
  names(out) = c("Estimate", paste(95, "%", "CI", sep = ""))
  rownames(out) = c("LED (months)")
  return(out)
}

