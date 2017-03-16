// GCG2014Qualification.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdlib.h>
#include <math.h>

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>

using namespace std;

const string OUTPUT_FILENAME = "output.txt";

template <typename T>
T StringToNumber ( const string &Text )
{
	istringstream ss(Text);
	T result;
	return ss >> result ? result : 0;
}

vector<string> &split(const string &s, char delim, vector<string> &elems) {
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

struct TestData {
	int rowA;
	int rowB;
	int dataA[4][4];
	int dataB[4][4];
};

struct InputDataSet {
	int T;
	vector<TestData> vecData;
};

void Calc( InputDataSet& data , ofstream& ofs ) 
{
	long long output = 0;

	//cout << "Input (" << data.lineNumber << ") " << data.name << " n=" << data.n << endl;

	for( int i = 0; i < data.vecData.size() ; i++ ) {
		TestData test = data.vecData.at(i);
		cout << i << " rows " << test.rowA << " " << test.rowB << endl;
		cout << "dataA" << endl;
		for( int j = 0 ; j < 4 ; j++ ) {
			for( int k = 0 ; k < 4 ; k++ ) {
				cout << test.dataA[j][k] << " ";
			}
			cout << endl;
		}
		cout << "dataB" << endl;
		for( int j = 0 ; j < 4 ; j++ ) {
			for( int k = 0 ; k < 4 ; k++ ) {
				cout << test.dataB[j][k] << " ";
			}
			cout << endl;
		}

		// calc num
		bool bMatch = false;
		bool bTooMany = false;
		int nAns = -1;
		for( int j = 0 ; j < 4 ; j++ ) {
			for( int k = 0 ; k < 4 ; k++ ) {
				if( test.dataA[test.rowA-1][j] == test.dataB[test.rowB-1][k] ) {
					if( bMatch ) {
						bTooMany = true;
					}
					bMatch = true;
					nAns = test.dataA[test.rowA-1][j];
				}
			}
		}
		if( bMatch && !bTooMany ) {
			cout << "Case #" << i+1 << ": " << nAns << endl;
			ofs << "Case #" << i+1 << ": " << nAns << endl;
			continue;
		}
		
		// test volunteer cheat
		if( !bMatch ) {
			cout << "Case #" << i+1 << ": " <<  "Volunteer cheated!" << endl;
			ofs << "Case #" << i+1 << ": " <<  "Volunteer cheated!" << endl;
			continue;
		}

		// test bad magician
		cout << "Case #" << i+1 << ": " <<  "Bad magician!" << endl;
		ofs << "Case #" << i+1 << ": " <<  "Bad magician!" << endl;

	}

	//cout << "Case #" << data.lineNumber << ": " << output << endl;
	//ofs <<  "Case #" << data.lineNumber << ": " << output << endl;
}

void MainFunc( ifstream& ifs ,  ofstream& ofs )
{
	InputDataSet inputData;

	string lineBuf;
	vector<string> splittedLineBuf;
	vector<long> splittedLineNums;

	int lineCount = 0;
	int Tcount = 0;
	TestData testData;

	while(ifs) {
		splittedLineBuf.clear();
		lineBuf.clear();
		splittedLineNums.clear();

		if( !getline(ifs, lineBuf) ) {
			cout << "eof" << endl;
			break;
		}
		split( lineBuf , ' ' , splittedLineBuf );
		
		//for each( const string& out in splittedLineBuf ) {
		//	long long llInput = _atoi64(out.c_str());
		//	long double ld = llInput;
		//	splittedLineNums.push_back( ld );
		//	cout << setprecision(32) << ld << "/";
		//}
		//cout << endl;

		if( lineCount == 0 ) {
			Tcount = StringToNumber<int>( lineBuf );
			inputData.T = Tcount;
		}
		else if( lineCount % 10 == 1 ) {
			testData.rowA = StringToNumber<int>( lineBuf );
		}
		else if( lineCount % 10 == 2 ) {
			testData.dataA[0][0] = StringToNumber<int>( splittedLineBuf[0] );
			testData.dataA[0][1] = StringToNumber<int>( splittedLineBuf[1] );
			testData.dataA[0][2] = StringToNumber<int>( splittedLineBuf[2] );
			testData.dataA[0][3] = StringToNumber<int>( splittedLineBuf[3] );
		}
		else if( lineCount % 10 == 3 ) {
			testData.dataA[1][0] = StringToNumber<int>( splittedLineBuf[0] );
			testData.dataA[1][1] = StringToNumber<int>( splittedLineBuf[1] );
			testData.dataA[1][2] = StringToNumber<int>( splittedLineBuf[2] );
			testData.dataA[1][3] = StringToNumber<int>( splittedLineBuf[3] );
		}
		else if( lineCount % 10 == 4 ) {
			testData.dataA[2][0] = StringToNumber<int>( splittedLineBuf[0] );
			testData.dataA[2][1] = StringToNumber<int>( splittedLineBuf[1] );
			testData.dataA[2][2] = StringToNumber<int>( splittedLineBuf[2] );
			testData.dataA[2][3] = StringToNumber<int>( splittedLineBuf[3] );
		}
		else if( lineCount % 10 == 5 ) {
			testData.dataA[3][0] = StringToNumber<int>( splittedLineBuf[0] );
			testData.dataA[3][1] = StringToNumber<int>( splittedLineBuf[1] );
			testData.dataA[3][2] = StringToNumber<int>( splittedLineBuf[2] );
			testData.dataA[3][3] = StringToNumber<int>( splittedLineBuf[3] );
		}
		else if( lineCount % 10 == 6 ) {
			testData.rowB = StringToNumber<int>( lineBuf );
		}
		else if( lineCount % 10 == 7 ) {
			testData.dataB[0][0] = StringToNumber<int>( splittedLineBuf[0] );
			testData.dataB[0][1] = StringToNumber<int>( splittedLineBuf[1] );
			testData.dataB[0][2] = StringToNumber<int>( splittedLineBuf[2] );
			testData.dataB[0][3] = StringToNumber<int>( splittedLineBuf[3] );
		}
		else if( lineCount % 10 == 8 ) {
			testData.dataB[1][0] = StringToNumber<int>( splittedLineBuf[0] );
			testData.dataB[1][1] = StringToNumber<int>( splittedLineBuf[1] );
			testData.dataB[1][2] = StringToNumber<int>( splittedLineBuf[2] );
			testData.dataB[1][3] = StringToNumber<int>( splittedLineBuf[3] );
		}
		else if( lineCount % 10 == 9 ) {
			testData.dataB[2][0] = StringToNumber<int>( splittedLineBuf[0] );
			testData.dataB[2][1] = StringToNumber<int>( splittedLineBuf[1] );
			testData.dataB[2][2] = StringToNumber<int>( splittedLineBuf[2] );
			testData.dataB[2][3] = StringToNumber<int>( splittedLineBuf[3] );
		}
		else if( lineCount % 10 == 0 ) {
			testData.dataB[3][0] = StringToNumber<int>( splittedLineBuf[0] );
			testData.dataB[3][1] = StringToNumber<int>( splittedLineBuf[1] );
			testData.dataB[3][2] = StringToNumber<int>( splittedLineBuf[2] );
			testData.dataB[3][3] = StringToNumber<int>( splittedLineBuf[3] );

			inputData.vecData.push_back( testData );
			memset( &testData , 0 , sizeof(testData) );
		}

		lineCount++;
	}

	Calc( inputData , ofs );

}

int _tmain(int argc, _TCHAR* argv[])
{
	if( argc > 3 || argc == 1 ) {
		cout << "invalid args" << endl;
		return -1;
	}

	ifstream ifs( argv[1] );
	ofstream ofs( OUTPUT_FILENAME );

	MainFunc( ifs , ofs );

	ifs.close();
	ofs.close();

	cout << "enter any key ..." << endl;
	char in;
	cin.get(in);

	return 0;
}

