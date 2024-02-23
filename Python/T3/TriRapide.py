import sys
import random


def partition(A, p, r):
    pivot = A[r - 1]
    i = p
    for j in range(p, r - 1):
        if A[j] <= pivot:
            temp = A[i]
            A[i] = A[j]
            A[j] = temp
            i += 1
    temp = A[i]
    A[i] = A[r - 1]
    A[r - 1] = temp
    return i


def sousTriRapide(A, p, r):
    if p < r - 1:
        q = partition(A, p, r)
        sousTriRapide(A, p, q)
        sousTriRapide(A, q + 1, r)


def triRapide(A, n):
    sousTriRapide(A, 0, n)


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

    sys.setrecursionlimit(1000000)
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
    triRapide(a, max)
    print(a)






