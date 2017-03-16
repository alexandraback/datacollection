#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include <iterator>
using namespace std;

void display(int row)
{
    cout << ' ' << row;
}

int main(int argc, char* argv[])
{
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; ++test)
    {
        cout << "Case #" << test << ": ";
        int row;
        string dummy;
        cin >> row;
        set<int> rowdata;
        int data;
        for (int i=1; i<=4; ++i)
        {
            for (int j=0; j<4; ++j)
            {
                cin >> data;
                if (i==row)
                {
                    rowdata.insert(data);
                }
            }
        }
//        for_each(rowdata.begin(), rowdata.end(), display);
//        cout << endl;
        
        cin >> row;
        set<int> matches;
        for (int i=1; i<=4; ++i)
        {
            for (int j=0; j<4; ++j)
            {
                cin >> data;
                if (i==row)
                {
                    if (rowdata.find(data) != rowdata.end())
                    {
                        matches.insert(data);
                    }
                }
            }
        }
//        for_each(matches.begin(), matches.end(), display);
        if (matches.empty())
        {
            cout << "Volunteer cheated!" << endl;
        }
        else if (matches.size() == 1)
        {
            cout << *matches.begin() << endl;
        }
        else
        {
            cout << "Bad magician!" << endl;
        }
    }
    return 0;
}
