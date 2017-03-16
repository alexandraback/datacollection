#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int absolute(int a,int b)
{
    if(a>b)return (a-b);
    return (b-a);
}

int find_diff(string a,string b)
{
    //cout<<a<<" "<<b<<endl;
    int n=a.length();
    int m=b.length();
    //first characters must match
    int i=1,j=1;
    int count=0;
    while(i<n && j<m)
    {
        if(a[i]==b[j]){i++;j++;}
        else
        {
            if(a[i]==a[i-1]){i++;}//collapse repitition in a
            else {j++;}//collapse repitition in b
            count++;
        }
    }
    if(i==n)count+=(m-j);
    else count+=(n-i);
    return count;
}

string process(string s)
{
    string snew="";
    snew=snew+(s[0]);
    for(int i=1;i<s.length();++i)
    {
        if(s[i]!=s[i-1])snew.push_back(s[i]);
    }
    return snew;
}

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("output.txt","w",stdout);
    int t;cin>>t;int testcaseno=1;
    while(t--)
    {
        int n;string str[2],str1,target;
        cin>>n;bool flag=true;
        int diff=0;int start=1;
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
        else //for small dataset
        {
            //find_median();
            //cout<<str[0]<<" "<<str[1]<<endl;
            cout<<find_diff(str[0],str[1])<<endl;
        }
        testcaseno++;
    }
    return 0;
}
