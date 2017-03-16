enum Contest { CodeChef, CodeJam };
enum IOBinding { File, StandartStream };

Contest contest = CodeJam;

IOBinding inputBinding = File;
//IOBinding inputBinding = StandartStream;

IOBinding outputBinding = File;
//IOBinding outputBinding = StandartStream;

#include <algorithm>
#include <cassert>
#include <string>
#include <fstream>
#include <istream>
#include <ostream>
#include <iostream>
#include <vector>

std::istream *input;
std::ostream *output;

typedef long long int int64;
typedef std::vector <int64> IVec;

class Problem {
public:
    Problem();
    ~Problem();
    void solve();

private:
    int64 numGone(int64 time);
    int64 B, N;
    IVec M;
};

Problem::Problem() {
    *input >> B >> N;
    M.resize(B);
    for(int b = 0; b < B; ++b)
        *input >> M[b];
}

Problem::~Problem() {

}

void Problem::solve() {
    int64   minTime = 0,
            maxTime = N * *std::max_element(
                M.begin(), M.end()),
            minGone = numGone(minTime),
            maxGone = numGone(maxTime);

    for(;;) {
        int64 time = (maxTime + minTime) / 2;
        if ((time == minTime) || (time == maxTime)) break;
        int64 gone = numGone(time);
        if (gone < N) {
            minTime = time;
            minGone = gone;
        }
        else if (gone >= N) {
            maxTime = time;
            maxGone = gone;
        }
    }

    while(numGone(minTime) < N) ++minTime;
    int64 gone = numGone(--minTime);
    for(;;) {
        ++minTime;
        for(int b = 0; b < B; ++b) {
            if (minTime % M[b] == 0) {
                if (++gone == N) {
                    *output << b + 1 << '\n';
                    return;
                }
            }
        }
        ++minTime;
    }
}

int64 Problem::numGone(int64 time) {
    if (time < 0) return 0;
    int64 res = 0;
    for(int b = 0; b < B; ++b) {
        res += 1 + time / M[b];
    }
    return res;
}

void solveCase() {
    Problem p;
    p.solve();
}

int main(int argc, char *argv[])
{
    std::ios_base::sync_with_stdio(false);

    if (inputBinding == File)
        input = new std::ifstream("input.txt");
    else input = &std::cin;

    if (outputBinding == File)
        output = new std::ofstream("output.txt");
    else output = &std::cout;

    int T; *input >> T;
    for(int t = 1; t <= T; ++t) {
        if (contest == CodeJam)
            *output << "Case #" << t << ": ";
        solveCase();
    }

    if (inputBinding == File) delete input;
    if (outputBinding == File) delete output;

    return 0;
}
