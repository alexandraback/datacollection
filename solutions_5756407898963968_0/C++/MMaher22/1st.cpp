#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<fstream>
#include<string.h>
#include<stack>
#include<queue>
using namespace std;
int main()
{
     ifstream cin ("A-small-attempt0.in");
    ofstream cout ("clocks.out");
    int n;
    cin>>n;
    for(int counter=1;counter<=n;counter++)
    {
        int arr1[5],arr2[5];
        int n1,n2,i,j,k;
        cin>>n1;
        for(i=1;i<5;i++)
        {
            for(j=1;j<5;j++)
            {
                if(i==n1)
                cin>>arr1[j];
                else
                cin>>k;
            }
        }
        cin>>n2;
        for(i=1;i<5;i++)
        {
            for(j=1;j<5;j++)
            {
                if(i==n2)
                cin>>arr2[j];
                else
                cin>>k;
            }
        }
        int check=0;
        for(i=1;i<=5;i++)
        {
            for(j=1;j<=5;j++)
            {
                if(arr1[i]==arr2[j])
                {
                    if(check!=0)
                    {
                        check=999;break;
                    }
                    check=arr1[i];
                }
            }
            if(check==999)break;
        }
        cout<<"Case #"<<counter<<": ";
        if(check==0)
        cout<<"Volunteer cheated!"<<endl;
        else if(check==999)
        cout<<"Bad magician!"<<endl;
        else
        cout<<check<<endl;
    }
return 0;
}
