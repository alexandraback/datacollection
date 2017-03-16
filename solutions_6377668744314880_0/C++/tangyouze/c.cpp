#include <bits/stdc++.h>
#include <cmath>
using namespace std;
int x[2000];
int y[2000];
int n;
double angle(int a, int b){
    return atan2(y[b] - y[a], x[b] - x[a]);
}
vector<double> angles;
double pi = acos(-1);
double eps = 1e-8;
double go2(double a1, double a2){
    if(a2 <a1 - eps)
        a2 += 2 * pi;
    return a2 - a1;
}
double same(double x, double y ){

    return  x<=y+eps && x>= y-eps;
}
void soo(int start){
    angles.clear();
    for(int i=0; i<n; i++){
        if(i!=start)
        angles.push_back( angle(start, i));
    }
    sort(angles.begin(), angles.end());

    for(int i=0; i<n-1 ;i++)
        cerr<<"angle " << angles[i] << endl;
    for(int i=0; i<n-1; i++){
        angles.push_back(angles[i]);
    }
    int j = 1;
    int ans = n-1;
    for(int i=0; i<n-1; i++){
        if( i > 0 && same(angles[i], angles[i-1]))
            continue;
        while(go2(angles[i], angles[j]) <= pi  + eps && j<i + n - 1){
            j++;
        }

        int jj = j;
        int ii = i;
        while(same(angles[i], angles[ii]) && ii < i + n - 1)
            ii++;
        while(same(go2(angles[i], angles[jj]) , pi)){
            jj--;
        }
        //cerr << "go2  " << go2(angles[i], angles[j]) << endl;
        cerr <<  "cur " << i << " " << j  << " " << ii << " " << jj<< endl;
        ans =  min(ans, jj-ii + 1);
        ans =  min(ans, n - 1 - (j-i));
    }
    //cout << ans  << endl;
    printf("%d\n", ans);
}
void solve(int icase){
    cin >> n;
    memset(x, 0, sizeof x);
    memset(y, 0, sizeof y);
    for(int i=0; i<n; i++){
        cin >> x[i] >> y[i];
    }
    printf("Case #%d:\n", icase);
    for(int i=0; i<n; i++){
        soo(i);
    }
}
int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        solve(i+1);

    }
    //cerr<< angle(0, 1) << endl;;
    //cerr<< angle(0, 2) << endl;;
    //cerr<< angle(0, 3) << endl;;

}
