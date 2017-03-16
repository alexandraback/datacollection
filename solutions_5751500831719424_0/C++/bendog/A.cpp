#include<iostream>
#include<cstdio>
#include<cstring>
#define SIZE 128
using namespace std;
char s1[SIZE],s2[SIZE];
int main()
{
   // freopen("A-small-attempt1.in","r",stdin);
  //  freopen("A-small.txt","w",stdout);
    int cas;cin>>cas;
    for(int q=1;q<=cas;q++)
    {
        int n;cin>>n;
        cin>>s1>>s2;
        char *a1,*a2;
        a1 = s1;a2= s2;
        int l1 = strlen(s1);
        int l2 = strlen(s2);
        int f1,f2;
        f1 = 0;f2=0;
        int sol = 0;
        bool has = true;
        while(has && f1 < l1 && f2 < l2)
        {
            char ch;
            if(a1[f1]!=a2[f2])has = false;
            else
            {
                ch = a1[f1];
                int t1,t2;
                t1 = f1;t2 = f2;
                while(t1<l1 && ch == a1[t1])t1++;
                while(t2<l2 && ch == a2[t2])t2++;

                sol+= (t1-f1 > t2-f2) ? (t1-f1-t2+f2) : (t2-f2-t1+f1);
                f1 = t1; f2 = t2;
            }
        }
        if(f1<l1 || f2 < l2)has = false;
        if(has)
        cout<<"Case #"<<q<<": "<<sol<<endl;
        else
        cout<<"Case #"<<q<<": Fegla Won"<<endl;

    }

    return 0;
}
