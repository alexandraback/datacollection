#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;


int T, n;
int m;
int a[5005];
int x, y;
int main(){
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);



    cin >> T;
    for (int q = 1; q<=T; q++){
        printf("Case #%d: ", q);


        cin >> n;
        for (int i = 0; i<n; i++) cin >> a[i];
        x = 0;
        y = 0;
        for (int i = 1; i<n; i++) if (a[i] < a[i-1]) x+= a[i-1]-a[i];
        int maxdiff = 0;
        for (int i = 1; i<n; i++){
            maxdiff = max(maxdiff, a[i-1] - a[i]);
        }

        for (int i = 0; i<n-1; i++){
            if (a[i]>=maxdiff) y+=maxdiff;
            else y+=a[i];
        }

        cout << x << " " << y << endl;



    }


}
