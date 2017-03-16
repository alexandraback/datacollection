#include <fstream>

using namespace std;

int solve0(int r, int c, int n) {
    int ans = (r - 1) * c + (c - 1) * r, cnt = ((r - 2) * (c - 2) + 1) / 2;
    if(n <= cnt)
        return ans - 4 * n;
    ans -= 4 * cnt;
    n -= cnt;
    cnt = (r * c + 1) / 2 - cnt;
    if((r * c) & 1)
        cnt -= 4;
    else
        cnt -= 2;
    if(n <= cnt)
        return ans - 3 * n;
    ans -= 3 * cnt;
    n -= cnt;
    return ans - 2 * n;
}

int solve1(int r, int c, int n) {
    int ans = (r - 1) * c + (c - 1) * r, cnt = ((r - 2) * (c - 2)) / 2;
    if(n <= cnt)
        return ans - 4 * n;
    ans -= 4 * cnt;
    n -= cnt;
    cnt = (r * c) / 2 - cnt;
    if(!((r * c) & 1))
        cnt -= 2;
    if(n <= cnt)
        return ans - 3 * n;
    ans -= 3 * cnt;
    n -= cnt;
    return ans - 2 * n;
}

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    int t;
    in >> t;
    for(int tt = 0; tt < t; tt++) {
        int r, c, n;
        in >> r >> c >> n;
        out << "Case #" << tt + 1 << ": ";
        if(n <= (r * c + 1) / 2) {
            out << 0 << '\n';
            continue;
        }
        if(r == 1) {
            if(c & 1)
                out << (n - (c + 1) / 2) * 2 << '\n';
            else
                out << (n - (c + 1) / 2) * 2 - 1 << '\n';
            continue;
        }
        if(c == 1) {
            if(r & 1)
                out << (n - (r + 1) / 2) * 2 << '\n';
            else
                out << (n - (r + 1) / 2) * 2 - 1 << '\n';
            continue;
        }
        n = r * c - n;
        int ans0 = solve0(r, c, n), ans1 = solve1(r, c, n);
        out << min(ans0, ans1) << '\n';
    }
    return 0;
}
