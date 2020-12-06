#include <bits/stdc++.h>

#define int long long int

constexpr int max_n = 10;
constexpr int max_q = 100;

using namespace std;

int32_t main()
{
    srand(time(0));
    int n = rand() % max_n + 1;
    int q = rand() % max_q;
    cout << n << " " << q << endl;
    while(q--)
    {
        int t = rand() % 3 + 1;
        cout << t << " " ;
        if(t != 3)
        {
            int c = rand() % n + 1, p = rand() % 2000 - 1000;
            cout << c << " " << p;
        }
        cout << endl;
    }
}