#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
#define SZ 100
//vector<int> seglen;//to store the length of each segment of the string
int ar[SZ][101];//first index denotes segment  number
int segmedian[SZ];
int segno=0;int n;

int absolute(int a,int b)
{
    if(a>b)return (a-b);
    return (b-a);
}

int find_diff(string s[SZ])
{
    //find  median length of each segment
    //cout<<segno<<endl;
    int median;
    if(n%2){median=(n/2)+1;}
    else{median=(n/2);}
    int count;
    for(int i=0;i<segno;++i)
    {
        count=0;
        for(int j=1;j<=100;++j)
        {
            //cout<<ar[i][j]<<" ";
            if((count+ar[i][j])>=median){segmedian[i]=j;break;}
            count+=ar[i][j];
        }
        //cout<<endl;cout<<segmedian[i]<<endl;
    }
    //cout<<endl;
    long long int diff=0;
    for(int i=0;i<segno;++i)
    {
        for(int j=1;j<=100;++j)
        {
            diff+=ar[i][j]*absolute(j,segmedian[i]);
        }
    }
    return diff;
}

string process(string s)
{
    string snew="";
    snew=snew+(s[0]);
    int curlen=1;
    int seg=0;
    for(int i=1;i<s.length();++i)
    {
        if(s[i]!=s[i-1])
        {
            //seglen[sno].push_back(curlen);//segment ends at i-1, new segment begins at i
            ar[seg++][curlen]++;
            curlen=1;
            snew.push_back(s[i]);
        }
        else
        {
            curlen++;
        }
    }
    //seglen[sno].push_back(curlen);//last segment
    ar[seg++][curlen]++;
    segno=seg;
    return snew;
}

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("output2.txt","w",stdout);
    int t;cin>>t;int testcaseno=1;
    while(t--)
    {
        for(int i=0;i<SZ;++i)
        {
            for(int j=0;j<SZ;++j)ar[i][j]=0;
        }
        cin>>n;
        string str[n],str1,target;
        bool flag=true;
        int start=1;
        for(int i=0;i<n;++i)
        {
            cin>>str[i];
            str1=process(str[i]);
            if(start==1){start=0;target=str1;}
            else{
                if(target!=str1)//not equal
                {
                    flag=false;break;
                }
            }
        }
        cout<<"Case #"<<testcaseno<<": ";
        if(flag==false)
        {
            cout<<"Fegla Won\n";
        }
        else{
            cout<<find_diff(str)<<endl;
        }
        testcaseno++;
    }
    return 0;
}
