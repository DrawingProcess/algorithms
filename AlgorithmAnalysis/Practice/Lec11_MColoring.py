def color(i, vcolor):
    #구현 시작
    if promising(i, vcolor):
        if i == n-1:
            print(vcolor)
        else:
            for tmp in range(1, m+1):
                vcolor[i+1] = tmp
                color(i+1, vcolor)
    #구현 종료

def promising(I, vcolor):
    #구현 시작
    switch = True
    j = 0

    while j<I and switch:
        if W[I][j] and vcolor[I] == vcolor[j]:
            switch = False
        j += 1

    return switch
    #구현 종료

n = 4
W = [[0, 1, 1, 1], [1, 0, 1, 0], [1, 1, 0, 1], [1, 0, 1, 0]]
vcolor = n * [-1]
m = 3

color(-1, vcolor)