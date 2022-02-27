class Queue(object):
    
    front=0
    rear=0
    data=None
    length=None
    
    def __init__(self, length):
        self.length=length
        self.data =self.length*[0]

 # 최대 n-1개의 데이터가 저장. 만일 rear=front를 full의 판단으로 사용한다면
 # 꽉찬 것과 empty와 구분 불가
    def isFull(self):
        return ((self.rear+1) % self.length==self.front)

    def isEmpty(self):
        if self.front==self.rear:
            return True
 def enqueue(self, name):
        if self.isFull( )==True:
            print("Queue is full")
            return
        else:
            self.data[self.rear]=name
            self.rear=(self.rear+1)%self.length

    def dequeue(self):
        if self.isEmpty( )==True:
              print("no data")
        else:
              self.front=(self.front+1) % self.length

    def printQ(self):
        if(self.isEmpty()==True):
            return
        if(self.rear<self.front):
            for i in range(self.front, self.length):
                 print(self.data[i], end=" ")
            for i in range(0, self.rear):
                 print(self.data[i], end=" ")            
        else:
            for i in range(self.front, self.rear):
                 print(self.data[i], end=" ")
        print()

q = Queue(5)
q.enqueue("A")
q.printQ()
q.enqueue("B")
q.printQ()
q.enqueue("C")
q.enqueue("D")
q.printQ()
q.dequeue()
q.printQ()
q.dequeue()
q.printQ()
q.enqueue("E")
q.printQ()
q.enqueue("F")
q.printQ()
q.dequeue()
q.printQ()