//
//  main.cpp
//  code_jam_qualification_round
//
//  Created by hijackyan on 4/11/15.
//  Copyright (c) 2015 hackerrank. All rights reserved.
//

#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;
struct barber
{
    long long num;
    long long time;
    barber(long long i)
    {
        num = i;
        time = 0;
    }
};

struct cmp
{
    bool operator()(barber a, barber b)
    {
        return a.time != b.time ? b.time < a.time: b.num < a.num;
    }
};

long long gcd(long a, long b)
{
    return b == 0? a : gcd(b, a%b);
}

int main() {
    int T;
    cin>>T;
    int case_number = 1;
    while(T--)
    {
        long long n, b, i, j;
        cin>>b>>n;
        vector<long long> cut_time;
        priority_queue<barber, vector<barber>, cmp> q;
        long long lcm = 1;
        for(i = 0; i < b; i++)
        {
            cin>>j;
            cut_time.push_back(j);
            q.push(barber(i));
            lcm = lcm*j/gcd(lcm, j);
        }
        //cout<<lcm<<" aa"<<endl;
        int total = 0;
        for(i = 0; i < b; i++)
            total += lcm/cut_time[i];
        
        n %= total;
        if(n == 0) n += total;
        for(i = 0; i < n-1; i++)
        {
            barber temp = q.top();
            q.pop();
            temp.time += cut_time[temp.num];
            q.push(temp);
        }
        cout<<"Case #"<<case_number++<<": "<<q.top().num+1<<endl;
    }
}
