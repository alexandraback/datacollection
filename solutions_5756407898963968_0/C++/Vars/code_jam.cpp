// code_jam.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "InputFileReader.h"
#include <conio.h>
#include <algorithm>
#include <map>

using namespace std;

class SecondTask : public InputFileReader
{

public:
   SecondTask(string fileName)
      : InputFileReader(fileName)
   {

   }
   virtual void readTestCase( std::ifstream & file, std::ofstream & fileOut, int z ) 
   {
	  int firstTimeRowNumber;
	  readValue(file, firstTimeRowNumber);
	  firstTimeRowNumber --;
	  vector<int> firstTimeRow;
	  for (int i=0; i < 4; i++)
	  {
		   vector<int> tempRow;
		   readValue(file, tempRow);
		   if (i == firstTimeRowNumber)
		   {
			   firstTimeRow = tempRow;
		   }
	  }

	  int secondTimeRowNumber;
	  readValue(file, secondTimeRowNumber);
	  secondTimeRowNumber --;
	  vector<int> secondTimeRow;
	  for (int i=0; i < 4; i++)
	  {
		  vector<int> tempRow;
		  readValue(file, tempRow);
		  if (i == secondTimeRowNumber)
		  {
			  secondTimeRow = tempRow;
		  }
	  }

	  string result = "Volunteer cheated!";
	  vector<int> resultVector;
	  for (int i = 0; i < 4; i ++)
	  {
		  for (int j = 0; j < 4; j ++)
		  {
			  if (firstTimeRow[i] == secondTimeRow[j])
			  {
				  resultVector.push_back(firstTimeRow[i]);
			  }
		  }
	  }
	  
	 
	  if (resultVector.size()>1)
	  {
		result = "Bad magician!";

	  } 
	  if (resultVector.size() == 1)
	  {
		  fileOut << "Case #" << z+1 << ": " << resultVector[0];
	  } 
	  else
	  {
		  fileOut << "Case #" << z+1 << ": " << result;
	  }
      
      fileOut << endl;
   }

};


int _tmain(int argc, _TCHAR* argv[])
{
	SecondTask fr("c:\\jam.in");
	fr.readFile();
    getch();
	return 0;
}

