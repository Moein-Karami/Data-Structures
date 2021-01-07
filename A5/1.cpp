#include <bits/stdc++.h>
#define f first
#define s second
#define int long long int
using namespace std;

typedef pair<int, int> pii;

const int maxn = 1e5 + 5;
int d[maxn], cost[maxn];
int n, c;

void merge_sort(int a, int b)
{
	if (a + 1 >= b)
		return;
	int mid = (a + b) / 2;
	merge_sort(a, mid);
	merge_sort(mid, b);
	int p1 = a, p2= mid;
	vector <int> v1, v2;
	while (p1 < mid && p2 < b)
	{
		if (d[p1] < d[p2])
		{
			v1.push_back(d[p1]);
			v2.push_back(cost[p1]);
			p1++;
		}
		else
		{
			v1.push_back(d[p2]);
			v2.push_back(cost[p2]);
			p2++;
		}
	}
	while (p1 < mid)
	{
		v1.push_back(d[p1]);
		v2.push_back(cost[p1]);
		p1++;
	}
	while (p2 < b)
	{
		v1.push_back(d[p2]);
		v2.push_back(cost[p2]);
		p2++;
	}
	int cnt = a;
	for (int i = 0; i < v1.size(); i++)
	{
		d[cnt] = v1[i];
		cost[cnt] = v2[i];
		cnt++;
	}
}

int32_t main()
{
	srand(time(0));
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> d[i];
	for (int i = 1; i <= n; i++)
		cin >> cost[i];
	cin >> c;

	merge_sort(0, n+1);

	int money = c;
	int pos = 0;
	int payment = 0;
	set<pii> se;
	se.insert(pii(0, 0));
	for (int i = 0; i < n; i++)
	{
		if (d[i + 1] - pos > money)
		{
			while (se.size())
			{
				if (d[i + 1] - (*(se.begin())).s <= c)
					break;
				else 
					se.erase(se.begin());
			}
			if (se.size() == 0)
			{
				cout << -1;
				return 0;
			}
			pii tmp = *se.begin();
			money -= tmp.s - pos;
			pos = tmp.s;
			payment += (d[i+1] - pos - money) * tmp.f;
			money = d[i+1] - pos;
		}
		se.insert(pii(cost[i + 1], d[i + 1]));
	}
	cout << payment;
}