import utility

class Node:
    def __init__(self, data):
        self.l_child=None
        self.r_child=None
        self.data = data

def tree(key,r,i,j):
    k=r[i][j]
    if(k==0):
        return
    else:
        p=Node(key[k])
        p.l_child=tree(key,r,i,k-1)
        p.r_child=tree(key,r,k+1,j)
        return p

# basic input
# key=[" ","A","B","C","D"]
# p=[0,0.375, 0.375, 0.125, 0.125]

# assignment input
key=[" ","A","B","C","D","E"]
p=[0, 4/15, 5/15, 1/15, 3/15, 2/15]
n=len(p)-1

a=[[0 for j in range(0,n+2)] for i in range(0,n+2)]
r=[[0 for j in range(0,n+2)] for i in range(0,n+2)]

for i in range (1,n+1):
    a[i][i-1]=0
    a[i][i]=p[i]
    r[i][i]=i
    r[i][i-1]=0

a[n+1][n]=0
r[n+1][n]=0

for diagonal in range(1,n+1):
    for i in range(1, n-diagonal+2):
        j = i + diagonal - 1
        a[i][j] = 987654321
        psum = sum(p[i:j+1]) # p[i]~p[j]까지의 합  

        for k in range(i, j+1):
            temp = a[i][k-1] + a[k+1][j] + psum
            if(temp < a[i][j]):
                a[i][j] = temp
                r[i][j] = k

print("---------------------------------------------------------------")
print("HW05_1 최적이진검색트리(p6_dp_OBStree_alignment.pptx p10)\n")
utility.printMatrixF(a)
print()
utility.printMatrix(r)

root=tree(key,r,1,n)
utility.print_inOrder(root)
print()
utility.print_preOrder(root)

# --------------------------------------------------------------------------------

# basic input
# a=['A','A','C','A','G','T','T','A','C','C']
# b=['T','A','A','G','G','T','C','A']

# assignment input
a=['A','A','C','A','G','T','A','C','C']
b=['T','A','C','G','T','T','C','A']

m=len(a)
n=len(b)
table=[[0 for j in range(0,n+1)] for i in range(0,m+1)]
minindex = [[ (0,0) for j in range(0,n+1)] for i in range(0,m+1)]

for j in range(n-1,-1,-1):
    table[m][j] =table[m][j+1]+2

for i in range(m-1,-1,-1):
    table[i][n] =table[i+1][n]+2

# 테이블 생성 구현
for i in range(m-1, -1, -1):
    for j in range(n-1, -1, -1):
        pernalty = 1
        if a[i] == b[j]:
            pernalty = 0
        table[i][j] = min(min(table[i+1][j+1] + pernalty, table[i+1][j] + 2), table[i][j+1] + 2)

# minindex
i = 0; j = 0
while i < m and j < n:
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

print("---------------------------------------------------------------")
print("HW05_2 DNA 서열 맞춤 알고리즘(p6_dp_OBStree_alignment.pptx p29)\n")
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