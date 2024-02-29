#!/bin/bash

algo='a'
min=10000
max=50000
pas=1000
remplissage='a'
decalage=1
nomFichier='donnees'
scriptR='n'

while getopts ":a:m:M:p:r:n:s:" flag
do
    case "${flag}" in
        a) algo=${OPTARG};;
	    m) min=${OPTARG};;
        M) max=${OPTARG};;
	    p) pas=${OPTARG};;
        r) remplissage=${OPTARG};;
        n) nomFichier=${OPTARG};;
        s) scriptR=${OPTARG};;
    esac
done

fichier='./out/'$nomFichier'.csv'

echo version,taille,temps 1> $fichier

taille=$min
while [[ $taille -lt $max ]]
do
    if [ $algo == 'i' ]
    then
        if [ $remplissage == 'd' ]
        then
            res=`(/usr/bin/time -f "%U"  bin/triInsertion $taille $max -r $remplissage $decalage > /dev/null ) 2>&1`
        else
            res=`(/usr/bin/time -f "%U"  bin/triInsertion $taille $max -r $remplissage > /dev/null ) 2>&1`
        fi
        echo "insertion,$taille,$res" 1>> $fichier
    elif [ $algo == 'f' ]
    then
        if [ $remplissage == 'd' ]
        then
            res=`(/usr/bin/time -f "%U"  bin/triFusion $taille $max -r $remplissage $decalage > /dev/null ) 2>&1`
        else
            res=`(/usr/bin/time -f "%U"  bin/triFusion $taille $max -r $remplissage > /dev/null ) 2>&1`
        fi
        echo "fusion,$taille,$res" 1>> $fichier
    elif [ $algo == 'r' ]
    then
        if [ $remplissage == 'd' ]
        then
            res=`(/usr/bin/time -f "%U"  bin/triRapide $taille $max -r $remplissage $decalage> /dev/null) 2>&1`
        else
            res=`(/usr/bin/time -f "%U"  bin/triRapide $taille $max -r $remplissage > /dev/null) 2>&1`
        fi
        echo "rapide,$taille,$res" 1>> $fichier
    elif [ $algo == 'a' ]
    then
        # Insertion
        if [ $remplissage == 'd' ]
        then
            res=`(/usr/bin/time -f "%U"  bin/triInsertion $taille $max -r $remplissage $decalage> /dev/null) 2>&1`
        else
            res=`(/usr/bin/time -f "%U"  bin/triInsertion $taille $max -r $remplissage > /dev/null ) 2>&1`
        fi
        echo "insertion,$taille,$res" 1>> $fichier

        # Fusion
        if [ $remplissage == 'd' ]
        then
            res=`(/usr/bin/time -f "%U"  bin/triFusion $taille $max -r $remplissage $decalage > /dev/null) 2>&1`
        else
            res=`(/usr/bin/time -f "%U"  bin/triFusion $taille $max -r $remplissage > /dev/null ) 2>&1`
        fi
        echo "fusion,$taille,$res" 1>> $fichier

        # Rapide
        if [ $remplissage == 'd' ]
        then
            res=`(/usr/bin/time -f "%U"  bin/triRapide $taille $max -r $remplissage $decalage > /dev/null) 2>&1`
        else
            res=`(/usr/bin/time -f "%U"  bin/triRapide $taille $max -r $remplissage > /dev/null ) 2>&1`
        fi
        echo "rapide,$taille,$res" 1>> $fichier
    else
	    exit -1
    fi

    taille=$(expr $taille + $pas)
done

if [ $scriptR == 'n' ]
then
    Rscript ./rScripts/normal.R $nomFichier > /dev/null
elif [ $scriptR == 'l' ]
then
    Rscript ./rScripts/logarithme.R $nomFichier > /dev/null
fi

