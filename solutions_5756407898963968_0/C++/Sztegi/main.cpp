#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

struct TestCase
{

    vector< vector<int> > _cards1;
    vector< vector<int> > _cards2;

    int _answer1;
    int _answer2;

    string answer()
    {
        int count = 0;
        int card = 0;

        vector<int> &row2 = _cards2[_answer2-1];

        for(int i = 0; i <4; ++i)
        {
            if(row2.end() != find(row2.begin(), row2.end(), _cards1[_answer1-1][i]))
            {
                card = _cards1[_answer1-1][i];
                ++count;
            }
        }

        if(count == 0) return  "Volunteer cheated!";

        if(count == 1)
        {
            char buf[3];
            sprintf(buf, "%d", card );
            return  string(buf);
        }

        return "Bad magician!";
    }

};

int main()
{
    ifstream in("in.txt");
    ofstream out("out.txt");

    int t;
    string line;

    {
        std::getline(in, line);
        istringstream iss(line);
        iss >> t;
    }

    for(int i = 0; i < t; ++i)
    {
        TestCase testCase;

        {
            std::getline(in, line);
            istringstream iss(line);
            iss >> testCase._answer1;
        }

        for(int j = 0; j < 4; ++j)
        {
            std::getline(in, line);
            istringstream iss(line);

            vector<int> row(4);
            iss >> row[0] >> row[1] >> row[2] >> row[3];
            testCase._cards1.push_back(row);
        }

        {
            std::getline(in, line);
            istringstream iss(line);
            iss >> testCase._answer2;
        }

        for(int j = 0; j < 4; ++j)
        {
            std::getline(in, line);
            istringstream iss(line);

            vector<int> row(4);
            iss >> row[0] >> row[1] >> row[2] >> row[3];
            testCase._cards2.push_back(row);
        }

        out << "Case #" << i + 1 << ": " << testCase.answer() << endl;
    }

    return 0;
}


