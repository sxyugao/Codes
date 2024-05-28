s = input().split()
l, r = int(s[0]), int(s[1])
def f(x):
    return (x + 1) // 2 + x // 4
print(f(r) - f(l - 1))
