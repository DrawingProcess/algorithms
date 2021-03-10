# Sequential Sum
a = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
days = 0
for i in range(0, 12):
    days += a[i]
print(days)