#include <iostream>

using namespace std;

int main()
{
    int t,m,n;
    int a[4][4],b[4][4];
    cin>>t;
    for (int ii = 0; ii < t; ++ii)
    {
        cin>>m;
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
            {
                cin>>a[i][j];
            }
        cin>>n;
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
            {
                cin>>b[i][j];
            }
        int sum = 0,x = -1;
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                if (a[m-1][i] == b[n-1][j])
                {
                    ++sum;
                    x = a[m-1][i];
                }
        cout<<"Case #"<<ii + 1<<": ";
        if (sum > 1)
        {
            cout<<"Bad magician!"<<endl;
        }else if (sum == 0){
            cout<<"Volunteer cheated!"<<endl;
        }else{
            cout<<x<<endl;
        }
    }
    return 0;
}

