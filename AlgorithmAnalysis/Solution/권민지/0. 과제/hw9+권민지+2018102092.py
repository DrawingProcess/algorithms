# 2018102092 소프트웨어융합학과 권민지
#(1) 31-33쪽: [실습과제] 방법2을 이용하여 makeHeap을 구현하고 힙정렬 알고리즘을 python으로 완성하라.

class Heap:
    def __init__(self):
        self.heap = []
        self.n = 0
        self.origin = []

    def leftChild(self, i):
        if 2 * i + 1 < self.n:
            return 2 * i + 1
        return None

    def rightChild(self, i):
        if 2 * i + 2 < self.n:
            return 2 * i + 2
        return None

    def maxHeapify(self, node):
        if node < self.n:
            m = node
            lc = self.leftChild(node)
            rc = self.rightChild(node)
            if lc is not None and self.heap[lc] > self.heap[m]:
                m = lc
            if rc is not None and self.heap[rc] > self.heap[m]:
                m = rc
            if m != node:
                temp = self.heap[node]
                self.heap[node] = self.heap[m]
                self.heap[m] = temp
                self.maxHeapify(m)

        self.origin[1:] = self.heap

    def makeHeap(self, a):
        self.n = len(a) - 1
        self.origin = list(a)
        self.heap = list(a)[1:]
        for i in range(self.n // 2, -1, -1):
            self.maxHeapify(i)

    def heapSort(self):
        size = self.n
        for i in range(size//2, -1, -1):
            self.maxHeapify(i)

        for i in range(size -1, -1, -1):
            temp = self.heap[i]
            self.heap[i] = self.heap[0]
            self.heap[0] = temp
            self.maxHeapify(0)

    def addElt(self, data):
        self.heap.append(data)
        curr = self.n
        self.n += 1
        while (curr - 1) // 2 >= 0 and self.heap[curr] > self.heap[(curr - 1) // 2]:
            temp = self.heap[(curr - 1) // 2]
            self.heap[(curr - 1) // 2] = self.heap[curr]
            self.heap[curr] = temp
            curr = (curr - 1) // 2

        self.origin[1:] = self.heap

    def display(self):
        print(self.origin)

    def display_sorted(self):
        print(self.heap)


# 인덱스를 간단히 하기 위해 처음 엘리먼트 0 추가
a=[0, 11, 14, 2, 7, 6, 3, 9, 5]
b=Heap()
b.makeHeap(a)
b.maxHeapify(0)
b.display()

b.addElt(50)
b.display()

b.heapSort()
b.display_sorted()