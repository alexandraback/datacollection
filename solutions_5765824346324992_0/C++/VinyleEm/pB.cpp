#include <iostream>
#include <vector>
#include <string>

using namespace std;

long long numSlots(const vector<int>& B, long long T)
{
    long long ret = 0;
    for (auto b : B) {
        ret += T / b + 1;
    }

    return ret;
}

long long getMinTime(vector<int>& B, int N)
{
    long long lo = 0, hi = 1LL<<45;
    for (;hi - lo > 1;) {
        long long md = (lo + hi) / 2;
        if (numSlots(B, md) < N)
            lo = md + 1;
        else hi = md;
    }

    if (numSlots(B, lo) >= N)
        return lo;
    return hi;
}

long long numServed(vector<int>& B, long long T)
{
    if (T < 0)
        return 0;
    long long ret = 0;
    for (auto b : B)
        ret += 1 + T / b;
    return ret;
}

int main(int argc, char **argv)
{
    int T;
    cin >> T;

    for (int t = 1;t <= T; t++) {
        int B, N;
        cin >> B >> N;

        vector<int> M(B);
        for (auto& m : M)
            cin >> m;

        long long minTime = getMinTime(M, N);
        long long numClients = numServed(M, minTime - 1);
        vector<int> ret;
        for (int i = 0;i < B; ++i)
            if (minTime % M[i] == 0)
                ret.push_back(i + 1);

        cout << "Case #" << t << ": " << ret[N - numClients - 1] << endl;
    }

    return 0;
}
