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

# Kruskal algorithm 구현
def kruskal(graph):
    F = set()
    for i in graph['vertices']:
        make_singleton_set(i)
    while (len(F) < len(graph['vertices']) - 1):
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
mst = kruskal(graph)
print(mst)  # set이므로 순서는 무관

# output
# {(2, 'C', 'E'), (4, 'C', 'D'), (1, 'A', 'B'), (3, 'A', 'C')}