#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define NL '\n'
#define xx first
#define yy second
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(i=j;i<=k;i++)
#define REV(i,j,k) for(i=j;i>=k;i--)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)
#define pi 2.0*acos(0.0)
#define MOD 1000000007
#define MAX 100005

set < pii > s;
set < pii >::iterator it;
vector <string> v;
char ch[100];

int main()
{
    //READ("A-small-attempt0.in");
    //WRITE("A-small-attempt0.out");
    std::ios_base::sync_with_stdio(0);
    int cases, caseno=0, n, i, j, k, cnt, sum;
    pii p, q;
    string str;

    cin >> cases;

    FOR(i,0,25)
    {
        ch[i] = 'A'+i;
    }

    while(cases--)
    {
        cin >> n;

        sum = 0;
        v.clear();
        s.clear();

        FOR(i,0,n-1)
        {
            cin >> k;
            s.insert( mp(k, i) );
            sum += k;
        }

        while(!s.empty())
        {
            it = s.end();
            it--;
            p = *it;
            s.erase(it);
            it = s.end();
            it--;
            q = *it;

            if(p.xx > q.xx)
            {
                p.xx--;
                str.clear();
                str += ch[p.yy];
                v.pb(str);
                if(p.xx > 0) s.insert(p);
            }
            else
            {
                if(s.size() == 2 && p.xx == 1)
                {
                    str.clear();
                    str += ch[p.yy];
                    v.pb(str);
                    continue;
                }
                s.erase(it);
                p.xx--; q.xx--;
                str.clear();
                str += ch[p.yy];
                str += ch[q.yy];
                v.pb(str);
                if(p.xx > 0) s.insert(p);
                if(q.xx > 0) s.insert(q);
            }
        }

        cout << "Case #" << ++caseno << ":";

        n = v.size();

        FOR(i,0,n-1)
            cout << " " << v[i];
        cout << NL;
    }

    return 0;
}




