def triInsertion(A, n):
    for i in range(0, n - 1):
        cle = A[i]
        j = i - 1
        while j >= 0 & A[j] > cle:
            A[j + 1] = A[j]
        A[j + 1] = cle

if __name__ == "__main__":
    max = 100
    a = [0]*max
    for i in range(max):
        a[i] = random.randint(1, 100)

    # Démarrer le chronomètre
    debut = time.time()

    triInsertion(a, max)
    print(a)

    # Arrêter le chronomètre
    fin = time.time()
    # Calculer et afficher la durée
    duree = fin - debut
    print(f"Temps écoulé: {duree} secondes")
