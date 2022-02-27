inf = 1000
w = [[0,7,4,6,1],[inf,0,inf,inf,inf],
    [inf,2,0,5,inf], [inf,3,inf,0,inf], [inf,inf,inf,1,0]]
n = 5
f = set()
touch = n*[0]
length = n*[0]

for i in range(1,n):
    length[i] = w[0][i]

# for save_length
save_length = n*[0]

# for max_length_update
total_edge_num = 0
for i in range(0,n):
    for j in range(0,n):
        if 0 < w[i][j] and w[i][j] < inf:
            total_edge_num += 1
start_length_update = 0
for i in range(1,n):
    if w[0][i] != inf:
        start_length_update += 1

current_length_update = 0
# Dijkstra algorithm 구현
for cnt in range(n):
    min_ = inf
    for i in range(1, n):
        if (0 <= length[i] and length[i] < min_):
            min_ = length[i]
            vnear = i
    e = (touch[vnear], vnear)
    f.add(e)
    for i in range(1, n):
        if (length[vnear] + w[vnear][i] < length[i]):
            length[i] = length[vnear] + w[vnear][i]
            touch[i] = vnear
            current_length_update += 1

    # for save_length
    if length[vnear] != -1:
        save_length[vnear] = length[vnear]

    length[vnear] = -1

print(f)

# for save_length
print(save_length)

# for max_length_update
max_length_update = total_edge_num - start_length_update
print(max_length_update)
# for current_length_update
print(current_length_update)