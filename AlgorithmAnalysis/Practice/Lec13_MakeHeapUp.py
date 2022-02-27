# 방법1: 데이터가 입력되는 순서대로 heap을 매번 구성

import math
class Heap(object):
    n=0
    def __init__(self, data):
        self.data=data
        self.n=len(self.data)-1
        
    def siftUp(self, i):
        while (i >= 2):
            parentpos = i//2
            if self.data[parentpos] > self.data[i]:
                return self.data[i]
            temp = self.data[i]
            self.data[i] = self.data[parentpos]
            self.data[parentpos] = temp
            i = parentpos
        return self.data[i]

    def siftDown(self,i):
        siftkey = self.data[i]
        parent = i
        spotfound = False
        while(2*parent <= self.n and not spotfound):
            if(2*parent < self.n and self.data[2*parent] < self.data[2*parent+1]):
                largerchild = 2*parent + 1
            else:
                largerchild = 2*parent
            if(siftkey < self.data[largerchild]):
                self.data[parent] = self.data[largerchild]
                parent = largerchild
            else:
                spotfound = True
                
        self.data[parent] = siftkey

    def root(self):
        if(self.n>0):
            keyout = self.data[1]
            self.data[1] = self.data[self.n]
            self.n = self.n - 1
            self.siftDown(1)  
        return keyout
     
    def makeHeap1(self):
        for i in range(1, self.n + 1):
            self.siftUp(i)
    
    def removeKeys(self):
        result = []
        for i in range(self.n,0,-1):
            result.append(self.root())
        return result
          
def heapSort(a):
    h = Heap(a)
    h.makeHeap1()
    return h.removeKeys()

a=[0,11,14,2,7,6,3,9,5]
b=Heap(a)
b.makeHeap1()
print(b.data)
s=heapSort(a)
print(s)