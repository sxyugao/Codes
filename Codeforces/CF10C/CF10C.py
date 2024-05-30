n = int(input())
cnt = [n // 9 for _ in range(9)]
for i in range(1, n % 9 + 1):
    cnt[i] += 1
ans = 0
for i in range(9):
    for j in range(9):
        ans += cnt[i] * cnt[j] * cnt[i * j % 9]
for i in range(1, n + 1):
    ans -= n // i
print(ans)