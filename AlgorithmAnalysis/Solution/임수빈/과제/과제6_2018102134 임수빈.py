#2018102134 임수빈

import utility

def DNA_Sequence_Alignment(a,b):
    m=len(a)
    n=len(b)
    table=[[0 for j in range(0,n+1)] for i in range(0,m+1)]
    minindex = [[ (0,0) for j in range(0,n+1)] for i in range(0,m+1)]

    for j in range(n-1,-1,-1):
        table[m][j] =table[m][j+1]+2

    for i in range(m-1,-1,-1):
        table[i][n] =table[i+1][n]+2

    si = m-1
    sj = n-1
    i = si
    j = sj


    while (True):   
        penalty = 0
        if a[i] != b[j]:
            penalty = 1
            
        table[i][j] = table[i+1][j+1] + penalty
        t1 = table[i+1][j] + 2
        t2 = table[i][j+1] +2
        if table[i][j] > t1:
            table[i][j] = t1
            minindex[i][j] = (i+1,j)
        elif table[i][j] > t2:
            table[i][j] = t2
            minindex[i][j] = (i,j+1)
        else:
            minindex[i][j] = (i+1,j+1) 
            
        if i == 0 and j == 0:break
        
        elif i == m-1 or j == 0:
            if si > 0:
                si -= 1
                i = si
                j = n-1
            else:
                i = 0;
                sj -= 1
                j = sj
        else:
            i += 1
            j -= 1
            
            
            
    utility.printMatrix(table)
    x=0
    y=0

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
            

a1=['A','A','C','A','G','T','T','A','C','C']
b1=['T','A','A','G','G','T','C','A']

a2=['T', 'G', 'A', 'C', 'A', 'A', 'G', 'T']
b2=['T', 'A', 'C', 'A', 'A', 'T', 'T']

DNA_Sequence_Alignment(a1,b1)
print("\n")
DNA_Sequence_Alignment(a2,b2)

