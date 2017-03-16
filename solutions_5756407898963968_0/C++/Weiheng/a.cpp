#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr1[4][4],arr2[4][4];
    int r1,r2;
    int i,j;
    int t=1;
    while(n>0)
    {
        cin>>r1;
        r1-=1;
        for(i=0;i<4;i++)
            for(j=0;j<4;j++)
                cin>>arr1[i][j];
        cin>>r2;
        r2-=1;
        for(i=0;i<4;i++)
            for(j=0;j<4;j++)
                cin>>arr2[i][j];
        int cnt=0;
        int ans=0;
        for(i=0;i<4;i++)
            for(j=0;j<4;j++)
                if(arr1[r1][i]==arr2[r2][j]){
                    cnt++;
                    ans=arr1[r1][i];
                }
        cout<<"Case #"<<t++<<": ";
        if(cnt==0)
        {
            cout<<"Volunteer cheated!"<<endl;
        }
        else if(cnt>1)
        {
            cout<<"Bad magician!"<<endl;
        }
        else
        {
            cout<<ans<<endl;
        }
        n--;
    }
    return 0;
}
