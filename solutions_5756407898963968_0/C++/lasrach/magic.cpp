/**
 * @author: Ruben S. Andrist
 * @version: 0.1
 * @date: 2014-04-11
 * Contact: lasrach[at]gmail.com
 */

#include <set>
#include <cstdio>
#include <algorithm>
using namespace std;

#define sz(a) int((a).size())
#define all(c) (c).begin(),(c).end()

set<int> read_set() {
    int row = 0, x;
    set<int> numbers;
    scanf(" %d", &row);
    row -= 1;
    for (int i = 0; i<row*4; i++) scanf(" %*d");
    for (int i = row*4; i<row*4+4; i++) {
        scanf(" %d", &x);
        numbers.insert(x);
    }
    for (int i = row*4+4; i<16; i++) scanf(" %*d");
    return numbers;
}

int main() {
    int cases = 0;
    scanf(" %d", &cases);
    for (int caseno = 1; caseno <= cases; caseno++) {
        printf("Case #%d: ", caseno);
        set<int> a = read_set(), b = read_set(), c;
        set_intersection(all(a), all(b), inserter(c, c.end()));
        if (c.size()==0) {
            printf("Volunteer cheated!\n");
        }else if (c.size()==1) {
            printf("%d\n", *c.begin());
        }else {
            printf("Bad magician!\n");
        }
    }
    return 0;
}

// vim: set ff=unix ai tw=80 ts=4 sts=4 sw=4 et:
