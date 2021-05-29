import math
class Heap(object):
    n=0
    def __init__(self, data):
        self.data=data
        self.n=len(self.data)-1

    def siftDown(self,i):
        siftkey = self.data[i]
        parent = i
        spotfound = False
        while(2*parent <= self.n and not spotfound):
            if(2*parent < self.n and self.data[2*parent] < self.data[2*parent+1]):
                largerchild = 2*parent +1
            else:
                largerchild = 2*parent
            if(siftkey < self.data[largerchild]):
                self.data[parent] = self.data[largerchild]
                parent = largerchild
            else:
                spotfound = True
        self.data[parent] = siftkey
     
    def makeHeap2(self):
        for i in range(int(self.n/2), 0,-1):
            self.siftDown(i)

    def root(self):
        if(self.n>0):
            keyout = self.data[1]
            self.data[1] = self.data[self.n]
            self.n = self.n - 1
            self.siftDown(1)   
        return keyout
    
    def removeKeys(self):
        result = []
        for i in range(self.n,0,-1):
             result.append(self.root()) #?
            
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