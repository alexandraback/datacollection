
#include <iostream>
#include <iomanip> //setprecision
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <iterator> //istream_iterator

using namespace std;

#define REP(i,N) for(int i=0;i<(N);i++)
#define FOR(i,A,B) for(int i=(A);i<=(B);i++)
#define ROF(i,A,B) for(int i=(B);i>=(A);i--)
#define ALL(A) (A).begin(),(A).end()

#define ISIi std::istream_iterator<int>
#define ISS std::istringstream
#define cinL2B(L,B) getline(cin,L); B.clear(); B.str(L);

typedef pair<int,int> pi;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vector<vi> > vvvi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
typedef queue<pi> qpi;
typedef set<int> si;
typedef set<pi> spi;
typedef set<si> ssi;

int main(){
  int N,nr;
  string line;
  int mat1[5][5],mat2[5][5];
  int r1,r2;
  
  getline(cin,line); istringstream(line)>>N;
  for(nr=0;nr<N;nr++){
    getline(cin,line); istringstream(line)>>r1;
    REP(i,4){
      getline(cin,line);
      ISS buffer(line);
      REP(j,4)
	buffer>>mat1[i][j];
    }
    getline(cin,line); istringstream(line)>>r2;
    REP(i,4){
      getline(cin,line);
      ISS buffer(line);
      REP(j,4)
	buffer>>mat2[i][j];
    }
    cout<<"Case #"<<nr+1<<":";
    // ------------------------------------------------------
    //cout<<endl; REP(i,4) {REP(j,4) cout<<mat2[i][j]<<" "; cout<<endl;}

    int row[5],col[5];
    bool gasit;

    REP(j,4){
      gasit=false;
      for(int a=0;a<4 && !gasit; a++)
	for(int b=0;b<4 && !gasit; b++)
	  if(mat1[r1-1][j]==mat2[a][b]){
	    row[j]=a;
	    col[j]=b;
	    gasit=true;
	  }
    }

    //    REP(j,4){ cout<<row[j]<<" "<<col[j]<<endl;}

    int count=0,poz=-1;
    REP(j,4)
      if(row[j]==r2-1){
	count++;
	poz=j;
      }

    if(count>1)
      cout<<" Bad magician!"<<endl;
    if(count==0)
      cout<<" Volunteer cheated!"<<endl;
    if(count==1)
      cout<<" "<<mat2[row[poz]][col[poz]]<<endl;
  }
}
