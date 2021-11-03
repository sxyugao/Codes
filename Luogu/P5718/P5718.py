n = int(input())
a = input().split()
mn = 1001
for i in range(0, n):
    if int(a[i]) < mn: mn = int(a[i])
print(mn)