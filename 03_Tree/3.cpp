#include <iostream>

#define int long long int

using namespace std;

enum Color{
    red,
    black
};
int max_id = 0;
struct Node{
    
    Node(Node* par = NULL, int val = 0, Color color = Color::black, int id = ++max_id)
    : id(id)
    , par(par)
    , val(val)
    , color(color)
    {
    }

    void right_rotate()
    {
        Node* left_child = l;
        l->par = par;
        if(par)
        {
            if(this == par->r)
                par->r = l;
            else 
                par->l = l;
        }
        par = l;
        l = left_child->r;
        if(l)
            l->par = this;
        left_child->r = this;
    }

    void left_rotate()
    {
        Node* right_child = r;
        r->par = par;
        if(par)
        {
            if(this == par->r)
                par->r = r;
            else 
                par->l = r;
        }
        par = r;
        r = right_child->l;
        if(r)
            r->par = this;
        right_child->l = this;
    }

    void add_child()
    {
        l = new Node(this);
        r = new Node(this);
    }

    Node* get_bro()
    {
        if(this == par->l)
            return par->r;
        else 
            return par->l;
    }

    Node* get_uncle()
    {
        return par->get_bro();
    }

    void fix()
    {
        if (par == NULL)
        {
            color = Color::black;
            return;
        }
        if (color != Color::red || par->color != Color::red)
            return;
        
        Node* uncle = get_uncle();
        
        if(uncle->color == Color::red)
        {
            uncle->color = Color::black;
            par->color = Color::black;
            par->par->color = Color::red;
            par->par->fix();
            return;
        }

        if (par == par->par->l)
        {
            if (this == par->r)
            {
                color = Color::black;
                par->par->color = Color::red;
                par->left_rotate();
                par->right_rotate();
            }
            else
            {
                par->color = Color::black;
                par->par->color = Color::red;
                par->par->right_rotate();
            }
        }
        else
        {
            if (this == par->l)
            {
                color = Color::black;
                par->par->color = Color::red;
                par->right_rotate();
                par->left_rotate();
            }
            else
            {
                par->color=Color::black;
                par->par->color = Color::red;
                par->par->left_rotate();
            }
        }
    }

    void add(int x)
    {
        if(val)
        {
            if (x > val)
                r->add(x);
            else
                l->add(x);
            return;
        }
        val = x;
        add_child();
        if (par == NULL)
            return;
        color = Color::red;
        fix();
    }

    string find(int x)
    {
        if (val == 0)
            return "NO";
        else if (val == x)
            return "YES";
        if (x < val)
            return l->find(x);
        return r->find(x);
    }

    void print(string s)
    {
        cerr << s << ": ID: " << id << ", Val: " << val << ", Color:" << color;
        if(l)
            cerr << ", LEFT ID : " << l->id;
        if(r)
            cerr <<", RIGHT ID: "<<r->id;
        if(par != NULL)
            cerr<<", PAR ID: "<<par->id;
        cerr<<endl;
        if (val == 0)
            return;
        l->print(s + " L");
        r->print(s + " R");
    }

    int val;
    Color color;
    Node* par;
    Node* r;
    Node* l;
    int id;
};

int32_t main()
{
    ios_base::sync_with_stdio(false);
    srand(time(0));
    Node* root = new Node();
    int n;
    cin >> n;
    while (n--)
    {
        root->color = Color::black;
        int t, val;
        cin >> t >> val;
        if (t == 1)
        {
            root->add(val);
            while (root->par != NULL)
                root = root->par;
        }
        else
            cout << root->find(val) << "\n";
    }
    return 0;
}