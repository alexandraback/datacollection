#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t;
    int i;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        int n;
        cin>>n;

        string s1,s2;
        cin>>s1>>s2;
        
        int j;
        string t1,t2;
        
        t1.push_back(s1[0]);
        for(j=1;j<s1.length();j++) 
        {
            if(s1[j]!=s1[j-1])
              t1.push_back(s1[j]);
        }
        
        t2.push_back(s2[0]);
        for(j=1;j<s2.length();j++) 
        {
            if(s2[j]!=s2[j-1])
              t2.push_back(s2[j]);
        }
        if(t1.compare(t2) != 0)
        {

            printf("Case #%d: Fegla Won\n",i);
            continue;
        }
        int fp=0,sp =0;
        int ans = 0;
        while(fp<s1.length() && sp<s2.length())
        {
            if(s1[fp] == s2[sp]) 
            {
                fp++;
                sp++;
            }
            else
            {
                if(s1[fp]!=s1[fp-1])
                  sp++;
                else
                  fp++;
                ans++;
            }
        }
            ans+=(s1.length()-fp)+(s2.length()-sp);
            printf("Case #%d: %d\n",i,ans);
    }
}
