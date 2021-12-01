#include<bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef pair<int, int> pii;

const int maxn = 1e3 + 3;

char c[maxn][maxn];
bool b[maxn*maxn];
int d[maxn][maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	int n ,m;
	int a, e;
	cin >> n >> m;
	for (int i = 0; i <= n + 1; i++)
	{
		for (int j = 0; j <= m + 1; j++)
		{
			d[i][j] = maxn * maxn;
			if (i == 0 || i == n + 1 || j == 0 || j == m + 1)
			{
				c[i][j] = '#';
				continue;
			}
			cin >> c[i][j];
			if (i == 1 || i == n || j == 1 || j == m)
				if (c[i][j] == '-')
					a = i, e = j;
		}
	}

	queue<pii> q;
	d[a][e] = 1;
	q.push(pii(a, e));

	while (q.size())
	{
		pii p = q.front();
		int x = p.f, y = p.s;
		q.pop();
		for (int i = -1; i <= 1; i++)
		{
			for (int j = -1; j <= 1; j++)
			{
				x = p.f + i;
				y = p.s + j;
				if (i == j || i == -j || c[x][y] == '#')
					continue;
				if (d[x][y] > d[p.f][p.s] + 1)
				{
					d[x][y] = d[p.f][p.s] + 1;
					q.push(pii(x, y));
				}
				
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (c[i][j] == '*')
			{
				while (b[d[i][j]])
					d[i][j]++;
				ans = max(ans, d[i][j]);
				b[d[i][j]] = 1;
			}
		}
	}
	cout << ans;
}