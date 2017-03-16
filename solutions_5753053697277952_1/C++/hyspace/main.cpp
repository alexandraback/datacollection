//
//  main.cpp
//  c
//
//  Created by hyspace on 4/8/16.
//  Copyright © 2016 hyspace. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

string check(string s){
    return "";
}

int main(int argc, const char * argv[]) {
    std::ifstream infile("A-large.in");
    std::ofstream outfile("A-large.out");
    std::string line;
    std::getline(infile, line);
    int total = atoi(line.c_str());

    
    for (int i = 0; i < total; ++i){
        std::getline(infile, line);
        
        int length = atoi(line.c_str());
        
        std::string singleLine;
        std::getline(infile, singleLine);
        
        multimap<int, char, std::greater<int>> ma;
        string buf;
        stringstream ss(singleLine);
        
        char now = 'A';
        while (ss >> buf){
            ma.insert(pair<int, char>(atoi(buf.c_str()), now));
            now++;
        }
        
        vector<string> res;
        
        while(true){
            string ans;
            auto it = ma.begin();
            int num = it->first;
            char party = it->second;
            
            if(num == 0 || it == ma.end())break;
            ans += party;
            if(num == 1 && ma.size() % 2){
                ma.erase(it);
                if(num - 1 > 0)ma.insert(pair<int, char>(num - 1, party));
                res.push_back(ans);
                continue;
            }
            
            auto it2 = ++it;
            --it;
            int num2 = it2->first;
            char party2 = it2->second;
            if(num == 0 || it2 == ma.end()){
                ma.erase(it);
                if(num - 1 > 0)ma.insert(pair<int, char>(num - 1, party));
                res.push_back(ans);
            }
            else if(num2 != num){
                ma.erase(it);
                if(num - 1 > 0)ma.insert(pair<int, char>(num - 1, party));
                res.push_back(ans);
            }else{
                ans += party2;
                ma.erase(it);
                if(num - 1 > 0)ma.insert(pair<int, char>(num - 1, party));
                ma.erase(it2);
                if(num - 1 > 0)ma.insert(pair<int, char>(num2 - 1, party2));
                res.push_back(ans);
            }
            
        }
        
        string ans = "";
        for(auto str:res)
            ans += " " + str;
            
        outfile << "Case #" << i+1 << ":" << ans << endl;

    }
}
