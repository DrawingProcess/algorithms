#2017110260
import utility
# Kruskal algorithm

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
            if rank[r1] == rank[r2]: rank[r2] += rank[r1]
            
def kruskal(graph):
    F = set()
    for i in graph['vertices']:
        make_singleton_set(i)
    
    while (len(F) < 4):
        e = min(graph['edges'])
        graph['edges'].remove(e)
        (i,j) = (e[1],e[2])
        p = find(i)
        q = find(j)
        if p !=q:
            union(p,q)
            F.add(e)

            
    return F




graph = {
        'vertices': ['A', 'B', 'C', 'D', 'E'],
        'edges': set([
            (1, 'A', 'B'),
            (3, 'A', 'C'),
            (3, 'B', 'C'),
            (6, 'B', 'D'),
            (4, 'C', 'D'),
            (2, 'C', 'E'),
            (5, 'D', 'E'),
            ])
        }
mst=kruskal(graph)

print(mst)



#실습9 9page
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

