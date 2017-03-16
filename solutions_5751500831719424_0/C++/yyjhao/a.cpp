#include <string>
#include <iostream>
#include <vector>

using namespace std;

int dp[200][200];
string a, b;
int getCost(int p1, int p2) {
    if (dp[p1][p2] != -1) return dp[p1][p2];
    if (p1 == 0) {
        if (b[p2 - 1] == a[0]) return dp[p1][p2] = getCost(p1, p2 - 1) + 1;
    } else if (p2 == 0) {
        if (a[p1 - 1] == b[0]) return dp[p1][p2] = getCost(p1 - 1, p2) + 1;
    }

    if (a[p1 - 1] == b[p2 - 1]) {
        return dp[p1][p2] = getCost(p1 - 1, p2 - 1);
    }

    int cost = 999;
    if ((p2 > 1 && b[p2 - 1] == b[p2 - 2]) ||
        (p2 < b.size() && b[p2 - 1] == b[p2])) {
        cost = getCost(p1, p2 - 1) + 1;
    }

    if ((p1 > 1 && a[p1 - 2] == a[p1 - 1]) ||
        (p1 < a.size() && a[p1 - 1] == a[p1])) {
        cost = min(cost, getCost(p1 - 1, p2) + 1);
    }

    return dp[p1][p2] = cost;
}

int main() {
    int t;
    cin>>t;
    for(int ca = 0; ca < t; ca++) {
        int n;
        cin>>n;
        cin>>a>>b;
        for (int i = 0; i <= a.size(); i++)for(int j = 0; j <= b.size(); j++) {
            dp[i][j] = -1;
        }
        dp[0][0] = 0;
        cout<<"Case #"<<(ca+1)<<": ";
        int cost = getCost(a.size(), b.size());
        if (cost > 200) {
            cout<<"Fegla Won"<<endl;
        } else {
            cout<<cost<<endl;
        }
    }
    return 0;
}