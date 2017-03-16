enum Contest { CodeChef, CodeJam };
enum IOBinding { File, StandartStream };

Contest contest = CodeJam;

IOBinding inputBinding = File;
//IOBinding inputBinding = StandartStream;

IOBinding outputBinding = File;
//IOBinding outputBinding = StandartStream;

#include <string>
#include <fstream>
#include <istream>
#include <ostream>
#include <iostream>

std::istream *input;
std::ostream *output;

void solveCase() {
    int N, *M; *input >> N;
    M = new int [N];
    for(int n = 0; n < N; ++n) *input >> M[n];

    int res1 = 0, res2 = 0;
    for(int n = 1; n < N; ++n) {
        if (M[n] < M[n-1]) res1 += M[n-1] - M[n];
    }

    int rate = 0;
    for(int n = 1; n < N; ++n) {
        if (M[n] < M[n-1]) {
            if (M[n-1] - M[n] > rate)
                rate = M[n-1] - M[n];
        }
    }

    for(int n = 0; n < N - 1; ++n) {
        if (rate <= M[n]) res2 += rate;
        else res2 += M[n];
    }

    *output << res1 << ' ' << res2 << '\n';

    delete[] M;
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
