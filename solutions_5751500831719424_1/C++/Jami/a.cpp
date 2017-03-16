#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<stack>
#include<vector>
#include<cctype>
#include<cstdio>
#include<string>
#include<sstream>
#include<cstring>
#include<cstdlib>
#include<fstream>
#include<iterator>
#include<iostream>
#include<algorithm>

using namespace std;

#pragma comment(linker,"/STACK:16777216")
#pragma warning(disable:4786)

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define myabs(a) ((a)<0?(-(a)):(a))
#define pi acos(-1.0)
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define pb push_back
#define all(a) a.begin(),a.end()
#define xx first
#define yy second
#define eps 1e-9
#define root 1
#define lft 2*idx
#define rgt 2*idx+1
#define cllft lft,st,mid
#define clrgt rgt,mid+1,ed
#define inf (1<<25)
#define i64 long long
#define MX 192

typedef pair<char,int> pii;

vector<pii> a[MX];
string s[MX];
int n;

void split(int idx){
    int i,sz=0;
    string ss=s[idx];
    a[idx].clear();
    a[idx].pb(pii(ss[0],1));
    for(i=1;i<ss.size();i++){
        if(ss[i]==ss[i-1]){
            a[idx][sz].yy++;
        }
        else{
            sz++;
            a[idx].pb(pii(ss[i],1));
        }
    }
}

int func(){
    int i,j,k,ret=0,tmp,x;
    for(i=0;i<a[0].size();i++){
        for(j=1;j<n;j++){
            if(a[j].size()!=a[0].size() || a[0][i].xx!=a[j][i].xx)return inf;
        }
    }
    for(i=0;i<a[0].size();i++){
        tmp=inf;
        for(k=1;k<=100;k++){
            x=0;
            for(j=0;j<n;j++){
                x+=myabs(k-a[j][i].yy);
            }
            tmp=min(tmp,x);
        }
        ret+=tmp;
    }
    return ret;
}

int main(){
    freopen("A-large.in","r",stdin);
	//freopen("in.in","r",stdin);
	freopen("out.txt","w",stdout);
	int i,res,t=1,cs;
	cin>>cs;
	while(cs--){
	    cin>>n;
	    for(i=0;i<n;i++){
	        cin>>s[i];
	        split(i);
	    }
	    res=func();
	    if(res<inf)printf("Case #%d: %d\n",t++,res);
	    else printf("Case #%d: Fegla Won\n",t++);
	}
	return 0;
}


