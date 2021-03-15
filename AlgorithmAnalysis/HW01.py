import random
import time

# (2)-(A) O(n^2) 인 exchange sort 알고리즘을 구현
def exchangeSort(lst):
    n = len(lst)
    temp = 0
    for i in range(0, n-1):
        for j in range(i+1, n):
            if lst[j] < lst[i]:
                temp = lst[i]
                lst[i] = lst[j]
                lst[j] = temp

# (2)-(B) O(n log n) 알고리즘인 merge sort 알고리즘을 구현
def mergeSort(lst):
    if len(lst) <= 1:
        return lst

    mid = len(lst) // 2
    left = lst[:mid]
    right = lst[mid:]

    left = mergeSort(left)
    right = mergeSort(right)
    return merge(left, right)

def merge(left, right):
    result = []
    while len(left) > 0 or len(right) > 0:
        if len(left) > 0 and len(right) > 0:
            if left[0] <= right[0]:
                result.append(left[0])
                left = left[1:]
            else:
                result.append(right[0])
                right = right[1:]
        elif len(left) > 0:
            result.append(left[0])
            left = left[1:]
        elif len(right) > 0:
            result.append(right[0])
            right = right[1:]
    return result

# (1) n개의 데이타를 random으로 생성
# (3) n=2,000, 4,000, 12,000에 대해 알고리즘 A, B가 종료될 때까지의 시간을 측정한다.
num = [2000, 4000, 37000]
for n in num:
    dataA = [random.randrange(1, 101) for i in range(n)]
    dataB = [random.randrange(1, 101) for i in range(n)]

    Stime = time.time()
    exchangeSort(dataA)
    Ltime = time.time()
    Atime = Ltime - Stime

    Stime = time.time()
    mergeSort(dataB)
    Ltime = time.time()
    Btime = Ltime - Stime
    
    print(f'{Atime:10.5f} {Btime:10.5f}')
    print(time.strftime('%M-%S', time.localtime(Atime)))