LED_post_plot = function(var) {
  df = data.frame(LED = var)
  psup = mean(df$LED>0)
  p = ggplot(df, aes(x = LED)) +
      geom_density(alpha = .5, color = 'grey', fill = 'lightblue') +
      geom_vline(xintercept = 0, col = 'darkred') +
      scale_fill_brewer() + 
      theme(axis.text=element_text(size=12),
            axis.title=element_text(size=14,face="bold"),
            strip.text.y = element_text(size = 12, face = "bold"))
  d <- ggplot_build(p)$data[[1]]
  p = p +  geom_area(data = subset(d, x>0), aes(x=x, y = y), fill="red", alpha = .3) +
    annotate("text", x = mean(df$LED), y = mean(d$y), label = paste('P(LED>0)=', psup, sep = ''), 
             size = 7, alpha = .7)
  return(p)
}

HR_post_plot = function(var) {
  df = data.frame(HR = var) 
  psup = mean(df$HR<1)
  p = ggplot(df, aes(x = HR)) +
    geom_density(alpha = .5, color = 'grey', fill = 'lightblue') +
    geom_vline(xintercept = 1, col = 'darkred') +
    scale_fill_brewer() + 
    theme(axis.text=element_text(size=12),
          axis.title=element_text(size=14,face="bold"),
          strip.text.y = element_text(size = 12, face = "bold"))
  d <- ggplot_build(p)$data[[1]]
  p = p +  geom_area(data = subset(d, x<1), aes(x=x, y = y), fill="red", alpha = .3) +
    annotate("text", x = mean(df$HR), y = mean(d$y), label = paste('P(HR<1)=', psup, sep = ''), 
             size = 7, alpha = .7)
  return(p)
}

