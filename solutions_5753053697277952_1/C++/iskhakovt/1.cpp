#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

string ntos(int n) {
    return string(1, 'A' + n);
}

vector<string> solve() {
    vector<string> ret;
    
    int n;
    cin >> n;
    
    long long sum = 0;
    vector<int> p(n);
    for (int &elem : p) {
        cin >> elem;
        sum += elem;
    }
    
    priority_queue<pair<int, int>> queue;
    for (int i = 0; i != n; ++i) {
        queue.push({p[i], i});
    }
    
    if (sum % 2) {
        int num = queue.top().second;
        ret.push_back(ntos(num));
        p[num] -= 1;
        queue.pop();
        queue.push({p[num], num});
    }
    
    while (queue.top().first) {
        int num1 = queue.top().second;
        p[num1] -= 1;
        queue.pop();
        queue.push({p[num1], num1});
        int num2 = queue.top().second;
        p[num2] -= 1;
        queue.pop();
        queue.push({p[num2], num2});
        
        ret.push_back(ntos(num1) + ntos(num2));
    }
    
    return ret;
}

void print(vector<string> const &vs) {
    for (int i = 0; i != vs.size(); ++i) {
        cout << vs[i];
        if (i != vs.size() - 1) cout << ' ';
    }
}

int main() {
    int tests;
    cin >> tests;
    
    for (int test = 0; test != tests; ++test) {
        cout << "Case #" << test + 1 << ": ";
        print(solve());
        cout << '\n';
    }
    
    return 0;
}