#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
 
using namespace std;
 
vector<int> combination;
vector<int> total;
int answer;
int R;
int C;

void check_answer(vector<int>& v) {
    int temp = 0;
    bool chosen[16];
    for (int i = 0 ; i < 16 ; i++) chosen[i] = false;
    for (int i = 0 ; i < v.size() ; i++) {
	chosen[v[i]] = true;
	//cout << v[i] << " ";
    }
	//cout << endl;
    for (int i = 0 ; i < R ; i++)
	for (int j = 0 ; j < C ; j++)
 	{
	    if (i != R-1) {
		//cout << "i*C+j = " << i*C + j << " : " << chosen[i*C + j]<< endl;
		if (chosen[i*C + j] && chosen[(i+1)*C+j]) temp++;
		}
	    if (j != C-1) {
		if (chosen[i*C + j] && chosen[i*C+j+1]) temp++;
		}
	}
	//cout << "temp is " << temp << endl;
    if (answer > temp) answer = temp;
	return;
}

void recursive(int offset, int k) {
  if (k == 0) {
    check_answer(combination);
    return;
  }
  for (int i = offset; i <= total.size() - k; ++i) {
    combination.push_back(total[i]);
    recursive(i+1, k-1);
    combination.pop_back();
  }
}

int main()
{
    ifstream fin("B-small-attempt0.in");
    ofstream fout("B-small-attempt0.out");
    int T;
    fin >> T;
    int N;
    for (int t = 1 ; t <= T; t++)
    {  
	fin >> R >> C >> N;
	answer = 1000;
	for (int i = 0 ; i < R*C ; i++)
	    total.push_back(i);
	recursive(0,N);
	
       fout << "Case #" << t << ": " << answer << endl;  
	combination.clear();
	total.clear();     
    }
}
