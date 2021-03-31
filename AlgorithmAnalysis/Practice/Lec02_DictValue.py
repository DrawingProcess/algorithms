# Find value using key
a={'college':'eni', 'dept':'ce'}
print(a['college'])
print(a['dept'])
print(a.get('dept'))

# Change value
a={'college':'eni', 'id':1234}
a['id']=4321
print(a)
