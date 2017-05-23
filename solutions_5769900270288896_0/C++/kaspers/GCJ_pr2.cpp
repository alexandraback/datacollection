#include<bits/stdc++.h>
using namespace std;
int check(int idx,int r,int c)
{
    int arr[16][16]={0},counter=0,i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(idx&(1<<((i*c)+j)))
            {
                arr[i][j]=1;
            }
        }
    }
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(arr[i][j]==1)
            {
                if(j<(c-1)&&arr[i][j+1]==1)
                    counter++;
                if(i<(r-1)&&arr[i+1][j]==1)
                    counter++;
            }
        }
    }
    return counter;
}
int main()
{
     freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    int j,i,n,t,r,c,counter,temp;
    int minima[19][26][20];
    for(i=0;i<17;i++)
    {
        for(j=0;j<17;j++)
        {
            for(r=0;r<17;r++)
                minima[i][j][r]=INT_MAX;
        }
    }
	cin>>t;
	for(r=1;r<=16;r++)
    {
        for(c=1;c<=16;c++)
        {
            if(r*c<=16){
            for(i=0;i<(1<<(r*c));i++)
            {
                counter=0;
                for(j=0;j<(r*c);j++)
                {
                    if(i&(1<<j)){
                            counter++;
                    }
                }
                temp=check(i,r,c);
                if(temp<minima[r][c][counter])
                    minima[r][c][counter]=temp;
                }
            }
        }
    }
        j=0;
	while(t--)
    {
        j++;
        cin>>r>>c>>n;
        cout<<"Case #"<<j<<": "<<minima[r][c][n]<<"\n";
    }
	return 0;
}
