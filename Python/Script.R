def <-read.csv(file="PythonTrie.csv" , header=TRUE ,sep=",")
def$trie <- as.integer(def$trie)
def$temps <- as.double(def$temps)
def$mem <- as.integer(def$mem)
library(ggplot2)
ggplot (def , aes(x=taille,y=temps , color= version))+  geom_point()+geom_smooth()+  facet_wrap(~trie)
