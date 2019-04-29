# trial_time = 30
# enrollment_time = 15
# N = 1000
# p_lfu = 0.1
# alpha1 = 1.4
# alpha2 = 1.1
# theta1 = -8.7
# theta2 =  -7
# data = sim_data(trial_time, enrollment_time, N, p_lfu, alpha1, alpha2, theta1, theta2)
# write.csv(data, file = 'ex_data_1.csv')
# 
# 
# trial_time = 30
# enrollment_time = 15
# N = 1000
# p_lfu = 0.1
# alpha1 = 1.1
# alpha2 = 1.4
# theta1 = -6.65
# theta2 =  -8.7
# data = sim_data(trial_time, enrollment_time, N, p_lfu, alpha1, alpha2, theta1, theta2)
# write.csv(data, file = 'ex_data_2.csv')
# 
# 
# trial_time = 30
# enrollment_time = 15
# N = 1000
# p_lfu = 0.1
# alpha1 = 1.4
# alpha2 = 1.4
# theta1 = -8.5
# theta2 =  -8.7
# data = sim_data(trial_time, enrollment_time, N, p_lfu, alpha1, alpha2, theta1, theta2)
# write.csv(data, file = 'ex_data_3.csv')
# 
# 
# setwd('~/Dropbox/BSDA/Lilly data LY2510924_CXAC')
# dat = read.sas7bdat('os.sas7bdat')
# data = data.frame(time = dat$OS_DUR, event = dat$CENS, arm = as.numeric(as.factor(dat$ARMCD)) - 1)
# setwd('~/Dropbox/BSDA/data')
# write.csv(data, file = 'OS_LY2510924_CXAC.csv')
# setwd('~/Dropbox/BSDA/Lilly data LY2510924_CXAC')
# dat = read.sas7bdat('pfs.sas7bdat')
# data = data.frame(time = dat$PFS_DUR, event = dat$CENS, arm = as.numeric(as.factor(dat$ARMCD)) - 1)
# setwd('~/Dropbox/BSDA/data')
# write.csv(data, file = 'PFS_LY2510924_CXAC.csv')
