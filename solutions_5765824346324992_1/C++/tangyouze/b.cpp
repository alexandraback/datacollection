//long long 


#include <iostream>
#include <vector>
using namespace std;
typedef  long long ll;
vector<ll> a;
ll n, m;
bool can(ll t){
    ll ans = 0;
    for(ll i=0; i<m; i++){
        ans += t/a[i];
        //if ( t % a[i])
            ans ++;
    }
    return ans>=n;

}
ll lfs(ll t){
    ll prev = 0;
    for(ll i=0; i<m; i++){
        prev += t/a[i];
        if (t%a[i])
            prev ++;
    }
    ll q = n - prev;
    for(ll i=0; i<m; i++){
    cerr<< "q" << q << " " << i  << endl;
        if (q==1 && t % a[i] == 0){
            return i;
        }
        if (t % a[i] == 0)
            q--;
    }
    return -1000;
}
ll search(ll l, ll r){
    //cerr<< l << " " << r << endl;
    ll mid = (l+r)/2;
    ll can1 = can(mid);
    ll can2 = can(mid-1);
    if (can1 && !can2){
        return mid;
    }
    if(can1){
        return search(l, mid-1);
    }
    return search(mid+1, r);


}

void solve(ll icase){
    cin >> m >> n;
    a.clear();
    for(ll i=0; i<m; i++){
        ll t;
        cin >> t;
        a.push_back(t);
    }
    ll tm = search(0, 100000*n + 100);
    cerr<<"tm " <<tm << endl;
    
    cout<<"Case #" << icase << ": "   << lfs(tm) + 1 << endl;
}
int main(){
    ll n;
    cin >> n;
    for(ll i=0; i<n; i++){
        solve(i+1);
    }
    //cout<<can(10)<<endl;

}
