#include <algorithm>
#include <bitset>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <limits>
#include <list>
#include <numeric>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

struct party {
    size_t count;
    char name;
};

bool operator<(const party &a, const party &b) {
    return a.count < b.count || (a.count == b.count && a.name < b.name);
}

int main(int argc, const char *argv[]) {
    freopen("C_A.in", "r", stdin);
    freopen("C_A.out", "w", stdout);
    size_t t = 0;
    scanf("%zd", &t);
    for (size_t i = 1; i <= t; ++i) {
        printf("Case #%zd:", i);
        size_t n, total_size = 0;
        scanf("%zd", &n);
        priority_queue<party> ps;
        for (size_t j = 0; j < n; ++j) {
            party p;
            p.name = 'A' + j;
            scanf("%zd", &p.count);
            ps.push(p);
            total_size += p.count;
        }
        if (total_size % 2 == 1) {
            auto p = ps.top();
            ps.pop();
            printf(" %c", p.name);
            --p.count;
            if (p.count > 0) {
                ps.push(p);
            }
        }
        while (!ps.empty()) {
            auto p1 = ps.top();
            ps.pop();
            printf(" %c", p1.name);
            --p1.count;
            if (p1.count > 0) {
                ps.push(p1);
            }
            auto p2 = ps.top();
            ps.pop();
            printf("%c", p2.name);
            --p2.count;
            if (p2.count > 0) {
                ps.push(p2);
            }
        }
        printf("\n");
    }
    return EXIT_SUCCESS;
}