# (1) 9쪽: [실습프로그램] 부분집합의 합 문제 해결 알고리즘을 python으로 완성하라. 모든 해를 출력하도록 작성할 것. 데이터는 S={1,2,3,4,5,6}, W=9 로 할 것.

def promising(i,weight, total):
    return (weight+total >= W) and (weight == W or weight+w[i+1] <= W)

def s_s(i, weight, total, include):
    # sum of subsets 구현
    if (promising(i,weight, total)):
        if (weight == W):
            print(include)
        else:
            include[i+1] = 1
            s_s(i+1, weight+w[i+1], total-w[i+1], include)
            include[i+1] = 0
            s_s(i+1, weight, total-w[i+1], include)

n = 6
w = [1,2,3,4,5,6]
w.sort()
W = 9
print("---------------------------------------------------------------")
print("HW07_2 Subset Sum(p11_sumOFsubsets_m_coloring p9)\n")

print("items =", w, "W =", W)
include = n*[0]
total=0
for k in w:
    total += k
s_s(-1,0,total,include)

# (2) 15쪽: [실습프로그램] m-coloring 문제 해결 알고리즘을 python으로 완성하라. 모든 해를 출력하도록 작성할 것.

def color(i, vcolor):
    #구현 시작
    if promising2(i, vcolor):
        if i == n-1:
            print(vcolor)
        else:
            for tmp in range(1, m+1):
                vcolor[i+1] = tmp
                color(i+1, vcolor)
    #구현 종료

def promising2(I, vcolor):
    #구현 시작
    switch = True
    j = 0

    while j<I and switch:
        if W[I][j] and vcolor[I] == vcolor[j]:
            switch = False
        j += 1

    return switch
    #구현 종료

n = 4
W = [[0, 1, 1, 1], [1, 0, 1, 0], [1, 1, 0, 1], [1, 0, 1, 0]]
vcolor = n * [-1]
m = 3

print("---------------------------------------------------------------")
print("HW07_2 M_Coloring(p11_sumOFsubsets_m_coloring p15)\n")

color(-1, vcolor)

print("---------------------------------------------------------------")
