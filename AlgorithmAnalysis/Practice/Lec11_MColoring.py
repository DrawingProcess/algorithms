def promising(i, vcolor):
    k = 0
    switch = True
    while k < i and switch:
        if W[i][k] and vcolor[i] == vcolor[k]:
            switch = False
        k += 1
    return switch

def color(i, vcolor):
    if promising(i, vcolor):
        if i == n-1:
            print(vcolor)
        else:
            for j in range(1, m+1):
                vcolor[i+1] = j
                color(i+1, vcolor)

n = 4
W = [[0, 1, 1, 1], [1, 0, 1, 0], [1, 1, 0, 1], [1, 0, 1, 0]]
vcolor = n * [-1]
m = 3

color(-1, vcolor)