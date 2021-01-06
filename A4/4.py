maxn = 1003

inp = input().strip().split()

n = int(inp[0])
m = int(inp[1])

tb = []
for i in range(n):
	tb.append(input().strip())
	if (tb[i][0] == '-'):
		x, y = i, 0
	elif (tb[i][m - 1] == '-'):
		x, y = i, m - 1

q = [[x, y]]
cnt = 0
d = []
b = []
for i in range(n):
	tmp = []
	tmp_b = []
	for j in range(m):
		tmp.append(1000000)
		b.append(0)
	d.append(tmp)
d[x][y] = 1
direc = [[0, 1], [1, 0], [0, -1], [-1, 0]]


while (cnt < len(q)):
	x, y = q[cnt][0], q[cnt][1]
	cnt += 1
	for i in direc:
		if (x + i[0] > 0 and x + i[0] < n and y + i[1] > 0 and y + i[1] < m ):
			if (d[x + i[0]][y + i[1]] > d[x][y] + 1 and tb[x + i[0]][y + i[1]] != '#'):
				q.append([x + i[0], y + i[1]])
				d[x + i[0]][y + i[1]] = d[x][y] + 1

ans = 0

for i in range(n):
	for j in range(m):
		if (tb[i][j] == '*'):
			while (b[d[i][j]]):
				d[i][j] += 1
			ans = max(ans, d[i][j])
			b[d[i][j]] = 1;

print(ans)