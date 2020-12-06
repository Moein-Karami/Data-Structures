#include <iostream>

#define int long long int

using namespace std;

constexpr int maxn = 1e5 + 5;

int seg[4*maxn];
int n;

void add(int id, int L, int R, int l, int r, int val)
{
    if (l == L && r == R)
    {
        seg[id] ^= val;
        return;
    }
    int mid = (L + R) / 2;
    if (l < mid)
        add(2 * id, L, mid, l, min(r, mid), val);
    if (r > mid)
        add(2 * id + 1, mid, R, max(l, mid), r, val);
}

int get(int id, int L, int R, int idx)
{
    if (L + 1 == R)
        return seg[id];
    int mid = (L + R) / 2;
    if (idx < mid)
        return seg[id] ^ get(2 * id, L, mid, idx);
    else
        return seg[id] ^ get(2 * id + 1, mid, R, idx);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    while(q--)
    {
        int t;
        cin >> t;
        if (t == 2)
        {
            int ind;
            cin >> ind;
            cout << get(1, 1, n + 1, ind) << "\n";
        }
        else
        {
            int l, r, val;
            cin >> l >> r >> val;
            ++r;
            add(1, 1, n + 1, l, r, val);
        }
    }
}