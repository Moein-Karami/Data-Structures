#include<bits/stdc++.h>
#define int long long int

using namespace std;

int32_t main()
{
    string s;
    cin>>s;
    for(int i = 0; i < s.size() - 1; i++)
    {
        if(s[i] == ')' && s[i + 1] == '(')
        {
            while (true)
                i++;
        }
    }
    s += ')';
    int ans = 0;
    int tmp;
    vector<int> v;
    v.push_back(0);
    v.push_back(1);
    tmp = 0;
    int last_num = 0;
    for(int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            tmp -= last_num;
            v.push_back(tmp);
            v.push_back(last_num);
            tmp = 0;
        }
        else if(s[i] == ')')
        {
            tmp *= v.back();
            v.pop_back();
            tmp += v.back();
            v.pop_back();
        }
        else
        {
            if (v.back() == 0)
                continue;
            last_num = s[i] - '0';
            tmp += last_num;
        }
    }
    cout << tmp;
}