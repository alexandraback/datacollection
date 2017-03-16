//
//  main.cpp
//  codejam
//
//  Created by fq_bright on 10/4/15.
//  Copyright (c) 2015 fq_bright. All rights reserved.
//
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <queue>
using namespace std;
long long min(long long a,long long b) {return a>b?b:a;}
int max(int a,int b) {return a>b?a:b;}
long long until_finnish[1001];

bool cmp(string s1, string s2) { return s1.length() < s2.length(); }
typedef bool (*comp)(int,int);
int a[2000];
int B;
bool cmp(int i, int j) {
    if (until_finnish[i] == until_finnish[j])
        return i > j;
    return until_finnish[i] > until_finnish[j];
}
long long find(long long mid) {
    long long ret = 0;
    for (int i = 0; i < B; ++i)
        ret += mid/a[i];
    return ret;
}

long long bs(long long st, long long end, long long tar) {
    while (st <= end) {
        long long mid = (st+end)/2;
        if (find(mid) >= tar)
            end = mid-1;
        else st = mid+1;
    }
    return st;
}

int main() {
    string path = "/Users/fq_bright/Desktop/B-large.in";
    string out_path = "/Users/fq_bright/Desktop/ret.txt";
    ifstream ifs;
    ofstream ofs;
    
    ofs.open(out_path.c_str());
    ifs.open(path.c_str());
    int T;
    string tt = "Case #";
    ifs >> T;
    int time = 1;
    while (time <= T) {
        int N;
        ifs >> B >> N;
    
        for (int i = 0; i < B; ++i)
            ifs >> a[i];
        
        if (N <= B) {
            ofs << tt;
            ofs << time++;
            ofs << ": ";
            ofs << N << endl;
            continue;
        }
        long long maxi_time = (long long)100000*N;
        long long least_time = bs(0, maxi_time, N-B);
        
        cout << least_time << endl;
        
        long long total = N-B;
        for (int i = 0; i < B; ++i) {
            long long c_num = min(total,least_time/a[i]);
            total -= c_num;
            until_finnish[i] = c_num*a[i] - least_time;
            cout << until_finnish[i] << " ";
        }
        cout << endl;
        priority_queue<int, vector<int>, comp>  pq(cmp);
        for (int i = 0; i < B; ++i)
            pq.push(i);
        
        while (--B) {
            int tmp = pq.top();
            pq.pop();
            until_finnish[tmp] += a[tmp];
            pq.push(tmp);
        }
        ofs << tt;
        ofs << time++;
        ofs << ": ";
        ofs << pq.top()+1 << endl;
        
    }
    ifs.close();
    ofs.close();
    system("pause");
}










