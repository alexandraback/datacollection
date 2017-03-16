#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<functional>
#include<string>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<utility>
#include<fstream>
#include<sstream>
#include<cmath>
#include<stack>
#include<assert.h>
using namespace std;

#define f(i,a,b) for(int i = a;i < b;i++)
#define pb push_back
#define itr iterator
#define get(t) int t;cin >> t;
#define fi first
#define se second
#define mp make_pair
#define foreach(it,x) for(__typeof(x.begin()) it=x.begin();it!=x.end(); it++)
#define all(x) x.begin(),x.end()


typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
typedef vector<double> vd;

inline void sfr (int *a)
{
    char c = 0;
    while(c<33)
    c = fgetc(stdin);
    *a = 0;
    while(c>33)
    {
               *a = *a*10 + c - '0';
               c = fgetc(stdin);
    }
}

inline void sfp(int a){
     char c[1000];
     sprintf(c,"%d",a);
     puts(c);
}

int A[4][4];
int B[4][4];
int main(){
    ofstream out;
    out.open("output.txt");
    ifstream in;
    in.open("input.txt");
    int t;
    in >> t;
    f(c,1,t+1){
               int a,b;
               in >> a;
               f(i,0,4)f(j,0,4)in >> A[i][j];
               in >> b;
               f(i,0,4)f(j,0,4)in >> B[i][j];
               cout << a << " " << b << endl;
               a--;
               b--;
               int cnt = 0;
               int val;
               f(i,0,4)f(j,0,4)if(A[a][i] == B[b][j]){
                                          cnt++;
                                          val = A[a][i];
               }
               out << "Case #" << c << ": ";
               if(cnt == 1)out << val << endl;
               else if(cnt > 1)out << "Bad magician!" << endl;
               else out << "Volunteer cheated!" << endl;
    }
    out.close();
    get(wait);
}

