#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <climits>
#include <cassert>
#include <cmath>
using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define INF INT_MAX/3
#define LINF LLONG_MAX/3
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define ALL(v) (v).begin(),(v).end()
#define debug(x) cout<<#x<<":"<<x<<endl
#define debug2(x,y) cout<<#x<<","<<#y":"<<x<<","<<y<<endl

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

string alfa="ABCDEFGHIJKLMNOPQRSTUVWXYZ";


void solve(){
    int N;cin>>N;
    vector<pair<int,string>> num(N);
    int sum=0;
    rep(i,N){
        int n;cin>>n;
        sum += n;
        num[i].first=n;
        num[i].second=alfa[i];
    }
    sort(ALL(num));
    reverse(ALL(num));
    vector<string> ans;


    while(1){
        if(sum==0) break;
        if(sum==1){
            for(int i=0;i<ans.size();i++) cout << ans[i] << endl;
            assert(false);
        }
        if(sum==2){
            string a;
            a += num[0].second;
            a += num[1].second;
            ans.push_back(a);
            break;
        }else{
            string a;
            a += num[0].second;
            num[0].first--;
            sum--;
            if(sum/2<num[1].first){
                a += num[1].second;
                num[1].first--;
                sum--;
            }
            ans.push_back(a);
            sort(ALL(num));
            reverse(ALL(num));
        }
    }

    rep(i,ans.size()-1){
        cout << ans[i] << " ";
    }
    cout << ans[ans.size()-1];
    cout << endl;
}

int main(){
    int T;
    cin >> T;
    rep(i,T){
        printf("Case #%d: ",i+1);
        solve();
    }
}
