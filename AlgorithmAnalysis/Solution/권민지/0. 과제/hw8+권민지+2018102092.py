# (1) 29,30쪽: [실습프로그램] 분기한정 가지치기 너비우선검색 방법으로 0-1 배낭문제를 해결하는 알고리즘을 python으로 완성하라.
from queue import Queue

class Node:
        def __init__(self,level,weight, profit, include):
                self.level = level
                self.weight = weight
                self.profit = profit
                self.include = include

def kp_BFS():
    global maxProfit
    global bestset

    q = Queue()
    
    # 구현 시작
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

    # 구현 종료


def compBound(u):
    # 구현 시작
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
    # 구현 종료


n = 4
W = 16
p = [40, 30, 50, 10]
w = [2, 5, 10, 5]
include = [0] * n
maxProfit = 0
bestset = n * [0]
kp_BFS()
print(bestset)



# (2) 36,37쪽: [실습프로그램] 분기한정 가지치기 최고우선검색 방법으로 0-1 배낭문제를 해결하는 알고리즘을 python으로 완성하라.
class Node2:
        def __init__(self,level,weight, profit, bound, include):
                self.level = level
                self.weight = weight
                self.profit = profit
                self.bound = bound
                self.include = include

def kp_Best_FS():
    global maxProfit
    global bestset
    temp = n * [0]
    v = Node2(-1, 0, 0, 0.0, temp)

    # 구현 시작
    q = Queue()
    v.bound = compBound(v)
    q.put(v)

    while (not q.empty()):
        v = q.get()
        u = Node2(-1, 0, 0, 0.0, temp)

        if (v.bound > maxProfit):
            u.level = v.level + 1
            u.weight = v.weight + w[u.level]
            u.profit = v.profit + p[u.level]
            u.include = v.include[:]

            if ((u.weight <= W) and (u.profit > maxProfit)):
                maxProfit = u.profit

            u = Node2(u.level, u.weight, u.profit, 0.0, u.include[:])
            u.bound = compBound(u)

            if(u.bound > maxProfit):
                u.include[u.level] = 1
                q.put(u)
                bestset = u.include[:]

            u = Node2(u.level, v.weight, v.profit, 0.0, u.include[:])
            u.bound = compBound(u)
            u.include[u.level] = 0

            if (u.bound > maxProfit):
                u.include[u.level] = 0
                q.put(u)
                bestset = u.include[:]

    # 구현 종료


def compBound(u):
    if u.weight >= W:
        return 0

    else:
        # 구현 시작
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
        # 구현 종료

    return result


n = 4
W = 16
p = [40, 30, 50, 10]
w = [2, 5, 10, 5]
include = [0] * n
maxProfit = 0
bestset = n * [0]

kp_Best_FS()
print()
print(bestset)
print(maxProfit)