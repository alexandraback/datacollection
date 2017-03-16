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
        int b, n;
        in >> b >> n;
        vector<int> v(b);
        for (int i = 0; i < b; i++)
            in >> v[i];
        long long l = -1, r = 100000L * 1000000000L + 1;
        while (r - l > 1) {
            long long med = (r + l) / 2;
            long long sm = 0;
            for (int i = 0; i < b; i++)
                sm += med / v[i] + 1;//(med % v[i] ? 0 : 1);
            if (sm >= n)
                r = med;
            else
                l = med;
        }
        long long sm = 0;
        for (int i = 0; i < b; i++)
            sm += r / v[i] + (r % v[i] ? 1 : 0);
        for (int i = 0; i < b; i++)
            if (r % v[i] == 0) {
                sm++;
                if (sm == n) {
                    l = i;
                    break;
                }
            }
        out << "Case #" << t + 1 << ": " << l + 1 << endl;
    }
    return 0;
}

