#include <fstream>
#include <iostream>
using std::endl;
#include <stdlib.h>
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <map>
using std::map;
std::ofstream gLogger("./log");

/*void SortedInsertInt( vector<int> &v, const int &i) {
  for (vector<int>::iterator itr=v.begin(); itr!=v.end(); ++itr){
    if (i < *itr) {
      v.insert(itr,i);
      return;
    }
  }  
  v.push_back(i);
}
*/


class Magictrick {
public:
  Magictrick( const char * filename ) : mInFile(filename)  {
    gLogger << "Magictrick contructed with: " << filename << endl;
  }
  void Load() {
    mInFile >> mNumTestCases;
    gLogger << "Number of testcases: " << mNumTestCases << endl;

    int tmpCard;
    for (int testCaseIdx=0; testCaseIdx < mNumTestCases; ++testCaseIdx) {
       gLogger << " Loading testcase: " << testCaseIdx+1 << endl;
       

       mMatrix1.clear();
       mMatrix2.clear();

       mInFile >> mRowChoice1;
       for(int row_idx=0; row_idx < 4; ++row_idx) {
	 Row tmpRow;
	 mMatrix1.push_back( tmpRow );
	 for (int col_idx=0; col_idx < 4; ++col_idx) {
	   mInFile >> tmpCard;
	   mMatrix1[row_idx].push_back(tmpCard);
	 }
       }
       
       mInFile >> mRowChoice2;
       for(int row_idx=0; row_idx < 4; ++row_idx) {
	 Row tmpRow;
	 mMatrix2.push_back( tmpRow );
	 for (int col_idx=0; col_idx < 4; ++col_idx) {
	   mInFile >> tmpCard;
	   mMatrix2[row_idx].push_back(tmpCard);
	 }
       }

       std::cout << "Case #" << testCaseIdx +1 << ": ";
       this->SolveCurrentProblem();
       std::cout << endl;
    }
  }
  void SolveCurrentProblem() {
     //gLogger << "\nFirst row choices(" << mRowChoice1 << "): ";
     int matchesfound=0;
     int lastmatch;
     for(int col1=0; col1<4; ++col1)
       for(int col2=0; col2<4; ++col2)
         if ( mMatrix1[mRowChoice1-1][col1] == mMatrix2[mRowChoice2-1][col2] ) {
	   matchesfound++;
	   lastmatch=mMatrix1[mRowChoice1-1][col1];
	   gLogger << "   Found match(" << matchesfound << "): " << lastmatch << endl;
	 }
     if (matchesfound==0)
       std::cout << "Volunteer cheated!";
     else if (matchesfound > 1)
       std::cout << "Bad magician!";
     else
       std::cout << lastmatch;
     
  }
private:
  Magictrick();
  std::ifstream mInFile;
  int mNumTestCases;
  typedef vector<int> Row;
  vector< Row > mMatrix1;
  vector< Row > mMatrix2;
  int mRowChoice1;
  int mRowChoice2;
};

void cleanup() {
  gLogger.close();
}

int main(int argc, char ** argv) {
  if (argc < 2) {
    std::cerr << "No file given\n";
    return 1;
  } else {
    atexit(&cleanup);
    Magictrick problem(argv[1]);
    problem.Load();
  }
  return 0;
}