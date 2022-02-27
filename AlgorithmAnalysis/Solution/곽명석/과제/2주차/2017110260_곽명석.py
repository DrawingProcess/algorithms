# 저장공간을 구하기 위한 클래스.
import sys

class  saveCount:
    def __init__(self):
        self.result = 0
        self.max = -1
    def add(self,num):                      # 분영될때마다 더해줌
        self.result += len(num)
    def sub(self,num):
        self.result -= len(num)
    def change(self):
        if self.result > self.max:
            self.max = self.result


##############################################   mergeSort    ###########################################

def mergeSort(n,s):                 # n = 요소의 갯수, s = 리스트.
    h = n // 2 
    m = n-h
    if(n>1):                        
        leftlist = s[:h]            
        rightlist = s[m:]         

        save_num.add(leftlist)          
        save_num.add(rightlist)
        save_num.change()

        mergeSort(h,leftlist)
        mergeSort(m,rightlist)
        merge(h,m,leftlist,rightlist,s)

        save_num.sub(leftlist)
        save_num.sub(rightlist)

# 15page                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
def merge(h,m,u,v,s):
    i = 0
    j = 0
    k = 0
    while(i<h and j< m):
        if(u[i] < v[j]):
            s[k] = u[i]
            i = i + 1
        else:
            s[k] = v[j]
            j = j  +1
        k = k + 1
    if( i >= h):
        s[k:h+m] = v[j:m]
    else:
        s[k:h+m] = u[i:h]
        





#저장공간의 갯수
save_num = saveCount()

s = [3,5,2,9,10,14,4,8]
mergeSort(8,s)
print(s)
print(save_num.max)


############################################### mergeSort2 ###########################################################



# 21page


def merge2(s,low,mid ,high):
    i = low
    j = mid + 1
    k = low
    u = s[:]
    while(i<=mid and j<=high):
        if(s[i]<s[j]):
            u[k] = s[i]
            i+=1
        else:
            u[k] = s[j]
            j+=1
        k+=1

    if(i>mid):
        u[k:high+1] = s[j:high+1]
    else:
        u[k:high+1] = s[i:mid+1]
    s[low:high+1] = u[low:high+1]
    





def mergeSort2(s, low,high):
    if(low < high):
        mid = (low + high) // 2
        mergeSort2(s,low,mid)
        mergeSort2(s,mid+1,high)
        save_num2.add(s)
        save_num2.change()
        merge2(s,low,mid,high)
        save_num2.sub(s)



save_num2 = saveCount()

s = [3,5,2,9,10,14,4,8]
mergeSort2(s,0,7)
print(s)
print(save_num2.max)