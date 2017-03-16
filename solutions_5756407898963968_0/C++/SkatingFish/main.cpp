//
//  main.cpp
//  Magic
//
//  Created by Liubing Yu on 4/11/14.
//  Copyright (c) 2014 Liubing Yu. All rights reserved.
//
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>
#include <unordered_map>
using namespace std;

int main(int argc, const char * argv[])
{

    ifstream fin;
    ofstream fout;

    int T,m,n,i,j,k,num,key,needkey;
    int show[4][4];
    unordered_map<int,int> needmap;
    int show1[4][4];
    
    string result1;
    fin.open ("/Users/liubingyu/Desktop/A-small-attempt0.in.txt");
    fout.open("/Users/liubingyu/Desktop/A-small-attempt0.out.txt");
    fin>>T;
    std::cout << T<<"Hello, World!\n";
    for(j=0;j<T;j++){
        needmap.clear();
        fin>>needkey;
        needkey--;
        for(i=0;i<4;i++){
            fin>>show[i][0]>>show[i][1]>>show[i][2]>>show[i][3];
        }
        needmap[show[needkey][0]]=0;
        needmap[show[needkey][1]]=0;
        needmap[show[needkey][2]]=0;
        needmap[show[needkey][3]]=0;
        
        fin>>needkey;
        needkey--;
        for(i=0;i<4;i++){
            fin>>show[i][0]>>show[i][1]>>show[i][2]>>show[i][3];
        }
        num=0;
        if(needmap.find(show[needkey][0])!=needmap.end()){
            key=show[needkey][0];
            
            num++;
        }
        if(needmap.find(show[needkey][1])!=needmap.end()){
            key=show[needkey][1];
            num++;
        }
        if(needmap.find(show[needkey][2])!=needmap.end()){
            key=show[needkey][2];
            num++;
        }
        if(needmap.find(show[needkey][3])!=needmap.end()){
            key=show[needkey][3];
            num++;
        }

        //cout<<num<<endl;
        if(num==1){
            fout<<"Case #"<<j+1<<": "<<key<<endl;
            cout<<"Case #"<<j+1<<": "<<key<<endl;
        }
        else if(num==0){
            fout<<"Case #"<<j+1<<": Volunteer cheated!"<<endl;
            cout<<"Case #"<<j+1<<": Volunteer cheated!"<<endl;
        }
        else if(num>1&&num<5){
            fout<<"Case #"<<j+1<<": Bad magician!"<<endl;
            cout<<"Case #"<<j+1<<": Bad magician!"<<endl;
        }
        else {
            fout<<"Case #"<<j+1<<"ERROR "<<endl;
            cout<<"Case #"<<j+1<<"ERROR "<<endl;
        }

    }
    fin.close();
    fout.close();
    

        
}

