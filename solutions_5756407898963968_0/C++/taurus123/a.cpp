#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int T;
    cin >> T;
    for(int caseIdx = 1; caseIdx <= T; ++ caseIdx)
    {
        vector<int> cards[2];
        for(int answerIdx = 0; answerIdx < 2; ++ answerIdx)
        {
            int answer;
            cin >> answer;
            for(int row = 0; row < 4; ++ row)
                for(int col = 0; col < 4; ++ col)
                {
                    int elem;
                    cin >> elem;
                    if( row == answer - 1)
                    {
                        cards[answerIdx].push_back(elem);
                    }
                }
        }
        int nCount = 0;
        int numOnCard = 0;
        for(vector<int>::const_iterator iIter = cards[0].begin(); iIter != cards[0].end(); ++ iIter)
        {
            for(vector<int>::const_iterator jIter = cards[1].begin(); jIter != cards[1].end(); ++ jIter)
            {
                if(*iIter == *jIter)
                {
                    ++ nCount;
                    numOnCard = *iIter;
                }
            }
        }
        switch(nCount)
        {
        case 0:
            cout << "Case #" << caseIdx << ": Volunteer cheated!" << endl;
            break;
        case 1:
            cout << "Case #" << caseIdx << ": " << numOnCard << endl;
            break;
        default:
            cout << "Case #" << caseIdx << ": Bad magician!" << endl;
        }

    }
    return 0;
}
