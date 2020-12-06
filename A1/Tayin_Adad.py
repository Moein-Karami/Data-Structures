import math

mod = int(1e8 + 7)
pows = [1]
maxn = int(1e5+5)

for i in range(1, maxn):
    pows.append((pows[i-1]*10)%mod)

ans = 0 
t = input()
s = input()
tmp = 0
while (len(s) < len(t)):
    s = '?' + s
for i in s:
    if i == '?':
        tmp += 1
for i in range (len(t)):
    if(s[i] == '?'):
        tmp -= 1
        ans += pows[tmp] * int(t[i])
    elif(s[i] < t[i]):
        ans += pows[tmp]
        break
    elif(t[i] < s[i]):
        break
    ans %= mod

print(ans%mod)
