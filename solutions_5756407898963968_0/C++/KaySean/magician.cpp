#include <iostream>
#include <fstream>
#include <sstream>

#include <string>
#include <list>
#include <vector>
#include <map>
#include <set>

#include <algorithm>

typedef std::set<int>  NumSet;
void readSpecifyRowToSet(std::ifstream & fin, NumSet & numset, int row)
{
    std::string line;
    int number = 0;
    for (int j = 1; j <= 4; ++j)
    {
        getline(fin, line);
        if (row != j)
        {
            continue;
        }

        std::stringstream ss(line);
        int k = 0;
        while (k++ < 4)
        {
            ss >> number;
            numset.insert(number);
        }
    }
}

void testMagician()
{
    // read case number
    std::ifstream fin("E:/testdata/magician/input.txt");
    std::string line;
    getline(fin, line);
    std::stringstream ss(line);
    int caseNumber;
    ss >> caseNumber;
    if (caseNumber <= 0)
    {
        return ;
    }

    std::ofstream fout("E:/testdata/magician/output.txt");
    for (int i = 1; i <= caseNumber; ++i)
    {
        // for one case.
        int firtRow, secondRow;
        NumSet firstRowSet;
        NumSet secondRowSet;
        
        // get first arrangements.
        getline(fin, line);
        if (line.empty())
        {
            continue;
        }
        std::stringstream ss(line);
        ss >> firtRow;
        readSpecifyRowToSet(fin, firstRowSet, firtRow);

        // get second arrangements.
        getline(fin, line);
        if (line.empty())
        {
            continue;
        }
        std::stringstream sss(line);
        sss >> secondRow;
        readSpecifyRowToSet(fin, secondRowSet, secondRow);

        int foundValue = 0, foundCount = 0;
        for (auto v : firstRowSet)
        {
            if (secondRowSet.find(v) != secondRowSet.end())
            {
                foundValue = v;
                foundCount++;
            }
        }

        if (1 == foundCount)
        {
            fout << "Case #" << i << ": " << foundValue << std::endl;
        }
        else if (0 == foundCount)
        {
            fout << "Case #" << i << ": " << "Volunteer cheated!" << std::endl;
        }
        else
        {
            fout << "Case #" << i << ": " << "Bad magician!" << std::endl;
        }
    }
    fin.close();
    fout.close();
}

int main()
{
    testMagician();
    return 0;
}