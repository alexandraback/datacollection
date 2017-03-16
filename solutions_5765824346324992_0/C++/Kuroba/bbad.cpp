#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;


int T, n;
int m, b;
int a[1005];


int gcd(int x, int y){
    if (x==0) return y;
    return gcd(y%x,x);
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);



    cin >> T;
    for (int q = 1; q<=T; q++){
        printf("Case #%d: ", q);

        vector<pair<int,int> > v;
        cin >> n >> b;
        for (int i = 0; i<n; i++) cin >> a[i];

        int k = a[0];
        for (int i = 1; i<n; i++) k = gcd(k, a[i]);
        int lcm = k;
        for (int i = 0; i<n; i++) lcm *= a[i]/k;

        for (int i = 0; i<n; i++){
            for (int j = 0; j<lcm; j+=a[i]){
                v.push_back(make_pair(j,i));
            }
        }

        sort(v.begin(), v.end());

        //for (int i = 0; i<v.size(); i++) cout << v[i].first << " " << v[i].second << endl;

        cout << v[(b-1)%v.size()].second+1 << endl;











    }


}
