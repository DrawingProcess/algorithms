A=[[1,2,3],[4,5,6]]
B=[[1,2],[3,4],[5,6]]
mul = [[0,0],[0,0]]

for i in range(len(A)):
    for j in range(len(B[0])):
        for k in range(len(B)):
            mul[i][j]+=A[i][k]*B[k][j]
for m in mul:
    print(m)
