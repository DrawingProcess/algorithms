import random

def mergeSort(lst):
    if len(lst) <= 1:
        return lst

    mid = len(lst) // 2
    left = lst[:mid]
    right = lst[mid:]

    left1 = mergeSort(left)
    right1 = mergeSort(right)
    return merge(left1, right1)

def merge(left, right):
    i = 0
    j = 0
    result = []

    while(i < len(left)) & (j < len(right)):
        if left[i] < right[i]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1

    while (i < len(left)):
        result.append(left[i])
        i += 1

    while(j < len(right)):
        result.append(right[j])
        j += 1

    return result

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

n = 10
data = [random.randrange(1, 101) for i in range(n)]

for i in range(n):
    print(data[i])
print(" ")
data = mergeSort(data)
for i in range(n):
    print(data[i])