#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    ifstream input("A-small-attempt0.in");
    ofstream output("small_out.txt");
    int t, n, r, curr, prev, s1, s2, max;
    input >>t;
    for (int i = 0; i < t; ++i) {
        input >>n;
        input >>curr;
        prev = curr;
        r = 0;
        max = 0;
        s1 = 0;
        s2 = 0;
        vector<int> m (1, curr);
        for (int j = 1; j < n; ++j) {
            input >>curr;
            if (curr < prev) {
                s1 += prev - curr;
                max = (prev - curr > max)? prev - curr: max;
            }
            m.push_back(curr);
            prev = curr;
        }
        for (int j = 0; j < n - 1; ++j) {
            if (m[j] >= max) {
                s2 += max;
            } else {
                s2 += m[j];
            }
        }
        output <<"Case #" <<t+1 <<": " <<s1 <<" " <<s2 <<endl;
    }
    output.close();
    input.close();
    return 0;
}


