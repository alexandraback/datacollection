# include <iostream>
# include <cmath>
# include <vector>
# include <string>
# include <algorithm>
# include <ostream>
# include <fstream>
# include <queue>
# include <stack>
# include <climits>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<pair<int, int> > vp;
typedef vector<vd> vvd;


# define REP(i,a,b) for(int i = a; i < b; i++)
# define REVREP(i,a,b) for(int i = a; i >= b; i--)
# define newl cout << endl
# define debl(a) cout << a << " "
# define debl2(a,b) cout << a << " " << b << " "
# define debnl(a) cout << a << endl
# define debnl2(a,b) cout << a << " " << b << endl
# define minv(a) *min_element(a.begin(), a.end())
# define maxv(a) *max_element(a.begin(), a.end())
# define minvind(a) min_element(a.begin(), a.end())
# define maxvind(a) max_element(a.begin(), a.end())

//string CaseName = "prac";
//string CaseName = "A-small-attempt0";
string CaseName = "A-large";

// Input Stream for input data //
ifstream In;

// Opens output stream //
ofstream Out;

void Solve(vi &party) {
  
  int N = party.size();
  
  vi rem = party;
  
  int Ncount = 0;
  REP(i,0,N) {
    Ncount += party[i];
  }
  
  string ans;
  while (Ncount > 0) {
    
    string out;
    
    int first = -1, second = -1;
    int firstind = -1, secondind = -1;
    
    REP(i,0,N) {
      if (rem[i] > first) {
        first = rem[i];
        firstind = i;
      }
    }
    
    rem[firstind]--;
    Ncount--;
    
    out = firstind+'A';
    
    bool maj1 = false;
    
    REP(i,0,N) {
      
      if ((float)((float)rem[i]/(float)Ncount) > 0.5) {
        maj1 = true;
        break;
      }
    }
    
    
    REP(i,0,N) {
      if (rem[i] > second) {
        second = rem[i];
        secondind = i;
      }
    }
    
    rem[secondind]--;
    Ncount--;
    
    bool maj2 = false;
    
    REP(i,0,N) {
      //cout << (float)((float)rem[i]/(float)Ncount) << endl;
      if ((float)((float)rem[i]/(float)Ncount) > 0.500000000) {
        maj2 = true;
        break;
      }
    }
    
    if (!maj2) {
      out += secondind+'A';
    } else {
      Ncount++;
      rem[secondind]++;
    }
    
    
    
    
    //cout << out << " " << maj1 << " " << maj2 << endl;
    ans += out + " ";
    //Ncount = 0;
  
  }
  
  cout << ans << endl;
  Out << ans << endl;
  
  
  return;
}

int main() {

	int NCases; 
	
	In.open(CaseName+".in");
	
	// Reads Number of cases //
  In >> NCases;
  
  Out.open(CaseName+".out");
  
	
	int i,j;

  REP(i,1,NCases+1) {
  
    int Nparties;
    In >> Nparties;
    
    vector<int> party(Nparties);
    
    REP(j, 0, Nparties) {
      In >> party[j];
    }
    
  
		Out << "Case #" << i << ": ";
		cout << "Case #" << i << ": ";		
		
    Solve(party);
		
	}
	// Close Input and Output Files //
	In.close();
	Out.close();

	return 0;

}
