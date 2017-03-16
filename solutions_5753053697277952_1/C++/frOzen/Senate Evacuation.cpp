//
//  main.cpp
//  MagicTrick
//
//  Created by L on 14-4-12.
//  Copyright (c) 2014ๅนด L. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, const char * argv[])
{

    // insert code here...
    ifstream fin;
    ofstream fout;
    int case_count;
    fin.open("data.in",std::ofstream::in);
    fout.open("data.out",std::ofstream::out);
    fin>>case_count;
    string str;

    for (int step=0;step<case_count;step++)
    {
        int n;
        fin>>n;
        int p[27][2] = {0};
        int total = 0;
        for (int i=0;i<n;i++)
        {
            int x;
            fin>>x;
            p[i][0] = i;
            p[i][1] = x;
            total +=x;
        }
        for (int i=0;i<n;i++)
            for (int j=i+1;j<n;j++)
                if (p[i][1]<p[j][1])
        {
            swap(p[i][1],p[j][1]);
            swap(p[i][0],p[j][0]);
        }

        fout<<"Case #"<<step+1<<": ";

        while (total>0)
        {

            fout<<char('A'+p[0][0]);
            cout<<char('A'+p[0][0]);
            p[0][1]--;
            total--;
            int i=0;
            while ( (i+1<n)&&(p[i][1]<p[i+1][1]))
            {
                swap(p[i][0],p[i+1][0]);
                swap(p[i][1],p[i+1][1]);
                i++;
            }
            if (total==0) break;
            if (2 * p[0][1]>total)
            {
                fout<<char('A'+p[0][0]);
                cout<<char('A'+p[0][0]);
                p[0][1]--;
                total--;
                i=0;
                while ( (i+1<n)&&(p[i][1]<p[i+1][1]))
                {
                    swap(p[i][0],p[i+1][0]);
                    swap(p[i][1],p[i+1][1]);
                    i++;
                }

            }
            fout<<" ";
            cout<<" ";

        }

        fout<<endl;
        cout<<endl;

    }


    fin.close();
    fout.close();
    return 0;
}

