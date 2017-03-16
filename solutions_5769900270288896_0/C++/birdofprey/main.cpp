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
#include <algorithm>
#include <vector>

std::istream *input;
std::ostream *output;

typedef std::vector <int> IVec;

class Problem {
public:
    Problem();
    ~Problem();
    void solve();
    bool improve();
    void incCost(int r, int c);
    void decCost(int r, int c);
    void add(int r, int c);
    void rem(int r, int c);
    int R, C, N;
    bool **map;
    int **cost;
    int freeCost[5], busyCost[5];
};

bool Problem::improve() {
    int minFreeCost = 4;
    int maxBusyCost = 0;
    for(int i = 0; i < 5; ++i)
        if(busyCost[i]) maxBusyCost = i;
    for(int i = 4; i >= 0; --i)
        if(freeCost[i]) minFreeCost = i;

    if (minFreeCost >= maxBusyCost) return false;

    int rF = -1, cF, rB = -1, cB;
    for(int r = 0; r < R; ++r) {
        for(int c = 0; c < C; ++c) {
            if (map[r][c] && (cost[r][c] == maxBusyCost)) {
                rB = r; cB = c;
                if (rF >= 0) {
                    c = C;
                    r = R;
                    break;
                }
            }
            else if (!map[r][c] && (cost[r][c] == minFreeCost)) {
                rF = r; cF = c;
                if (cF >= 0) {
                    c = C;
                    r = R;
                    break;
                }
            }
        }
    }

    rem(rB, cB);
    add(rF, cF);

    return true;
}



void Problem::incCost(int r, int c) {
    if ((r < 0) || (c < 0) || (r >= R) || (c >= C)) return;
    if (map[r][c]) {
        --busyCost[cost[r][c]];
        ++cost[r][c];
        ++busyCost[cost[r][c]];
    }
    else {
        --freeCost[cost[r][c]];
        ++cost[r][c];
        ++freeCost[cost[r][c]];
    }
}

void Problem::decCost(int r, int c) {
    if ((r < 0) || (c < 0) || (r >= R) || (c >= C)) return;
    if (map[r][c]) {
        --busyCost[cost[r][c]];
        --cost[r][c];
        ++busyCost[cost[r][c]];
    }
    else {
        --freeCost[cost[r][c]];
        --cost[r][c];
        ++freeCost[cost[r][c]];
    }
}

void Problem::add(int r, int c) {
    int t = cost[r][c];
    --freeCost[cost[r][c]];
    ++busyCost[cost[r][c]];
    map[r][c] = true;
    incCost(r-1, c);
    incCost(r+1, c);
    incCost(r, c-1);
    incCost(r, c+1);
}

void Problem::rem(int r, int c) {
    --busyCost[cost[r][c]];
    ++freeCost[cost[r][c]];
    map[r][c] = false;
    decCost(r-1, c);
    decCost(r+1, c);
    decCost(r, c-1);
    decCost(r, c+1);
}

Problem::Problem() {
    *input >> R >> C >> N;
    map = new bool* [R];
    cost = new int* [R];
    for(int r = 0; r < R; ++r) {
        map[r] = new bool [C];
        cost[r] = new int [C];
        memset(map[r], 0, C * sizeof(bool));
        memset(cost[r], 0, C * sizeof(int));
    }
    memset(freeCost, 0, 5 * sizeof(int));
    memset(busyCost, 0, 5 * sizeof(int));
    freeCost[0] = R * C;
}

Problem::~Problem() {
    for(int r = 0; r < R; ++r) {
        delete[] map[r];
        delete[] cost[r];
    }
    delete[] map;
    delete[] cost;
}

void Problem::solve() {
    for(int r = 0; r < R; ++r) {
        for(int c = 0; c < C; ++c) {
            if (!N) break;
            add(r, c);
            --N;
        }
        if (!N) break;
    }

    while(improve()) {
        // DO NOTHING: ALL IS DONE INSIDE "improve"
    }

    int res = 0;
    for (int i = 1; i < 5; ++i) {
        res += i * busyCost[i];
    }
    *output << res / 2 << '\n';

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
