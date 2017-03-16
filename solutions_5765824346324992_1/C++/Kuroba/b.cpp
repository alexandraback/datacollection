#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int T;
int n;
long long m, b;
long long a[1005];



long long calcpos(long long x){
    long long pos = 0;
    for (int i = 0; i<n; i++){
        pos += (1 + x/a[i]);
    }
    return pos;
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);



    cin >> T;
    for (int q = 1; q<=T; q++){
        printf("Case #%d: ", q);


        cin >> n >> b;
        for (int i = 0; i<n; i++) cin >> a[i];

        long long hi = 10000000000000LL;
        long long lo = -1;
        long long mid;
        long long pos = 0, pos2;
        bool found = false;
        while (!found && lo<hi-1){
            //cout << mid << endl;
            mid = (lo+hi)/2;

            pos = 0;


            pos = calcpos(mid);
            pos2 = calcpos(mid-1);


            if (pos>=b && pos2<b) found = true;
            else if (pos>=b) hi = mid;
            else if (pos<b) lo = mid;



        }


        long long remain = b - pos2;
        long long ans = 0;
        //cout << mid << " " << calcpos(mid) << " " << calcpos(mid-1) << " " << remain << endl;
        //cout << mid % a[0] << endl;
        for (int i = 0; i<n; i++){
            if (mid%a[i] == 0) remain--;
            if (remain == 0){
                    ans = i+1;
                    break;
            }
        }

        cout << ans << endl;




    }


}
