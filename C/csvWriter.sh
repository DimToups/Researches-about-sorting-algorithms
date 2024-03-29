#!/bin/bash

scriptsR(){
    if [[ $1 == *"n"* ]]
    then
        Rscript ./rScripts/normal.R $2 > /dev/null
    fi
    if [[ $1 == *"l"* ]]
    then
        Rscript ./rScripts/logarithme.R $2 > /dev/null
    fi
}

insertion(){
    if [ $1 == 'd' ]
    then
        res=`(/usr/bin/time -f "%U"  bin/triInsertion $2 $3 -r $1 $4 > /dev/null ) 2>&1`
    else
        res=`(/usr/bin/time -f "%U"  bin/triInsertion $2 $3 -r $4 > /dev/null ) 2>&1`
    fi
    echo "insertion,$2,$res" 1>> $5
}

fusion(){
    if [ $1 == 'd' ]
    then
        res=`(/usr/bin/time -f "%U"  bin/triFusion $2 $3 -r $1 $4 > /dev/null ) 2>&1`
    else
        res=`(/usr/bin/time -f "%U"  bin/triFusion $2 $3 -r $4 > /dev/null ) 2>&1`
    fi
    echo "fusion,$2,$res" 1>> $5
}

rapide(){
    if [ $1 == 'd' ]
    then
        res=`(/usr/bin/time -f "%U"  bin/triRapide $2 $3 -r $1 $4 > /dev/null ) 2>&1`
    else
        res=`(/usr/bin/time -f "%U"  bin/triRapide $2 $3 -r $4 > /dev/null ) 2>&1`
    fi
    echo "rapide,$2,$res" 1>> $5
}

fusionInsertion(){
    if [ $1 == 'd' ]
    then
        res=`(/usr/bin/time -f "%U"  bin/triFusionInsertion $2 $3 $6 -r $1 $4 > /dev/null ) 2>&1`
    else
        res=`(/usr/bin/time -f "%U"  bin/triFusionInsertion $2 $3 $6 -r $4 > /dev/null ) 2>&1`
    fi
    echo "fusion avec insertion,$2,$res" 1>> $5
}

rapideInsertion(){
    if [ $1 == 'd' ]
    then
        res=`(/usr/bin/time -f "%U"  bin/triRapideInsertion $2 $3 $6 -r $1 $4 > /dev/null ) 2>&1`
    else
        res=`(/usr/bin/time -f "%U"  bin/triRapideInsertion $2 $3 $6 -r $4 > /dev/null ) 2>&1`
    fi
    echo "rapide avec insertion,$2,$res" 1>> $5
}


algo='ifrFR'
min=10000
max=50000
pas=1000
remplissage='a'
decalage=1
seuil=10
nomFichier='donnees'
scriptR='n'
override=true

# Gestion des arguments
while getopts ":a:m:M:p:r:n:s:o:S:" flag
do
    case "${flag}" in
        a) algo=${OPTARG};;
        m) min=${OPTARG};;
        M) max=${OPTARG};;
        p) pas=${OPTARG};;
        r) remplissage=${OPTARG};;
        n) nomFichier=${OPTARG};;
        s) scriptR=${OPTARG};;
        S) seuil=${OPTARG};;
    esac
done
while [ $# -gt 0 ]; do
    case $1 in
        o) override=false;;
    esac
    shift
done

echo $seuil

# Gestion du fichier
fichier='./out/'$nomFichier'.csv'
if $override && [ -f $fichier ]
then
    echo version,taille,temps 1> $fichier
fi

taille=$min
while [[ $taille -lt $max ]]
do
    if [[ $algo == *"i"* ]]
    then
        insertion $remplissage $taille $max $decalage $fichier
    fi
    if [[ $algo == *"f"* ]]
    then
        fusion $remplissage $taille $max $decalage $fichier
    fi
    if [[ $algo == *"r"* ]]
    then
        rapide $remplissage $taille $max $decalage $fichier
    fi
    if [[ $algo == *"F"* ]]
    then
        fusionInsertion $remplissage $taille $max $decalage $fichier $seuil
    fi
    if [[ $algo == *"R"* ]]
    then
        rapideInsertion $remplissage $taille $max $decalage $fichier $seuil
    fi

    taille=$(expr $taille + $pas)
done

# Exécution des scripts R voulu
scriptsR $scriptR $nomFichier
