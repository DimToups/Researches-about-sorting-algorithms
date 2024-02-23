#!/bin/bash

algo='a'
min=10000
max=50000
pas=100

while getopts ":a:m:M:p:" flag
do
    case "${flag}" in
        a) algo=${OPTARG};;
	    m) min=${OPTARG};;
        M) max=${OPTARG};;
	    p) pas=${OPTARG};;
    esac
done
echo $pas

echo version,taille,temps 1> ./out/machin.csv

taille=$min
while [[ $taille -lt $max ]]
do
    if [ $algo == 'i' ]
    then
	    res=`(/usr/bin/time -f "%U"  bin/triInsertion $taille $max > /dev/null) 2>&1`
        echo "insertion,$taille,$res" 1>> ./out/machin.csv
    elif [ $algo == 'f' ]
    then
        res=`(/usr/bin/time -f "%U"  bin/triFusion $taille $max > /dev/null) 2>&1`
        echo "fusion,$taille,$res" 1>> ./out/machin.csv
    elif [ $algo == 'r' ]
    then
        res=`(/usr/bin/time -f "%U"  bin/triRapide $taille $max > /dev/null) 2>&1`
        echo "rapide,$taille,$res" 1>> ./out/machin.csv
    elif [ $algo == 'a' ]
    then
        res=`(/usr/bin/time -f "%U"  bin/triInsertion $taille $max > /dev/null) 2>&1`
        echo "insertion,$taille,$res" 1>> ./out/machin.csv
        res=`(/usr/bin/time -f "%U"  bin/triFusion $taille $max > /dev/null) 2>&1`
        echo "fusion,$taille,$res" 1>> ./out/machin.csv
        res=`(/usr/bin/time -f "%U"  bin/triRapide $taille $max > /dev/null) 2>&1`
        echo "rapide,$taille,$res" 1>> ./out/machin.csv
    else
	    exit -1
    fi

    taille=$(expr $taille + $pas)
done
