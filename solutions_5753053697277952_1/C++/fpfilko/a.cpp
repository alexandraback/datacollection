#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int get_max_size(vector<pair<int, char>> &v) {
    int m = 0;
    int mc = 0;
    for(int i = 0; i<v.size(); i++) {
        if(v[i].first>m) {
            m = v[i].first;
            mc = 1;
        }
        else if(v[i].first == m) {
            mc++;
        }
    }
    return mc;
}

bool nonempty(vector<pair<int, char>> &v) {
    int sum = 0;
    for(int i = 0; i<v.size(); i++) {
        sum += v[i].first;
    }
    return sum != 0;
}

int get_max(vector<pair<int, char>> &v) {
    int m = 0;
    int mi = 0;
    for(int i = 0; i<v.size(); i++) {
        if(v[i].first > m) {
            m = v[i].first;
            mi = i;
        }
    }
    return mi;
}

int main() {
    int T; cin >> T;
    for(int t = 1; t<=T; t++) {
        int n; cin >>n;
        int x;
        vector<pair<int,char>> v;
        for(char i = 0; i<n; i++) {
            cin >> x;
            v.push_back(make_pair(x,i+'A'));
        }
        cout << "Case #" << t << ":";
        while(nonempty(v)) {
            if(get_max_size(v) % 2) {
                int s = get_max(v);
                v[s].first = v[s].first - 1;
                cout << " " << v[s].second;
            }
            else {
                int s = get_max(v);
                v[s].first = v[s].first - 1;
                cout << " " << v[s].second;
                s = get_max(v);
                v[s].first = v[s].first - 1;
                cout << v[s].second;
            }
        }
        cout << "\n";
    }
}
