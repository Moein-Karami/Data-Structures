#include<bits/stdc++.h>

using namespace std;

#define int long long int

const int maxn = 1e6;
const int mod = 10;
class Int 
{
    public:
    vector<int> v;
    Int(int x)
    {
        v.push_back(x);
    }
    Int(){}
    void fix()
    {
        for(int i = 0; i < v.size(); i++)
        {
            if(v[i] >= mod)
            {
                if(i == v.size()-1)
                    v.push_back(0);
                v[i+1] += v[i] / mod;
                v[i] %= mod;
            }
            if(v[i] < 0)
            {
                if(i == v.size()-1)
                    continue;
                while (v[i] < 0)
                {
                    v[i+1]--;
                    v[i]+=mod;
                }
            }
        }
    }
    Int operator*(Int a)
    {
        int s = a.v.size() + v.size() - 2;
        Int tmp;
        for(int i = 0 ; i <= s; i++)
            tmp.v.push_back(0);
        for(int i = 0 ; i < v.size(); i++)
            for(int j = 0; j < a.v.size(); j++)
                tmp.v[i + j] += v[i] * a.v[j];
        tmp.fix();
        return tmp; 
    }
    Int operator+(Int a)
    {
        int s = max(a.v.size() ,v.size());
        Int tmp;
        for(int i = 0 ; i < s; i++)
            tmp.v.push_back(0);
        for(int i = 0 ; i < v.size(); i++)
            tmp.v[i] = v[i];
        for(int i = 0 ; i < a.v.size(); i++)
            tmp.v[i] += a.v[i];   
        tmp.fix();
        return tmp; 
    }
    Int operator-(Int a)
    {
        int s = max(a.v.size() ,v.size());
        Int tmp;
        for(int i = 0 ; i < s; i++)
            tmp.v.push_back(0);
        for(int i = 0 ; i < v.size(); i++)
            tmp.v[i] = v[i];
        for(int i = 0 ; i < a.v.size(); i++)
            tmp.v[i] -= a.v[i];   
        tmp.fix();
        return tmp; 
    }
    void print()
    {
        int t=1;
        while(v[v.size()-t]==0 && t < v.size())
            t++;
        for(int i = (int)v.size() - t; i >= 0; i--)
        {
            cout<<v[i];
        }
    }
};

int32_t main()
{
    string s;
    cin >> s;
    if (s == "Preorder")
    {
        cin >> s;
        vector<Int> v;
        for(int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == '*')
            {
                Int t1 = v.back();
                v.pop_back();
                Int t2 = v.back();
                v.pop_back();
                v.push_back(t1 * t2);
            }
            else if (s[i] == '-')
            {
                Int t1 = v.back();
                v.pop_back();
                Int t2 = v.back();
                v.pop_back();
                v.push_back(t1 - t2);
            }
            else if (s[i] == '+')
            {
                Int t1 = v.back();
                v.pop_back();
                Int t2 = v.back();
                v.pop_back();
                v.push_back(t1 + t2);
            }
            else
            {
                v.push_back(s[i] - '0');
            }
        }
        //cout << v.back();
        v.back().print();
    }
    else
    {
        cin >> s;
        vector<Int> v;
        for(int i = 0; i < s.size(); i++)
        {
            if (s[i] == '*')
            {
                Int t1 = v.back();
                v.pop_back();
                Int t2 = v.back();
                v.pop_back();
                v.push_back(t1 * t2);
            }
            else if (s[i] == '-')
            {
                Int t2 = v.back();
                v.pop_back();
                Int t1 = v.back();
                v.pop_back();
                v.push_back(t1 - t2);
            }
            else if (s[i] == '+')
            {
                Int t1 = v.back();
                v.pop_back();
                Int t2 = v.back();
                v.pop_back();
                v.push_back(t1 + t2);
            }
            else
            {
                v.push_back(s[i] - '0');
            }
        }
        //cout << v.back();
        v.back().print();
    }
}