import queue

class Node:
    def __init__(self,level,weight, profit, bound, include):
        self.level = level
        self.weight = weight
        self.profit = profit
        self.bound = bound
        self.include = include
    def __cmp__(self, other):
        return cmp(self.bound, other.bound)

def kp_Best_FS():
    global maxProfit
    global bestset
    temp = n*[0]
    v = Node(-1,0,0, 0.0,temp)
    q = queue.PriorityQueue()

    # 구현
    q = queue.Queue()
    v.bound = compBound(v)
    q.put(v)

    while (not q.empty()):
        v = q.get()
        u = Node(-1, 0, 0, 0.0, temp)

        if (v.bound > maxProfit):
            u.level = v.level + 1
            u.weight = v.weight + w[u.level]
            u.profit = v.profit + p[u.level]
            u.include = v.include[:]

            if ((u.weight <= W) and (u.profit > maxProfit)):
                maxProfit = u.profit

            u = Node(u.level, u.weight, u.profit, 0.0, u.include[:])
            u.bound = compBound(u)

            if(u.bound > maxProfit):
                u.include[u.level] = 1
                q.put(u)
                bestset = u.include[:]

            u = Node(u.level, v.weight, v.profit, 0.0, u.include[:])
            u.bound = compBound(u)
            u.include[u.level] = 0

            if (u.bound > maxProfit):
                u.include[u.level] = 0
                q.put(u)
                bestset = u.include[:]

def compBound(u):
    if u.weight >= W:
        return 0
    else:
        result = u.profit
        j = u.level + 1
        totweight = u.weight
        while ((j < n) and (totweight + w[j] <= W)):
            totweight = totweight + w[j]
            result += p[j]
            j += 1
        k = j
        if (k < n):
            result += ((W - totweight) * p[k] / w[k])
    return result
            
# heap이 minheap이라 bound를 계산하여 -를 하여 리턴한다. 비교를 < maxProfit으로 수행한다.
n=4
W=16
p=[40,30,50,10]
w=[2,5,10,5]
include=[0]*n
maxProfit =0
bestset=n*[0]
kp_Best_FS()
print(bestset)
print(maxProfit)
