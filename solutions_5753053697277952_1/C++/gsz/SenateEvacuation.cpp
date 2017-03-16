#include <cassert>
#include <limits>
#include <memory>
#include <ios>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

typedef int i32;
typedef unsigned int u32;
typedef long long int i64;
typedef unsigned long long int u64;

const string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

string read_solve_case() {
    int N;
    vector<int> P;
    cin >> N;
    int P_sum = 0;
    for (int i = 0; i < N; ++i) {
        int Pi;
        cin >> Pi;
        P_sum += Pi;
        P.push_back(Pi);
    }
    string result;
    while (P_sum > 0) {
        int largest = 0;
        for (int i = 1; i < N; ++i) {
            if (P[i] > P[largest]) {
                largest = i; }
        }
        P[largest] -= 1;
        P_sum -= 1;
        int second = -1;
        for (int i = 0; i < N; ++i) {
            if (P[i] > P_sum / 2) {
                second = i; 
                P[second] -= 1;
                P_sum -= 1;
                break;
            }
        }
        if (second != -1) {
            result += letters[largest];
            result += letters[second];
        } else {
            result += letters[largest];
        }
        result += ' ';
    }
    result.pop_back();
    return result;
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int ci = 1; ci <= T; ++ci) {
        cout << "Case #" << ci << ": " << read_solve_case() << endl;
    }
    return 0;
}

