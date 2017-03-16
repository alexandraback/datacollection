#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int N;
string S[101];
int cnt[101][101];
int tot;
string possible (int j) {
    string s = "";
    int cur=-1;
    for (int i=0;i<S[j].size();++i) {
        if (i==0 || S[j][i-1]!=S[j][i]) s += S[j][i],++cur;
        ++cnt[j][cur];
    }
    tot=cur;
    return s;
}

int main () {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T;
    cin >> T;
    for (int z=1;z<=T;++z) {
    cin >> N;
    for (int i=1;i<=N;++i) {
        cin >> S[i];
        for (int j=0;j<S[i].size();++j) cnt[i][j]=0;
    }
    string g = possible(1);
    bool ok=1;
    for (int i=2;i<=N;++i) {
        string t = possible(i);
        if (t!=g) {
            ok=0;
            break;
        }
    }
    cout << "Case #" << z << ": ";
    if (ok) {
        int ans=0;
        for (int i=0;i<=tot;++i) {
            vector<int> v;
            for (int j=1;j<=N;++j) {
                v.push_back(cnt[j][i]);
            }
            sort(v.begin(),v.end());
            int x=v.size()/2;
            for (int j=0;j<v.size();++j) {
                ans+=abs(v[j]-v[x]);
            }
        }
        cout << ans << "\n";
    }
    else cout << "Fegla Won\n";
}
    return 0;
}
