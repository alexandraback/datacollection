#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

string to_string(long long x){
    char s[50];
    sprintf(s, "%lld", x);
    return string(s);
}

string solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int res1 = 0;
    for(int i = 0; i+1 < n; i++) res1 += max(0, a[i] - a[i+1]);

    int diff = 0;
    for(int i = 0; i+1 < n; i++) diff = max(diff, a[i] - a[i+1]);
    int res2 = 0;
    for(int i = 0; i+1 < n; i++) res2 += min(diff, a[i]);

    return to_string(res1) + " " + to_string(res2);
}

int main(){
    int TEST_CASE; cin >> TEST_CASE;
    for(int i = 1; i <= TEST_CASE; i++){
        cout << "Case #" << i << ": " << solve() << endl;
    }
}


