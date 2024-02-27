import time
import random

import sys


def fusion(A, p, q, r):
    n1 = q - p
    n2 = r - q
    Ag = [0]*n1
    Ad = [0]*n2

    for i in range(0, n1):
        Ag[i] = A[p + i]
    for j in range(0, n2):
        Ad[j] = A[q + j]

    indg = 0

    indd = 0

    i = p

    while i < r:
        if indg == n1:
            A[i] = Ad[indd]
            indd = indd + 1
        elif indd == n2:
            A[i] = Ag[indg]
            indg = indg + 1
        elif indd == n2:
            A[i] = Ag[indg]
            indg += 1
        elif Ag[indg] < Ad[indd]:
            A[i] = Ag[indg]
            indg = indg + 1
        else:
            A[i] = Ad[indd]
            indd = indd + 1
        i = i + 1


def sousTriFusion(A, p, r):
    if p < r - 1:
        q = (p + r) // 2
        sousTriFusion(A, p, q)
        sousTriFusion(A, q, r)
        fusion(A, p, q, r)


def triFusion(A, n):
    sousTriFusion(A, 0, n)



    
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
    triFusion(a, max)
    print(a)

    


