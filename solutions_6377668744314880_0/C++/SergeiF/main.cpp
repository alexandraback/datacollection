//	main: load input, run tasks, write output

#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <assert.h>

#include "R1A_C.h"

using namespace std;

///////////////////////////////////////////////////////////

class CInParser {
public:
	explicit CInParser( const std::string& fileName );

	int ReadLineAsInt();
	std::string ReadLineAsString();
	void ReadLineAsIntsVector( std::vector<int>& ints );
	void ReadLineAsIntsVector( std::vector<__int64>& ints );
	void ReadLineAsTwoInts( int& int1, int& int2 );
	void ReadLineAsTwoInt64( __int64& int1, __int64& int2 );
	void ReadLineAsIntAndString(int& n, std::string& str);

private:
	std::ifstream inFile;
};

///////////////////////////////////////////////////////////

//const string inFileName = "./../in/test.txt";
//const string outFileName = "./../out/test.txt";
const string inFileName = "./../in/C-small-attempt1.in";
const string outFileName = "./../out/C-small-attempt1.out";
//const string inFileName = "./../in/C-large.in";
//const string outFileName = "./../out/C-large.out";


void writeOutput( std::ofstream& outFile, int setN, const std::vector<int>& logs )
{
	outFile << "Case #" << setN << ":\n";
	for( int i = 0; i < (int)logs.size(); i++ ) {
		outFile << logs[i] << "\n";
	}
}

///////////////////////////////////////////////////////////

CInParser::CInParser( const string& fileName )
{
	inFile.open( fileName.c_str() );
}

int CInParser::ReadLineAsInt()
{
	std::string line;
	std::getline(inFile, line);
	std::istringstream iss(line);
	int result = 0;
	iss >> result;
	return result;
}

//	N "str"
void CInParser::ReadLineAsIntAndString(int& n, std::string& str)
{
	std::string line;
	std::getline(inFile, line);
	std::istringstream iss(line);
	iss >> n;
	iss >> str;
}

std::string CInParser::ReadLineAsString()
{
	std::string line;
	std::getline(inFile, line);
	return line;
}

void CInParser::ReadLineAsIntsVector( std::vector<int>& ints )
{
	std::string line;
	std::getline(inFile, line);
	std::istringstream iss(line);
	ints.clear();
	int n = 0;
	while(iss >> n) {
		ints.push_back(n);
	}
}

void CInParser::ReadLineAsIntsVector( std::vector<__int64>& ints )
{
	std::string line;
	std::getline(inFile, line);
	std::istringstream iss(line);
	ints.clear();
	__int64 n = 0;
	while(iss >> n) {
		ints.push_back(n);
	}
}

void CInParser::ReadLineAsTwoInts( int& int1, int& int2 )
{
	std::vector<int> ints;
	ReadLineAsIntsVector( ints );
	assert( (int)ints.size() == 2 );
	int1 = ints[0];
	int2 = ints[1];
}

void CInParser::ReadLineAsTwoInt64( __int64& int1, __int64& int2 )
{
	std::vector<__int64> ints;
	ReadLineAsIntsVector( ints );
	assert( (int)ints.size() == 2 );
	int1 = ints[0];
	int2 = ints[1];
}

///////////////////////////////////////////////////////////

void parseInFile( CInParser& parser, std::vector<CPoint>& trees )
{
	const int numberOfTrees = parser.ReadLineAsInt();
	assert( numberOfTrees > 0 );

	trees.clear();
	for( int i = 0; i < numberOfTrees; i++ ) {
		CPoint pt;
		parser.ReadLineAsTwoInts( pt.X, pt.Y );
		trees.push_back( pt );
	}
}

int main(int argc, char* argv[])
{
	//	parse input
	CInParser parser( inFileName );
	const int numberOfSets = parser.ReadLineAsInt();
	assert( numberOfSets > 0 );

	std::ofstream outFile( outFileName.c_str() );

	CR1A_CTaskProcessor taskProcessor;

	for( int setN = 1; setN <= numberOfSets; setN++ ) {
		cout << "Processing set #" << setN <<"...\n";

		//	parse in file
		std::vector<CPoint> trees;
		parseInFile( parser, trees );

		//	process		
		std::vector<int> logs;
		taskProcessor.checkTrees( trees, logs );
		assert( logs.size() == trees.size() );

		//	output
		writeOutput( outFile, setN, logs );
	}

	return 0;
}

