#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;
typedef long long ll;

int orient(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3){
    ll val = x1*y2 + x2*y3 + x3*y1 - x1*y3 - x2*y1 - x3*y2;
    if(val>0) return 1;
    else if(val<0) return -1;
    else return 0;
}

int main(){
    int T;
    cin >> T;
    for(int t=1;t<=T;t++){
        int N;
        cin >> N;
        
        if(N==1){
            int X, Y;
            cin >> X >> Y;
            cout << "Case #" << t << ": " << endl;
            cout << 0 << endl;   
        }else{
        
            vector<ll> Xs(N);
            vector<ll> Ys(N);
        
            for(int i=0;i<N;i++) cin >> Xs[i] >> Ys[i];
        
            cout << "Case #" << t << ": " << endl;    
        
            for(int i=0;i<N;i++){
                int minval = N;
                for(int j=0;j<N;j++){
                    if(j!=i){
                        int plus = 0;
                        int minus = 0;
                        for(int k=0;k<N;k++){
                            int sgn = orient(Xs[i], Ys[i], Xs[j], Ys[j], Xs[k], Ys[k]);
                            if(sgn==1) plus++;
                            else if(sgn==-1) minus++;
                        }
               //         cout << i << " " << j << " " << plus << " " << minus << endl;
                        if(plus<minval) minval=plus;
                        if(minus<minval) minval=minus;
                    }
                }
                cout << minval << endl;
            }
        
        }
        
    }

    return 0;
}