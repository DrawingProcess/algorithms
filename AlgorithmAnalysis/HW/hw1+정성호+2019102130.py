import random
import time


def exchange_sort(n, S):            #exchange sort

    for i in range(0, n-1):         
        for j in range(i+1, n):
            if(S[j] < S[i]):
                temp = S[i]
                S[i] = S[j]
                S[j] = temp

                
def merge_sort(S):                  #merge sort
    
    Select1 = 0
    Select2 = 0
    Select = 0

    n = len(S)

    if n <= 1:
        return

    mid = n // 2
    Part1 = S[:mid]
    Part2 = S[mid:]
    merge_sort(Part1)
    merge_sort(Part2)

    while Select1 < len(Part1) and Select2 < len(Part2):

        if Part1[Select1] > Part2[Select2]: 

            S[Select] = Part1[Select1]
            Select += 1
            Select1 += 1


        else:
            S[Select] = Part2[Select2]
            Select += 1
            Select2 += 1

    while Select1 < len(Part1):
        S[Select] = Part1[Select1]
        Select1 += 1
        Select += 1

    while Select2 < len(Part2):

        S[Select] = Part2[Select2]
        Select2 += 1
        Select += 1



numList = [2000, 4000, 12000]               # 난수 생성량
ExOpTm = []
MgOpTm = []

for n in numList:    
    dataExchg = [random.randrange(1, 100) for i in range(n)]        
    sTime = time.time()                 # 현재 시간
    exchange_sort(n, dataExchg)         # 함수 실행
    nTime = time.time()                 # 실행 후 시간
    TimeEx = nTime - sTime              # 걸린 시간
    ExOpTm.append(TimeEx)               



    dataMerge = [random.randrange(1, 100) for i in range(n)]
    sTime = time.time()             # 현재 시간
    merge_sort(dataMerge)           # 함수 실행
    nTime = time.time()             # 실행 후 시간
    TimeMg = nTime - sTime          # 걸린 시간
    MgOpTm.append(TimeEx)               

    print(n, "일떄 수행시간 결과")
    print("Exchange Sort : ", TimeEx, " Merge Sort : ", TimeMg)


import math


Sum1 = 0
Sum2 = 0

# ExOpTm 은 Exchange Sort 실행에 걸린 시간을 담고 있음
# MgOpTm 은 Merge Sort 실행에 걸린시간을 담고 있음

for i in range(0, len(numList)):
    Sum1 += ((numList[i]*numList[i]) / ExOpTm[i]) 

for i in range(0, len(numList)):
    Sum2 += ((numList[i]*math.log2(numList[i])) / MgOpTm[i]) 

print(Sum1 / len(numList))
print(Sum2 / len(numList))