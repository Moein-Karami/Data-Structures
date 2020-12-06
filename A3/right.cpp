#include <bits/stdc++.h>

#define int long long int

constexpr int inf = 1e15;

using namespace std;

int32_t main()
{
    int n, q;
    cin >> n >> q;
    vector<int> v[n+10];
    while(q--)
    {
        int t;
        cin >> t;
        if (t == 3)
        {
            int ans = inf;
            for (auto& i : v)
                for (auto j : i)
                    ans = min (ans, j);
            if (ans == inf)
                ans = -1;
            cout << ans << endl;
            bool b = 1;
            for (auto& i : v)
            {
                for (int j = 0; j < i.size(); j++)
                {
                    if(i[j] == ans && b)
                    {
                        b = 0;
                        swap(i[j], i.back());
                        i.pop_back();
                    }
                }
            }
        }
        else if (t == 1)
        {
            int c, x;
            cin >> c >> x;
            v[c].push_back(x);
        }
        else
        {
            int c, x;
            cin >> c >> x;
            for (auto& i : v[c])
                i += x;
        }
    }
}