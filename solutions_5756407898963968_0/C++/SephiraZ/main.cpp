#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    int num1;
    int row[16];
    int rowans[4];
    int ans,ans2;
    int ansnum = 0,anstime = 0;
    ifstream myfile ("A-small-attempt1.in");
    ofstream myfile2 ("output.txt");
    myfile >> num1;
    for(int ro=1; ro<=num1;ro++)
{
    ans =0,ans2=0,ansnum=0,anstime=0;
    myfile >> ans;
    for(int i=0;i<16;i++)
    myfile >> row[i];
    if(ans == 1)
    {
    rowans[0] = row[0];
    rowans[1] = row[1];
    rowans[2] = row[2];
    rowans[3] = row[3];
    }
    else if(ans == 2)
    {
    rowans[0] = row[4];
    rowans[1] = row[5];
    rowans[2] = row[6];
    rowans[3] = row[7];
    }
    else if(ans == 3)
    {
    rowans[0] = row[8];
    rowans[1] = row[9];
    rowans[2] = row[10];
    rowans[3] = row[11];
    }
    else if(ans == 4)
    {
    rowans[0] = row[12];
    rowans[1] = row[13];
    rowans[2] = row[14];
    rowans[3] = row[15];
    }
    myfile >> ans2;
    for(int i=0;i<16;i++)
    myfile >> row[i];
    if(ans2 == 1)
    {
            for(int i=0;i<4;i++)
            {
            if(rowans[i] == row[0])
                         {
                         anstime = anstime+1;
                         ansnum = row[0];
                         }
                        if(rowans[i] == row[1])
                         {
                         anstime = anstime+1;
                         ansnum = row[1];
                         }
                         if(rowans[i] == row[2])
                         {
                         anstime = anstime+1;
                         ansnum = row[2];
                         }
                         if(rowans[i] == row[3])
                         {
                         anstime = anstime+1;
                         ansnum = row[3];
                         }
            }
    }
        if(ans2 == 2)
    {
            for(int i=0;i<4;i++)
            {
            if(rowans[i] == row[4])
                         {
                         anstime = anstime+1;
                         ansnum = row[4];
                         }
                        if(rowans[i] == row[5])
                         {
                         anstime = anstime+1;
                         ansnum = row[5];
                         }
                         if(rowans[i] == row[6])
                         {
                         anstime = anstime+1;
                         ansnum = row[6];
                         }
                         if(rowans[i] == row[7])
                         {
                         anstime = anstime+1;
                         ansnum = row[7];
                         }
            }
    }
        if(ans2 == 3)
    {
            for(int i=0;i<4;i++)
            {
            if(rowans[i] == row[8])
                         {
                         anstime = anstime+1;
                         ansnum = row[8];
                         }
                        if(rowans[i] == row[9])
                         {
                         anstime = anstime+1;
                         ansnum = row[9];
                         }
                         if(rowans[i] == row[10])
                         {
                         anstime = anstime+1;
                         ansnum = row[10];
                         }
                         if(rowans[i] == row[11])
                         {
                         anstime = anstime+1;
                         ansnum = row[11];
                         }
            }
    }
        if(ans2 == 4)
    {
            for(int i=0;i<4;i++)
            {
            if(rowans[i] == row[12])
                         {
                         anstime = anstime+1;
                         ansnum = row[12];
                         }
                        if(rowans[i] == row[13])
                         {
                         anstime = anstime+1;
                         ansnum = row[13];
                         }
                         if(rowans[i] == row[14])
                         {
                         anstime = anstime+1;
                         ansnum = row[14];
                         }
                         if(rowans[i] == row[15])
                         {
                         anstime = anstime+1;
                         ansnum = row[15];
                         }
            }
    }
    if(anstime == 1)
    myfile2 << "Case #" << ro << ": "<< ansnum<<endl;
    else if(anstime > 1)
    myfile2 << "Case #" << ro <<": " << "Bad magician!"<<endl;
    else if(anstime == 0)
    myfile2 << "Case #" <<ro << ": "<< "Volunteer cheated!"<<endl;
}
   // system("PAUSE");
    return EXIT_SUCCESS;
}
