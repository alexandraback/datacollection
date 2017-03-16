#define _CRT_SECURE_NO_WARNINGS

#include <thread>
#include <condition_variable>
#include <mutex>

#include <memory>

#include <vector>
#include <queue>

#include <cstdio>

#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>
#include <iostream>
#include <assert.h>
using namespace std;

#pragma comment(linker, "/STACK:167772160")

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 1e9;
const double EPS = 1e-9;
const double PI = acos(-1.);



struct TResult {
    ll ans1, ans2;
    void PrintToStdout(int index) {
        printf("Case #%d: %lld %lld\n", (int)(index + 1), ans1, ans2);
    }
};

struct TInput {
    int N;
    vector<int> vals;
    void ReadFromStdin() {
        scanf("%d", &N);
        for (int i = 0; i < N; ++i) {
            int t;
            scanf("%d", &t);
            vals.push_back(t);
        }
    }

    void Run(TResult& result) {
        int ans1 = 0;
        int ans2 = 0;
        int mxd = 0;
        for (int i = 1; i < N; ++i) {
            if (vals[i] < vals[i - 1]) {
                ans1 += vals[i - 1] - vals[i];
                mxd = max(mxd, vals[i - 1] - vals[i]);
            }
        }
        for (int i = 0; i + 1 < N; ++i) {
            ans2 += min(vals[i], mxd);
        }
        result.ans1 = ans1;
        result.ans2 = ans2;
    }
};

typedef shared_ptr<TResult> TResultPtr;
typedef shared_ptr<TInput> TInputPtr;

class TResultQueue {
    struct TResultQueueItem {
        TResultPtr Result;
        size_t Index;

        TResultQueueItem(const TResultPtr& result, size_t index)
            : Result(result)
            , Index(index)
        {
        }

        bool operator < (const TResultQueueItem& other) const {
            return Index > other.Index;
        }
    };

    size_t NextIndex;
    priority_queue<TResultQueueItem> ResultQueue;
    mutex Sync;

public:
    TResultQueue()
        : NextIndex(0)
    {}

    void Push(TResultPtr result, size_t index) {
        lock_guard<mutex> g(Sync);
        ResultQueue.push(TResultQueueItem(result, index));
        while (ResultQueue.size() > 0 && ResultQueue.top().Index == NextIndex) {
            TResultQueueItem item = ResultQueue.top();
            item.Result->PrintToStdout(item.Index);
            ++NextIndex;
            ResultQueue.pop();
            if ((NextIndex >= 10000 && NextIndex % 100 == 0) || (NextIndex < 10000 && NextIndex >= 1000 && NextIndex % 10 == 0) || (NextIndex < 1000)) {
                cerr << "\r" << NextIndex << "     ";
            }
        }
    }
};

class TJobQueue {
    typedef pair<TInputPtr, size_t> TInputQueueItem;
    queue<TInputQueueItem> InputQueue;
    bool IsRunning;
    size_t JobIndex;

    typedef shared_ptr<thread> TThreadPtr;
    vector<TThreadPtr> Threads;

    mutex Sync;

    TResultQueue ResultQueue;

    void operator() () {
        TInputQueueItem job;
        while (GetNewJob(job)) {
            TResultPtr result(new TResult);
            job.first.get()->Run(*result.get());
            ResultQueue.Push(result, job.second);
        }
    }

    bool GetNewJob(TInputQueueItem& resJob) {
        lock_guard<mutex> g(Sync);
        if (InputQueue.empty())
            return false;
        resJob = InputQueue.front();
        InputQueue.pop();
        return true;
    }

public:
    TJobQueue()
        : IsRunning(false)
        , JobIndex(0)
    {
    }

    void Push(TInputPtr input) {
        assert(!IsRunning);
        InputQueue.push(make_pair(input, JobIndex));
        ++JobIndex;
    }

    void Run(size_t numThreads) {
        IsRunning = true;
        if (numThreads == 1) {
            (*this)();
            return;
        }
        for (size_t i = 0; i < numThreads; ++i) {
            Threads.push_back(TThreadPtr(new thread(&TJobQueue::operator(), this)));
        }
        for (const auto& t : Threads) {
            t->join();
        }
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    TJobQueue jobQueue;
    for (int i = 0; i < T; ++i) {
        TInputPtr in(new TInput);
        in->ReadFromStdin();
        jobQueue.Push(in);
    }
    jobQueue.Run(8);
    return 0;
}
