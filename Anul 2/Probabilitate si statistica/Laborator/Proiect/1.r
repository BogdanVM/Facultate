# initializam setul de date cu cel built-in
my_data <- randu

# calculam valoarea medie pentru toate cele 3 coloane: x, y, z
mean_x <- mean(my_data$x)
mean_y <- mean(my_data$y)
mean_z <- mean(my_data$z)

# calculam mediana pentru coloane, mediana = valoarea din mijloc
median_x <- median(my_data$x)
median_y <- median(my_data$y)
median_z <- median(my_data$z)

# calculam deviatiile standard
sd_x <- sd(my_data$x)
sd_y <- sd(my_data$y)
sd_z <- sd(my_data$z)

# calculam dispersiile
var_x <- var(my_data$x)
var_y <- var(my_data$y)
var_z <- var(my_data$z)

# afisam quantilele pentru cele 3 coloane
quantile(my_data$x)
quantile(my_data$y)
quantile(my_data$z)

sapply(my_data, mean)
boxplot(my_data)