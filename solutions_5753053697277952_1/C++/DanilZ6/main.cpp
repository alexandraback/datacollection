#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

class cint
{
    public:
    int l;
    char c;
};
bool operator<(cint a,cint b)
{
    return a.l>b.l;
}
vector<cint> p;
int main()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    int t;
    cin >> t;
    for (int gp=1;gp<=t;gp++)
    {
        int n;
        cin >> n;
        p.clear();
        cout << "Case #" << gp << ": ";
        for (char i=0;i<n;i++)
        {
            cint l;
            cin >> l.l;
            l.c=i+65;
            p.push_back(l);
        }
        sort(p.begin(),p.end());
        while (p[0].l>p[1].l)
        {
            cout << p[0].c << ' ';
            p[0].l--;
        }
        for (int i=2;i<n;i++)
        {
            for (int j=0;j<p[i].l;j++)
            cout << p[i].c << ' ';
        }
        for (int i=0;i<p[0].l;i++){cout << p[0].c << p[1].c << ' ';}
        cout << endl;
    }
    return 0;
}
