def fib1 (n):
  if (n <= 1):
    return n
  else:
    return fib1(n-1) + fib1(n-2)

def fib2 (n):
  f = []
  if (n <= 1):
    return n
  if (n > 1):
    f.append(0)
    f.append(1)
    i = 2
    while (i <= n):
      f.append(f[i-1] + f[i-2])
      i += 1
  return f[n]

for i in range(0, 10):
  print(i, fib1(i))
for i in range(0, 10):
  print(i, fib2(i))
