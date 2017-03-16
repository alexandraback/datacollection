#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iomanip>
#include<fstream>
using namespace std;
int main()
{
    fstream fin,fout;
    fin.open("A-small-attempt1.in",ios::in);
    fout.open("A-small-attempt1.out",ios::out);
    int T;
    fin>>T;
    int a[4][4],b[4][4],m,n;
    for(int t=1;t<=T;++t)
    {
        fin>>m;
        --m;
        for(int i=0;i<4;++i)
            for(int j=0;j<4;++j)
                fin>>a[i][j];
        fin>>n;
        --n;
        for(int i=0;i<4;++i)
            for(int j=0;j<4;++j)
                fin>>b[i][j];
//        cout<<m+1<<"                     "<<n+1<<endl;
//        for(int i=0;i<4;++i)
//        {
//            for(int j=0;j<4;++j)
//                cout<<setw(2)<<a[i][j]<<' ';
//            cout<<"     ";
//            for(int j=0;j<4;++j)
//                cout<<setw(2)<<b[i][j]<<' ';
//            cout<<endl;
//        }
        int cnt=0,rec;
        for(int i=0;i<4;++i)
            for(int j=0;j<4;++j)
                if(a[m][i]==b[n][j])
                {
                    ++cnt;
                    rec=a[m][i];
                    break;
                }
        fout<<"Case #"<<t<<": ";
        if(cnt==0)
            fout<<"Volunteer cheated!"<<endl;
        else if(cnt==1)
            fout<<rec<<endl;
        else
            fout<<"Bad magician!"<<endl;
//        cout<<"Case #"<<t<<": ";
//        if(cnt==0)
//            cout<<"Volunteer cheated!"<<endl;
//        else if(cnt==1)
//            cout<<rec<<endl;
//        else
//            cout<<"Bad magician!"<<endl;
    }
    fin.close();
    fout.close();
    return 0;
}
