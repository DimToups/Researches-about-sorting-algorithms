# Utilisation du csvWriter pour algorithmes de tri en C
## Description
Le csvWriter est un outil permettant de créer un certain nombre d'échantillons de tests se basant sur le temps d'exécution de programmes de tri de tableau. Cet outil va créer un fichier de sortie contenant l'ensemble des échantillons créés durant son exécution; ce fichier est initialement nommé ./out/donnees.csv. De multiples options sont disponibles pour gérer la taille minimale, maximale et le pas à faire pour la taille du tableau à trier, mais aussi l'algorithme de tri à exécuter, le type de remplissage de tableau à faire et aussi le nom à donner au fichier de sortie.
## Lancement de la commande
Pour exécuter la commande, il faut obligatoirement avoir un systême d'exploitation Linux sur sa machine. Elle s'exécute à l'aide de la commande `sh csvWriter` et le fichier ne doit pas être déplacé pour qu'il puisse fonctionner.
## Liste des options
### -a [algorithme]
Le type d'algorithme à exécuter. Quatre options supplémentaires sont possibles :
- **i** : tri par insertion
- **f** : tri par fusion
- **r** : tri rapide
- **F** : tri par fusion avec une injection de tri par insertion
- **R** : tri rapide avec une injection de tri par insertion
### -m [taille]
La taille minimale du tableau à trier, la taille est de 10000 par défaut. La taille doit être inférieure à la taille maximale.
### -M [taille]
La taille maximale du tableau à trier, la taille est de 50000 par défaut. La taille doit être supérieure à la taille minimale.
### -p [pas]
Le pas à ajouter à la taille du tableau à trier. Le pas est de 1000 par défaut.
### -r [remplissage]
Le type de remplissage de tableau à faire par défaut. Trois types de remplissages sont disponibles :
- **a** : remplissage aléatoire. Option par défaut
- **i** : remplissage incrémental
- **d** : remplissage incrémental en décalé. Le décalage doit être inscrit manuellement pour l'instant
### -n [fichier de sortie]
Le nom du fichier de sortie du programme. Le fichier sera toujours positionné dans le répertoire ./out/ et sera toujours de type csv. Le fichier de sortie de base est ./out/donnees.csv Le fichier de sortie sera ecrasé s'il existe déjà, il est donc important de faire attention au fichier que vous allez écraser.
### -s [script R]
Le type de script R à exécuter à la fin du programme pour générer un graphique. Tout comme pour le fichier csv construit, le graphique construit remplacera le précédant; il faudra donc faire attention de mettre l'option -o si l'on ne veut pas avoir de graphique de sortie ou tout simplement stocker le graphique voulu autre part. Trois scripts sont disponibles :
- **n** : script convertissant simplement le résultat du programme en un graphique pdf du même nom que le fichier de sortie csv. Option par défaut.
- **l** : script convertissant le résultat du programme en un graphique pdf avec une échelle logarithmique pour pouvoir mieux comparer l'évolution des diférentsalgorithmes de tri.
- **o** : option permettant de ne pas créer de graphique de sortie.
### -o
Option permettant de continuer à remplir le fichier cible.