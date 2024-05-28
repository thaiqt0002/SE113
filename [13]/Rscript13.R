# p7
data = read.csv(file.choose())

# p9
boxplot(CC~BUG, data=data)

# p10
cc0 = data$CC[data$BUG==0]
cc1 = data$CC[data$BUG==1]
summary(cc0)
summary(cc1)


# p13
set.seed(1234)
idx = sample( nrow(data) )

# p14
d.train = data[idx[1:300], ]
d.test = data[idx[301:nrow(data)], ]

# p15
d.train$BUG[d.train$CC>10]

# p16
result = d.train$BUG[d.train$CC>10]
length(result)
sum(result)

# p18
sum(d.train$BUG)

# p29
f.value = function(bug, target){
  result = bug[target]
  recall = sum(result)/sum(bug)
  precision = sum(result)/sum(target)
  2*recall*precision/(recall + precision)
}

# p30
f.value(d.train$BUG, d.train$CC>10)

# p31
f.value(d.test$BUG, d.test$CC>10)


# p34
order(d.test$CC, decreasing = T)
found.bugs = d.test$BUG[order(d.test$CC, decreasing = T)]

# p35
found.bugs
for ( i in 2:length(found.bugs) ){
  found.bugs[i] = found.bugs[i-1] + found.bugs[i]
}

# p36
plot(found.bugs, type='l')

# p37
b80 = max(found.bugs)*0.8
sum(found.bugs<b80)/length(found.bugs)


# p44
model = glm(BUG ~ CC+CALL+LOC, d.train, family="binomial")
summary(model)

# p45
result = predict(model, type="response", d.test)
result = as.vector(result)

# p46
found.bugs = d.test$BUG[order(result, decreasing = T)]

# p47
for ( i in 2:length(found.bugs) ){
  found.bugs[i] = found.bugs[i-1] + found.bugs[i]
}

# p48
plot(found.bugs, type='l')

# p49
b80 = max(found.bugs)*0.8
sum(found.bugs<b80)/length(found.bugs)

# p50
sum(d.train$BUG==1)
sum(d.train$BUG==0)

# p54
install.packages("smotefamily")
library(smotefamily)

# p55
set.seed(1234)
d.train.smote = SMOTE(d.train[,c(2,3,4)], d.train$BUG, K = 10)$data

# p56
names(d.train.smote)[4] = "BUG"
d.train.smote$BUG = as.numeric(d.train.smote$BUG)

# p57
model = glm(BUG ~ CC+CALL+LOC, d.train.smote, family="binomial")
result = predict(model, type="response", d.test)
result = as.vector(result)


# p58
found.bugs = d.test$BUG[order(result, decreasing = T)]
for ( i in 2:length(found.bugs) ){
  found.bugs[i] = found.bugs[i-1] + found.bugs[i]
}
plot(found.bugs, type='l')

b80 = max(found.bugs)*0.8
sum(found.bugs<b80)/length(found.bugs)

