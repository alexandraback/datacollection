#include<iostream>
#include<set>
using namespace std;

int m[1005];
set<pair<long long,int> > q;

int main()
{
    int t;
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    cin >> t;
    for (int ii = 0; ii < t; ii++)
    {
        int b,n;
        q.clear();
        cin >> b >> n;
        int l = 1;
        for (int i = 0; i < b; i++)
        {
            cin >> m[i];
            l *= m[i];
            q.insert(make_pair(0,i + 1));
        }
        int r = 0;
        for (int i = 0; i < b; i++)
            r += l / m[i];
        if (n % r)
             n = n % r;
        else
            n = r;
        for (int i = 0; i < n - 1; i++)
        {
            set<pair<long long,int> >::iterator it = q.begin();
            long long time = it->first;
            int indx = it->second;
            q.erase(it);
            q.insert(make_pair(time + m[indx - 1],indx));
        }
        cout << "Case #" << ii + 1 << ": " << q.begin()->second << endl;
    }
    return 0;
}
