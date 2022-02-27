import queue

class Node:
    def __init__(self,level,weight, profit, include):
        self.level = level
        self.weight = weight
        self.profit = profit
        self.include = include

def kp_BFS():
    global maxProfit
    global bestset
    
    q = queue.Queue()
    v = Node(0,0,0, include)

    maxprofit=0
    v = Node(-1, 0, 0, n * [0])
    q.put(v)

    while (not q.empty()):
        v = q.get()
        u = Node(-1, 0, 0, n * [0])

        u.level = v.level + 1
        u.weight = v.weight + w[u.level]
        u.profit = v.profit + p[u.level]
        u.include = v.include[:]

        if ((u.weight <= W) and (u.profit > maxProfit)):
            maxProfit = u.profit

        u = Node(u.level, u.weight, u.profit, u.include[:])

        if (compBound(u) > maxProfit):
            u.include[u.level] = 1
            q.put(u)
            bestset = u.include[:]

        u = Node(u.level, v.weight, v.profit, u.include[:])
        u.include[u.level] = 0

        if (compBound(u) > maxProfit):
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

n=4
W=16
p=[40,30,50,10]
w=[2,5,10,5]
include=[0]*n
maxProfit =0
bestset=n*[0]
kp_BFS()
print(bestset)
