#include<bits/stdc++.h>
#define int long long int

using namespace std;

const int maxn = 1e6 + 6;

int d[maxn];
int mod1 = 1e6 - 1, mod2 = 1e6 - 3, mod = 1e9 + 7;
int base1 = 27, base2 = 29;
bool b[maxn];
int po1[maxn];

int32_t main()
{
	po1[0] = 1;
	for (int i = 1; i < maxn; i++)
		po1[i] = (po1[i - 1] * base1) % mod1;

	int n, m;
	b[0] = 1;
	cin >> n >> m;
	string s;
	cin >> s;
	for (int i = 1 ; i <= m; i++)
		cin >> d[i];

	int hash1 = 0, hash2 = 0;
	for (int i = 0; i < s.size(); i++)
	{
		hash1 = (hash1 * base1 + s[i] - 'a' + 1) % mod1;
		hash2 = (hash2 +  po1[i] * (s[s.size() - 1 - i] - 'a' + 1)) % mod1;
		if (hash1 == hash2)
			b[i + 1] = 1;
	}
	int len = s.size();
	// for (int i = 1; i <= len; i++)
	// 	cout << b[i];
	// cout << endl;
	
	for (int i = 1; i < m; i++)
	{
		if (d[i] + len >= d[i + 1])
		{
			if (!b[d[i] + len - d[i + 1]])
			{
				cout << 0;
				return 0;
			}
			n -= (d[i + 1] - d[i]);
		}
		else
			n -= len;
	}

	if (m)
		n -= len;

	int ans = 1;

	while(n--)
		ans = (ans * 26) % mod;
	cout << ans;
}