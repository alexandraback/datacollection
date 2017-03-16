#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/// Duplicator of output into two different streams.
class CDoubleOutput
{
public:
    CDoubleOutput(ostream &stream1, ostream &stream2): stream1(stream1), stream2(stream2) { }
    
    /// normal output operator
    template<typename T>
    CDoubleOutput& operator<<(const T &value)
    {
        stream1 << value;
        stream2 << value;
        return *this;
    }
    /// operator that helps with manipulators
    CDoubleOutput& operator<<(std::ostream &(*fmanip)(std::ostream &))
    {
        fmanip(stream1);
        fmanip(stream2);
        return *this;
    }
    
private:
    ostream &stream1;
    ostream &stream2;
};

struct SCreditToSpend
{
    unsigned int index;
    unsigned int p;
    
    bool operator<(const SCreditToSpend& right) const
    {
        return p < right.p;
    }
};

/// quadratic algorithm at this case means approx. the same number of steps as the linear one
/// going for quadratic as it shows clearly what is happening
void SolveTestCase(int n, istream& inpStream, CDoubleOutput& outStream)
{
    unsigned int cards[4];
    // read the first arrangement
    unsigned int lineNum;
    inpStream >> lineNum;
    string dummy;
    for (unsigned int i = 1; i <= 4; ++i)
    {
        if (i == lineNum)
            inpStream >> cards[0] >> cards[1] >> cards[2] >> cards[3];
        else
            inpStream >> dummy >> dummy >> dummy >> dummy;
    }
    // read the second arrangement
    unsigned int commonCards = 0;
    unsigned int lastCommonCard = 0;
    inpStream >> lineNum;
    for (unsigned int i = 1; i <= 4; ++i)
    {
        if (i == lineNum)
        {
            for (unsigned int j = 0; j < 4; ++j)
            {
                unsigned int card;
                inpStream >> card;
                for (unsigned int k = 0; k < 4; ++k)
                {
                    if (cards[k] == card)
                    {
                        ++commonCards;
                        lastCommonCard = card;
                    }
                }
            }
        }
        else
            inpStream >> dummy >> dummy >> dummy >> dummy;
    }
    // print out the result
    outStream << "Case #" << n + 1 << ": ";
    switch (commonCards)
    {
        case 0:
            outStream << "Volunteer cheated!";
            break;
        case 1:
            outStream << lastCommonCard;
            break;
        default:
            outStream << "Bad magician!";
            break;
    }
    outStream << endl;
}

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        cerr << "No input file!" << endl;
        return 1;
    }
    ifstream inputFile(argv[1]);
    string outputFileName(argv[1]);
    outputFileName.replace(outputFileName.length() - 3, 3, ".out"); // ok, we know we do not need to check here
    ofstream outputFile(outputFileName);
    CDoubleOutput outputStream(cout, outputFile);
    unsigned int n;
    inputFile >> n;
    for (unsigned int i = 0; i < n; ++i)
        SolveTestCase(i, inputFile, outputStream);
    outputFile.flush();
    outputFile.close();
    return 0;
}
