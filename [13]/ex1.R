
data <- read.csv("data13.csv")

set.seed(1234) # Pin random result (default), delete/edit for different result
idx <- sample(nrow(data))
d_train <- data[idx[1:300], ]
d_test <- data[idx[301:nrow(data)], ]

bug <- d_train$BUG
target <- d_train$LOC > 30
result <- bug[target]
recall <- sum(result) / sum(bug)
precision <- sum(result) / sum(target)
fscore <- 2 * recall * precision / (recall + precision)

print(paste("Length of result: ", length(result)))
print(paste("Sum of result: ", sum(result)))
print(paste("Sum of d_train: ", sum(d_train$BUG)))
print(paste("Recall value: ", recall))
print(paste("Precision value: ", precision))
print(paste("F score:", fscore))
