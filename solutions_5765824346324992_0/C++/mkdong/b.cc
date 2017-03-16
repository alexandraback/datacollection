#include <iostream>
#include <queue>

using namespace std;

int m[2001];

long long gcd(long long a, long long b)
{
    while (1) {
        if (a < b) {
            long long c = a;
            a = b;
            b = c;
        }
        // a > b
        long long r = a % b;
        if (r == 0) return b;
        a = b;
        b = r;
    }
}


struct Node {
    int id;
    long long freetime;
};

bool operator < (const Node &a, const Node &b)
{
    if (a.freetime > b.freetime) return true;
    if (a.freetime < b.freetime) return false;
    if (a.id > b.id) return true;
    return false;
}

int main()
{
    int T;
    cin >> T;
    for (int t=0; t<T; ++t) {
        priority_queue<Node> q;
        int b;
        long long n;
        cin >> b >> n;
        long long lca = 1;
        for (int i=0; i<b; ++i) {
            cin >> m[i];
            int g = gcd(lca, m[i]);
            lca = lca / g * m[i];
            q.push((Node){i,0});
        }
        //cout << lca << endl;
        long long round = 0;
        for (int i=0; i<b; ++i) {
            round += lca / m[i];
        }
        //cout << round << endl;
        n %= round;
        int ans = -1;
        if (n == 0) n = round;
        //cout << "new n: "<< n << endl;
        //cout << q.size() << endl;
        while (n--) {
            Node a = q.top();
            q.pop();
            ans = a.id;
            //cout << "got" << a.id << " " << a.freetime << endl;
            a.freetime += m[a.id];
            q.push(a);
        }
        cout << "Case #" << t+1 << ": " << ans+1 << endl;
    }
    return 0;
}
