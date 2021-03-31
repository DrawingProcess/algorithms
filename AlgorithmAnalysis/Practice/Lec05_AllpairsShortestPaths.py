# All-pairs chortest paths problem - Optimization problem
def floyd(n, W, D):
    D = W[:]
    for k in range(1, n+1):
        for i in range(1, n+1):
            for j in range(1, n+1):
                D[i][j] = min(D[i][j], D[i][k] + D[k][j])
def path (p, q):
    if P[p][q] != 0:
        path(q, P[p][q])
        print(" v", P[p][q])
        path(P[p][q], q)
