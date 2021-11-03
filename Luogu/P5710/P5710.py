def check_1(x):
    return x % 2 == 0

def check_2(x):
    return (4 < x) and (x <= 12)

x = int(input())
f1 = check_1(x)
f2 = check_2(x)
print(int(f1 and f2), int(f1 or f2), int(f1 ^ f2), int(not (f1 or f2)))
