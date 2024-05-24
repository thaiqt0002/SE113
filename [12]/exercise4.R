# p44
cm1 <- read.csv(file.choose()) ## select data12.csv

mean(cm1$CC[cm1$BUG == 1])
median(cm1$CC[cm1$BUG == 1])

mean(cm1$CC[cm1$BUG == 0])
median(cm1$CC[cm1$BUG == 0])