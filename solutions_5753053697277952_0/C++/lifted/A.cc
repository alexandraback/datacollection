#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <cassert>
#include <queue>
#include <algorithm>

using namespace std;

bool NoMajority(const vector<int>& counts, const int total) {
    for (int c : counts) {
        if ((c * 2) > total) {
            return false;
        }
    }
    return true;
}

struct OrderByCount {
    vector<int> * counts;
    bool operator()(int i, int j) const {
        return (*counts)[i] < (*counts)[j];
    }
};

vector<string> EvacuationPlan(vector<int> counts) {
    vector<string> plan;

    const int n = counts.size();
    int total = accumulate(counts.begin(), counts.end(), 0);

    OrderByCount cmp = {&counts};
    priority_queue<int, vector<int>, OrderByCount> Q(cmp);

    for (int i = 0; i < n; i++) Q.push(i);

    while (total > 0) {
        int first = Q.top();
        Q.pop();
        int second = Q.top();
        Q.pop();

        // try decrease both
        counts[first]--;
        counts[second]--;

        string term;
        if (NoMajority(counts, total - 2)) {
            term.reserve(2);
            term.push_back('A' + first);
            term.push_back('A' + second);
            total -= 2;
        } else {
            term.reserve(1);
            term.push_back('A' + first);
            counts[second]++;
            total -= 1;

        }
        plan.push_back(term);

        if (counts[first] > 0) Q.push(first);
        if (counts[second] > 0) Q.push(second);
    }

    return plan;
}

void DisplayPlan(ostream& os, const vector<string>& plan) {
    bool first = true;
    for (auto& s : plan) {
        if (first) {
            first = false;
        } else {
            os << " ";
        }
        os << s;
    }
}

int main() {
    int num_tests;
    cin >> num_tests;
    for (int test = 1; test <= num_tests; test++) {
        int num_rooms;
        cin >> num_rooms;
        vector<int> counts(num_rooms);
        for (int r = 0; r < num_rooms; r++) {
            cin >> counts[r];
        }
        cout << "Case #" << test << ": ";
        DisplayPlan(cout, EvacuationPlan(counts));
        cout << "\n";
    }
    return 0;
}
