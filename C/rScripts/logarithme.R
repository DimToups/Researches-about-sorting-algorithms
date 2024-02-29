#!/usr/bin/env Rscript

# Gestion des arguments
args = commandArgs(trailingOnly=TRUE)
if(length(args) != 1){
    stop("Usage : script.R [fichier]")
}
srcFile <- paste("./out/", args[1], ".csv", sep = "")
outputFile <- paste("./out/", args[1], "_logarithmique.pdf", sep = "")

# Importation de la librairie ggplot2 pour générer le graphe
library(ggplot2)

# Création du graphique
def <-read.csv(file=srcFile, header=TRUE ,sep=",")
def$temps <- as.double(def$temps)
def$taille <- as.integer(def$taille)
graphe <- ggplot(def, aes(x=taille, y=temps, color=version)) + expand_limits(y=0) + geom_point() + geom_smooth() + scale_x_continuous(trans = 'log10') + scale_y_continuous(trans = 'log10')

# Conversion du graphique en pdf
pdf(outputFile)
print(graphe)
dev.off()
