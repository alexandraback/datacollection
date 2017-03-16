//	main: load input, run tasks, write output

#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <assert.h>

#include "R1A_A.h"

using namespace std;

///////////////////////////////////////////////////////////

class CInParser {
public:
	explicit CInParser( const std::string& fileName );

	int ReadLineAsInt();
	std::string ReadLineAsString();
	void ReadLineAsIntsVector( std::vector<int>& ints );
	void ReadLineAsIntsVector( std::vector<__int64>& ints );
	void ReadLineAsIntAndString(int& n, std::string& str);

private:
	std::ifstream inFile;
};

///////////////////////////////////////////////////////////

//const string inFileName = "./../in/test.txt";
//const string outFileName = "./../out/test.txt";
//const string inFileName = "./../in/A-small-attempt0.in";
//const string outFileName = "./../out/A-small-attempt0.out";
const string inFileName = "./../in/A-large.in";
const string outFileName = "./../out/A-large.out";


void writeOutput( std::ofstream& outFile, int setN, int result1, int result2 )
{
	outFile << "Case #" << setN << ": " << result1 << " " << result2 << "\n";
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

///////////////////////////////////////////////////////////

void parseInFile( CInParser& parser, std::vector<int>& mushroomsCounts )
{
	std::string str;
	const int count = parser.ReadLineAsInt();
	assert( count > 0 );
	mushroomsCounts.clear();
	parser.ReadLineAsIntsVector( mushroomsCounts );
	assert( (int)mushroomsCounts.size() == count );
}

int main(int argc, char* argv[])
{
	//	parse input
	CInParser parser( inFileName );
	const int numberOfSets = parser.ReadLineAsInt();
	assert( numberOfSets > 0 );

	std::ofstream outFile( outFileName.c_str() );

	CR1A_ATaskProcessor taskProcessor;

	for( int setN = 1; setN <= numberOfSets; setN++ ) {
		cout << "Processing set #" << setN <<"...\n";

		//	parse in file
		std::vector<int> mushroomsCounts;
		parseInFile( parser, mushroomsCounts );

		//	process		
		const int result1 = taskProcessor.findMinMushroomsMethod1( mushroomsCounts );
		const int result2 = taskProcessor.findMinMushroomsMethod2( mushroomsCounts );

		//	output
		writeOutput( outFile, setN, result1, result2 );
	}

	return 0;
}

