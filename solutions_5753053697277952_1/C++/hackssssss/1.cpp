
#include <bitset>
#include <map>
#include <vector>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#define inf 0x3f3f3f3f
#define mem(a,x) memset(a,x,sizeof(a))
#define F first
#define S second
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

inline int in()
{
    int res=0;char c;int f=1;
    while((c=getchar())<'0' || c>'9')if(c=='-')f=-1;
    while(c>='0' && c<='9')res=res*10+c-'0',c=getchar();
    return res*f;
}
struct node
{
    int num;
    char ch;
}no[35];
vector<string> v;

bool cmp(const node &a,const node &b)
{
    if(a.num != b.num)
        return a.num > b.num;
        return a.ch < b.ch;
}

int main(){
    freopen("A-large.in","r",stdin);
    freopen("in.txt","w",stdout);
    int T,t = 0;
    scanf("%d",&T);
    while(T--)
    {
        int n,sum = 0;
        string str;
        v.clear();
        scanf("%d",&n);
        for(int i = 0; i < n; ++i){
            no[i].num = in();
            no[i].ch = 'A'+i;
            sum += no[i].num;
        }
        int flag = 1;
        while(flag){
            flag = 0;
            str = "";
            sort(no,no+n,cmp);
            if(no[0].num)
            {
                if(sum == 3 || !no[1].num)
                {
                    v.push_back(str+no[0].ch);
                    --no[0].num;
                    --sum;
                }
                else if(no[1].num)
                {
                    v.push_back(str+no[0].ch+no[1].ch);
                    --no[0].num;
                    --no[1].num;
                    sum -= 2;
                }
                flag = 1;
            }
        }
        int len = v.size();
        printf("Case #%d:",++t);
        for(int i = 0; i < len; ++i)
            cout<<" "<<v[i];
        puts("");
    }
    return 0;
}

