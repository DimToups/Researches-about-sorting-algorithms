#!/bin/bash


echo "taille,temps,mem,version"


for ((V=1 ; c<=2 ;c++))
do

  for (( max=1; c<=20; c++ ))
  do
    taille=`shuf -i 0-50000 -n1`
    res=`(/usr/bin/time -f "%U,%M"  python3 T1/triInsertion.py $taille  $V> /dev/null) 2>&1`
    echo "$taille,$res, Insertion "
    res=`(/usr/bin/time -f "%U,%M"   python3 T2/TriFusion.py  $taille   $V> /dev/null) 2>&1`
    echo "$taille,$res, Fusion "
    res=`(/usr/bin/time -f "%U,%M"   python3 T3/TriRapide.py   $taille $V > /dev/null) 2>&1`
    echo "$taille,$res, Rapide "
    

  done
done




#  read.csv
#
# def <-read.csv(file="PythonTrie.csv" , header=TRUE ,sep=",")
# def$cpu <- as.double(def$cpu)
# def$taille <- as.integer(def$taille)
# def$mem <- as.integer(def$mem)
#  ggplot (def , aes(x=taille,y=cpu , color= version))+  geom_point()+geom_smooth()

#
#
#
