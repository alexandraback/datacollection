#include<bits/stdc++.h>
using namespace std;
#define test int t;scanf("%d", &t);while(t--)
#define sd(n) scanf("%d", &n)
#define pd(n) printf("%d", n)
#define fl(i, n) for(int i=0;i<n;i++)
#define MOD 1000000007
int fact[5001];
int invfact[5001];
int inv(int a, int b){
    if(b==0)
        return 1;
    if(b&1)
        return (long long)a*inv(a, b-1)%MOD;
    else{
        int res = inv(a, b>>1);
        return (long long)res*res%MOD;
    }
}
void init(){
    fact[0] = 1;
    for(int i=1;i<5001;i++){
        fact[i] = (long long)fact[i-1]*i%MOD;
    }
    invfact[5000] = inv(fact[5000], MOD-2);
    for(int i=5000;i>0;i--){
        invfact[i-1] = (long long)invfact[i]*i%MOD;
    }
}
int C(int n, int r){
    if(r>n || r<0)
        return 0;
    return (long long)((long long)fact[n]*invfact[r]%MOD)*invfact[n-r]%MOD;
}
void solve(){
    int T;
    sd(T);
    for(int t=1;t<=T;t++){
        int n;
        sd(n);
        int arr[n];
        int summ = 0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            summ+=arr[i];
        }
        vector<pair<int, int> > ary(n);
        for(int i=0;i<n;i++){
            ary[i] = make_pair(arr[i], i);
        }
        string alph = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        vector<string> v;
        while(true){
            sort(ary.rbegin(), ary.rend());
            if(ary[0].first==0) break;
            string s="";
            s+=alph[ary[0].second];
            ary[0].first--;
            summ--;
            sort(ary.rbegin(), ary.rend());
            if(ary[0].first>summ/2) {
                    s+=alph[ary[0].second];
                    ary[0].first--;
                    summ-=2;
            }
            v.push_back(s);

        }
        cout<<"Case #"<<t<<": ";
        for(int i=0;i<v.size();i++){
            if(i==v.size()-1)   cout<<v[i];
            else    cout<<v[i]<<" ";
        }
        cout<<"\n";
    }
}
int main(){
    FILE *fin = freopen("A-large.in", "r", stdin);
	assert( fin!=NULL );
	FILE *fout = freopen("A-large.out", "w", stdout);
    solve();
    return 0;
}
