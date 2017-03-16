#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
    ifstream fin("A-small-attempt0.in");
    ofstream fout("A-small-attempt0.out");

    int T;
    fin>>T;
    for (int Test=1;Test<=T;Test++)
    {
    ///mainbody
        int N;
        fin>>N;
        int mushrooms[N];
        for(int i=0;i<N;i++)
            fin>>mushrooms[i];
        int counter1=0;
        int counter2=0;
        for (int i=N-1;i>0;i--)
        {
            if(mushrooms[i-1]>mushrooms[i])
                counter1+=mushrooms[i-1]-mushrooms[i];
        }
        int rate=0;
        for (int i=N-1;i>0;i--)
        {
            int d=mushrooms[i-1]-mushrooms[i];
            if(d>0)
            {
                rate=rate>d?rate:d;
            }
        }

        for(int i=0;i<N-1;i++)
        {
            if(mushrooms[i]<rate)counter2+=mushrooms[i];
            else counter2+=rate;
        }



        fout<<"Case #"<<Test<<": "<<counter1<<" "<<counter2<<"\n";

    }



    return 0;
}
