import random

import sys


def triInsertion(A, n):
    for i in range(0, n ):
        cle = A[i]
        j = i - 1
        while ((j >= 0) & (A[j] > cle)):
            A[j + 1] = A[j]
            j=j-1
        A[j + 1] = cle
    


def tableauAleatoire(n):
    t = [0]*n
    for i in range(n):
        t[i] = random.randint(1, n)
    return t

def tableauCroissant(n):
    t = [0]*n
    for i in range(n):
        t[i] = i
    return t

def tableauDecroissant(n):
    t = [0]*n
    for i in range(n):
        t[i] = n - i
    return t

def TableauCroissantSaufDernier(n):
    t = [0]*n
    for i in range(n):
        t[i] = i
    t[n-1] = 0
    return t

if __name__ == "__main__":


    max = int(sys.argv[1])
    a = [0]*max

    if int(sys.argv[2]) == 0:
        a = tableauAleatoire(max)
    elif int(sys.argv[2]) == 1:
        a = tableauCroissant(max)
    elif int(sys.argv[2]) == 2:
        a = tableauDecroissant(max)
    elif int(sys.argv[2]) == 3:
        a = TableauCroissantSaufDernier(max)
    else:
        print("Erreur")
    print(a)
    triInsertion(a, max)
    print(a)

