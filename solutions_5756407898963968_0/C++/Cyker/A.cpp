#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define RANGE(i,b,e) for(int (i)=(b);(i)<(int)(e);(i)++)
#define CRANGE(i,b,e) for(int (i)=(b);(i)<=(int)(e);(i)++)
#define RRANGE(i,b,e) for(int (i)=(b);(i)>=(int)(e);(i)--)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define PI 3.1415926535897932384626433832795
#define INF 0x7FFFFFFF

int T;
int row1, row2;
vector<int> vec1, vec2;

void readline(vector<int> *pvec)
{
    vector<int> vec;
    int k;
    for (int i = 0;i < 4;i++) {
        cin >> k;
        vec.push_back(k);
    }
    if (pvec) {
        *pvec = vec;
    }
}

int main(int argc, char **argv)
{
    cin >> T;
    for (int t = 0;t < T;t++) {
        vec1.clear();
        vec2.clear();

        cin >> row1;
        for (int i = 0;i < row1 - 1;i++) {
            readline(NULL);
        }
        readline(&vec1);
        for (int i = row1;i < 4;i++) {
            readline(NULL);
        }

        cin >> row2;
        for (int i = 0;i < row2 - 1;i++) {
            readline(NULL);
        }
        readline(&vec2);
        for (int i = row2;i < 4;i++) {
            readline(NULL);
        }

        sort(vec1.begin(), vec1.end());
        sort(vec2.begin(), vec2.end());

        int cnt = 0;
        int num = 0;
        for (auto k : vec1) {
            if (find(vec2.begin(), vec2.end(), k) != vec2.end()) {
                num = k;
                cnt++;
            }
        }

        cout << "Case #" << t + 1 << ": ";
        if (cnt == 1) {
            cout << num;
        } else if (cnt == 0) {
            cout << "Volunteer cheated!";
        } else {
            cout << "Bad magician!";
        }
        cout << endl;
    }

    return 0;
}

