# @@@ author : 2018102092 Minji Kwon @@@
# @@@ Assignment 2 source code @@@

import tracemalloc # count size and peok of memory
import sys         # set the number of limitation when we call recursion
import math
sys.setrecursionlimit(10000)


# Slide 15 -- Merge Sort 1
def merge(h, m, U, V, S):
    # 함수 내에서 사용되는 변수
    # i, j, k, h, m, U, V, S
    # 공간복잡도 = 5 + 2n
    # 하지만 python에서 list는 mutable하므로, U,V,S는 이미 mergeSort 함수에서 할당됨. => 5만큼의 추가 공간이 필요

    i = j = k = 0

    while(i < h and j < m):
        if(U[i] <= V[j]):
            S[k] = U[i]
            i += 1
        else:
            S[k] = V[j]
            j += 1
        k += 1

    if(i >= h):
        while(j < m):
            S[k] = V[j]
            k += 1
            j += 1

    else:
        while (i < h):
            S[k] = U[i]
            k += 1
            i += 1

def mergeSort(n ,S, count):
    # 함수 내에서 사용되는 변수
    # h, m, n, S, U, V, count
    # 공간복잡도 = (S[], U[], V[], count[]의 원소를 저장할 공간 2n+1) + (변수 h, m , n을 위한 공간) = 2n + 4
    # python 내의 list는 mutable하므로, S, U, V, count[]를 위한 공간 2n+1은 처음 선언 때에만 포함됨 => +3

    h = n // 2
    m = n - h
    U = []
    V = []

    # 추가 저장공간 더함
    if(h > 0):
        tmp = 0
        for i in count:
            if(h == i):
               tmp += 1
        if(tmp <= 1):
            #count.append(111111111111)
            count.append(h)
            count.append(m)
            #count.append(111111111111)


    if(n>1):
        for i in range(h):
            U.append(S[i])
        for j in range(m):
            V.append(S[j + h])

        mergeSort(h, U, count)
        mergeSort(m, V, count)
        merge(h, m, U, V, S)


tracemalloc.start()  # 추적 시작
print(">>> Slide 15")

count = []     # 변수 개수 계산을 위한 변수
s1=[3,5,2,9,10,14,4,8]   # input array

print("\nGiven array is", s1)
mergeSort(8, s1, count)
print("Sorted array is", s1)    # print sorted array


### 공간복잡도(함수 내에서 만들어지는 변수 개수) 계산 결과
total = 0

# 추가 저장 공간 계산 과정 출력
tmp_str1 = "                         = "
for i in range(len(count)):
    if(i == len(count)-1):
        tmp_str1 += "{}".format(count[i])
    else:
        tmp_str1 += "{} + ".format(count[i])
    total += count[i]

print("\ntotal additional storage =", total)
print(tmp_str1)

# first_size : 추적한 메모리 블록의 현재
# first_peak : 메모리 최대 사용량
first_size, first_peak = tracemalloc.get_traced_memory()
tracemalloc.stop()  # 추적 중지

print("\nSize of mem = ", first_size)
print("Peak of mem = ", first_peak, '\n')
print("-------------------------------------------------------\n")



# Slide 21 -- Merge Sort 2
def merge2(s, low, mid, high):
    # 함수 내에서 사용하는 변수
    # n1, n2, mid, low, high, L[n1], R[n2], i, j, S[n], k
    # 공간복잡도 = (L[], R[], S[]을 위한 공간. 이때, 주의할 점은 S[]는 이미 선언되어 있음 =>n만 필요) + (n1, n2, mid, low, high, i, j, k를 위한 공간)
    #          = n + 8

    n1 = mid - low + 1  # size of left array(low)
    n2 = high - mid     # size of right array(high)

    # allocates array
    L = [0] * (n1)  # Left
    R = [0] * (n2)  # Right

    for i in range(0, n1):
        L[i] = s[low + i]

    for j in range(0, n2):
        R[j] = s[mid + 1 + j]

    i = 0
    j = 0
    k = low

    while i < n1 and j < n2:
        if L[i] <= R[j]:
            s[k] = L[i]
            i += 1
        else:
            s[k] = R[j]
            j += 1
        k += 1

    while i < n1:
        s[k] = L[i]
        i += 1
        k += 1

    while j < n2:
        s[k] = R[j]
        j += 1
        k += 1


def mergeSort2(s, low, high, count):
    # 사용하는 변수 : s[n], low, high, count[1], mid
    # 공간복잡도 = (n + 1) + 3
    # list는 선언 이후 mutable하게 동일한 메모리에서 값만 변경되므로 초기에 한 번만 더해주면 됨.

    if low < high:
        mid = (low + (high - 1)) // 2

        mergeSort2(s, low, mid, count)
        mergeSort2(s, mid + 1, high, count)

        check = 0
        num = high-low+1
        if(num > 0):
            for i in count:
                if (num == i):
                    check += 1
            if (check < 1):
                count.append(num)

        merge2(s, low, mid, high)


tracemalloc.start()
print(">>> Slide 21\n")

s2 = [3, 5, 2, 9, 10, 14, 4, 8]
n2 = len(s2)
count2 = []

print("Given array is", s2)
mergeSort2(s2, 0, n2 - 1, count2)
print("Sorted array is", s2, '\n')

### merge2 공간복잡도 계산
total2 = 0
tmp_str2 = "                         = "
for i in range(len(count2)):
    if(i == len(count2)-1):
        tmp_str2 += "{}".format(count2[i])
        total2 += count2[i]
    else:
        tmp_str2 += "{} - ".format(count2[i])
        tmp_str2 += "{} + ".format(count2[i])

print("\ntotal additional storage =", total2)
print(tmp_str2)

### memory
second_size, second_peak = tracemalloc.get_traced_memory()
print("\nSize of mem = ", second_size)
print("Peak of mem = ", second_peak)