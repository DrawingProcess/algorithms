import random
import time

def mymax(i, Alist):
    m = 0
    for j in range(i+1):
        if Alist[j] > m:
            m = Alist[j]
    return m


def alg1(Alist):
    mList = []
    for i in range(len(Alist)):
        mList.append(mymax(i,Alist))
    return mList


def alg2(Alist):
    mList = []
    curMax = 0
    for i in Alist:
        if curMax < i:
            curMax = i

        mList.append(curMax)
    return mList
'''
def alg3(Alist):
    mList = []
    cur = 0
    for i in Alist:
        cur = max(cur,i)
        mList.append(cur)
    return mList
'''
while(True):
    n = int(input("Enter n: "))
    if(n < 0):break  
    A = []
    for i in range(n):
        A.append(random.randint(1,99))



    startTime = time.time()
    M1 = alg1(A)
    endTime = time.time()
    print("alg1 :",endTime-startTime)

    startTime = time.time()
    M2 = alg2(A)
    endTime = time.time()
    print("alg2 :",endTime-startTime)

    print()
