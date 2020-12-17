#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;

vector<int> v[maxn];

int dp[maxn];
int up[maxn];
int ans[maxn];
int mini = maxn;

void dfs(int p, int x)
{
	for (auto u : v[x])
	{
		if (u == p)
			continue;
		dfs(x, u);
		dp[x] = max(dp[u] + 1, dp[x]);
	}
}

void fix_up(int p, int x)
{
	int max1 = 0, max2 = 0;
	ans[x] = max(up[x], dp[x]);
	mini = min(mini, ans[x]);

	for (auto u : v[x])
	{
		if (u == p)
			continue;
		if (dp[u] + 2 > max1)
		{
			max2 = max1;
			max1 = dp[u] + 2;
		}
		else if (dp[u] + 2 > max2)
			max2 = dp[u] + 2;
	}

	for (auto u : v[x])
	{
		if (u == p)
			continue;
		if(dp[u] + 2 == max1)
			up[u] = max2;
		else
			up[u] = max1;
		up[u] = max(up[u], up[x] + 1);
		fix_up(x, u);
	}
}

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	dfs(0, 1);
	fix_up(0, 1);

	for (int i = 1; i <= n; i++)
		if (ans[i] == mini)
			cout << i << " ";
}