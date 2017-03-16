#include <set>
#include <map>
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

string path = "/home/nicolai/work/CLionProjects/untitled/";


int main() {
    int N;
    ifstream in(path + "input.txt");
    in.sync_with_stdio(false);
    ofstream out(path + "output.txt");
    in >> N;
    for (int t = 0; t < N; t++) {
        int n;
        in >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            in >> v[i];
        int m = 0;
        for (int i = 0; i < n - 1; i++)
            m = max(m, v[i] - v[i + 1]);
        int s1 = 0, s2 = 0;
        for (int i = 0; i < n - 1; i++) {
            s1 += max(0, v[i] - v[i + 1]);
            s2 += min(v[i], m);
        }
        out << "Case #" << t + 1 << ": " << s1 << ' ' << s2 << endl;
    }
    return 0;
}

