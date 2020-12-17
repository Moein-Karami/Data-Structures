#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef pair<int, int> pii;

const int MAXN = 1e5 + 5;

vector<pii> edges;
vector<int> v[MAXN];
int ans[MAXN];

void dfs(int x)
{
	for (int i = 0; i < v[x].size(); i++)
	{
		int u = v[x][i];
		if (!ans[u])
		{
			ans[u] = 3 - ans[x];
			dfs(u);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
		edges.push_back(pii(a, b));
	}

	for (int i = 1; i <= n; i++)
	{
		if (!ans[i])
		{
			ans[i] = 1;
			dfs(i);
		}
	}

	for(int i = 0; i < m; i++)
	{
		if (ans[edges[i].f] == ans[edges[i].s] )
		{
			cout << "NO\n";
			return 0;
		}
	}

	cout << "YES\n";
	for (int i = 0; i < m; i++)
		cout << ans[edges[i].f] - 1;

	return 0;
}