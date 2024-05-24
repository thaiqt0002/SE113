data <- read.csv("data12.csv")

# Create a histogram of the CC column
pdf("ex3-1.pdf")
hist(data$CC)
dev.off()
# Compute the kernel density estimation of the CC column
pdf("ex3-2.pdf")
plot(density(data$CC))
dev.off()