//
//  main.cpp
//  ProblemA
//
//  Created by Lydia Yang on 14-5-3.
//  Copyright (c) 2014年 杨荔雅5110309443. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int change(string str){
    int leng;
    leng = (int)str.size();
    char a;
    a = str[0];
    int tmp = 0;
    for (int j = 1; j < leng; j++) {
        if (a == str[j]) {
            tmp++;
        }
        else {
            a = str[j];
        }
    }
    return tmp;
    
}

string change2(string str){
    string tmp;
    int leng;
    leng = (int)str.size();
    char a;
    int tmp2 = 0;
    a = str[0];
    tmp += a;
    
    for (int j = 1; j < leng; j++) {
        if (a == str[j]) {
        }
        else {
            tmp2++;
            a = str[j];
            tmp += a;
        }
    }
    return tmp;
}

int main()
{
    ifstream in("/Users/apple/Desktop/in.txt");
    ofstream out("/Users/apple/Desktop/out.txt");
    
    int T;
    int N;
    
    string str[100];
    string str2[100];
    int ans;
    
    in >> T;
    for (int i = 0; i < T; i++) {
        in >> N;
        int chan[N];
        ans = 0;
        for (int j = 0; j < N; j++) {
            in >> str[j];
            chan[j] = change(str[j]);
            //cout<< chan[j]<<endl;
            str2[j] = change2(str[j]);
            //cout << str[j]<<endl;
        }
        
        for (int j = 0; j < N-1; j++) {
            if (str2[j] == str2[j+1]) {
                
            }
            else {
                ans = -1;
                break;
            }
        }
        
        if (ans < 0) {
            out << "Case #"<<i+1<<": Fegla Won"<<endl;
        }
        else {
            int size = (int)str2[0].size();
            int count[N][size];
            int leng;
            char a;
            int l;
            for (int j = 0; j < N; j++) {
                for (int k=0; k < size; k++) {
                    count[j][k] = 0;
                }
            }
            for (int jj = 0; jj < N; jj++) {
                leng = (int)str[jj].size();
                a = str[jj][0];
                l = 0;
                for (int k = 1; k < leng; k++) {
                    if (a == str[jj][k]) {
                        count[jj][l]++;
                    }
                    else {
                        a = str[jj][k];
                        l++;
                    }
                }
            }
            
            int count2[N];
            int flag;
            for (int l = 0; l < size; l++) {
                for (int j = 0; j < N; j++) {
                    count2[j] = 0;
                    
                }
                for (int j = 0; j < N; j++) {
                    for (int k = 0; k < N; k++) {
                        if (count[k][l]>count[j][l]) {
                            count2[j] += count[k][l]-count[j][l];
                        }
                        else count2[j] += count[j][l]-count[k][l];
                        
                    }
                    
                }
                flag = 0;
                for (int k = 0; k < N-1; k++) {
                    if(count2[k+1] < count2[flag]){
                        flag = k+1;
                    }
                }
                ans += count2[flag];
            }
            
            
            out << "Case #"<<i+1<<": "<<ans<<endl;
        }
        
        
    }
    
    
    in.close();
    out.close();
    return 0;
}
