#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

struct S {
    int num;
    char p;
};

bool operator < (const S& a, const S& b) {
    return a.num > b.num;
}

int main(int argc, char *argv[])
{
    int T = 0;
    cin >> T;

    for (int cas = 1; cas <= T; cas++) {
        int N = 0;
        S s[32];
        memset(s, 0, sizeof(s));

        cin >> N;
        int remain = 0;
        for (int i = 0; i < N; i++) {
            s[i].p = 'A' + i;
            cin >> s[i].num;
            remain += s[i].num;
        }

        cout << "Case #" << cas << ":";
        while (remain > 0) {
            sort(s, s + N);
            /** try first two */
            if (s[0].num > 0 && (s[0].num - 1) * 2 <= remain - 2 &&
                N > 0 && s[1].num > 0 && (s[1].num - 1) * 2 <= remain - 2 &&
                (N <= 2 || s[2].num * 2 <= remain - 2)) {
                s[0].num -= 1;
                s[1].num -= 1;
                remain -= 2;
                cout << " " << s[0].p << s[1].p;
            } else if (s[0].num > 0 && (s[0].num - 1) * 2 <= remain - 1 &&
                       (N <= 1 || s[1].num * 2 <= remain - 1)) {
                s[0].num -= 1;
                remain -= 1;
                cout << " " << s[0].p;
            } else {
                cout << "WTF?";
                break;
            }
        }
        cout << endl;
    }
    return 0;
}

    
