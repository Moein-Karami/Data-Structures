#include<bits/stdc++.h>
#define int long long int

using namespace std;

const int maxn = 1e5 + 5, mod = 1e9 + 7;

vector<int> v[maxn], rev[maxn];
int a[maxn];
int mini[maxn];
int mark[maxn];
int mini_cnt[maxn];
bool seen[maxn];
int cnt;
vector<int> topol;

void dfs(int x)
{
	seen[x] = 1;
	for (auto u : v[x])
		if (!seen[u])
			dfs(u);
	topol.push_back(x);
}

void reverse_dfs(int x)
{
	mark[x] = cnt;
	if (a[x] < mini[cnt])
	{
		mini[cnt] = a[x];
		mini_cnt[cnt] = 1;
	}
	else if(a[x] == mini[cnt])
		mini_cnt[cnt]++;

	for (auto u : rev[x])
		if (!mark[u])
			reverse_dfs(u);
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	for(int i = 0; i < maxn; i++)
		mini[i] = mod;

	int n, m;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		rev[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)
		if (!seen[i])
			dfs(i);
	reverse(topol.begin(), topol.end());
	for (auto x : topol)
	{
		//cout << x <<"*";
		if (!mark[x])
		{
			cnt++;
			reverse_dfs(x);
		}
	}//cout << endl;

	// for (int i = 1; i <= n; i++)
	// 	cout << mark[i] << " ";
	// 	cout << endl;

	int ans = 0, way = 1;
	for (int i = 1; i <= cnt; i++)
	{
		ans += mini[i];
		way = (way * mini_cnt[i]) % mod;
	}
	cout << ans << " " << way;
}