
data <- read.csv("data13.csv")

set.seed(1234)
idx <- sample(nrow(data))
d_train <- data[idx[1:300], ]
d_test <- data[idx[301:nrow(data)], ]

order(d_test$CC, decreasing = TRUE)

#Ex2-1
found_bugs <- d_test$BUG[order(d_test$LOC, decreasing = TRUE)]

found_bugs
for (i in 2:length(found_bugs)){
  found_bugs[i] <- found_bugs[i - 1] + found_bugs[i]
}

plot(found_bugs, type = "l")

b80 <- max(found_bugs) * 0.8
sum(found_bugs < b80) / length(found_bugs)

#Ex2-2
found_bugs <- d_test$BUG[order(d_test$CALL, decreasing = TRUE)]
found_bugs
for (i in 2:length(found_bugs)){
  found_bugs[i] <- found_bugs[i - 1] + found_bugs[i]
}

plot(found_bugs, type = "l")

b80 <- max(found_bugs) * 0.8
sum(found_bugs < b80) / length(found_bugs)
