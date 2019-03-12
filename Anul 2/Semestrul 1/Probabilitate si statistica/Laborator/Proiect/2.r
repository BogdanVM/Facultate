# Initializam setul de date
my_data <- randu

# --------------------- VERIFICAREA SETULUI DE DATE --------------------- #

# Calculam corelatia dintre date
cor(my_data$x, my_data$y)

# Construim modelul liniar
linearModel <- lm(x ~ y, data = my_data)
print(linearModel)

# Retinem valorile modelului liniar
modelSummary <- summary(linearModel)

# Salvam coeficientii relatiei dintre predicator si variabila raspuns
coeffs <- modelSummary$coefficients

# Salvam estimarile pentru coef y si eroarea standard
betaEstimate <- coeffs["y", "Estimate"]
stdError <- coeffs["y", "Std. Error"]

# Calculam valoarea t si p
tValue <- betaEstimate / stdError
pValue <- 2 * pt(-abs(tValue), df = nrow(my_data) - ncol(my_data))

# Calculam modelul F statistic
fStatistic <- linearModel$fstatistic[1]
f <- summary(linearModel)$fstatistic

# Calculam modelul p-value
modelP <- pf(f[1], f[2], f[3], lower=FALSE)

# Calculcam AIC si BIC
AIC(linearModel)
BIC(linearModel)

# ---------------- REGRESIA SIMPLA ----------------- #

# Cream setul de date de training si de test din datele originale
set.seed(100)
trainingRowIndex <- sample(1:nrow(my_data), 0.8 * nrow(my_data))
trainingData <- my_data[trainingRowIndex, ]
testData <- my_data[-trainingRowIndex, ]

# Dezvoltam modelul pe datele de training si il folosim sa prezicem x pe datele test
lmMod <- lm(x ~ y, data = trainingData)
xPred <- predict(lmMod, testData)

# Calculam precizia predictiilor si erorile
actualPred <- data.frame(cbind(actuals = testData$x, predicteds = xPred))
correlationAccuracy <- cor(actualPred)
head(actualPred)

# Calculam min-max-accuracy si mean-absolute-percentage-error
min_max_accuracy <- mean(apply(actualPred, 1, min) / apply(actualPred, 1, max)) 
mape <- mean(abs((actualPred$predicteds - actualPred$actuals)) / actualPred$actuals)

# ------------------------ REGRESIA MULTIPLA ----------------------- #
set.seed(1000)
index <- sample(1:nrow(my_data), 0.8 * nrow(my_data))
trainingD <- my_data[index, ]
testD <- my_data[-index, ]

# Dezvoltam modelul pe datele de training si il folosim sa prezicem x pe datele test
lmModM <- lm(x ~ y + z, data = trainingD)
xPredM <- predict(lmModM, testD)

# Calculam precizia predictiilor si erorile
actualPredM <- data.frame(cbind(actuals = testD$x, predicteds = xPredM))
correlationAccuracyM <- cor(actualPredM)
head(actualPredM)

# Calculam min-max-accuracy si mean-absolute-percentage-error
min_max_accuracyM <- mean(apply(actualPredM, 1, min) / apply(actualPredM, 1, max)) 
mapeM <- mean(abs((actualPredM$predicteds - actualPredM$actuals)) / actualPredM$actuals)
