#include<bits/stdc++.h>

using namespace std;
#define xx first
#define yy second
#define LL long long
#define inf 100000000
#define pb push_back
#define vsort(v) sort(v.begin(),v.end())
#define pi acos(-1)
#define clr(a,b) memset(a,b,sizeof a)
#define bclr(a) memset(a,false,sizeof a)
#define pii pair<int,int>
#define MOD 1000000007
#define MP make_pair
#define MX 1005

using namespace std;
priority_queue<pii>PQ;

int main(){
    freopen("input.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int test; cin>>test;
    for(int kase=1;kase<=test;kase++){
        int n; cin>>n;
        for(int i=0;i<n;i++){
            int a; cin>>a;
            PQ.push(MP(a,i));
        }
        vector<string>res;
        while(!PQ.empty()){
            pii A=PQ.top(); PQ.pop();
            A.xx--;
            if(A.xx==0 && PQ.size()==1){
                pii B=PQ.top(); PQ.pop();
                string x="";
                x+=(char)(A.yy+'A');
                x+=(char)(B.yy+'A');
                res.pb(x);
            }
            else if(A.xx==1 && PQ.size()>=1){
                pii B=PQ.top(); PQ.pop();
                string x="";
                x+=(char)(A.yy+'A');
                x+=(char)(B.yy+'A');
                res.pb(x);
                B.xx--;
                PQ.push(A);
                PQ.push(B);
            }
            else{
                string x=""; x+=(char)(A.yy+'A');
                res.pb(x);
                if(A.xx>0)  PQ.push(A);
            }
        }
        cout<<"Case #"<<kase<<":";
        for(int i=0;i<res.size();i++) cout<<" "<<res[i];
        cout<<endl;
    }
    return 0;
}

