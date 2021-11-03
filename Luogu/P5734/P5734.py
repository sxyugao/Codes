n = int(input())
s = input().strip()
for i in range(0, n):
    opt = input().split()
    if opt[0] == '1': s = s + opt[1]
    if opt[0] == '2':
        l = int(opt[1])
        r = l + int(opt[2])
        s = s[l:r]
    if opt[0] == '3':
        p = int(opt[1])
        s = s[:p] + opt[2] + s[p:]
    if opt[0] == '4': print(s.find(opt[1]))
    if opt[0] != '4': print(s)