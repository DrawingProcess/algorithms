import random
import time
import matplotlib.pyplot as plt

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

# (1) n개의 데이타를 random으로 생성
# (3) n=2,000, 4,000, 12,000에 대해 알고리즘 A, B가 종료될 때까지의 시간을 측정한다.
num = [2000, 4000, 12000]
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
    print(f'{}')
    print(f'{Atime:10.5f} {Btime:10.5f}')

# (4) A, B 를 1분간 수행할 때 해결할 수 있는 문제의 크기
At = []
countA = 0
while True:
    n = countA * 1000
    dataA = [random.randrange(1, 101) for i in range(n)]

    Stime = time.time()
    exchangeSort(dataA)
    Ltime = time.time()
    Atime = Ltime - Stime

    At.append(Atime)
    countA = countA + 1
    print(f'{countA:2d} {Atime:10.5f}')
    print(time.strftime('%M-%S', time.localtime(Atime)))
    if Atime > 60:
        break

Bt = []
countB = 0
while True:
    n = countB * 30000
    dataB = [random.randrange(1, 101) for i in range(n)]

    Stime = time.time()
    mergeSort(dataB)
    Ltime = time.time()
    Btime = Ltime - Stime

    Bt.append(Btime)
    countB = countB + 1
    print(f'{countB:2d} {Btime:10.5f}')
    print(time.strftime('%M-%S', time.localtime(Btime)))
    if Btime > 60:
        break

Ax = []
for i in range(countA):
    Ax.append(i * 1000)
Bx = []
for i in range(countB):
    Bx.append(i * 10000)
plt.plot(Ax, At, 'r--', Bx, Bt, 'bs')
plt.xlabel('Number of Data')
plt.ylabel('Time')
plt.show()
plt.savefig('./SortingTime_limit60.png')