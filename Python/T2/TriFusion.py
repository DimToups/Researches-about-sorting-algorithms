import time
import random


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


if __name__ == "__main__":
    max = 100
    a = [0]*max
    for i in range(max):
        a[i] = random.randint(1, 100)

    # Démarrer le chronomètre
    debut = time.time()

    triFusion(a, max)
    print(a)

    # Arrêter le chronomètre
    fin = time.time()
    # Calculer et afficher la durée
    duree = fin - debut
    print(f"Temps écoulé: {duree} secondes")

