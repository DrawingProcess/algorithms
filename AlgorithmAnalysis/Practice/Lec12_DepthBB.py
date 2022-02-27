# [실습프로그램] 분기한정 가지치기로 깊이우선검색 p10

def kp(i, profit, weight):
    global bestset
    global maxp
    
    if( weight <= W and profit >maxp):
        maxp = profit
        bestset = include[:]
    # best = include는 best를 include의 reference로 만든다.
    # 한 번 동일한 값을 가진 후 그 이후는 계속 동일함.
    if (promising(i, weight, profit)):
        include[i+1] = 1
        kp(i+1, profit + p[i+1], weight + w[i+1])
        include[i+1] = 0
        kp(i+1, profit, weight)

def promising(i, weight, profit):
    global maxp
    if (weight >= W):
        return False;
    else:
        j = i+1
        bound = profit
        totweight = weight
        while (j < n and totweight + w[j] <= W):
            totweight = totweight + w[j];
            bound = bound + p[j]
            j += 1
        k = j
        if (k < n):
            bound = bound + (W - totweight) * p[k] / w[k]
        return bound > maxp

n=4
W=16
p=[40,30,50,10]
w=[2,5,10,5]
maxp=0
include =[0,0,0,0]
bestset = [0,0,0,0]
kp(-1,0,0)
print(maxp)
print(bestset)