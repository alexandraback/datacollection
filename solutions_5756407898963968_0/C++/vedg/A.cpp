//#define ONLINE_JUDGE

#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <set>
#include <map>
#include <list>
#include <limits>
#include <queue>
#include <stdexcept>
# include <array>

using namespace std;

struct Test {
    int ans;
    typedef std::array<int, 4> Row;
    std::array<Row, 4> cards;

    void read() {
        cin >> ans;
        for (size_t i = 0; i < cards.size(); ++i) {
            for (size_t j = 0; j < cards[i].size(); ++j)
                cin >> cards[i][j];
        }
    }

    const Row & selectedRow() const {
        return cards[ans - 1];
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("cin", "r", stdin);

    freopen("small.out", "w", stdout);
#endif

    int cases;
    cin >> cases;
    for (int cas = 1; cas <= cases; ++cas) {
        std::array<Test, 2> tests;
        for (size_t i = 0; i < tests.size(); ++i)
            tests[i].read();

        std::vector<int> candidates(tests[0].selectedRow().begin(),
                                    tests[0].selectedRow().end());
        {
            const Test::Row & r = tests[1].selectedRow();
            candidates.erase(
                std::remove_if(candidates.begin(), candidates.end(),
            [& r](int card) {
                return std::find(r.begin(), r.end(), card) == r.end();
            }),
                candidates.end());
        }


        cout << "Case #" << cas << ": ";
        if (candidates.empty())
            std::cout << "Volunteer cheated!";
        else if (candidates.size() == 1)
            std::cout << candidates.back();
        else
            std::cout << "Bad magician!";
        std::cout << endl;
    }


#ifndef ONLINE_JUDGE
    fclose(stdin);
    //putchar('\n');
#endif
}
