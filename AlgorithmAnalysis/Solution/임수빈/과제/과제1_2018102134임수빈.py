'''
다음과 같은 기능을 수행하는 파이썬 프로그램을 작성하라.

리스트 S 에 n개의 정수 (각 정수의 범위는 1~10 이며 random으로 생성된다)가 저장되어 있다.
리스트 S 내에 연속한 m 개의 정수(m<n)의 합 들 중에서 제일 큰 값 tmax 와 제일 작은 값 tmin을 구한 후 출력한다.

(예) S=[5,1,4,7,2], n=5, m=2 이면 연속된 2개의 정수의 합은
6,5,11,9가 된다. 최대 tmax=11, 최소 tmin=5 를 출력한다.

n은 사용자가 프로그램 수행 중 입력하게 되고, S는 한 번만 생성된다. n>=3.
m은 사용자가 입력하게 되고, 입력될 때 마다 결과를 생성하며, m의 입력은 반복적으로 할 수 있다.
입력으로 m=0 이 주어지면, 프로그램은 종료된다.
프로그램은 입력 오류가 있을 경우 적절한 오류메시지를 생성하여야 한다.

제출방법: file_name.py 를 구글클래스룸에 업로드. 파일명에 학번+이름을 포함.
마감: 2020년 3월 25일(수) 23:59
-마감 후 제출결과물에는 점수를 부여 하지 않음.
-타 학생과 동일한 과제결과물인 경우 마이너스 점수를 부여함.
'''
# 2018102134 임수빈


import random

#m > len(s)
def getMinAndMax(s, m):
    tmin = 10 * m 
    tmax = 1
    
    for i in range(len(s)-m + 1): 
        temp = 0
        for j in range(m):
            temp += s[i+j]
            
        if temp > tmax:
            tmax = temp
        if temp < tmin:
            tmin = temp

    return (tmin,tmax)
        

while(True):
    n = input("Enter n (n >= 3):")
    try:
        n = int(n)
    except:
        print("n은 3이상의 정수여야 합니다.")
        continue
    if(n >= 3):
        break
    else:
        print("n은 3이상의 정수여야 합니다.")

s = []
for i in range(n):
     s.append(random.randint(1,10))

print("s = ",s)

while(True):
    m = input("Enter m (m < n): ")
    try:
        m = int(m)
    except:
        print("m 은 n보다 작은 정수여야 합니다.")
        continue
    if(m == 0):

        print("프로그램을 종료합니다.")
        break
    elif(m < n):
        result = getMinAndMax(s,m)
        print("tmin :",result[0]," tmax:",result[1])
    else:
        print("m 은 n보다 작은 정수여야 합니다.")
    
