"""
@ Author : 2018102092 Minji Kwon(minmin0916@khu.ac.kr)
@ Brief : (1) Chained matrix multiplication, (2) Optimal Binary Search Tree.
@ KHU Analysis of Algorithms 2020-2
"""

### (1) 연쇄 행렬 곱셈 ###
"""
# problem : n개의 matrix를 곱하는 최적의 순서 출력
# param : n, p
# print : 최적의 순서
"""
def order(p, i, j):
# 구현 시작
    if i == j:
        print("A{}".format(i), end=" ")

    else:
        k = p[i][j]
        print("(", end=" ")
        order(p, i, k)
        order(p, k+1, j)
        print(")", end=" ")
# 구현 종료

d = [5,2,3,4,6,7,8]
n = len(d) - 1

m=[[0 for j in range(1,n+2)] for i in range(1,n+2)]
p=[[0 for j in range(1,n+2)] for i in range(1,n+2)]

# 구현 시작

class util:     # Utility class
    def __init__(self):
        pass

    def printMatrix(self, d):
        m = len(d)
        n = len(d[0])

        for i in range(0, m):
            for j in range(0, n):
                print("%4d" % d[i][j], end=" ")
            print()

    # print float matrix
    def printMatrixF(self, d):
        n = len(d[0])
        for i in range(0, n):
            for j in range(0, n):
                print("%5.2f" % d[i][j], end=" ")
            print()

utility = util()    # class constructor

for diag in range(1, len(d)):
    for i in range(1, len(d)-diag):
        j = i + diag
        min = 10000000000

        for k in range(i, j):
            temp = m[i][k] + m[k + 1][j] + d[i - 1] * d[k] * d[j]
            if min > temp:
                min = temp
                min_index = k

        m[i][j] = min
        p[i][j] = min_index

# 구현 종료

utility.printMatrix(m)
print()
utility.printMatrix(p)
order(p,1,6)
print("\n\n")


### (2) 최적 이진 탐색 트리 ###
"""
- utility import하지 않고, class로 사용.
- inorder, preorder  함수 별도로 정의하여 사용.
"""

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

# 구현 시작
import fractions
key=[" ", "A", "B", "C", "D", "E"]
p=[0, fractions.Fraction(5,15),
   fractions.Fraction(4,15), fractions.Fraction(3,15),
   fractions.Fraction(2,15), fractions.Fraction(1,15)]
# 구현 종료

#key=[" ","A","B","C","D"]
#p=[0,0.375, 0.375, 0.125, 0.125]
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

# 구현 시작
def print_inOrder(root):            # print tree inorder
    if not root:
        return
    print_inOrder(root.l_child)
    print(root.data)
    print_inOrder(root.r_child)

def print_preOrder(root):           # print tree preorder
    if not root:
        return
    print(root.data)
    print_preOrder(root.l_child)
    print_preOrder(root.r_child)

def sum_(start, end):       # return total sum of p[start] to p[end]
    sum_total = 0
    for i in range(start, end+1):
        sum_total = sum_total + p[i]
    return sum_total

"""
for diagonal in range(1,n):
    for i in range(1, n-diagonal+1):
        j = i + diagonal
        min = 1000000

        for k in range(i, j+1):
            temp = a[i][k-1] + a[k+1][j] + sum_(i,j)
            if(min > temp):
                print(temp)
                min = temp
                min_k = k

        a[i][j] = min
        r[i][j] = min_k

"""
for diagonal in range(1,n+1):
    for i in range(1, n-diagonal+2):
        j = i + diagonal - 1
        a[i][j] = 999999

        for k in range(i, j+1):
            temp = a[i][k-1] + a[k+1][j] + sum_(i,j)
            if(temp < a[i][j]):
                a[i][j] = temp
                r[i][j] = k

# 구현 종료

utility.printMatrixF(a)
print()
utility.printMatrix(r)

root=tree(key,r,1,n)
print_inOrder(root)
print()
print_preOrder(root)
