import time
import random


def partition(A, p, r):
    pivot = A[r-1]
    i = p
    for j in range(p,r-1):
        if A[j] <= pivot :
            temp=A[i]
            A[i] =A[j]
            A[j]=temp
            i+=1
    temp = A[i]
    A[i] = A[r-1]
    A[r-1] = temp
    return i

def sousTriRapide(A, p, r) :
    if  p<r-1 :
        q = partition(A, p, r)
        sousTriRapide(A, p, q)
        sousTriRapide(A, q + 1, r)


def triRapide(A,n) :
    sousTriRapide(A, 0, n)




if __name__ == "__main__":
    max = 10000;
    max = 10000;
    a = [0]*max
    for i in range(max):
        a[i] = random.randint(1, 100)

    # Démarrer le chronomètre
    debut = time.time()

    triRapide(a, max);
    print(a)

    # Arrêter le chronomètre
    fin = time.time()
    # Calculer et afficher la durée
    duree = fin - debut
    print(f"Temps écoulé: {duree} secondes")