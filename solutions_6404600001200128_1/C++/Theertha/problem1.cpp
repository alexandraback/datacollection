#include <iostream>
#include <algorithm>
#include <vector>
#include<fstream>
using namespace std;
int main()
{
  long int T,i,j,k;
  char c;
  long int N;
  int a[4];
  int b[4];
  long int number, convc;
  int standupsofar;
  long int friends;
  long int answer1;
  long int answer2;
  vector<long int> plate;
  ifstream input;
  ofstream output;
  long int rate;
  input.open("B.in");
  output.open("bout.txt");
  input >> T;
  for(i=0;i<T;i++){
	input >> N;
	answer1 = 0;
	rate = 0;
	answer2= 0;
	plate.clear();
	for (j=0;j<N;j++) {
	  input >> friends;
	  plate.push_back(friends);
	}
	for (j=0; j<N-1;j++){
	  rate = max(rate, plate[j] - plate[j+1]);
	  if (plate[j]-plate[j+1] > 0) {
	    answer1 = answer1 +plate[j]-plate[j+1];
	  }
	}
	for (j=0;j<N-1;j++) {
	  answer2 = answer2+ min(rate, plate[j]);
	}
	output << "Case #"<< i+1 <<": ";
	output << answer1 << " " << answer2 << endl;
	//	if(temp==1)
	//		output << num;
	//	if(temp ==0)
	//		output << "Volunteer cheated!";
	//	if(temp >1)
	//		output << "Bad magician!";
	//	output << endl;
	//	cout << number << endl;
	//	cout << rowb << endl;
  }
  return 0;
}
