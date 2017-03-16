#include <iostream>
#include <algorithm>
#include <vector>
#include<fstream>
using namespace std;
int main()
{
  long int T,i,j,k,m;
  long int countl;
  long int countr;
  long int countz;
  char c;
  long int N;
  int a[4];
  int b[4];
  long int number, convc;
  int standupsofar;
  long int friends;
  long int answer1;
  long int answer2;
  vector<long int> x;
  vector<long int> y;
  vector<long int> ans;
  ifstream input;
  ofstream output;
  long int rate;
  input.open("B.in");
  output.open("dout.txt");
  input >> T;
  for(i=0;i<T;i++){
	input >> N;
	answer1 = 0;
	rate = 0;
	answer2= 0;
	x.clear();
	y.clear();
	ans.clear();
	for (j=0; j<N; j++) {
	  input >> friends;
	  x.push_back(friends);
	  input >> friends;
	  y.push_back(friends);
	  ans.push_back(N);
	}
	for (j=0; j<N; j++){
	  for (k=0;k<N; k++) {
	    if (j != k) {
	      countl = 0;
	      countr = 0;
	      countz = 0;
	      for (m = 0; m<N; m++){
		if ((y[m]-y[j])*(x[k]-x[j]) < (x[m]-x[j])*(y[k]-y[j])){
		  countl++;	  
		}
		if ((y[m]-y[j])*(x[k]-x[j]) > (x[m]-x[j])*(y[k]-y[j])){
		  countr++;	  
		}
		if ((y[m]-y[j])*(x[k]-x[j]) == (x[m]-x[j])*(y[k]-y[j])){
		  countz++;	  
		}
	      }
	      if (countl + countr + countz != N) {
		cout << "danger" << endl;
	      }
	      cout << countl << " " << countr << " " << countz;
	      countl = min(countl,countr);
	      cout << " " << countl << endl;
	      ans[j] = min(ans[j], countl);
	    }		  
	  }
	}
	output << "Case #"<< i+1 <<":" << endl;
	if (N > 1){
	  for(j=0;j<N;j++) {
	    output << ans[j] << endl;
	  }
	}
	if (N ==1){
	  output << 0 << endl;
	}
  }
  return 0;
}
