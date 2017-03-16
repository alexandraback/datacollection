#include <iostream>
#include <cstdio>
#include <string>
#include <cctype>
#include <cmath>
#include <climits>
#include <queue>
#include <utility>
using namespace std;

typedef pair<int, int> ii;

int main() {
    freopen("A-small-attempt0.in.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int cases;
    cin >> cases;
    int senators[26];
    for (int i = 1; i <= cases; i++) {
        priority_queue<ii> q;
        printf("Case #%d:", i);
        int parties, sum = 0;
        cin >> parties;
        for (int j = 0; j < parties; j++) {
            cin >> senators[j];
            sum += senators[j];
            q.push(make_pair(senators[j], j));
        }
        while (!q.empty()) {
            ii p1, p2;
            p1 = q.top(); q.pop();
            if (!q.empty()) {p2 = q.top(); q.pop();}
            else {
                printf(" %c", p1.second + 'A');
                if (p1.first == 2) printf("%c", p1.second + 'A');
                break;
            }
            printf(" %c", p1.second + 'A');
            p1.first--;
            sum--;
            if (p2.first > p1.first && sum % 2 == 1) {
                printf("%c", p2.second + 'A');
                p2.first--;
                sum--;
            } else if (p1.first > 0 && sum % 2 == 1){
                printf("%c", p1.second + 'A');
                p1.first--;
                sum--;
            }
            if (p1.first > 0) q.push(p1);
            if (p2.first > 0) q.push(p2);
        }
        printf("\n");
    }
    return 0;
}
