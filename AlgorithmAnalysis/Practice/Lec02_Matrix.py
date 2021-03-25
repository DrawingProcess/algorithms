A=[[1,2,3],[4,5,6]]
B=[[5,2,3], [1,3,1]]
hap=[[0,0,0],[0,0,0]]

for i in range(len(A)):
    for j in range(len(A[0])):
           hap[i][j]=A[i][j]+B[i][j]
for m in hap:
    print(m)
print(hap)
