/* Code Jam 2014
 * Task: Magic Trick
 * User: SmBe19 (Benjamin Schmid)
*/

#include <iostream>

using namespace std;

int main()
{
    int tcn;
    cin >> tcn;
    for(int tc = 1; tc <= tcn; tc++)
    {
        int sol = 0;
        int a;
        cin >> a;
        bool pos[16];
        for(int i = 0; i < 16; i++)
            pos[i] = false;
        for(int i = 0; i < 4; i++)
        {
            int inp[4];
            for(int j = 0; j < 4; j++)
                cin >> inp[j];
            if(a - 1 == i)
                for(int j = 0; j < 4; j++)
                    pos[inp[j]-1] = true;
        }
        cin >> a;
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                int tmp;
                cin >> tmp;
                if(a - 1 == i && pos[tmp-1])
                {
                    if(sol == 0)
                        sol = tmp;
                    else
                        sol = -1;
                }
            }
        }

        cout << "Case #" << tc << ": ";
        if(sol > 0)
            cout << sol << endl;
        if(sol == -1)
            cout << "Bad magician!" << endl;
        if(sol == 0)
            cout << "Volunteer cheated!" << endl;
    }
    return 0;
}
