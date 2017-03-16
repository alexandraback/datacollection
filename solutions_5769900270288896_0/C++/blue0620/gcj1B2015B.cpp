#include <stdio.h> 
#include <stdlib.h>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <fstream>


using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define CLR(a) memset((a), 0 ,sizeof(a))
#define REP(i,n) for(int i = 0; i < (int)(n); ++i)
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

//conversion
//------------------------------------------
inline int toLL(string s) {long long v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;


int main(){
	ifstream ifs("B-small-attempt1.in");
	ofstream ofs("test.txt");
	int T,N,R,C;
	ifs>>T;
	vector<LL>answer;
	
	REP(tt,T){
		ifs>>R>>C>>N;
		if(R>C)swap(R,C);
		vector<string>mp1,mp2;
		int cnt1=0,cnt2=0;
		REP(i,C){
			string str1="",str2="";
			REP(j,R){
				if(i%2==j%2){
					cnt1++;
					str1+='O';
					str2+='X';
				}else{
					cnt2++;
					str1+='X';
					str2+='O';
				}
			}
			//cout<<str1<<endl;
			mp1.PB(str1);
			mp2.PB(str2);
		}
		vector<int>cost1,cost2;
		REP(i,C)REP(j,R){
			if(mp1[i][j]=='X'){
				if(i==0||i==C-1||j==0||j==R-1){
					if((i==0&&R==1)||(i==C-1&&R==1))cost1.PB(1);
					else if((i==0&&j==0)||(i==0&&j==R-1)||(i==C-1&&j==0)||(i==C-1&&j==R-1)||R==1)cost1.PB(2);
					else cost1.PB(3);
				}else{
					cost1.PB(4);
				}
			}
			if(mp2[i][j]=='X'){
				if(i==0||i==C-1||j==0||j==R-1){
					if((i==0&&R==1)||(i==C-1&&R==1))cost2.PB(1);
					else if((i==0&&j==0)||(i==0&&j==R-1)||(i==C-1&&j==0)||(i==C-1&&j==R-1)||R==1)cost2.PB(2);
					else cost2.PB(3);
				}else{
					cost2.PB(4);
				}
			}
		}
		SORT(cost1);SORT(cost2);
		int res1=0,res2=0;
		int N1,N2;
		N1=N2=N;
		N1-=cnt1;
		N2-=cnt2;
		REP(i,N1){
			res1+=cost1[i];
		}
		REP(i,N2){
			res2+=cost2[i];
			//cout<<cost2[i]<<" ";
		}
		//cout<<res1<<" "<<res2<<endl;
		if(res1!=0&&res2!=0)cout<<R<<" "<<C<<" "<<N<<"="<<min(res1,res2)<<endl;
		answer.PB(min(res1,res2));
	}
	REP(tt,T){
		//cout<<answer[tt]<<endl;
		ofs<<"Case #"<<tt+1<<": "<<answer[tt]<<endl;
	}
	return 0;
}