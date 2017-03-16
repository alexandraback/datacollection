#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;
typedef long long ll;

ll eval(ll T, vector<ll>& M){
    if(T==-1) return 0;
    int B = M.size();
    ll ans = 0;
    for(int i=0;i<B;i++) ans+= 1+(T/M[i]);
    
    return ans;
}

int main(){
    int T;
    cin >> T;
    for(int t=1;t<=T;t++){
        int B;
        ll N;
        cin >> B >> N;
        
        vector<ll> M(B);
        for(int i=0;i<B;i++) cin >> M[i];
        
        ll low=-1;
        ll high = N*M[0];
        while(high - low>1){
            ll mid = (low+high)/2;
            
            ll val = eval(mid, M);
            if(val>=N){
                high = mid;
            }else{
                low = mid;
            }
        }
        
        ll ord = N-eval(low, M);
        int ans = B;
        int free = 0;
        for(int i=0;i<B;i++){
            if(high%M[i]==0){
                free++;
                if(free==ord){
                    ans = i;
                }
            }
        }

        
        cout << "Case #" << t << ": " << (ans+1) << endl;    
    }

    return 0;
}