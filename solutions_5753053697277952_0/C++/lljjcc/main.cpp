#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <fstream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;
#define INF 0x3f3f3f3f
const int N=1005;
const int mod=1e9+7;

int p[30];

int main() {
    ifstream ifile;
    ofstream ofile;
    ofile.open("/Users/lijiechen/Downloads/123.txt",ios::out);
    ifile.open("/Users/lijiechen/Downloads/A-small-attempt0.in.txt",ios::out);
    int n,k,t,kase=0;
    ifile>>t;
    while (t--) {
        kase++;
        ifile>>n;
        int mid=n/2,num=0;
        for (int i=0; i<n; i++) {
            ifile>>p[i];
            num+=p[i];
        }
        ofile<<"Case #"<<kase<<": ";
        
        int m1,m2,sum=0;
        while (num>0) {
            m1=m2=0;
            for (int i=0; i<n; i++) {
                if (p[i]>=sum) {
                    m2=m1;
                    m1=i;
                    sum=p[i];
                }
            }
            sum=0;
            if (m2==0) {
                for (int i=0; i<n; i++) {
                    if (i==m1) {
                        continue;
                    }
                    if (p[i]>sum) {
                        m2=i;
                        sum=p[i];
                    }
                }
            }
            if (p[m1]-p[m2]>=2) {
                num-=2;
                p[m1]-=2;
                ofile<<(char)(m1+'A')<<(char)(m1+'A')<<" ";
            } else {
                if (num==3) {
                    ofile<<(char)(m1+'A')<<" ";
                    p[m1]--;
                    num-=1;
                } else {
                    ofile<<(char)(m1+'A')<<(char)(m2+'A')<<" ";
                    p[m1]--,p[m2]--;
                    num-=2;
                }
            }
        }
        ofile<<endl;
    }
    return 0;
}