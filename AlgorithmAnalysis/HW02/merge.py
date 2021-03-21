import random
import time

# i) first method - Ascending order
def mergeSortA(lst):
    if len(lst) <= 1:
        return lst

    mid = len(lst) // 2
    left = lst[:mid]
    right = lst[mid:]

    left = mergeSortA(left)
    right = mergeSortA(right)
    return merge(left, right)

def merge(left, right):
    result = []
    i = 0; j = 0
    while( i < len(left) and j < len(right)):
        if left[i] <= right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1
    if i == len(left): result += right[j:len(right)]
    if j == len(right): result += left[i:len(left)]
    return result

# ii) second method - Descending order
def mergeSortB(a):
    n = len(a)
    if n <= 1:
        return

    mid = n // 2
    g1 = a[:mid]
    g2 = a[mid:]
    mergeSortB(g1)
    mergeSortB(g2)

    i1 = 0
    i2 = 0
    ia = 0
    while i1 < len(g1) and i2 < len(g2):
        if g1[i1] > g2[i2]: # 부등호 방향 뒤집기
            a[ia] = g1[i1]
            i1 += 1
        else:
            a[ia] = g2[i2]
            i2 += 1
        ia += 1
    while i1 < len(g1):
        a[ia] = g1[i1]
        i1 += 1
        ia += 1
    while i2 < len(g2):
        a[ia] = g2[i2]
        i2 += 1
        ia += 1

# Sorting - First & Second Method
n = 10
data = [random.randrange(1, 101) for i in range(n)]
for i in range(n):
    print(data[i])
print(" ")

dataA = mergeSortA(data)
for i in range(n):
    print(dataA[i]) 
print(" ")
mergeSortB(data)
for i in range(n):
    print(data[i]) 
print(" ")

# Time Measurement - First & Second Method
numList = [2000, 4000, 12000, 37000]
for n in numList:
    dataA = [random.randrange(1, 100) for i in range(n)]
    dataB = [random.randrange(1, 100) for i in range(n)]
    stime = time.time()
    mergeSortA(dataA)
    nTime = time.time()
    print(nTime - stime)

    stime = time.time()
    mergeSortB(dataB)
    nTime = time.time()
    print(nTime - stime)

# inefficient merge method
# def merge(left, right):
#     result = []
#     while len(left) > 0 or len(right) > 0:
#         if len(left) > 0 and len(right) > 0:
#             if left[0] <= right[0]:
#                 result.append(left[0])
#                 left = left[1:]
#             else:
#                 result.append(right[0])
#                 right = right[1:]
#         elif len(left) > 0:
#             result.append(left[0])
#             left = left[1:]
#         elif len(right) > 0:
#             result.append(right[0])
#             right = right[1:]
#     return result