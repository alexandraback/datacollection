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
    int ans[3010];
    int cnt;
    void PrintToStdout(int index) {
        printf("Case #%d:\n", (int)(index + 1));
        for (int i = 0; i < cnt; ++i) {
                printf("%d\n", ans[i]);
        }
    }
};

struct point {
    ll x, y;

    point() 
        : x(0)
        , y(0)
    {}

    point(ll x, ll y)
        : x(x)
        , y(y)
    {}

    point operator - (const point & other) {
        return point(x - other.x, y - other.y);
    }

    ll operator % (const point & other) {
        return x*other.y - y*other.x;
    }

    void scan() {
        scanf("%lld %lld", &x, &y);
    }
};

struct TInput {
    int N;
    point P[3010];

    void ReadFromStdin() {
        scanf("%d", &N);
        for (int i = 0; i < N; ++i) {
            P[i].scan();
        }
    }

    void Run(TResult& result) {
        result.cnt = N;
        for (int i = 0; i < N; ++i) {
            result.ans[i] = N;
        }
        if (N == 1) {
            result.ans[0] = 0;
            return;
        }
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                int cnt1 = 0;
                int cnt2 = 0;
                for (int k = 0; k < N; ++k) {
                    ll v = (P[k] - P[i]) % (P[j] - P[i]);
                    if (v < 0)
                        ++cnt1;
                    if (v > 0)
                        ++cnt2;
                }
                int ans = min(cnt1, cnt2);
                result.ans[i] = min(result.ans[i], ans);
                result.ans[j] = min(result.ans[j], ans);
            }
        }
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
    jobQueue.Run(15);
    return 0;
}
