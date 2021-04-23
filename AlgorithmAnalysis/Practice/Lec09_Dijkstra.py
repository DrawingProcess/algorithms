inf=1000
w=[[0,7,4,6,1],[inf,0,inf,inf,inf],
   [inf,2,0,5,inf], [inf,3,inf,0,inf], [inf,inf,inf,1,0]]
n=5
f = set()
touch = n*[0]
length = n*[0]

save_length = n*[0]

for i in range(1,n):
    length[i] = w[0][i]

# Dijkstra algorithm 구현
for cnt in range(n):
    min = inf
    for i in range(1, n):
        if (0 <= length[i] and length[i] < min):
            min = length[i]
            vnear = i
    e = (touch[vnear], vnear)
    f.add(e)
    for i in range(1, n):
        if (length[vnear] + w[vnear][i] < length[i]):
            length[i] = length[vnear] + w[vnear][i]
            touch[i] = vnear

    # for save_length
    if length[vnear] != -1:
        save_length[vnear] = length[vnear]

    length[vnear] = -1

print(f)
print(save_length)