


def sousTriRapide(A, p, r) :
    if  p<r-1 :
        q = partition(A, p, r)
        sousTriRapide(A, p, q)
        sousTriRapide(A, q + 1, r)
