#------------------------------분기한정 가지치기로 너비우선검색 --------------------------#
import queue

class Node:
    def __init__(self, level, weight, profit, include):
        self.level = level
        self.weight = weight
        self.profit = profit
        self.include = include

    


def kp_BFS():
    global maxProfit
    global bestset

    q = queue.Queue()
    v = Node(-1,0,0,[0,0,0,0])
    maxProfit = 0
    q.put(v)

    while not q.empty():
        v = q.get()

        
        u = Node(   level=v.level+1,
                    weight=v.weight+w[v.level+1],
                    profit=v.profit+p[v.level+1],
                    include=v.include[:])
        u.include[u.level] = 1

        if u.weight <= W and u.profit > maxProfit:
            maxProfit = u.profit
            bestset = u.include[:]

        if compBound(u) > maxProfit:
            q.put(u)
            
        u = Node(   level=u.level,
                    weight=v.weight,
                    profit=v.profit,
                    include=v.include[:])
        u.include[u.level] = 0
        if compBound(u) > maxProfit:
            q.put(u)

def compBound(u):
    
    if u.weight >= W:
        return 0
    else:
        result = u.profit
        j = u.level+1
        totweight = u.weight
        while j < n and totweight + w[j] <= W:
            totweight += w[j]
            result += p[j]
            j += 1

    k = j
    if k < n:
        result += (W-totweight) * (p[k]/w[k])

    return result   

n = 4
W = 16
p = [40, 30, 50, 10]
w = [2, 5, 10, 5]
include = [0]*n
maxProfit = 0
bestset = n*[0]
kp_BFS()
print(bestset)



#-------------------------분기한정 가지치기로 최고우선검색 -----------------------#
"""
import queue

class Node:
    def __init__(self, level, weight, profit, bound, include):
        self.level = level
        self.weight = weight
        self.profit = profit
        self.bound = bound
        self.include = include

    def __cmp__(self, other):
        return (self.bound == other.bound)
    
    def __lt__(self, other):
        return self.bound < other.bound


def kp_Best_FS():
    global maxProfit
    global bestset
    temp = n*[0]
    v = Node(-1, 0, 0, 0.0, temp)

    PQ = queue.PriorityQueue()
    maxProfit = 0
    v.bound = compBound(v)

    PQ.put(v)

    while not PQ.empty():
        v = PQ.get()

        if v.bound < -maxProfit:
            u = Node( level=v.level+1,
                        weight=v.weight + w[v.level+1],
                        profit=v.profit + p[v.level+1],
                        bound=0.0,
                        include=v.include[:])
            if u.weight <= W and u.profit > maxProfit:
                maxProfit = u.profit

            u.bound = compBound(u)
            u.include[u.level] = 1
            if u.bound < -maxProfit:
                PQ.put(u)
                bestset = u.include[:]
            
            u = Node(level=u.level,
                        weight=v.weight,
                        profit=v.profit,
                        bound=0.0,
                        include=u.include[:])
            u.bound=compBound(u)
            u.include[u.level] = 0
            if u.bound<-maxProfit:
                PQ.put(u)
                bestset = u.include[:]


def compBound(u):
    if u.weight >= W:
        return 0
    
    else:
        result = u.profit
        j = u.level+1
        totweight = u.weight
        while j < n and totweight + w[j] <= W:
            totweight += w[j]
            result += p[j]
            j += 1

    k = j
    if k < n:
        result += (W-totweight) * (p[k]/w[k])

    return -result

# heap이 minheap이라 bound를 계산하여 -를 하여 리턴한다. 비교를 < maxProfit으로 수행한다.
n = 4
W = 16
p = [40, 30, 50, 10]
w = [2, 5, 10, 5]
include = [0]*n
maxProfit = 0
bestset = n*[0]
kp_Best_FS()
print(bestset)
print(maxProfit)    
"""