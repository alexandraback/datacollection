#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <fstream>
#include <cstring>

using namespace std;
typedef long long LL;

string s[110];
char ch[110][110];
int num[110][110];
int pos[110];
int n;

int calc(int t)
{
    for (int i=0;i<n;i++)
        if (pos[i]<=t) return -1;
    for (int i=0;i<n;i++)
        if (ch[i][t]!=ch[0][t]) return -1;
    vector<int> v;
    for (int i=0;i<n;i++) v.push_back(num[i][t]);
    sort(v.begin(),v.end());
    int ret=1000000;
    for (int k=0;k<n;k++)
    {
        int c=0;
        for (int i=0;i<n;i++)
            c+=abs(v[i]-v[k]);
        ret=min(ret,c);
    }
    return ret;
}
int main()
{
    freopen("the_repeater.in","r",stdin);
    freopen("the_repeater.out","w",stdout);
    int tc, nt=1;
    cin>>tc;
    while (tc--)
    {
        cin>>n;
        for (int i=0;i<n;i++) cin>>s[i];
        memset(pos,0,sizeof(pos));
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<s[i].size();j++)
            {
                int p=j;
                while (p<s[i].size() && s[i][j]==s[i][p]) p++;
                ch[i][pos[i]]=s[i][j];
                num[i][pos[i]++]=p-j;
                j=p-1;
            }
        }
/*        for (int i=0;i<n;i++)
        {
            for (int j=0;j<pos[i];j++) cout<<ch[i][j]<<" "<<num[i][j]<<"/";
            cout<<endl;
        }*/
        int ret=0, can=1;
        for (int i=0;i<n;i++)
            if (pos[i]!=pos[0]) can=0;
        for (int i=0;i<pos[0];i++)
        {
            int k=calc(i);
            if (k==-1) can=0;
            ret+=k;
        }
        cout<<"Case #"<<nt++<<": ";
        if (can==0) cout<<"Fegla Won"<<endl;
        else cout<<ret<<endl;
    }
}
