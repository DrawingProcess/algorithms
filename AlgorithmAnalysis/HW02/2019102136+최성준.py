import sys

class space:
    def __init__(self):
        self.result = 0
        self.max = -1
        self.result_str = ""
        self.string = "0"
    def add(self,num):
        self.result += len(num)
        self.string += " + " + str(len(num))
    def sub(self,num):
        self.result -= len(num)
        self.string += " + " + str(len(num))
    def maximum(self):
        if self.result > self.max:
            self.max = self.result
            self.result_str = "= " + self.string

def mergeSort (n, S):
    mid = n // 2; high = n - mid
    # left = [0 for i in range(h)]
    # right = [0 for i in range(m)]
    if (n > 1):
        left = S[:mid]
        right = S[mid:]

        num.add(left)          
        num.add(right)
        num.maximum()

        mergeSort(mid, left)
        mergeSort(high, right)
        merge(mid, high, left, right, S)

        num.sub(left)
        num.sub(right)

def merge(mid, high, left, right, S):
    i = 0; j = 0; k = 0
    while (i < mid and j < high):
        if (left[i] < right[j]):
            S[k] = left[i]
            i += 1
        else:
            S[k] = right[j]
            j += 1
        k += 1
    while i < mid:
        S[k] = left[i]
        i += 1
        k += 1
    while j < high:
        S[k] = right[j]
        j += 1
        k += 1

num = space()

s = [3,5,2,9,10,14,4,8]
mergeSort(8, s)
print(">> Sort List using mergeSort")
print(s)

print(">> Max Num of Save Space")
print(num.max, num.result_str)

def mergeSort2 (S, low, high):
    if (low < high):
        mid = (low + high) // 2
        mergeSort2(S, low, mid)
        mergeSort2(S, mid+1, high)
        num2.add(S)
        num2.maximum()
        merge2(S, low, mid, high)
        num2.sub(S)

def merge2(S, low, mid, high):
    i = low; j = mid+1; k = low
    U = S[:]
    while(i <= mid and j <= high):
        if(S[i] < S[j]):
            U[k] = S[i]
            i += 1
        else:
            U[k] = S[j]
            j += 1
        k += 1

    if(i > mid):
        U[k:high+1] = S[j:high+1]
    else:
        U[k:high+1] = S[i:mid+1]
    S[low:high+1] = U[low:high+1]

num2 = space()

s = [3,5,2,9,10,14,4,8]
mergeSort2(s, 0, 7)
print(">> Sort List using mergeSort2")
print(s)

print(">> Max Num of Save Space")
print(num2.max, num2.result_str)

# Validation List [3,16,13,1 ,9,2,7,5, 8,4,11,6, 15,14,10,12]