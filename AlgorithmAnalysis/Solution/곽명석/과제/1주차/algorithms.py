#alg01
import time

n = int(input())


sum = 0
result =[]
a = [0]

agl01_time = time.time()
for i in range(1,n+1):
    #5a.append(i)
    for j in range(0,i+1):
        sum+=j
    sum = sum / i
    result.append(sum)
    sum = 0

# print(len(result))
# for i in range(len(result)):
#      print(result[i])


agl01_end = time.time()
time_result = agl01_end - agl01_time
print("time : ",time_result)


#alg02
# agl02_time = time.time()
# for i in range(1,n+1):
#     #a.append(i)
#     for j in range(i,i+1):
#         sum+=j
#     result.append(sum/i)


# # for i in range(len(result)):
# #      print(result[i])
# agl02_end = time.time()
# time_result = agl02_end - agl02_time
# print("time : ",time_result)


    


    