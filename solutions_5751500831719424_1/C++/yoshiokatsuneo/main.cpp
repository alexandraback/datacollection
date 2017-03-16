//
//  main.cpp
//  googlecodejam
//
//  Created by Yoshioka Tsuneo on 4/12/14.
//  Copyright (c) 2014 Yoshioka Tsuneo. All rights reserved.
//

#include <fstream>
#include <iostream>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <numeric>
#include <algorithm>
#include <sstream>
#include <queue>
#include <stdexcept>

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cassert>
#include <unistd.h>
#include <string.h>

#include <stack>

#include <thread>

#define decltype(X) __typeof(X)
#define REP(i, n) for(int i=0; i<(int)n; i++)
#define FOR(it, c) for(decltype((c).begin()) it = (c).begin(); it!=(c).end(); it++)
#define ALL(c) (c).begin(), (c).end()

#define EPS 0.000001
using namespace std;

typedef long long ll;

#include <mutex>
#include <condition_variable>
using namespace std;

class semaphore{
private:
    mutex mtx;
    condition_variable cv;
    int count;
    
public:
    semaphore(int count_ = 0):count(count_){;}
    void notify()
    {
        unique_lock<mutex> lck(mtx);
        ++count;
        cv.notify_one();
    }
    void wait()
    {
        unique_lock<mutex> lck(mtx);
        
        while(count == 0){
            cv.wait(lck);
        }
        count--;
    }
};

vector< vector<int> > memo(1000, vector<int>(1000, -1));

int dfs(int root, int prev,  vector< vector<int> > &G, int N)
{
    if(prev != -1 && memo[root][prev] != -1){
        return memo[root][prev];
    }
    if(G[root].size()==1 || G[root].size()==3){
        return 0;
    }
    
    if(G[root].size()==2){
        if(G[root][0] == prev){
            return (memo[G[root][1]][root] = dfs(G[root][1], root, G, N));
        }else{
            return (memo[G[root][0]][root] = dfs(G[root][0], root, G, N));
        }
    }
    int total = 0;
    for(int i=0;i<G[root].size();i++){
        if(G[root][i] == prev){
            continue;
        }
        total += dfs(G[root][i], root, G, N);
    }

    int result = INT_MAX;
    for(int i=0;i<G[root].size();i++){
        if(G[root][i] == prev){
            continue;
        }
        for(int j=0;j<G[root].size();j++){
            if(G[root][j]==prev){
                continue;
            }
            int ret2 = total - dfs(G[root][i], root, G, N) - dfs(G[root][j], root, G, N);
            result = min(result, ret2);
        }
    }
    return result;
    
}


int testcase_itr(vector<string> strs)
{
    int N = (int)strs.size();
    vector<int> pos(N);
    int total_diff = 0;
    while(true){
        if(pos[0] == strs[0].size()){
            break;
        }
        int c = strs[0][pos[0]];
        
        vector<int> cnums(N);
        for(int i=0;i<N;i++){
            while(pos[i] < strs[i].size() && strs[i][pos[i]]==c){
                pos[i]++;
                cnums[i]++;
            }
            if(cnums[i] == 0){
                return -1;
            }
        }
        int cnum_sum = accumulate(cnums.begin(), cnums.end(), 0);
        double avg_cnum = (double)cnum_sum/(double)N;
        int avg_cnum_i = 0;
        if(avg_cnum - (int)(avg_cnum+0.000001) <=0.5){
            avg_cnum_i = (int)(avg_cnum+0.000001);
        }else{
            avg_cnum_i = (int)(avg_cnum+0.000001)+1;
        }
        // printf("avg_cnum = %lf, avg_cnum_i =%d\n", avg_cnum, avg_cnum_i);
        for(int i=0;i<cnums.size();i++){
            int cnum = cnums[i];
            int diff = abs(cnum - avg_cnum_i);
            total_diff += diff;
           // printf("cnums[%d]=%d, diff=%d, total_diff=%d\n", i, cnums[i], diff, total_diff);
        }
    }
    for(int i=0;i<N;i++){
        if(pos[i]!=strs[i].size()){
            return -1;
        }
    }
    
    return total_diff;
}


int  testcase(istream &in, int t)
{
    int N;
    in >> N;
    vector<string> strs;
    for(int i=0;i<N;i++){
        string str;
        in >> str;
        strs.push_back(str);
    }
    return testcase_itr(strs);
}


// #define MULTI_THREAD

#ifdef MULTI_THREAD
semaphore sem(6);
vector< pair<bool, double> > g_results;

void testcase_for_multithread(int t, double C, double F, double X)
{
    g_results[t].second = testcase_itr(C, F, X);
    g_results[t].first = true;
    // sleep(rand()/(RAND_MAX/3.0));
    sem.notify();
}
#endif

int main(int argc, const char * argv[])
{
    // sleep(1000);
    // insert code here...
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(15);
    string fname = "/dev/stdin";
    if(argc>=2){
        fname = argv[1];
    }
    ifstream in(fname);
    if(!in){
        cout << "File open error:" << fname << endl;
        exit(1);
    }
    int T;
    in >> T;
    
#ifndef MULTI_THREAD
    for(int t=0;t<T;t++){
        auto result = testcase(in, t);
        if(result == -1){
            cout << "Case #" << t+1 << ": " << "Fegla Won" << endl;
        }else{
            cout << "Case #" << t+1 << ": " << result << endl;
        }
        
    }
#else
    vector<thread> threads;
    g_results.resize(T);
    int cur_result = 0;
    for(int t=0;t<T;t++){
        sem.wait();
        while(g_results[cur_result].first == true){
            cout << "Case #" << cur_result+1 << ": " << g_results[cur_result].second << endl;
            cur_result++;
        }
        double C, F, X;
        
        in >> C >> F >> X;
        
        // thread th(testcase_for_multithread, t, C, F, X );
        threads.push_back(thread(testcase_for_multithread, t, C, F, X ));
    }
    while(cur_result<T){
        sem.wait();
        while(g_results[cur_result].first == true){
            cout << "Case #" << cur_result+1 << ": " << g_results[cur_result].second << endl;
            cur_result ++;
        }
    }
    for(int t=0;t<T;t++){
        threads[t].join();
    }
#endif
    // std::cout << "Hello, World!\n";
    return 0;
}


