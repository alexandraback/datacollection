
#include <iostream>
#include <vector>
using namespace std;
void solve(int icase){
    int n;
    vector<int> a;
    cin >> n;
    int ans1 = 0, ans2 = 0;
    for(int i=0; i<n; i++){
        int t;
        cin >> t;
        a.push_back(t);
        if (i>0){
            int diff = a[i-1] - a[i];
            if (diff > 0){
                ans1  += diff;
            }
            int rate = diff;
            ans2 = max(ans2, rate);
        }
    }
    int ans3 = 0;
    for(int i=0; i<n; i++){
        ans3 += min(ans2, a[i-1]);
    }
    printf("Case #%d: %d %d\n", icase, ans1, ans3);
}
int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        solve(i+1);

    }

}
