#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cstring>
#include <climits>
#include <iostream>
#include <cassert>
#define mod 1000000007
#define eps 1e-4
#define arsize 1000000001
#define INF 0x3f3f3f3f
#define NINF INT_MIN
#define INFL 0x3f3f3f3f3f3f3f3fLL
#define P 3.14159265358979323846264338327950288419716939937510
#define size 1000000
using namespace std;
ofstream fout ("/Users/priya/Desktop/A-small-att1.out");
ifstream fin ("/Users/priya/Desktop/A-large.in");
// int a, b;
// fin >> a >> b;
// fout << a+b << endl;
//  freopen("in", "r", stdin);
//  freopen("out", "w", stdout);
//long long int sum(long int x){
//    long long int ans=0;
//    for(long int i=1;i<sqrt(x);++i)if(x%i==0&&i%2!=0)ans+=i;
//    return ans;
bool isempty(int a[], int n){
    for(int i=0;i<n;i++)if(a[i]>0)return 1;
    return 0;
}
int maximumel(int a[], int n){
    long int max=0; int pos=-1; int i;
    for(i=0;i<n;i++)if(a[i]>max) max=a[i],pos=i;
    return pos;
}
bool allone(int a[], int n){
    for(int i=0;i<n;i++)if(a[i]>1)return 0;
    return 1;
}
int no_of_elements(int a[], int n){
    int count=0;
    for(int i=0;i<n;i++) if(a[i]>0)count++;
    return count;
}
int main()
{
    int t; fin>>t;
    for(int i=0;i<t;i++){
        int n; fin>>n;
        int a[n]; for(int k=0;k<n;k++)a[k]=0;
        for(int j=0;j<n;j++)fin>>a[j];
        fout<<"Case #"<<i+1<<":"<<" ";
        while(isempty(a,n))
        {
            if((no_of_elements(a,n)==3)&&(allone(a,n))) {
                int pos1=maximumel(a,n); if(pos1!=-1){
                    char c=(pos1+65); fout<<c<<" "; a[pos1]--;
                }
            }
            else{
            int pos1=maximumel(a,n);
            if(pos1!=-1)
            {char c=(pos1+65); fout<<c; a[pos1]--;}
            pos1=maximumel(a,n);
            if(pos1!=-1)
            {char c=(65+pos1); fout<<c<<" "; a[pos1]--;}
            }
        }
        fout<<endl;
    }
    return 0;
}