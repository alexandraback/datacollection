#include <iostream>

using namespace std;

int R,C,N;

int calMinAns(bool * state,int curNum,int curGrid,int &minAns,int curAns)
{
   if(curNum == N)
   {
       minAns = (minAns<curAns) ? minAns : curAns;
       return 0;
    }

    if(curGrid>=R*C)
    {
        return 0;
    }

    if((R*C-curGrid)<(N-curNum))
    {
        return 0;
    }

    //²»Ìí¼Ó
    calMinAns(state,curNum,curGrid+1,minAns,curAns);

    state[curGrid] = true;

    int addNum =0;

    if((curGrid-1)>=0&&(curGrid-1)<R*C&&(state[curGrid-1]==true)&&((curGrid-1)/C == curGrid/C))
        {
            addNum++;
        }
    if((curGrid+1)>=0&&(curGrid+1)<R*C&&(state[curGrid+1]==true)&&((curGrid+1)/C == curGrid/C))
        {
            addNum++;
        }
    if((curGrid-C)>=0&&(curGrid-C)<R*C&&(state[curGrid-C]==true))
        {
            addNum++;
        }
    if((curGrid+C)>=0&&(curGrid+C)<R*C&&(state[curGrid+C]==true))
        {
            addNum++;
        }
    calMinAns(state,curNum+1,curGrid+1,minAns,curAns+addNum);

    state[curGrid] = false;

    return 0;

}
int main()
{
    int T;
    //int R,C,N;
    int curCase;
    int minAns;

    freopen("D:\\ccpptrain\\codejam1b2\\B-small-attempt0.in","r",stdin);
    freopen("D:\\ccpptrain\\codejam1b2\\noisyout.txt","w",stdout);
    cin>>T;
    curCase = 0;
    while(T)
    {
        T--;
        curCase++;
        bool state[16]={false};
        cin>>R>>C>>N;
        minAns = 0xffff;
        calMinAns(state,0,0,minAns,0);

        cout<<"Case #"<<curCase<<": "<<minAns<<endl;
    }
    return 0;



}
