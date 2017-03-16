#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <map>
using namespace std;

typedef unsigned long long ull;
int T, n;
//int a[30];

struct S
{
    int x;
    char p;
    //bool operator() (S x, S y) {return x.x > y.x; }
};

bool cmp(S x, S y)
{
    return x.x > y.x;
}

int main()
{
    //freopen("A-small-attempt1.in","r",stdin);
    freopen("A-large.in","r",stdin);
    freopen("a.txt","w",stdout);
    scanf("%d", &T);
	for (int cse = 1; cse <= T; cse++)
	{
	    vector<S> a;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            S tmp;
            scanf("%d", &tmp.x);
            tmp.p = i + 65;
            a.push_back(tmp);
        }
        sort (a.begin(), a.end(), cmp);
        string ans = "";
        while (a[0].x > 1)
        {
            int e = 0;
            while (e < n && a[e].x == a[e + 1].x) e++;
            //printf("E %d\n", e);
            for (int i = 0; i + 1 <= e; i+=2)
            {
                a[i].x--;
                a[i + 1].x--;
                ans += " ";
                ans += a[i].p;
                ans += a[i + 1].p;
            }
            if (e % 2 == 0)
            {
                a[e].x--;
                ans += " ";
                ans += a[e].p;
            }
            //for (int i = 0; i < n; i++)                printf("%d ", a[i].x);            printf("\n");
            //for (int i = 0; i < n; i++)                printf("%c ", a[i].p);            printf("\n");
        }
        if (a[0].x == 1)
        {
            int i = 0;
            if (n %2 == 1)
            {
                a[0].x--;
                ans += " ";
                ans += a[0].p;
                i = 1;
            }
            for (; i + 1 < n; i+=2)
            {
                a[i].x--;
                a[i + 1].x--;
                ans += " ";
                ans += a[i].p;
                ans += a[i + 1].p;
            }
        }
        //printf("%s\n",ans.c_str());
        printf("Case #%d:%s\n", cse, ans.c_str());
        //cout<<ans<<endl;
        //for (int i = 0; i < n; i++)if (a[i].x) cerr<<"!"<<endl;
	}
	return 0;
}
