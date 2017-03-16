/* 
 * File:   main.cpp
 * Author: warlock
 *
 * Created on May 3, 2014, 11:32 AM
 */

#include <cstdlib>
#include <list>
#include <vector>
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <algorithm>
#include <string>

using namespace std;

string checkstr(string a)
{
    string res = "";
    res += a[0];
    for(int i = 1; i < a.length(); i++)
    {
        if(a[i] != a[i-1])
            res += a[i];
    }
    return res;
}

void solve(vector< string > a)
{
    string letter = checkstr(a[0]);
    vector< vector<int> > count;
    vector<int> temp;
    int c;
    int idx; 
    
    for(int i = 0; i < a.size(); i++)
    {
        c = 0;
        temp.clear();
        idx = 0;
//        cout<<"string "<<i<<" "<<a[i]<<"-"<<letter<<endl;
        for(int j = 0; j < a[i].length(); j++)
        {
            if(letter[idx] == a[i][j])
            {
                c++;
            }
            else
            {
                temp.push_back(c);
                c = 1;
                idx++;
            }
        }
        temp.push_back(c);
        count.push_back(temp);
        
//        for(int k = 0; k < temp.size(); k++) cout<<temp[k]<<" ";
//        cout<<endl;
    }
    
    int min;
    int rmin;
    int total = 0;
    
    for(int i = 0; i < count[0].size(); i++)
    {
        temp.clear();
        for(int j = 0; j < count.size(); j++)
        {
            temp.push_back(count[j][i]);
        }
        rmin = -1;
        for(int k = 0; k < temp.size(); k++)
        {
            c = temp[k];
            min = 0;
            for(int l = 0; l < temp.size(); l++)
            {
                min += abs(temp[l] - c);
            }
//            cout<<"min "<<min<<" rmin "<<rmin<<endl;
            if(rmin == -1) rmin = min;
            else
            {
                if(min < rmin) rmin = min;
            }
        }
        total += rmin;
//        cout<<"rmin "<<rmin<<endl;
    }
    cout<<total<<endl;
    
    
    
    
}

int main(int argc, char** argv) {
    int totalCases;
    int strings;
    string temp;
    vector<string> c;
    
//    freopen("log", "w", stderr);
    freopen("s.in", "r", stdin);
    freopen("out", "w", stdout);
    
    scanf("%d", &totalCases);
    for(int currCase = 1; currCase <= totalCases; currCase++)
    {
        scanf("%d", &strings);
        for(int i = 0; i < strings; i++)
        {
            cin >> temp;
            c.push_back(temp);
        }
        bool test = true;
        for(int i = 1; i < c.size(); i++)
        {
            if(checkstr(c[0]).compare(checkstr(c[i])) != 0)
                test = false;
        }
        
        cout << "Case #" << currCase << ": ";
        if(test)
        {
            solve(c);
        }
        else cout<<"Fegla Won"<<endl;
        c.clear();
        

    }
    
    
    
    return 0;
}

