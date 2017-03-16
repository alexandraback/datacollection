// Abdurrahman Akkas
// Google CodeJam 2014
// Qualification Round

#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ifstream fin("1.in");
    ofstream fout("1.out");
    int T,iT;
    fin>>T;
    for(iT=1;iT<=T;iT++){
        int row,els[4],dump,x,count=0;
        fin>>row;
        for(int i=1;i<=4;i++){
            if(i==row){
                fin>>els[0]>>els[1]>>els[2]>>els[3];
            }else fin>>dump>>dump>>dump>>dump;
        }
        fin>>row;
        for(int i=1;i<=4;i++){
            if(i==row){
                for(int k=0;k<4;k++){
                    fin>>dump;
                    for(int j=0;j<4;j++){
                        if(dump==els[j]){ count++;x=dump;}
                    }
                }
            }else fin>>dump>>dump>>dump>>dump;
        }
        fout<<"Case #"<<iT<<": ";
        if(count==0)
        fout<<"Volunteer cheated!";
        else if(count==1)
        fout<<x;
        else fout<<"Bad magician!";
        fout<<endl;
    }
    return 0;
}
