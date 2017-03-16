#include <iostream>
#include <cstdio>
using namespace std;
string str[101];

int main()
{
    freopen("input.in","r",stdin);
    freopen("output.txt","w",stdout);
    int x,t;
    cin>>t;
    for(x = 1; x <= t; x++)
    {
        int n;
        cin>>n;
        for(int i = 0;i < n; i++)
            cin>>str[i];
        int i = 0,j = 0;
        int count = 0;
        while(str[0][i] != '\0' || str[1][j] != '\0')
        {
            if(str[0][i] == str[1][j])
            {
                i++;
                j++;
            }
            else
            {
                if(i > 0 && str[0][i] == str[0][i-1])
                {
                    i++;
                    count++;
                }
                else if(j > 0 && str[1][j] == str[1][j-1])
                {
                    j++;
                    count++;
                }
                else
                {
                    count = -1;
                    break;
                }
            }
        }
        if(count != -1)
            cout<<"Case #"<<x<<": "<<count<<endl;
        else
            cout<<"Case #"<<x<<": Fegla Won"<<endl;
    }
    return 0;
}
