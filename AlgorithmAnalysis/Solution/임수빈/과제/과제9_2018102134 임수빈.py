#알고리즘 분석 과제 9
#2018102134 임수빈


import utility
e={0:[1,2,3], 1:[2,5], 2:[3,4,5,6], 3:[4,6],4:[6,7]}
n=8
a = [ [0 for j in range(0,n)] for i in range(0,n)]
for i in range(0,n-1):
    for j in range(i+1,n):
        if i in e:
           if j in e[i]:
              a[i][j]=1
              a[j][i]=1
utility.printMatrix(a)

visited =n*[0]

def DFS(a,v):
    print(v)
    visited[v] =1
    if v in e:
        for i in e[v]:
            if visited[i] != 1:
                DFS(a,i)

           
DFS(a,0)
print('\n\n ---------------------------\n\n')



def promising(i,col):
    k = 0
    switch = True
    while(k < i and switch):
        if col[i] == col[k] or abs(col[i] - col[k]) == i-k:
            switch = False
        k += 1
        
    return switch



def queens(n,i,col):
    if promising(i,col):
        if i+1 == n:
            print(col)
        else:
            for j in range(0,n):
                col[i+1] = j
                queens(n,i+1,col)




n=5
col=n*[0]
queens(n,-1,col)
