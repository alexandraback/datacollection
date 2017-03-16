#include <bits/stdc++.h>
using namespace std;

int n;
set<pair<int,int> > s;

int main()
{
    ios::sync_with_stdio(0);
    //freopen("input.in","r",stdin);
    //freopen("output.txt","w",stdout);
    int T;
    cin >> T;
    for(int t=1;t<=T;++t)
    {
        s.clear();
        cin >> n;
        for(int i=0;i<n;++i)
        {
            int x;
            cin >> x;
            s.insert(make_pair(-x,i));
        }
        printf("Case #%d:",t);
        while(s.size()>2)
        {
            pair<int,int> p = *s.begin();
            s.erase(s.begin());
            printf(" %c",'A' + p.second);
            p.first++;
            if(p.first<0) s.insert(p);
        }
        pair<int,int> a = *s.begin();
        s.erase(s.begin());
        pair<int,int> b = *s.begin();
        a.first*=-1;
        b.first*=-1;
        while(a.first>b.first) printf(" %c",'A' + a.second), a.first--;
        while(a.first) printf(" %c%c",'A' + a.second, 'A'+b.second), a.first--;
        printf("\n");
    }

}
