#include <iostream>
#include <stdio.h>
#include <set>

using namespace std;

int t, x, allcnt, n;

struct party {
    int id, cnt;
    party(int id, int cnt): id(id), cnt(cnt) {}

};
bool operator<(const party &left, const party &right) {
    return left.cnt > right.cnt || (left.cnt == right.cnt && left.id < right.id);
}

set<party> s;


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        allcnt = 0;
        scanf("%d", &n);
        for (int j = 0; j < n; ++j) {
            scanf("%d", &x);
            allcnt += x;
            s.insert(party(j, x));
        }
        printf("CASE #%d:", i + 1);
        while (s.size() > 0) {
            if (s.size() == 1) {
                printf(" %c", 'A' + s.begin()->id);
                s.erase(s.begin());
            } else if (s.size() == 2 && s.begin()->cnt * 2 == allcnt) {
                party first = *s.begin();
                s.erase(first);
                party second = *s.begin();
                s.erase(second);
                --first.cnt;
                --second.cnt;
                allcnt -= 2;
                printf(" %c%c", 'A' + first.id, 'A' + second.id);
                if (first.cnt > 0) {
                    s.insert(first);
                    s.insert(second);
                }
            } else {
                party first = *s.begin();
                s.erase(first);
                --first.cnt;
                --allcnt;
                printf(" %c", 'A' + first.id);
                if (first.cnt > 0) {
                    s.insert(first);
                }
            }
        }
        printf("\n");
    }
}
