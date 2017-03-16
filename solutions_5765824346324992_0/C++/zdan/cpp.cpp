#include <algorithm>
#include <numeric>
#include <cstdint>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;




unsigned int solve(unsigned long long int B, unsigned long long int N, std::vector<pair<unsigned long long int, unsigned int>>& M)
{
    assert(M.size() == B);
    //cout << str << " * " << X << endl;

    //auto comp = [](pair<unsigned int, unsigned int>& a, pair<unsigned int, unsigned int>& b) {
    //    return a.first < b.first;
    //};
    if (N <= B)
    {
        std::sort(M.begin(), M.end());
        return M[N - 1].second;
    }

    auto heap = M;

    double speed = 0;
    for (auto& m : heap)
        speed += 1. / m.first;
    unsigned long long int time_lowbound = N / speed - B;
    for (auto& m : heap)
    {
        unsigned long long int n = time_lowbound / m.first;
        N -= n;
        m.first *= n;
    }

    auto comp = [](pair<unsigned long long int, unsigned int>& a, pair<unsigned long long int, unsigned int>& b) {
        return a > b;
        //if (a.first == b.first)
        //    return a.second < b.second;
        //else
        //    return a.first > b.first;
    };
    std::make_heap(heap.begin(), heap.end(), comp);
    while (N > 1)
    {
        std::pop_heap(heap.begin(), heap.end(), comp);
        heap.back().first += M[heap.back().second - 1].first;
        std::push_heap(heap.begin(), heap.end(), comp);
        N -= 1;
    }

    std::sort_heap(heap.begin(), heap.end(), comp);
    return heap.back().second;
}


int main()
{
    //init_mult_table();

    int T; cin >> T;
    for (int test = 1; test <= T; ++test)
    {
        unsigned long long int N, B; // B fits in int, but N <= 10e9
        cin >> B >> N;
        std::vector<pair<unsigned long long int, unsigned int>> M;
        M.reserve(B);
        for (unsigned int i = 1; i <= B; ++i)
        {
            unsigned long long int m;
            cin >> m;
            M.push_back(make_pair(m, i));
        }

        cout << "Case #" << test << ": "
             << solve(B, N, M) << endl;
    }

    return 0;
}

