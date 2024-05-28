# p7
data <- read.csv(file.choose())

# p9
boxplot(CC ~ BUG, data = data)

# p10
cc0 <- data$CC[data$BUG == 0]
cc1 <- data$CC[data$BUG == 1]
summary(cc0)
summary(cc1)


# p13
set.seed(1234)
idx <- sample(nrow(data))

# p14
d_train <- data[idx[1:300], ]
d_test <- data[idx[301:nrow(data)], ]

# p15
d_train$BUG[d_train$CC > 10]

# p16
result <- d_train$BUG[d_train$CC > 10]
length(result)
sum(result)

# p18
sum(d_train$BUG)

# p29
f_value <- function(bug, target) {
  result <- bug[target]
  recall <- sum(result) / sum(bug)
  precision <- sum(result) / sum(target)
  2 * recall * precision / (recall + precision)
}

# p30
f_value(d_train$BUG, d_train$CC > 10)

# p31
f_value(d_test$BUG, d_test$CC > 10)


# p34
order(d_test$CC, decreasing = TRUE)
found_bugs <- d_test$BUG[order(d_test$CC, decreasing = TRUE)]

# p35
found_bugs
for (i in 2:length(found_bugs)){
  found_bugs[i] <- found_bugs[i - 1] + found_bugs[i]
}

# p36
plot(found_bugs, type = "l")

# p37
b80 <- max(found_bugs) * 0.8
sum(found_bugs < b80) / length(found_bugs)


# p44
model <- glm(BUG ~ CC + CALL + LOC, d_train, family = "binomial")
summary(model)

# p45
result <- predict(model, type = "response", d_test)
result <- as.vector(result)

# p46
found_bugs <- d_test$BUG[order(result, decreasing = TRUE)]

# p47
for (i in 2:length(found_bugs)){
  found_bugs[i] <- found_bugs[i - 1] + found_bugs[i]
}

# p48
plot(found_bugs, type = "l")

# p49
b80 <- max(found_bugs) * 0.8
sum(found_bugs < b80) / length(found_bugs)

# p50
sum(d_train$BUG == 1)
sum(d_train$BUG == 0)

# p54
install.packages("smotefamily", repos = "https://cloud.r-project.org/")
library(smotefamily)

# p55
set.seed(1234)
d_train_smote <- SMOTE(d_train[, c(2, 3, 4)], d_train$BUG, K = 10)$data

# p56
names(d_train_smote)[4] <- "BUG"
d_train_smote$BUG <- as.numeric(d_train_smote$BUG)

# p57
model <- glm(BUG ~ CC + CALL + LOC, d_train_smote, family = "binomial")
result <- predict(model, type = "response", d_test)
result <- as.vector(result)


# p58
found_bugs <- d_test$BUG[order(result, decreasing = TRUE)]
for (i in 2:length(found_bugs)){
  found_bugs[i] <- found_bugs[i - 1] + found_bugs[i]
}
plot(found_bugs, type = "l")

b80 <- max(found_bugs) * 0.8
sum(found_bugs < b80) / length(found_bugs)
