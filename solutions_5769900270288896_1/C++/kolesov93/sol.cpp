#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <thread>
#include <mutex>

using namespace std;
std::mutex output_lock;

bool check(int x1, int y1, int x2, int y2) {
    if (x1 == x2) return min(y1, y2) + 1 == max(y1, y2);
    if (y1 == y2) return min(x1, x2) + 1 == max(x1, x2);
    return false;
}

int do1(int r, int c, int n) {
    int lim = (r * c + 1) / 2;
    int ans = 4 * n;
    if (n <= lim) {
        return 0;
    }

    vector<int> costs(5);
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            if ((i + j) & 1) {
                int cost = 0;
                if (i - 1 >= 0) ++cost;
                if (i + 1 < r) ++cost;
                if (j - 1 >= 0) ++cost;
                if (j + 1 < c) ++cost;
                costs[cost]++;
            }

    ans = 0;
    n -= lim;
    int pointer = 0;
    while (n--) {
        if (costs[pointer] == 0) {
            ++pointer;
            ++n;
            continue;
        }
        --costs[pointer];
        ans += pointer;
    }
    return ans;
}

int do2(int r, int c, int n) {
    int lim = (r * c) / 2;
    int ans = 4 * n;
    if (n <= lim) {
        return 0;
    }

    vector<int> costs(5);
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            if (!((i + j) & 1)) {
                int cost = 0;
                if (i - 1 >= 0) ++cost;
                if (i + 1 < r) ++cost;
                if (j - 1 >= 0) ++cost;
                if (j + 1 < c) ++cost;
                costs[cost]++;
            }

    ans = 0;
    n -= lim;
    int pointer = 0;
    while (n--) {
        if (costs[pointer] == 0) {
            ++pointer;
            ++n;
            continue;
        }
        --costs[pointer];
        ans += pointer;
    }
    return ans;
}

class TSolver {
private:
    int r, c, n;
    int ans;

private:
    void doInputData() {
        cin >> r >> c >> n;
    }

    void doSolve() {
        ans = min(do1(r, c, n), do2(r, c, n));
    }

    void doOuptutData() {
        cout << ans << endl;
    }

public:
    void inputData() {
        doInputData();
        {
            std::lock_guard<std::mutex> lock(output_lock);
            cerr << "[#" << testNo << "]: input data finished\n";
        }
    }

    void solve() {
        doSolve();
        {
            std::lock_guard<std::mutex> lock(output_lock);
            cerr << "[#" << testNo << "]: solving finished\n";
        }
    }

    void outputData() {
        printf("Case #%d: ", testNo);
        doOuptutData();
    }

    void setTestNo(int number) {
        testNo = number;
    }
private:
    int testNo;
};

vector<TSolver> solvers;
queue<int> unsolved;
std::mutex queue_lock;

void worker() {
    while (true) {
        int testNo = -1;
        {
            std::lock_guard<std::mutex> lock(queue_lock);
            if (unsolved.empty()) {
                return;
            }
            testNo = unsolved.front();
            unsolved.pop();
        }
        solvers[testNo].solve();

    }
}

int main() {
    int T;
    scanf("%d\n", &T);

    solvers.resize(T);
    for (int i = 0; i < T; ++i) {
        solvers[i].setTestNo(i + 1);
        solvers[i].inputData();
        unsolved.push(i);
    }

#ifdef DEBUG
    const size_t THREAD_COUNT = 1;
#else
    const size_t THREAD_COUNT = 4;
#endif
    std::vector<std::thread> workers;
    for (size_t i = 0; i < THREAD_COUNT; ++i) {
        workers.emplace_back(worker);
    }
    for (auto& worker : workers) {
        worker.join();
    }

    for (auto& solver : solvers) {
        solver.outputData();
    }

    return 0;
}

