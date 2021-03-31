# union
a={1,2,3}
b={3,4,5}
c = a|b
print(c)
print(a.union(b))

# intersection
a={1,2,3}
b={3,4,5}
print(a & b)
print(a.intersection(b))

# difference
a={1,2,3}
b={3,4,5}
print(a - b)
print(a.difference(b))

# symmetric difference
a={1,2,3}
b={3,4,5}
print(a ^ b)
print(a.symmetric_difference(b))
