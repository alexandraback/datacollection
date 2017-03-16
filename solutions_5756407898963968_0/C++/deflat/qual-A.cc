#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<fstream>
#include<sstream>
#include<algorithm>
#include<vector>
#include<string>
#include<climits>


int main(int argc,char* argv[]){
    if(argc!=2){
        std::cerr<<"filename missing \n";
        return 1;
    }
    std::ifstream ifs(argv[1]);
    std::ofstream ofs("output.txt");
    std::string str;
    int T;
    ifs>>T;
    
    
    bool map[17];
    int tg,num;
    for(int CASE=0;CASE++<T;){
        int retnum=0;
        
        for(int i=1;i<17;i++){
            map[i]=false;
        }
        ifs>>tg;
        tg--;
        for(int i=0;i<16;i++){
            ifs>>num;
            if(i/4==tg) map[num]=true;
        }
        ifs>>tg;
        tg--;
        int j;
        bool flag=false;
        for(j=0;j<16;j++){
            ifs>>num;
            if(!flag&&j/4==tg&&map[num]){
                if(retnum!=0){
                    flag=true;
                }else{
                    retnum=num;
                }
            }
        }
        if(flag) ofs<<"Case #"<<CASE<<": "<<"Bad magician!"<<"\n";
        else if(retnum==0) ofs<<"Case #"<<CASE<<": "<<"Volunteer cheated!"<<"\n";
        else ofs<<"Case #"<<CASE<<": "<<retnum<<"\n";
    }
    
    
    ofs.close();
    return 0;
}