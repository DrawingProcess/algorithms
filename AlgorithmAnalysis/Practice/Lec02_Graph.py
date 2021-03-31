# Graph using python
# 1. list of list
g = [[0,1,1,0,0,0] , [1,0,1,1,1,0],[1,1,0,1,0,0],
     [0,1,1,0,1,1] , [0,1,0,1,0,0], [0,0,0,0,1,0]]
print (g)
# Num of nodes
print(len(g))
print(len(g[0]))
# Num of edges
def n_of_edges(g):
    e=0
    for i in range (0,len(g)):
        for j in range(i,len(g)):
            e+=g[i][j]
    return e
print(n_of_edges(g))
# Num of edges connected to Node i
def n_of_connected_edges(g,i):
    e=0
    for j in range (0,len(g)):
        e+=g[i][j]
    return e
print(n_of_connected_edges(g,2))


# 2. dict of sets
g={'A': {'B','C'}, 'B':{'A','C','D','E'},
   'C': {'A','B','D'}, 'D':{'C',’B’,'E','F'},
   'E': {'B','D'}, 'F':{'D'}}
print(g)
# Num of nodes
print(len(g))
print(len(g[‘A’]))
# Num of edges
def n_of_edges(g):
    e=0
    for i in g:
        e+= len(g[i])
    return e
print(int(n_of_edges(g)/2))
# Num of edges connected to Node i
def n_of_connected_edges(g,i):
    return len(g[i])
print(n_of_connected_edges(g,'A'))