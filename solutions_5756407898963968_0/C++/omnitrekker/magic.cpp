#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>  
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

template <class T>
bool from_string(T& t, const std::string& s, std::ios_base& (*f)(std::ios_base&)) {
  std::istringstream iss(s);
  return !(iss >> f >> t).fail();
}

template <typename T>
string tostr(const T& t) { 
	ostringstream os; os<<t; 
	return os.str();
} 

int _tmain(int argc, _TCHAR* argv[])
{
  string line,cell;
  vector<vector<string>> m;
  ifstream in ("A-small-attempt1.in");
  if (in.is_open())
  {
    while ( getline (in ,line) )
    {
        stringstream lineStream(line);
		vector<string> tmp;
        while( getline( lineStream, cell, ' ' ) ) {
			tmp.push_back(cell);
		}
		m.push_back(tmp);
    }
    in.close();
  }

  ofstream out;
  out.open("codejam.out");

  int no_cases;
  from_string<int>(no_cases, m[0][0], std::dec);

  for (int c=0;c<no_cases;c++) {
  //for (int c=0;c<2;c++) {
	  out << "Case #" << c+1 << ": ";
	  int linenumber=c*10+1;
	  int s1, s2;
	  from_string<int>(s1, m[linenumber][0], std::dec);
	  from_string<int>(s2, m[linenumber+5][0], std::dec);
	  int row1=linenumber+s1;
	  int row2=linenumber+s2+5;
	  int answers=0;
	  int answer=0;
	  int n1,n2;
	  for (int i=0;i<4;i++) {
		  from_string<int>(n1, m[row1][i], std::dec);
		  for (int j=0;j<4;j++) {
			  from_string<int>(n2, m[row2][j], std::dec);
			  //out << "[" << n1 << ", " << n2 << "] ";
			  if (n1==n2) {
				  answers++;
				  answer=n1;
			  }
		  }
	  }
	  
	  if (answers==0) out << "Volunteer cheated!\n";
	  if (answers==1) out << answer << "\n";
	  if (answers>1) out << "Bad magician!\n";
  }
  
  out.close();
  return 0;
}

