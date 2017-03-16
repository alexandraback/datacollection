//
//  main.cpp
//  google
//
//  Created by 張語航 on 2016/4/16.
//  Copyright © 2016年 張語航. All rights reserved.
//

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main() {
    ifstream openfile;
    fstream outfile;
    openfile.open("/Users/yuhang/Desktop/1.in");
    outfile.open("/Users/yuhang/Desktop/1.out", ios::out);
    int T;
    int N;
    openfile >> T;
    for (int cases = 1; cases <= T; cases++) {
        outfile << "Case #" << cases << ": ";
        openfile >> N;
        int temp[26]={0};
        for(int i=0;i<N;i++)
            openfile>>temp[i];
        if(N==2){
            for(int i=0;i<temp[0];i++){
                if(i!=0)outfile<<" ";
                outfile<<"AB";
            }
        }else{
            int nozero=N;
            for(;;){
                int maxindex=0;
                int max=temp[0];
                if(nozero==2){
                    for(int i=0;i<N;i++){
                        if(temp[i]){
                            outfile<<(char)('A'+i);
                            temp[i]--;
                        }
                    }
                }
                for(int i=0;i<N;i++){
                    if(temp[i]>max){max=temp[i];maxindex=i;}
                }
                if(max==0)break;
                temp[maxindex]--;
                if(temp[maxindex]==0)nozero--;
                outfile<<(char)('A'+maxindex)<<" ";
                
            }
        }

        outfile<<endl;
    }
    openfile.close();
    return 0;
}