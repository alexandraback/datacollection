#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    ifstream input;
    input.open("inp.txt");
    ofstream output;
    output.open("out.txt");
    int T;
    input>>T;
    for (int i=0 ; i<T ; i++)
    {
        output<<"Case #"<<i+1<<": ";
        int N;
        input>>N;
        int A[N],Sum=0;
        for (int j=0 ; j<N ; j++)
        {
            input>>A[j];
            Sum+=A[j];
        }
        while (1)
        {
            int large=-1, poi=-1,a,b,ch=0,tok=0,sec=-1;
            for (int j=0 ; j<N ; j++)
            {
                if((large==-1 || A[j]>large) && A[j]!=0)
                {
                    large=A[j];
                    poi=j;
                    tok=0;
                }
                else if(large==A[j] && large!=-1)
                {
                    tok++;
                    sec=j;
                }
            }
            char c=poi+'A';
            if(large!=-1)
            {
                if(tok!=1)
                {
                    output<<c<<" ";
                    //output<<poi<<" "<<A[poi]<<endl;
                    A[poi]-=1;
                    Sum-=1;
                }
                else
                {
                    output<<c;
                    c=sec+'A';
                    output<<c<<" ";
                    Sum-=2;
                    A[poi]--;
                    A[sec]--;
                }
            }
            else
                break;
        }
        output<<endl;
    }
}
