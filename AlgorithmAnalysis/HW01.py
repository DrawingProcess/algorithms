# (1) n개의 데이타를 random으로 생성
import random
n = int(input("Please input data number: "))
data = [random.randrange(1, 101) for i in range(n)]
for i in range(n):
    print(data[i])
print(" ")
# (2)-(A) O(n^2) 인 exchange sort 알고리즘
def exchangeSort(lst):
    n = len(lst)
    temp = 0
    for i in range(0, n-1):
        for j in range(i+1, n):
            if lst[j] < lst[i]:
                temp = lst[i]
                lst[i] = lst[j]
                lst[j] = temp

# (2)-(B) O(n log n) 알고리즘인 merge sort 알고리즘
def mergeSort(lst):
    