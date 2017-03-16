/*
 * dijkstra.cpp
 *
 *  Created on: Apr 11, 2015
 *      Author: ni
 */


#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
//#include <cstdlib>

int casenum;
std::vector<std::vector<int> > input;
std::vector<long long int> xx;
std::vector<int> result1;
std::vector<int> result2;

int table[5][5] = {{0,0,0,0,0},{0,1,2,3,4},{0,2,-1,4,-3},{0,3,-4,-1,2},{0,4,3,-2,-1}};

bool readinput(std::string & filename)
{
    std::ifstream in(filename);
    if(!in)
    {
        std::cout << "Can't read in input file\n";
        return false;
    }
    in >> casenum;
    input.resize(casenum);
    int times;
    for(unsigned i = 0; i < casenum; ++i)
    {
    	in >> times;
    	input[i].resize(times);
    	for(unsigned j = 0; j < times; ++j)
    	{
    		in >> input[i][j];
    	}
    }

    return true;
}

bool writeoutput(std::string & filename)
{
    std::ofstream out(filename);
    if(!out)
    {
        std::cout << "Can't open the output file\n";
        return false;
    }
    for(unsigned i = 0; i < casenum; ++i)
    {
        out << "Case #" << i+1 << ": " ;
        out << result1[i] << ' ' << result2[i] << std::endl;
    }
    return true;

}

void eatmushroom(std::vector<int> & input, int & result1, int & result2)
{
	result1 = 0;
	int max = 0;
	result2 = 0;
	for(unsigned i = 0; i < input.size() - 1; ++i)
	{
		int diff = input[i] - input[i+1];
		if(diff > 0)
			result1 += diff;
		if(diff > max)
			max = diff;
	}
	for(unsigned i = 0; i < input.size() - 1; ++i)
	{
		if(input[i] > max)
			result2 += max;
		else
			result2 += input[i];
	}
}

int main(int argc, char ** argv)
{
    std::string fn = argv[1];
    std::string output = fn.substr(0, fn.find_last_of(".")) + ".out";
    readinput(fn);
    result1.resize(casenum);
    result2.resize(casenum);
    for(unsigned i = 0; i < casenum; ++i)
    {
       eatmushroom(input[i], result1[i], result2[i]);
    }
    writeoutput(output);
}


