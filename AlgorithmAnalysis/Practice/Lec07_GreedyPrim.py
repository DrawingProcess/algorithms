import utility

inf = 1000
w=[[0,  1,  3,inf, inf],
   [1,  0,  3,6,   inf],
   [3,  3,  0,4,   2],
   [inf,6,  4,0,   5],
   [inf,inf,2,5,   0]]

F = set()
utility.printMatrix(w)
n=len(w)
nearest=n*[0]
distance=n*[0]

for i in range(1,n):
    nearest[i] = 0
    distance[i] = w[0][i]
# prim’s 알고리즘 구현
for cnt in range(n-1):
    min_ = inf
    for i in range(1, n):
        if (0 <= distance[i] and distance[i] < min_):
            min_ = distance[i]
            vnear = i
    e = (vnear, nearest[vnear])
    F.add(e)
    distance[vnear] = -1; # 찾은노드를 Y에 추가한다.
    for i in range(1, n):
        if (w[i][vnear] < distance[i]): # Y에 없는 각 노드에 대해서
            distance[i] = w[i][vnear] # distance[i]를 갱신한다.
            nearest[i] = vnear

print()
print(F) # set이므로 순서는 무관

# output
#    0    1    3 1000 1000 
#    1    0    3    6 1000 
#    3    3    0    4    2 
# 1000    6    4    0    5 
# 1000 1000    2    5    0 

# {(4, 2), (2, 0), (1, 0), (3, 2)}