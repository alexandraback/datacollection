#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>

using namespace std;

void solve(int testcase);

int main() {
    int N;
    cin >> N;
    for(int i=0; i<N; ++i)
        solve(i+1);
}

size_t method1(std::vector<size_t> &vals) {
    size_t ret = 0;
    size_t last = vals[0];
    for(unsigned i=1; i<vals.size(); ++i) {
        if(vals[i] < last) {
            ret += last-vals[i];
        }
        last = vals[i];
    }
    return ret;
}

size_t method2(std::vector<size_t> &vals) {
    size_t rate = 0;
    size_t ret = 0;
    size_t last = vals[0];
    for(unsigned i=1; i<vals.size(); ++i) {
        if(vals[i] < last) {
            if(last-vals[i] > rate) {
                rate = last-vals[i];
            }
        }
        last = vals[i];
    }
    //rate = 10*ceil (((double)rate) / 10.0);

    last = vals[0];
    for(unsigned i=1; i<vals.size(); ++i) {
        size_t eaten = min(last,rate);
        ret += eaten;
        last = vals[i];
    }
    return ret;
}

void solve(int testcase) {
    size_t numintervals;
    cin >> numintervals;
    vector<size_t> intervals;
    for(unsigned i=0; i<numintervals; ++i) {
        size_t tmp;
        cin >> tmp;
        intervals.push_back(tmp);
    }
    cout << "Case #" << testcase << ": " << method1(intervals) << " " << method2(intervals) << endl;
}
