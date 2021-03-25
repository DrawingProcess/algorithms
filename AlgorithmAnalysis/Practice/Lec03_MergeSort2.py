def mergeSort2 (S, low, high):
    if (low < high):
        mid = (low + high) // 2
        mergeSort2(S, low, mid)
        mergeSort2(S, mid+1, high)
        merge2(S, low, mid, high)

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

s = [3,5,2,9,10,14,4,8]
mergeSort2(s, 0, 7)
print(s)