#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <utility>
#include <algorithm>
#include <iterator>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define FOR(i,n) for(int i=0;i<(int)(n);++i)
#define REP(i,m,n) for(int i=(int)(m);i<(int)(n);i++)
#define FORR(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define FORE(i,n) for(int i=0;i<=(int)(n);++i)
#define MP(X,Y) make_pair(X,Y)
typedef pair<int,int> ipair;
typedef long long int64;
#define MF(X,val) memset(X,val,sizeof(X))
const double eps=1.0e-6;


//const int MAX_N=1000001;
const int MAX_N=51;

int A[4][4];
int B[4][4];

int main(int argc,char** argv){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int TC;
	cin>>TC;
	int row1,row2,val,num;
	REP(tc,1,TC+1){
		val=-1;
		num=0;
		cin>>row1;row1--;
		FOR(i,4)FOR(j,4)cin>>A[i][j];
		cin>>row2;row2--;
		FOR(i,4)FOR(j,4)cin>>B[i][j];
		FOR(i,4)FOR(j,4)if(A[row1][i]==B[row2][j]){
			val=A[row1][i];
			num++;
		}
		if(num==1){
			printf("Case #%d: %d\n",tc,val);
		}else if(num==0){
			printf("Case #%d: Volunteer cheated!\n",tc);
		}else{
			printf("Case #%d: Bad magician!\n",tc);
		}
		
	}
	return 0;
}