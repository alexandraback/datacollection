#include <iostream>
#include <iostream>
#include <queue>
#include <map>
using namespace std;
int gcd(int m, int n) {
    if (m < n) {
        int t = m;
        m = n;
        n = t;
    }
    while(n != 0) {
        int c = m % n;
        m = n;
        n = c;
    }
    return m;
}
int lcm(int m, int n) {
    return m * n / gcd(m, n);
}
int main() {
    int ncase;
    cin >> ncase;
    for (int nc = 1; nc <= ncase; nc++) {
        priority_queue< pair<int,int>, vector< pair<int, int> >, greater<pair<int,int> > >pq;
        vector<int> bt;
        int nb = 0, no = 0, llcm = 1, sum = 0;
        cin >> nb >> no;
        for (int i = 0; i < nb; i++) {
            int tmp;
            cin >> tmp;
            llcm = lcm(llcm, tmp);
            bt.push_back(tmp);
            pq.push(make_pair(0, i)); 
        }
        for (int i = 0; i < bt.size(); i++) {
            sum += llcm / bt[i];
        }
        /*
        while (!pq.empty()) {
            cout << pq.top().first << " " << pq.top().second << endl;
            pq.pop();
        }
        */
        int ans = 0;
        int up = (no - 1) % sum;
        for (int i = 0; i <= up; i++) {
            auto currb = pq.top();
            //cout << pq.top().first << " " << pq.top().second << endl;
            pq.pop();
            ans = currb.second;
            //cout << ans << endl;
            pq.push(make_pair(currb.first + bt[ans], ans));
        }
        cout << "Case #" << nc << ": " << ans + 1 << endl;
    } 
    return 0;
}
