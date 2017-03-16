#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
int N;
vector<int> mush;
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    int T,x;
    cin >> T;

    for(int t=0; t<T; t++)
    {
        mush.clear();

        cin >> N;

        for(int i=0; i<N; i++)
        {
            cin >> x;
            mush.push_back(x);
        }

        int min1= 0;
        int maxi=0;

        for(int i=0; i<N-1; i++)
        {
            if(mush[i] > mush[i+1])
                min1 += (mush[i] - mush[i+1]);
        }

        //int minToEat = mush[N-2] - mush[N-1];
        //if(minToEat<0)
        //    minToEat = 0;

        for(int i=0; i<N; i++)
        {
            maxi = max(maxi,mush[i]);
        }

        bool flag = false;
        int minToEat;
        for(int i=0; i<=maxi; i++)
        {
            flag = false;
            for(int j=0; j<N-1; j++)
            {
                if( (mush[j]-mush[j+1]) <= i)
                    continue;
                else
                    flag=true;
            }

            if(!flag)
            {
                minToEat = i;
                break;
            }
        }

        int min2=0;
        for(int i=0; i<N-1; i++)
        {
            if(mush[i] >= minToEat)
                min2 += minToEat;
            else
                min2 += mush[i];
        }

        cout << "Case #" << t+1 << ": " << min1 << " " << min2 << endl;
    }
    return 0;
}
