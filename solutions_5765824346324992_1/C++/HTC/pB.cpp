#include <iostream>
using namespace std;
int Btime[1005],B,N;
long long solve(){
    long long left = 0,right = 1000000000000000ll;
    long long sum,tmp;
    while(right - left > 0){
        tmp = (left + right) / 2;
        sum = 0;
        for(int i=0;i<B;i++){
            sum += tmp / Btime[i] + 1;
        }
        //cout << "tmp: " << tmp << " sum: " << sum << "\n";
        if(sum >= N)right = tmp;
        else left = tmp + 1;
    }
    return left;
}
int main (){
    int Z,ans;
    long long K,sum;
    cin >> Z;
    for(int ca=1;ca<=Z;ca++){
        cin >> B >> N;
        for(int i=0;i<B;i++)cin >> Btime[i];
        K = solve();
        //cout << "K = " << K <<"\n";
        sum = 0;
        for(int i=0;i<B;i++){
            sum += (K-1) / Btime[i] + 1;
        }
        //cout << "sum: " << sum <<"\n";
        N -= sum;
        for(int i=0;i<B;i++){
            if(K%Btime[i] == 0){
                N--;
                if(N == 0 ){
                    ans = i+1;
                    break;
                }
            }
        }
        cout <<"Case #" << ca << ": " << ans << "\n";
    }
    return 0;
}
