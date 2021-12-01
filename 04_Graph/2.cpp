#include <bits/stdc++.h>

using namespace std;

constexpr int maxn = 5e5+5;
int k;

vector<int> v[maxn];
vector<int> ans;

int d[maxn];

void dfs(int x, vector<int>& tmp)
{
	tmp.push_back(x);
	for (auto u : v[x])
	{
		if (d[x] - d[u] > k && d[u])
		{
			ans.push_back(u);
			while (tmp.back() != u)
			{
				ans.push_back(tmp.back());
				tmp.pop_back();
			}
			return;
		}
		else if (!d[u])
		{
			d[u] = d[x] + 1;
			dfs(u, tmp);
			return;
		}
	}
}

int main()
{
	int n, m;
	cin >> n >> m >> k;
	while(m--)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	d[1] = 1;
	vector<int> tmp;
	dfs(1, tmp);
	cout << ans.size() << "\n";
	while (ans.size())
	{
		cout << ans.back() << " ";
		ans.pop_back();
	}
	return 0;
}