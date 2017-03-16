#include <bits/stdc++.h>
using namespace std;

int pieces[1001];

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    int T;
    cin >> T;
    for (int qq=1;qq<=T;qq++)
    {
        int N,maxdiff = 0,one = 0;
        cin >> N;
        for (int i=0;i<N;i++)
        {
            cin >> pieces[i];
            if (i!=0)
            {
                maxdiff = max(maxdiff,pieces[i-1]-pieces[i]);
                one += max(0,pieces[i-1]-pieces[i]);
            }
        }
        int two = 0,cur = pieces[0];
        for (int i=0;i<N-1;i++)
        {
            two += min(maxdiff,cur);
            cur = pieces[i+1];
        }
        printf("Case #%d: %d %d\n",qq,one,two);
    }
}
