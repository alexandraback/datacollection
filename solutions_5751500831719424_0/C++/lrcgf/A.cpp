#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

#include <boost/lexical_cast.hpp>
#include <boost/assign.hpp>

using namespace std;
using namespace boost;
using namespace boost::assign;



int main(int argc, char** argv)
{
    // ifstream in("in");
    //ofstream out("A-large-1.out");
    auto& in = cin;
    auto& out = cout;

    out << setprecision(7);

    string line;
    getline(in, line);
    int nLines = boost::lexical_cast<int>(line); 


    for (int caseNo=0; caseNo < nLines; ++caseNo)
    {
        out << "Case #" << caseNo+1 << ": ";
        
        string words[100];
        int charCount[100];

        int N;
        in >> N;

        string::iterator iters[100];
        for (int i=0; i<N; ++i)
        {
            in >> words[i];
            iters[i] = words[i].begin();
        }

        bool hasFailed = false;
        int totalCount = 0;

        while (iters[0] != words[0].end() && !hasFailed)
        {
            for (int i=0; i<N; ++i)
            {
                charCount[i] = 0;
            }
            char firstchar = *iters[0];
            for (int i=0; i<N; ++i)
            {
                while (*iters[i] == firstchar)
                {
                    iters[i]++;
                    charCount[i]++;
                }
                if (charCount[i] == 0)
                {
                    hasFailed = true;
                    break;
                }
            }

            sort(&charCount[0], &charCount[N]);
            int average = charCount[N/2];
            for (int i=0; i<N; ++i)
            {
                int diff = charCount[i] - average;
                if (diff < 0)
                {
                    diff = -1 * diff;
                }
                totalCount += diff;
            }
        }

        for (int i=0;i<N; ++i)
        {
            if (iters[i] != words[i].end())
            {
                hasFailed = true;
            }
        }
    
         
        for (int i=0; i<N;++i)
        {
            charCount[i]=0;
        }
    

        if (hasFailed)
        {
            out << "Fegla Won";
        }
        else
        {
            out << totalCount;
        }

        out << endl;
    }


    return 0;
}

