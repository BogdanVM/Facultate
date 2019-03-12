# Afisam densitatea si repartitia una langa alta
par(mfrow = c(1, 2))

# Selectam o secventa de numere pentru a afisa plot-ul
t <- seq(-5, 5, 0.001)

# Afisam cate un plot pentru fiecare functie in parte
plot(t, dbeta(t, 1, 5), ylab = "Functia de densitate", col = "magenta")
plot(t, pbeta(t, 1, 5), ylab = "Functia de repartitie", col = "blue")