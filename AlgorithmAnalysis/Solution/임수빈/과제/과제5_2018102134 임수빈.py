#알고리즘 분석 과제5
#소프트웨어융합학과
#2018102134 임수빈

import utility

def order(p,i,j):
    if i ==j:
        print("A",i,end ="")
    else:
        k = p[i][j]
        print("(", end = "")
        order(p,i,k)
        order(p,k+1,j)
        print(")",end = "")
        
print("-------------연쇄행렬 곱셈-------------\n")
         
d=[5,2,3,4,6,7,8]
n=len(d)-1

m=[[0 for j in range(1,n+2)] for i in range(1,n+2)]
p=[[0 for j in range(1,n+2)] for i in range(1,n+2)]

for i in range(1,n+1):
    m[i][i] = 0
for diagonal in range(1,n):
    for i in range(1,n-diagonal+1):
        j = i + diagonal
        temp = 1000 # 최소값 저장용 
        for k in range(i,j):
            mm = m[i][k]+m[k+1][j] + d[i-1]* d[k]*d[j]
            if temp >= mm:
                temp = mm
                p[i][j] = k
            m[i][j] = temp    


utility.printMatrix(m)
print()
utility.printMatrix(p)
order(p,1,6)

#----------------------문제2--------------------------
print("\n\n-------------최적 이진 검색트리-------------\n")

class Node:
    def __init__(self,data):
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
    
key=[" ","A","B","C","D"]
p=[0,0.375, 0.375, 0.125,0.125]
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
for diagonal in range(1,n):
    for i in range(1,n-diagonal+1):
        j = i + diagonal
        temp = 1000 # 최소값 저장용
        pm = sum(p[i:j+1]) # p[i]~p[j]의 합  
        for k in range(i,j+1):
            aa = a[i][k-1]+a[k+1][j] + pm
            if temp > aa:
                temp = aa
                r[i][j] = k

        a[i][j] = temp
    

# utility.printMatrixF(a)
# print()
# utility.printMatrix(r)

# root=tree(key,r,1,n)
# utility.print_inOrder(root)
# print()
# utility.print_preOrder(root)


