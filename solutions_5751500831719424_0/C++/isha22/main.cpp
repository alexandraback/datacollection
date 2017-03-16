#include <iostream>
#include<cstdio>
#include<string>
using namespace std;

int main()
{
    freopen("A-small-attempt2.in","r",stdin);
    freopen("output.in","w",stdout);
    int test,n,tt,i,j,c1,c2;
    string s1,s2;
    scanf("%d",&test);
    for(tt=1;tt<=test;tt++)
    {
        c1=0;c2=0;
        scanf("%d",&n);
        cin>>s1>>s2;
        i=0;j=0;
        while(1)
        {
            if(c1==-1)
            break;
            if(i==s1.size()&&j==s2.size())
            break;
            else if(i==s1.size())
            {
                while(j<s2.size())
                {
                    //cout<<"e";
                    if(j-1>=0&&s2[j]==s2[j-1])
                    {
                        c1++;
                        j++;
                    }
                    else
                    {
                        c1=-1;
                        break;
                    }
                }
            }
            else if(j==s2.size())
            {
                while(i<s1.size())
                {
                    //cout<<"f";
                    if(i-1>=0&&s1[i]==s1[i-1])
                    {
                        c1++;
                        i++;
                    }
                    else
                    {
                        c1=-1;
                        break;
                    }
                }
            }
            else if(s1[i]==s2[j])
            {
                i++;
                j++;
            }
            else if(i-1>=0&&s1[i-1]==s2[j])
            {
                c1++;
                j++;
            }
            else if(i-1>=0&&s1[i-1]==s1[i])
            {
                c1++;
                i++;
            }
            else
            {
                c1=-1;
                break;
            }
        }
        i=0;j=0;
        while(1)
        {
            if(c2==-1)
            break;
             if(i==s2.size()&&j==s1.size())
            break;
            else if(i==s2.size())
            {
                while(j<s1.size())
                {
                    //cout<<"g";
                    if(j-1>=0&&s1[j]==s1[j-1])
                    {
                        c2++;
                        j++;
                    }
                    else
                    {
                        c2=-1;
                        break;
                    }
                }
            }
            else if(j==s1.size())
            {
                while(i<s2.size())
                {
                   // cout<<"h";
                    if(i-1>=0&&s2[i]==s2[i-1])
                    {
                        c2++;
                        i++;
                    }
                    else
                    {
                        c2=-1;
                        break;
                    }
                }
            }
            else if(s2[i]==s1[j])
            {
                i++;
                j++;
            }
            else if(i-1>=0&&s2[i-1]==s1[j])
            {
                c2++;
                j++;
            }
            else if(i-1>=0&&s2[i-1]==s2[i])
            {
                c2++;
                i++;
            }
            else
            {
                c2=-1;
                break;
            }
        }
        printf("Case #%d: ",tt);
        if(c1==-1&&c2==-1)
        printf("Fegla Won\n");
        else if(c1==-1)
        printf("%d\n",c2);
        else if(c2==-1)
        printf("%d\n",c1);
        else
        printf("%d\n",min(c1,c2));
    }
    return 0;
}
