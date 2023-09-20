from math import factorial

def C(n, m):
    return factorial(n) // factorial(m) // factorial(n - m)

s = input().split()
n = int(s[0])
a = int(s[1])
b = int(s[2])
print(C(a + n, a) * C(b + n, b))