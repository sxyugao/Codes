n = int(input())
mx = -1
mn = 100
sum = 0
arr = input().split()
for x in arr:
    t = int(x)
    if t > mx: mx = t
    if t < mn: mn = t
    sum += t
print("%.2f" % ((sum - mx - mn) / (n - 2)))