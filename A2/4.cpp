#include<bits/stdc++.h>

using namespace std;

struct st
{
    int beg=0;
    int end;
    int ans=0;
};

int main()
{
    st ans;
    st now;
    now.beg = -1;
    now.ans = 0;
    st tmp;
    st loc;
    loc.ans = 0;
    loc.beg = -1;
    loc.end = 0;
    string s;
    int n;
    cin >> n;
    vector<st> v;
    getline(cin, s);
    for(int i = 0; i < n; i++)
    {
        getline(cin, s);
        if (s == "For")
        {
            now.end = i;
            v.push_back(now);
            now.ans = -1;
            v.push_back(now);
            now.ans = 0;
            now.beg = i;
        }
        else if (s == "While")
        {
            now.end = i;
            v.push_back(now);
            now.ans = -2;
            v.push_back(now);
            now.ans = 0;
            now.beg = i;
        }
        else if (s == "Endfor")
        {
            //cerr<<"SHIT"<<endl;
            if(v.size() > 0 && v.back().ans == -1)
            {
                //cerr<<"WELL"<<endl;
                v.pop_back();
                //cerr<<v.back().ans<<endl;
                now.ans += v.back().ans + 1;
                //cerr<<now.ans<<endl;
                now.beg = v.back().beg;
                v.pop_back(); 
            }
            else
            {
                now.end = i;
                v.push_back(now);
                while(v.size())
                {
                    tmp = v.back();
                    v.pop_back();
                    if(tmp.ans < 0)
                        continue;
                    if(ans.ans < tmp.ans)
                        ans = tmp;
                }
                now.beg = i;
                now.ans = 0;
            }
        }
        else if (s == "Endwhile")
        {
            if(v.size() > 0 && v.back().ans == -2)
            {
                v.pop_back();
                now.ans += v.back().ans;
                now.beg = v.back().beg;
                loc.beg = ans.beg;
                loc.end = i+1;
                v.pop_back(); 
            }
            else
            {
                now.end = i;
                v.push_back(now);
                while(v.size())
                {
                    tmp = v.back();
                    v.pop_back();
                    if(tmp.ans < 0)
                        continue;
                    if(ans.ans < tmp.ans)
                        ans = tmp;
                }
                now.beg = i;
                now.ans = 0;
            }
        }
        else 
        {
            loc.beg = i - 1;
            loc.end = i + 1;
        }
    }
    now.end = n;
    v.push_back(now);
    while(v.size())
    {
        tmp = v.back();
        v.pop_back();
        if(tmp.ans < 0)
            continue;
        if(ans.ans <= tmp.ans)
            ans = tmp;
    }
    if (ans.ans == 0)
        ans = loc;
    cout << ans.ans << " " << ans.beg + 1 << " " << ans.end;
}