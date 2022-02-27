### @ author  : 2018102092 권민지
# (1) p7_greedy_MST - Slide 19 >>> Kruskal 알고리즘

parent = dict()
rank = dict()

def make_singleton_set(v):
    parent[v] = v
    rank[v] = 1

def find(v):
    if parent[v] != v:
        parent[v] = find(parent[v])
    return parent[v]


def union(r1, r2):
    if r1 != r2:
        if rank[r1] > rank[r2]:
            parent[r2] = r1
            rank[r1] += rank[r2]
        else:
            parent[r1] = r2
            if rank[r1] == rank[r2]:
                rank[r2] += rank[r1]


def kruskal(graph):
    #Kruskal algorithm 구현
    min_span_tree = list()

    for v in graph['vertices']:
        make_singleton_set(v)

    edges = graph['edges']
    edges.sort()

    for edge in edges:
        w, v1, v2 = edge
        r1 = find(v1)
        r2 = find(v2)

        if r1 != r2:
            union(r1, r2)
            min_span_tree.append(edge)

    return min_span_tree
    #구현 종료


graph = {
        'vertices': ['A', 'B', 'C', 'D', 'E'],
        'edges': [
            (1, 'A', 'B'),
            (3, 'A', 'C'),
            (3, 'B', 'C'),
            (6, 'B', 'D'),
            (4, 'C', 'D'),
            (2, 'C', 'E'),
            (5, 'D', 'E'),
            ]
        }

mst=kruskal(graph)
print(mst)
print()


#########################################################################
# (2) p9_greedy_Dijkstra_huffman - Slide 9 >>> Dijkstra 알고리즘
# problem : shortest path의 아크와 각 노드의 shortest path 출력

inf=1000
w=[[0,7,4,6,1],[inf,0,inf,inf,inf],
   [inf,2,0,5,inf], [inf,3,inf,0,inf], [inf,inf,inf,1,0]]
n=5
f=set()
touch=n*[0]
length=n*[0]
save_length=n*[0]

# 구현 시작
def dijkstra(n, w, f):
    for i in range(1, n):
        touch[i] = 0
        length[i] = w[0][i]

    for j in range(1,n):
        min = inf
        for i in range(1, n):
            if(length[i] >= 0 and length[i] < min):
                min = length[i]
                vnear = i

        f.add((touch[vnear], vnear))

        for i in range(1, n):
            if(length[vnear] + w[vnear][i] < length[i]):
                length[i] = length[vnear] + w[vnear][i]
                touch[i] = vnear
                save_length[i] = length[i]
            else:
                if length[i] != -1:
                    save_length[i] = length[i]

        length[vnear] = -1


dijkstra(n, w, f)
print(f)
# 구현 종료

print(save_length)
