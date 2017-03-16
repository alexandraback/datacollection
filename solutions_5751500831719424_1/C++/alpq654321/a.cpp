#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
#include <vector>
using namespace std;
int TT,Cases,i,T[105][105],o,j,sum,p,O,n,ans,q[10005];
bool FLAG;
char s[105],t[105][105];
int cmp(int i,int j ){return i<j;}
int main()
{
    scanf("%d",&Cases);
    for (TT=1; TT<=Cases; TT++)
    {
        scanf("%d",&n); FLAG=true;
        for (i=1; i<=n; i++)
        {
            scanf("%s",s);
            p=strlen(s);
            sum=1; o=0;
            for (j=1; j<p; j++)
              if (s[j]!=s[j-1])
              {
                  t[i][++o]=s[j-1];
                  T[i][o]=sum; sum=1;
              }  else  sum++;
            t[i][++o]=s[p-1];
            T[i][o]=sum;
            if (i!=1) for (j=1; j<=o; j++) if (t[i][j]!=t[i-1][j]) {FLAG=false;cout<<"Case #"<<TT<<": Fegla Won"<<endl;break;}
            if (!FLAG) break;
            if (i==1) O=o; else if (o!=O) {FLAG=false; cout<<"Case #"<<TT<<": Fegla Won"<<endl; break;}
        }
        if (!FLAG) continue;
        cout<<"Case #"<<TT<<": "; ans=0;
        for (i=1; i<=o; i++)
        {
            for (j=1; j<=n; j++) q[j]=T[j][i];
            sort(q+1,q+n+1,cmp);
            for (j=1; j<=n/2; j++) ans+=q[n-j+1]-q[j];
        }
        cout<<ans<<endl;
    }
    return 0;
}
