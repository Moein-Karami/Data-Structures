#include <iostream>
#include <vector>
#define int long long int

constexpr int INF = 1e17, maxn = 1e5 + 5, invalid = 1e15;

using namespace std;

class Class {
public:
    Class(int id)
    : id(id)
    , point(0)
    {
        students.push_back(-INF);
        students.push_back(INF);
    }

    void delete_min()
    {
        students[1] = students.back();
        if (students.size() > 2)
            students.pop_back();
        fix(1);
    }

    int get_min()
    {
        return students[1] + point;
    }

    void push_heap(int x)
    {
        students.push_back(x - point);
        fix(students.size() - 1);
    }

    void fix(int ind)
    {
        while (ind > 1)
        {
            if (students[ind / 2] > students[ind])
                swap(students[ind], students[ind / 2]), ind /= 2;
            else 
                break;
        }

        while (ind * 2 < students.size())
        {
            int son = 2 * ind;
            if (son + 1 < students.size())
                if (students[son + 1] < students[son])
                    son++;
            if (students[ind] > students[son])
            {
                swap(students[ind], students[son]);
                ind = son;
            }
            else 
                break;
        }
    }

    int id;
    int point;

private:
    vector<int> students;
};

Class* classes[maxn];
int ids[maxn];
int n;

void fix(int id)
{
    while (id > 1)
    {
        if (classes[id]->get_min() < classes[id / 2]->get_min() || (classes[id]->get_min() == classes[id / 2]->get_min() &&
                classes[id]->id < classes[id / 2]->id))
        {
            ids[classes[id]->id] = id / 2;
            ids[classes[id / 2]->id] = id;
            swap(classes[id], classes[id / 2]);
            id /= 2;
        }
        else
            break;
    }

    while (id * 2 <= n)
    {
        int son = id * 2;
        if (son + 1 <= n)
            if (classes[son]->get_min() > classes[son + 1]->get_min() || (classes[son]->get_min() == classes[son + 1]->
                    get_min() && classes[son]->id > classes[son + 1]->id))
                son ++;
        if (classes[id]->get_min() > classes[son]->get_min() || (classes[id]->get_min() == classes[son]->get_min() &&
                classes[id]->id > classes[son]->id))
        {
            ids[classes[id]->id] = son;
            ids[classes[son]->id] = id;
            swap(classes[id], classes[son]);
            id = son;
        }
        else 
            break;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);

    int q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++)
        ids[i] = i, classes[i] = new Class(i);

    for (int i = 1; i <= q; i++)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int class_id, point;
            cin >> class_id >> point;
            int id = ids[class_id];
            classes[id]->push_heap(point);
            fix(id); 
        }
        else if (t == 2)
        {
            int class_id, point;
            cin >> class_id >> point;
            int id = ids[class_id];
            classes[id]->point += point;
            fix(id);
        }
        else 
        {
            if (classes[1]->get_min() >= invalid)
                cout << -1 << '\n';
            else
            {
                cout << classes[1]->get_min() << '\n';
                classes[1]->delete_min();
                fix(1);
            }
        }
    }
}