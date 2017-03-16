#include <iostream>
#include <vector>

using namespace std;

bool inHalfspace(int x1, int y1, int x2, int y2, int ptx, int pty)
{
    long long nx = -(y2-y1);
    long long ny = x2-x1;
    if( nx*(ptx-x1) + ny*(pty-y1) > 0)
        return true;
    return false;
}

void doTest()
{
    int n;
    cin >> n;
    vector<int> x, y;
    for(int i=0; i<n; i++)
    {
        int tmp;
        cin >> tmp;
        x.push_back(tmp);
        cin >> tmp;
        y.push_back(tmp);
    }

    if(n == 1)
    {
        cout << endl << "0" << endl;
        return;
    }


    vector<int> chop;
    for(int i=0; i<n; i++)
        chop.push_back(n);

    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
        {
            int countleft=0,countright=0;
            for(int k=0; k<n; k++)
            {
                if(inHalfspace(x[i],y[i],x[j],y[j],x[k],y[k]))
                    countleft++;
                if(inHalfspace(x[j],y[j],x[i],y[i],x[k],y[k]))
                    countright++;
            }
            chop[i] = min(chop[i], countleft);
            chop[i] = min(chop[i], countright);
            chop[j] = min(chop[j], countleft);
            chop[j] = min(chop[j], countright);
        }

    cout << endl;
    for(int i=0; i<n; i++)
        cout << chop[i] << endl;
}


int main()
{
    int ncases;
    cin >> ncases;
    for(int i=0; i<ncases; i++)
    {
        std::cout << "Case #" << i+1 << ": ";
        doTest();
    }
}
