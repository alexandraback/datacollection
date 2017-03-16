#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define mod 1000000007
#define reset(s,val) memset(s,val,sizeof(s))
#define eps 1e-9
#define pi acos(-1)
#define sqr(x) (x)*(x)
#define two(x) (1<<(x))

int n,t,cnt[33];
vector<int> ans;

void display(int x) {
    char c='A'+x;
    cout<<c;
}

int main( ){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>t;
    For(cas,1,1+t) {
        cout<<"Case #"<<cas<<": ";
        cin>>n;
        For(i,0,n) cin>>cnt[i];
        bool flag=true;
        while(flag) {
            flag = false;
            For(i,0,n) if(cnt[i]) {
                cnt[i]--;
                ans.pb(i);
                flag = true;
            }
        }
        if(ans.size()&1) {
            display(ans.back());
            ans.pop_back();
            cout<<' ';
        }
        while(ans.size()) {
            display(ans.back());ans.pop_back();
            display(ans.back());ans.pop_back();
            cout<<' ';
        }
        cout<<endl;
    }
}
