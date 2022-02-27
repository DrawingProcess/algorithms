import utility

a=['A','A','C','A','G','T','T','A','C','C']
b=['T','A','A','G','G','T','C','A']

m=len(a)
n=len(b)
table=[[0 for j in range(0,n+1)] for i in range(0,m+1)]
minindex = [[ (0,0) for j in range(0,n+1)] for i in range(0,m+1)]

for j in range(n-1,-1,-1):
    table[m][j] =table[m][j+1]+2

for i in range(m-1,-1,-1):
    table[i][n] =table[i+1][n]+2

# 테이블 생성 구현
for i in range(9, -1, -1):
    for j in range(7, -1, -1):
        pernalty = 1
        if a[i] == b[j]:
            pernalty = 0
        table[i][j] = min(min(table[i+1][j+1] + pernalty, table[i+1][j] + 2), table[i][j+1] + 2)

# minindex
i = 0; j = 0
while i < 10 and j < 8:
    pernalty = 1
    if a[i] == b[j]:
        pernalty = 0
    val11 = table[i+1][j+1] + pernalty
    val01 = table[i][j+1] + 2
    val10 = table[i+1][j] + 2
    # print(table[i][j], val11, val01, val10)
    if table[i][j] == val11:
        minindex[i][j] = (i+1, j+1)
        # print(i, j, val11)
        i = i + 1
        j = j + 1
    elif table[i][j] == val01:
        minindex[i][j] = (i, j+1)
        # print(i, j, val01)
        j = j + 1
    elif table[i][j] == val10:
        minindex[i][j] = (i+1, j)
        # print(i, j, val10)
        i = i + 1


utility.printMatrix(table)
x=0
y=0

# 최적해 도출
while (x <m and y <n):
    tx, ty = x, y
    print(minindex[x][y])
    (x,y)= minindex[x][y]
    if x == tx + 1 and y == ty+1:
        print(a[tx]," ",  b[ty])
    elif x == tx and y == ty+1:
        print(" - ", " ", b[ty])
    else:
        print(a[tx], " " , " -")