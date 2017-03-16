#include <bits/stdtr1c++.h>
#define FILE "A-small-attempt0"
#define MAXN 105


using namespace std;

int n;

vector<pair<char, int> > a[MAXN];


void create(int index, string s) {
    for(int i = 0; i < s.size(); ++i) {
        int times = 1;
        char c = s[i];
        for(; i + 1 < s.size() && s[i] == s[i + 1]; ++i, ++times);

        a[index].push_back(make_pair(c, times));
    }
}

bool isPossible() {
    int s = a[0].size();
    for(int i = 0; i < n; ++i)
        if(s != a[i].size())
            return false;

    for(int i = 0; i < n; ++i)
        for(int j = i + 1; j < n; ++j)
            for(int u = 0; u < a[i].size(); ++u)
                if(a[i][u].first != a[j][u].first)
                    return false;
    return true;
}

long long compute(){
    long long answer = 0ll;

    for(int i = 0; i < a[0].size(); ++i){
        int mi = INT_MAX, ma = INT_MIN;

        for(int j = 0; j < n; ++j){
            mi = min(mi, a[j][i].second);
            ma = max(ma, a[j][i].second);
        }

        long long curMin = INT_MAX;

        for(int j = mi; j <= ma; ++j){
            long long c = 0;

            for(int u = 0; u < n; ++u)
                c += abs(a[u][i].second - j);

            curMin = min(curMin, c);
        }

        answer += curMin;
    }

    return answer;
}

int main() {
    freopen(FILE".in", "r", stdin);
      freopen(FILE".out", "w", stdout);

    ios_base::sync_with_stdio(false);


    int t;
    cin >> t;

    for(int t1 = 1; t1 <= t; ++t1) {
        for(int i = 0; i < MAXN; ++i)
            a[i].clear();

        cout << "Case #" << t1 << ": ";
        cin >> n;

        for(int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            create(i, s);


        }

        if(!isPossible())
            cout << "Fegla Won\n";
        else{
            cout << compute() << '\n';

        }


    }

}
