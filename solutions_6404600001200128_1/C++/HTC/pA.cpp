#include <iostream>
#include <algorithm>
using namespace std;
int a[1005],ans1,ans2;
int main (){
    int Z,N,d;
    cin >> Z;
    for(int ca=1;ca<=Z;ca++){
        cin >> N;
        for(int i=0;i<N;i++)cin >> a[i];
        d = ans1 = ans2 = 0;
        for(int i=0;i<N-1;i++){
            if(a[i+1] < a[i]){
                ans1 += a[i] - a[i+1];
                d = max(d,a[i] - a[i+1]);
            }
        }
        for(int i=0;i<N-1;i++){
            ans2 += min(d,a[i]);
        }
        cout << "Case #" << ca << ": " << ans1 << " " << ans2 << "\n";
    }
    return 0;
}
