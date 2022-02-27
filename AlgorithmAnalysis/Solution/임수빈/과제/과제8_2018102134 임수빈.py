#2018102134 임수빈
# 과제 8


inf=1000
w=[[0,7,4,6,1],[inf,0,inf,inf,inf],
   [inf,2,0,5,inf], [inf,3,inf,0,inf], [inf,inf,inf,1,0]]
n=5
f=set()
touch=n*[0]
length=n*[0]
save_length=n*[0]


for i in range(1,n):
    length[i] = w[0][i]

for r in range(n-1):
    mmin = inf
    for i in range(1,n):
        if 0 <= length[i] and length[i] < mmin:
            mmin = length[i]
            vnear = i
    e = (touch[vnear] , vnear)

    f.add(e)
    for i in range(1,n):
        if vnear == i:
            save_length[i] = length[i]
            continue
        if length[vnear] + w[vnear][i] < length[i]:
            length[i] = length[vnear] + w[vnear][i]
            touch[i] = vnear
            
    length[vnear] = -1

print(f)

print(save_length)


'''
(2) 20쪽 [실습과제] Huffman code 1을 직접 수행해 보고, 프로그램을 분석해 보세요.

이 문제에 관련하여 내용을 제출하는 것이 아니고, 각자 프로그램의 수행내용을 익힐 것.


라고 적혀있어서 huffman code 부분은 적지 않았습니다.

'''

