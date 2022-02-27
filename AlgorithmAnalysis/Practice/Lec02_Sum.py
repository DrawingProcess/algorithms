a = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
days = 0
for i in range(len(a)):
    days += a[i]    # days = days + a[i]
print(days)

days = 0
for i in range(0, 12):
    days += a[i]    # days = days + a[i]
print(days)

days = 0
for i in a:
    days += i
print(days)

def days(a):
    d =0
    for i in range(0,12):
        if i%2 == 0:
            d +=a[i]
    return d
a=[31,28,31,30,31,30,31,31,30,31,30,31]
print(days(a))
