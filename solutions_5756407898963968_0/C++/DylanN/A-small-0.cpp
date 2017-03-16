#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int test=1; test<=T; test++)
    {
        int row, temp;
        cin >> row;
        bool poss[17]={};
        for (int i=1; i<row; i++) cin >> temp >> temp >> temp >> temp;
        for (int i=0; i<4; i++) {cin >> temp; poss[temp]=true;}
        for (int i=row; i<4; i++) cin >> temp >> temp >> temp >> temp;
        int output = 0;
        bool found = false, found2=false;;
        cin >> row;
        for (int i=1; i<row; i++) cin >> temp >> temp >> temp >> temp;
        for (int i=0; i<4; i++)
        {
            cin >> temp;
            if (poss[temp])
            {
                output=temp;
                if (found) found2=true;
                found=true;
            }
        }
        for (int i=row; i<4; i++) cin >> temp >> temp >> temp >> temp;
        cout << "Case #" << test << ": ";
        if (found2) cout << "Bad magician!" << endl;
        else if (found) cout << output << endl;
        else cout << "Volunteer cheated!" << endl;
    }
    return 0;
}
