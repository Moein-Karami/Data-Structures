#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;
map<int, int> befor, after;
int nxt[maxn], pre[maxn];
int real_nxt[maxn], real_pre[maxn];
int cnt[maxn];
int a[maxn], b[maxn];
vector<int> v[maxn];
vector<vector<int>> vec[10];
int real_num[maxn];
bool cmp(vector<int>& a, vector<int>& b)
{
    return a.size() < b.size();
}
int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
        cnt[a[i]]++;
        cnt[b[i]]++;
        after[b[i]] = i;
        befor[a[i]] = i;
    }
    for(int i = 1; i <= n; i++)
    {
        if (a[i])
        {
            pre[i] = after[a[i]];
        }
        if (b[i])
        {
            nxt[i] = befor[b[i]];
        }
        //cerr << "_____" << pre[i] << nxt[i] << endl;
    }
    int tmp = 0;
    for(int i = 1; i <= n; i++)
    {
        if(pre[i] == 0)
        {
            tmp++;
            int t = i;
            while(t)
            {
                v[tmp].push_back(t);
                t = nxt[t];
            }
        }
    }
    for(int i = 1; i <= tmp; i++)
    {
        int x = v[i][0], y = v[i].back();
        if(a[x] == 0 && b[y] == 0)
        {
            vec[0].push_back(v[i]);
        }
        if(a[x] == 0 && b[y] != 0)
        {
            vec[1].push_back(v[i]);
        }
        if(a[x] != 0 && b[y] == 0)
        {
            vec[2].push_back(v[i]);
        }
        if(a[x] != 0 && b[y] != 0)
        {
            vec[3].push_back(v[i]);
        }
    }
    for (int i = 0; i < 4; i++)
        sort(vec[i].begin(), vec[i].end(), cmp);
    cout << vec[0].size() + vec[1].size() << endl;
    for (int i = 0; i < vec[1].size(); i++)
    {
        for (int j = 0; j < vec[1][i].size(); j++)
        {
            real_nxt[vec[1][i][j]] = vec[2][i][j];
            real_pre[vec[2][i][j]] = vec[1][i][j];
            if (j > 0)
                real_pre[vec[1][i][j]] = vec[2][i][j-1];
            if (j + 1 < vec[2][i].size())
                real_nxt[vec[2][i][j]] = vec[1][i][j+1];
        }
    }
    int ind = 0;
    while (ind < vec[0].size() && vec[0][ind].size() == 1)
        ind++;
    for (int i = 0; i < vec[3].size(); i++)
    {
        for (int j = 0; j < vec[3][i].size(); j++)
        {
            real_nxt[vec[0][i + ind][j]] = vec[3][i][j];
            real_pre[vec[3][i][j]] = vec[0][i + ind][j];
            real_nxt[vec[3][i][j]] = vec[0][i + ind][j+1];
            real_pre[vec[0][i + ind][j+1]] = vec[3][i][j];
        }
    }
    vector<int> hell;
    for (int i = 1; i <= n; i++)
        if (cnt[i] == 0)
            hell.push_back(i);
    for (int i = 1; i <= n; i++)
    {
        real_num[real_nxt[i]] = b[i];
        real_num[real_pre[i]] = a[i];
    }
    // for (int i = 1; i <= n; i++)
    //     cerr<<real_pre[i] <<" "<< real_nxt[i]<<endl;
    // for (int i = 1; i <= n; i++)
    //     cerr<<real_num[i]<<endl;
    for (int i = 1; i <=n ; i++)
    {
        if(a[i] == b[i])
        {
            cout << hell.back() << endl;
            hell.pop_back();
            continue;
        }
        if(real_pre[i] == 0)
        {
            int x = i;
            while (real_num[x])
            {
                cout << real_num[x] << " ";
                x = real_nxt[x];
            }
            cout << endl;
        }
    }
}