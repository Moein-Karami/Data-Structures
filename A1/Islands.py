import collections
maxn = 1002

tmp =[[0,1], [1,0], [0,-1], [-1, 0]]
table = [[0] * maxn for i in range(maxn)]
check = [[0] * maxn for i in range(maxn)]

inp = list(map(lambda x: int(x), input().strip().split(' ')))
n, m = inp[0], inp[1]

for i in range(1, n + 1):
    inp = list(map(lambda x: int(x), input().strip().split(' ')))
    for j in range(1, len(inp) + 1) :
        table[i][j]=inp[j-1]
    table[i].append(0)

cnt = 0
q = []
ind = 0
for i in range(1, n + 1):
    for j in range(1, m + 1):
        if (table[i][j] == 0 or check[i][j] != 0):
            continue
        cnt += 1
        check[i][j] = cnt
        q.append([i, j])
        while (ind < len(q)):
            r, c = q[ind][0], q[ind][1]
            ind += 1
            for k in range(4):
                x, y = tmp[k][0], tmp[k][1]
                if((table[r+x][c+y] == 1) and (check[r+x][c+y] == 0)):
                    check[r+x][c+y] = cnt
                    q.append([r+x, c+y])

print(cnt)
        


