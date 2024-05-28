
data <- read.csv("data13.csv")

install.packages("smotefamily", repos = "https://cloud.r-project.org/")
library(smotefamily)

set.seed(9876)
idx <- sample(nrow(data))
d_train <- data[idx[1:300], ]
d_test <- data[idx[301:nrow(data)], ]
d_train_smote <- SMOTE(d_train[, c(2, 3, 4)], d_train$BUG, K = 10)$data

names(d_train_smote)[4] <- "BUG"
d_train_smote$BUG <- as.numeric(d_train_smote$BUG)

model <- glm(BUG ~ CC + CALL + LOC, d_train_smote, family = "binomial")
result <- predict(model, type = "response", d_test)
result <- as.vector(result)

found_bugs <- d_test$BUG[order(result, decreasing = TRUE)]
for (i in 2:length(found_bugs)){
  found_bugs[i] <- found_bugs[i - 1] + found_bugs[i]
}
plot(found_bugs, type = "l")

b80 <- max(found_bugs) * 0.8
sum(found_bugs < b80) / length(found_bugs)
