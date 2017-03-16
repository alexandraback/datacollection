#include <fstream>
#include <vector>

using namespace std;

const int N = 4;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    int testCount;
    in >> testCount;
    for (int t = 1; t <= testCount; ++t) {
        vector< vector<int> > cards = vector< vector<int> >(N, vector<int>(N));
        vector<bool> first = vector<bool>(N * N, false), second = vector<bool>(N * N, false);
        int r;
        in >> r;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                in >> cards[i][j];
        for (int j = 0; j < N; ++j)
            first[cards[r - 1][j] - 1] = true;
        in >> r;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                in >> cards[i][j];
        for (int j = 0; j < N; ++j)
            second[cards[r - 1][j] - 1] = true;
        int count = 0, last = -1;
        for (int v = 0; v < N * N; ++v) {
            if (first[v] && second[v]) {
                ++count;
                last = v;
            }
        }
        out << "Case #" << t << ": ";
        if (count == 0) {
            out << "Volunteer cheated!\n";
        } else if (count > 1) {
            out << "Bad magician!\n";
        } else {
            out << last + 1 << "\n";
        }
    }
    in.close();
    out.close();
    return 0;
}
