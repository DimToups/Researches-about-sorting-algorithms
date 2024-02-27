#!/bin/bash


echo "taille,temps,mem,version,trie"
 for (( max=1; c<=10; c++ ))
  do
   for ((V =0; V <= 3; V++))
    do
    taille=`shuf -i 0-10000 -n1`
    res=`(/usr/bin/time -f "%U,%M"  python3 T1/triInsertion.py $taille  $V> /dev/null) 2>&1`
    echo "$taille,$res, Insertion ",$V
    res=`(/usr/bin/time -f "%U,%M"   python3 T2/TriFusion.py  $taille   $V> /dev/null) 2>&1`
    echo "$taille,$res, Fusion ",$V
    res=`(/usr/bin/time -f "%U,%M"   python3 T3/TriRapide.py   $taille $V > /dev/null) 2>&1`
    echo "$taille,$res, Rapide ",$V
  done
done


# R
#  read.csv
#
# def <-read.csv(file="PythonTrie.csv" , header=TRUE ,sep=",")
# def$cpu <- as.double(def$cpu)
# def$taille <- as.integer(def$taille)
# def$mem <- as.integer(def$mem)
# ggplot (def , aes(x=taille,y=temps , color= version))+  geom_point()+geom_smooth()

#
#
#
