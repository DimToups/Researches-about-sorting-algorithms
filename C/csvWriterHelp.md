# Utilisation du csvWriter pour algorithmes de tri en C
## Description
Le csvWriter est un outil permettant de créer un certain nombre d'échantillons de tests se basant sur le temps d'exécution de programmes de tri de tableau. Cet outil va créer un fichier de sortie contenant l'ensemble des échantillons créés durant son exécution; ce fichier est initialement nommé ./out/donnees.csv. De multiples options sont disponibles pour gérer la taille minimale, maximale et le pas à faire pour la taille du tableau à trier, mais aussi l'algorithme de tri à exécuter, le type de remplissage de tableau à faire et aussi le nom à donner au fichier de sortie.
## Lancement de la commande
La commande s'exécute à l'aide de la commande `sh csvWriter` et le fichier ne doit pas être déplacé pour qu'il puisse fonctionner.
## Liste des options
### -a [algorithme]
Le type d'algorithme à exécuter. Quatre options supplémentaires sont possibles :
- **i** : tri par insertion
- **f** : tri par fusion
- **r** : tri rapide
- **a** : exécute les trois tris. Option par défaut
### -m [taille]
La taille minimale du tableau à trier, la taille est de 10000 par défaut. La taille doit être inférieure à la taille maximale.
### -M [taille]
La taille maximale du tableau à trier, la taille est de 50000 par défaut. La taille doit être supérieure à la taille minimale.
### -p [pas]
Le pas à ajouter à la taille du tableau à trier. Le pas est de 1000 par défaut.
### -r [remplissage] [?décalage]
Le type de remplissage de tableau à faire par défaut. Trois types de remplissages sont disponibles :
- **a** : remplissage aléatoire. Option par défaut
- **i** : remplissage incrémental
- **d [décalage]** : remplissage incrémental en décalé. Demande un entier pour le décalage.
### -n [fichier de sortie]
Le nom du fichier de sortie du programme. Le fichier sera toujours positionné dans le répertoire ./out/ et sera toujours de type csv. Le fichier de sortie de base est ./out/donnees.csv Le fichier de sortie sera ecrasé s'il existe déjà, il est donc important de faire attention au fichier que vous allez écraser.