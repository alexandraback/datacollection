#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
    ifstream cinn("input.txt");
    ofstream coutt("output.txt");
    int T;
    cinn>>T;
    for(int iii=0;iii<T;iii++)
    {
        coutt<<"Case #"<<iii+1<<": ";
        int n,sum=0;
        priority_queue<pair<int,char> > arr;

        cinn>>n;
        for(int i=0;i<n;i++)
        {
            int tmp;
            cinn>>tmp;
            sum+=tmp;
            arr.push(make_pair(tmp,'A'+i));
        }
        for(;;)
        {
            if(arr.top().first==0)break;
            pair<int,char> tmpp=arr.top();
            coutt<<tmpp.second;
            tmpp.first--;
            arr.pop();
            arr.push(tmpp);

            sum--;
            if(sum>=arr.top().first*2)
            {
                coutt<<" ";
                continue;
            }
            if(arr.top().first==0)break;
            priority_queue<pair<int,char> > arrtmp;
            arrtmp=arr;
             tmpp=arr.top();
             tmpp.first--;
            arr.pop();
            arr.push(tmpp);

            sum--;
            if(sum<arr.top().first*2)
            {
                arr=arrtmp;
                sum++;
                coutt<<' ';
                continue;
            }
            coutt<<tmpp.second;
            coutt<<" ";
        }
        coutt<<endl;
    }
    return 0;
}
