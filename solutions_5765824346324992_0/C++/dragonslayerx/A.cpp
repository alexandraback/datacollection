 //You are weak? Why? Because You lack Hatred. - Itachi
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <queue>
using namespace std;

#define MAX 200500
#define MOD 1000000007
#define INF 1e9

int main()
{
    freopen("B-small-attempt1.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cout << "Case #"<< t << ": ";
        int B, N;
        cin >> B >> N;
        vector<pair<int, int> > m(B);
        for (int i = 0; i < B; i++) {
            cin >> m[i].first;
            m[i].second = i;
        }
        int lcm = m[0].first;
        for (int i = 1; i < B; i++){
            lcm = (lcm * m[i].first) / __gcd(lcm, m[i].first);
        }
        int total = 0;
        for (int i = 0; i < B; i++) {
            total += lcm/m[i].first;
        }
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > Q;
        for (int i = 0; i < B; i++) {
            Q.push(make_pair(0, i));
        }
        vector<int> ids;
        for (int i = 0; i < total; i++) {
            pair<int, int> top = Q.top();
            Q.pop();
            int time = top.first;
            int id = top.second;
            ids.push_back(id);
            Q.push(make_pair(top.first + m[id].first, id));
        }

        N--;
        cout << ids[N % total] + 1 << endl;
    }
}
