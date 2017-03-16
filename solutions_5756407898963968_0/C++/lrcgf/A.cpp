#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <tuple>

#include <boost/lexical_cast.hpp>
#include <boost/assign.hpp>

using namespace std;
using namespace boost;
using namespace boost::assign;


int main(int argc, char** argv)
{
    auto& in = cin;
    auto& out = cout;

    out << setprecision(7);

    string line;
    getline(in, line);
    int nLines = lexical_cast<int>(line); 

    for (int caseNo=0; caseNo < nLines; ++caseNo)
    {
        int row;
        in >> row;
        
        int dummy; 

        for (int i=0; i < row - 1; ++i)
            in >> dummy >> dummy >> dummy >> dummy;
        int numbers[4];
        in >> numbers[0] >> numbers[1] >> numbers[2] >> numbers[3];
        for (int i = row; i < 4; ++i)
            in >> dummy >> dummy >> dummy >> dummy;

        in >> row;
        for (int i=0; i < row - 1; ++i)
            in >> dummy >> dummy >> dummy >> dummy;
        int numbers2[4];
        in >> numbers2[0] >> numbers2[1] >> numbers2[2] >> numbers2[3];
        for (int i = row; i < 4; ++i)
            in >> dummy >> dummy >> dummy >> dummy;
        
        int nSame = 0;
        int same = 0;
        for (int i=0; i < 4; ++i)
        {
            for (int j=0; j < 4; ++j)
            {
                if (numbers[i] == numbers2[j])
                {
                    nSame++;
                    same = numbers[i];
                }
            }
        }
        
        out << "Case #" << caseNo+1 << ": ";
        if (nSame == 1)
            out << same;
        else if (nSame == 0)
            out << "Volunteer cheated!";
        else
            out << "Bad magician!";

        out << endl;
    }


    return 0;
}

