#과제 3 - 2018102134 임수빈

def quickSort(s,low, high):
    if(high > low):
        pivot = partition(s,low,high) # pivot을 기준으로 나눈다.
        quickSort(s,low,pivot-1) # pivot보다 작은 부분에서 다시 quickSort
        quickSort(s,pivot+1,high) # pivot 보다 큰 부분에서 다시 quickSort

    
def partition(s,low,high):
    pivotitem = s[low]
    j = low
    for i in range(low+1,high+1):
        if s[i] < pivotitem:
            j += 1
            temp = s[i]
            s[i] = s[j]
            s[j] = temp
            
    pivot = j
    temp = s[low]
    s[low] = s[pivot]
    s[pivot] = temp
    
    return pivot
            

    

s=[3,5,2,9,10,14,4,8]
quickSort(s,0,7)
print(s)


def prod2(a,b):
    n = max(len(str(a)),len(str(b)))
    if a == 0 or b == 0: return 0
    elif n <= 5:
        return a*b
    else:
        m = int(n/2)
        x = a // (10**m); y = a % 10**m
        w = b // (10**m); z = b % 10**m
        r = prod2(x+y,w+z)
        p = prod2(x,w)
        q = prod2(y,z)
        return p * 10**(2*m) + (r-p-q)*10**m +q





    
a=1234567812345678
b=2345678923456789

print(prod2(a,b))
print(a*b)
