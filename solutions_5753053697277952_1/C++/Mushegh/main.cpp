#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;
int n,p[32],i,j,t;
int q[32];
set < pair<int,int> > s;
set < pair<int,int> >::iterator it;
int Q = 1;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while(t)
    {
        t--;
        scanf("%d", &n);
        for(i=1;i<=n;i++) q[i] = 0;
        for(i=1;i<=n;i++)
        {
            scanf("%d", &p[i]);
            s.insert(make_pair(p[i],i));
        }
        printf("Case #%d: ", Q);
        Q++;
        while(!s.empty())
        {
            int k1 = (int)(s.size());
            if((int)(s.size()) == 1)
            {
                it = s.begin();
                int f = (*it).first;
                int h = (*it).second;
                printf("%c ", (h-1+'A'));
                s.erase(s.begin());
                if(f == 1) break;
                s.insert(make_pair(f-1,h));
            }
            int f1,h1,f2,h2;
            it = s.end();
            --it;
            f1 = (*it).first;
            h1 = (*it).second;
            s.erase(it);
            
            it = s.end();
            --it;
            f2 = (*it).first;
            h2 = (*it).second;
            s.erase(it);
            
            if(k1 >= 3)
            {
                printf("%c ", (h1-1+'A'));
                if(f1 > 1) s.insert(make_pair(f1-1,h1));
                s.insert(make_pair(f2,h2));
            }
            else
            {
                
                printf("%c%c ", (h1-1+'A'), (h2-1+'A'));
                if(f1>1)
                {
                    s.insert(make_pair(f1-1,h1));
                    s.insert(make_pair(f2-1,h2));
                }
            }
        }
        cout<<endl;
    }
    return 0;
}