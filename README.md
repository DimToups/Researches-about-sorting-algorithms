# P41 : Performances et optimisation

## Objectifs pédagogiques

  - Comprendre la complexité algorithmique. 
  - Savoir mesurer des performances applicatives en boite noire.
  - Savoir analyser des performances applicatives en regard de complexités théoriques. 

## Objectifs de réalisation

1. Comparer les performances applicatives 

  - temps d'exécution et consommation mémoire
  - de trois tris différents
  - dans trois langages différents
  - sur des données complètement aléatoires

2. Explorer une hypothèse


## Evaluation

### Générateur de données de test.

- [ ] Génère un fichier binaire d'entiers aléatoires selon une taille donnée en entrée.
- [ ] Permet de générer au moins trois types de tests différents.

### Tris par insertion.

- [ ] Un tri par insertion en C est codé et fonctionnel.
- [ ] Un tri par insertion en C# ou Java est codé et fonctionnel.
- [ ] Un tri par insertion en python est codé et fonctionnel.
- [ ] Les temps d'exécution des trois tris par insertion sont comparés dans un graphique.
- [ ] Les consommations mémoire des trois tris par insertion sont comparées dans un graphique.
- [ ] L'analyse est pertinente.

### Comparaison de différents tris dans un seul langage (au choix)

- [ ] Un tri rapide est codé et fonctionnel.
- [ ] Un tri par fusion est codé et fonctionnel.
- [ ] Un tri standard du langage ou de ses libraires est utilisé et fonctionnel.
- [ ] Les temps d'exécution sont comparés dans un ou plusieurs graphiques.
- [ ] Les consommations mémoire sont comparées dans un ou plusieurs graphique.
- [ ] L'analyse est pertinente.

### Etablissement et vérification d'une hypothèse 

- [ ] Une hypothèse pertinente est formulée. 
- [ ] L'hypothèse est originale. 
- [ ] L'hypothèse est difficile.
- [ ] Un plan d'expérimentation pertinent est présenté.
- [ ] Les résultats de l'expérimentation sont présentés.
- [ ] L'analyse est pertinente. 

### Evaluation des performances

- [ ] La plateforme expérimentale est décrite dans le rendu.
- [ ] Les paramètres expérimentaux sont indiqués dans le rendu.
- [ ] Les paramètres expérimentaux ne sont pas trop petits : tous les phénomènes et épi-phénomènes sont visibles.
- [ ] Les paramètres expérimentaux ne sont pas trop grands : il n'y a pas d'expériences superflues.
- [ ] Les performances sont analysées en regard de la théorie. 
- [ ] Les performances sont analysées face à plusieurs tests différents.
- [ ] Les performances sont analysées en regard de la consommation énergétique.

### Limites et pespectives

- [ ] Les limites de l'étude sont données dans le rendu. 
- [ ] Ces limites sont pertinentes.
- [ ] Des perspectives sont données dans le rendu.
- [ ] Ces perspectives sont pertinentes et en rapport avec les limites.

### Reproductibilité

- [ ] Les codes sont propres et commentés, et en lien direct depuis le rendu.
- [ ] Les codes sont systématiquement testés et les résultats des tests sont consultables.
- [ ] Les commandes pour reproduire toutes les expérimentations sont indiquées dans le code et le rendu.
- [ ] La commande pour compiler tous les codes est un make unique.
- [ ] Les données des expérimentations sont en lien depuis le rendu.
- [ ] Un script unique permet de reproduire toutes les expérimentations ; il est indiqué dans le rendu.

### Qualité des représentations graphiques

- [ ] Les graphiques ne comportent aucun artefact sans justification.
- [ ] Les axes et unités sont bien renseignés.
- [ ] Les légendes sont pertinentes. 
- [ ] Les échelles permettent de comparer aisément les séries.

## Rendu 

### Générateur de données

Lien vers le code : 

Utilisation :
```
Executable paramètres
```

### Comparaison des tris et langages

Choix des tris : 

  -
  - 
  -

Choix des langages :

  - Compilé (par défaut C) :
  - Compilé/interprêté  (par défaut C# ou Java) :
  - Interprété (par défaut Python) :

#### Description du protocole expérimental

  - Nombre d'expériences par tri/langage : 
  - Plage des paramètres : 
  - Méthode de fixation des paramètres :
  - Description de la machin de test :

```
Description de la machine de test
```

#### Résultats

`Unique graphique`

Analyse du graphique

### Hypothèse

Choisir une hypothèse dans la liste suivante et l'expérimenter, ou bien concevoir sa propre hypothèse et la faire valider par son enseignant. Supprimer du README les hypothèses non fouillées.
Le nombre d'étoiles indique la difficulté.

_Attention_ : certaines hypothèses peuvent être fausses.

- Le choix du pivot influence les performances du tri rapide (*)
- C est plus rapide que Java (*)
- La nature des données à trier influence les performances des tris (**)
- Les options du compilateur influencent les performances (**).
- Le tri rapide est plus complexe mais plus rapide que le tri fusion (**)
- Détecter la nature des données permet de gagner en temps d'exécution (***)
- Python est ralenti par l'absence de typage (***)

#### Description du protocole expérimental 

#### Résultats

### Conclusion générale