#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <string>
#include <queue>
#include <vector>
#include <set>
#define maxn 200
#define oo 1000000000
#define clearAll(a) memset(a,0,sizeof(a))
#define sq(a) ((a)*(a))

using namespace std;

typedef long long ll;

int n,m;
char s[maxn];
char a[maxn];
int cnt[maxn][maxn];

void deal(int id,char s[maxn]){
    int l = strlen(s);
    int pos=0;
    int num = 1;
    for (int i=1;i<l;i++)
        if (s[i]!=s[pos])
        {
            cnt[pos][id] = num;
            num = 1;
            s[++pos]=s[i];
        } else num++;

    cnt[pos][id]=num;
    s[++pos]=0;
}

int work(){
    m = strlen(s);
    for (int i=0;i<m;i++)
        sort(cnt[i],cnt[i]+n);
    int ans = 0;
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
            ans += abs(cnt[i][j]-cnt[i][n/2]);
    }
    return ans;
}

int main()
{
    freopen("E:\\codejam\\input.txt","r",stdin);
    freopen("E:\\codejam\\output.txt","w",stdout);

    int tt;
    cin >> tt;
    int id = 0;
    while (tt--)
    {
        cin >> n;
        scanf("%s",s);
        deal(0,s);
        bool flag = true;
        for (int i=1;i<n;i++)
        {
            scanf("%s",a);
            deal(i,a);
            if (strcmp(s,a)!=0)
                flag=false;
        }


        id++;
        printf("Case #%d: ",id);

        if (flag==false)
            printf("Fegla Won\n");
        else printf("%d\n",work());
    }
    return 0;
}
