


#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
//#include <cstdlib>

int casenum;
std::vector<std::vector<int> > input;
std::vector<long int> position;

std::vector<int> result;


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
    position.resize(casenum);
    int barber;
    for(unsigned i = 0; i < casenum; ++i)
    {
    	in >> barber >> position[i];
    	input[i].resize(barber);
    	for(unsigned j = 0; j < barber; ++j)
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
    for(int i = 0; i < casenum; ++i)
    {
        out << "Case #" << i+1 << ": " ;
        out << result[i] <<  std::endl;
    }
    return true;

}
int maxelement(std::vector<int> & input)
{
	int max = 0;
	for(unsigned i = 0; i < input.size(); ++i)
	{
		if(input[i] > max)
		{
			max = input[i];
		}
	}
	return max;
}

void haircut(std::vector<int> & input, int & result, long int pos)
{
	int bnum = input.size();
	if(pos <= bnum)
		result = pos;
	int maxbarber = maxelement(input);
	long long int maxtime = maxbarber * pos;
	long long int start = 0;
	long long int end = maxtime;
	long long int mid = (long long int)floor((end - start) / 2);

	bool stop = false;
	long long int count = 0;
	int tnum = 0;
	while(!stop)
	{
		count = 0;
		tnum = 0;
		for(unsigned i = 0; i < bnum; ++i)
		{
			count += (long long int)floor(mid / input[i]) + 1;
			if(mid % input[i] == 0)
				++tnum;
		}
		if(count >= pos)
		{
			if(count - tnum < pos)
				break;
			end = mid;
		}
		if(count < pos)
		{
			start = mid;
		}
		mid = (long long int) floor((end + start) / 2);
		//std::cout << start << ' ' << mid << ' ' << end << std::endl;
	}
	int mark = 0;
	for(unsigned i = 0; i < bnum; ++i)
	{
		if(mid % input[i] == 0)
		{
			++mark;
			if(mark == pos - count + tnum)
			{
				result = i+1;
				return;
			}
		}
	}
}

int main(int argc, char ** argv)
{
    std::string fn = argv[1];
    std::string output = fn.substr(0, fn.find_last_of(".")) + ".out";
    readinput(fn);
    result.resize(casenum);
    for(unsigned i = 0; i < casenum; ++i)
    {
        haircut(input[i], result[i], position[i]);
        //std::cout << "case number:" << i << std::endl;
    }
    writeoutput(output);
}


 /* question2.cpp
 *
 *  Created on: Apr 17, 2015
 *      Author: ni
 */




