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
        int idx[101] = {0};
        cin>>n;
        for(int i = 0;i < n; i++)
            cin>>str[i];
        int i = 0,j = 0;
        int count = 0;
        char curr;
        int ans = 0;
        while(1)
        {
            int single = 0,repeat = 0;
            curr = str[0][idx[0]];
            if(curr == '\0')
            {
                for(i = 0; i < n; i++)
                {
                    if(str[i][idx[i]] != '\0')
                    {
                        count = -1;
                        break;
                    }

                }
                break;
            }
            for(i = 0; i < n; i++)
            {
                if(curr != str[i][idx[i]])
                {
                    count = -1;
                    break;
                }
                if(str[i][idx[i]] == str[i][idx[i]+1])
                    repeat++;
                else    single++;
            }
            if(count == -1) break;
            if(single > repeat)
            {
                count += repeat;
            }
            else
                count += single;
            for(i = 0; i < n; i++)
            {
                if(str[i][idx[i]] == str[i][idx[i]+1])
                {
                    idx[i]++;
                }
                else if(single == n)
                    idx[i]++;
            }

        }
        if(count != -1)
            cout<<"Case #"<<x<<": "<<count<<endl;
        else
            cout<<"Case #"<<x<<": Fegla Won"<<endl;
    }
    return 0;
}
