#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstdlib>
#include <vector>

using namespace std;
int board1[4],board2[4];

int main()
{
    int T;
    cin>>T;
    int N1,N2,temp,I=0;
    while(T--)
    {
        I++;
        cin>>N1;
        vector<int> v(5);
        vector<int>::iterator it;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                if(i==N1-1)
                    cin>>board1[j];
                else
                    cin>>temp;
            }
        }
        cin>>N2;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                if(i==N2-1)
                    cin>>board2[j];
                else
                    cin>>temp;

            }
        }

        sort(board1,board1+4);
        sort(board2,board2+4);
       // for(int i=0;i<4;i++)
        //    cout<<board1[i]<<' '<<board2[i]<<endl;
        it=std::set_intersection (board1, board1+4, board2, board2+4, v.begin());
        v.resize(it-v.begin());
        //cout<<v.size()<<endl;
        if(v.size()==1)
            cout<<"Case #"<<I<<": "<<v[0]<<endl;
        else if(v.size()==0)
            cout<<"Case #"<<I<<": Volunteer cheated!"<<endl;
        else
            cout<<"Case #"<<I<<": Bad magician!"<<endl;
    }

}
