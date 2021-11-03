import math


def f(x):
    if (x == 0): return "x"
    res = "(x"
    if (x > 0): res += "+"
    return res + "%d)" % x


s = input()
s = s[3:]
a = 1
x = s.find("x")
if x > 0:
    if (x == 1):
        if (s[0] == '+'): b = 1
        else: b = -1
    else: b = (int)(s[0:x])
else: b = 0
s = s[x + 1:]
if len(s) > 0: c = (int)(s)
else: c = 0
d = (int)(math.sqrt(b * b - 4 * a * c))
x1 = (b + d) // (2 * a)
x2 = (b - d) // (2 * a)
if (x1 == x2):
    if (x1 == 0): print("x^2")
    else: print("(x%d)^2" % x1)
else: print(f(x1) + f(x2))