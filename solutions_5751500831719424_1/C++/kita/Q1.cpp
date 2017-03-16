
#include "stdafx.h"

#include <stdlib.h>
#include <math.h>

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <map>

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
	long N;
	vector<string> strs;
};

struct InputDataSet {
	int T;
	vector<TestData> vecData;
};

void Resolve( InputDataSet& data , ofstream& ofs ) 
{
	long long output = 0;

	//cout << "Input (" << data.lineNumber << ") " << data.name << " n=" << data.n << endl;



	for( int i = 0; i < data.vecData.size() ; i++ ) {
		TestData test = data.vecData.at(i);
		
		//memset( ans , 0 , test.R*test.C );

		cout << "T:" << i << endl;

		if( i == 1 ) {
			;
		}

		int TotalAct = 0;
		
		// 代表となる文字を抽出
		char keyChars[101] = {};
		int nIndex = 0;
		
		for( int j = 0 ; j < test.strs[0].size() ; j++ ) {
			if( 0 == nIndex ) {
				keyChars[nIndex++] = test.strs[0].at(j);
			}
			else if( keyChars[nIndex-1] != test.strs[0].at(j) ) {
				keyChars[nIndex++] = test.strs[0].at(j);
			}
		}

		bool bAbort = false;


		for( int n = 0 ; n < nIndex ; n++ ) {


			int actCount = 99999999;
			int charCount[101] = {};
			// key charの数をカウント
			for( int j = 0 ; j < test.N ; j++ ) {
				//cout << "[" <<  j << "]: "<< test.strs[j] << endl;
				// 代表となる文字を抽出
				{
					char keyCharsCur[101] = {};
					int nIndexCur = 0;
					for( int jj = 0 ; jj < test.strs[j].size() ; jj++ ) {
						if( 0 == nIndexCur ) {
							keyCharsCur[nIndexCur++] = test.strs[j].at(jj);
						}
						else if( keyCharsCur[nIndexCur-1] != test.strs[j].at(jj) ) {
							keyCharsCur[nIndexCur++] = test.strs[j].at(jj);
						}
					}
					if( 0 != strcmp( keyCharsCur , keyChars ) ) {
						// 順番が異なる。
						bAbort = true;
						break;
					}
				}

				// check sequence
				int kStart = 0;
				int keyCharPos = 0;
				for( kStart = 0 ; kStart < test.strs[j].size() ; kStart++ ) {
					if( test.strs[j].at(kStart) == keyChars[keyCharPos] ) {
						keyCharPos++;
						if( keyCharPos > n ) {
							break;
						}
					}
				}

				if( kStart == test.strs[j].size() ) {
					// 並びが異なる
					bAbort = true;
					break;
				}

				int kk = kStart;
				for( ; kk < test.strs[j].size() ; kk++ ) {
					if( test.strs[j].at(kk) == keyChars[n] ) {
						charCount[j]++;
					}
					else {
						break;
					}
				}

				// 同じ文字が全部に１つ以上あるか？
				if( charCount[j] == 0 ) {
					bAbort = true;
					break;
				}
			}

			if( bAbort ) {
				break;
			}
			else {
				int nMinAct = 99999999;
				for( int k = 1 ; k <= 100 ; k++ ){
					int nTmpAct = 0;
					for( int j = 0 ; j < test.N ; j++ ) {
						int nDiff = k - charCount[j];
						nDiff = nDiff < 0 ? -nDiff : nDiff;
						nTmpAct += nDiff;
					}
					if( nTmpAct < nMinAct ) {
						nMinAct = nTmpAct;
					}
				}
				if( actCount > nMinAct ) {
					actCount = nMinAct;
				}
			}
			if( actCount != 99999999 ) {
				TotalAct += actCount;
			}
		}

		if( bAbort ) {
			cout << "Case #" << i+1 << ": "
				<< "Fegla Won"
				<< endl;
			ofs << "Case #" << i+1 << ": "
				<< "Fegla Won"
				<< endl;
		}
		else {
			cout << "Case #" << i+1 << ": "
				<< TotalAct
				<< endl;
			ofs << "Case #" << i+1 << ": "
				<< TotalAct
				<< endl;
		}
		//ofs << fixed << setprecision(7) 
		//	<< "Case #" << i+1 << ": " 
		//	<< timeTotalPrev << endl;

		// test bad magician
		//cout << "Case #" << i+1 << ": " <<  "Bad magician!" << endl;
		//ofs << "Case #" << i+1 << ": " <<  "Bad magician!" << endl;

	}

	//cout << "Case #" << data.lineNumber << ": " << output << endl;
	//ofs <<  "Case #" << data.lineNumber << ": " << output << endl;
}

void ParseInput( ifstream& ifs ,  ofstream& ofs )
{
	InputDataSet inputData;

	string lineBuf;
	vector<string> splittedLineBuf;
	vector<long> splittedLineNums;

	int lineCount = 0;
	int Tcount = 0;
	TestData testData;
	TestData testDataEmpty = {};

	int readData = 0;
	
	while(ifs) {
		splittedLineBuf.clear();
		lineBuf.clear();
		splittedLineNums.clear();

		if( !getline(ifs, lineBuf) ) {
			cout << "eof" << endl;
			break;
		}
		split( lineBuf , ' ' , splittedLineBuf );

		if( lineCount == 0 ) {
			Tcount = StringToNumber<int>( lineBuf );
			inputData.T = Tcount;
			testData.N = 0;
			readData = 0;
		}
		else {
			if( testData.N == 0 ) {
				testData.N = StringToNumber<long>( lineBuf );
			}
			else {
				if( readData++ < testData.N ) {
					testData.strs.push_back( string(lineBuf) );
				}
				if( readData == testData.N ) {
					readData = 0;
					inputData.vecData.push_back( testData );
					testData = testDataEmpty;
					testData.N = 0;
				}
			}
		}

		lineCount++;
	}

	Resolve( inputData , ofs );

}

int _tmain(int argc, _TCHAR* argv[])
{
	if( argc > 3 || argc == 1 ) {
		cout << "invalid args" << endl;
		return -1;
	}

	ifstream ifs( argv[1] );
	ofstream ofs( OUTPUT_FILENAME );

	ParseInput( ifs , ofs );

	ifs.close();
	ofs.close();

	cout << "enter any key ..." << endl;
	char in;
	cin.get(in);

	return 0;
}

