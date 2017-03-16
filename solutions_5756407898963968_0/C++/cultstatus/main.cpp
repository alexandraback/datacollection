/* 
 * File:   main.cpp
 * Author: warlock
 *
 * Created on April 11, 2014, 8:19 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int totalCases;
    int row;
    int currRow;
    int temp;
    int matches;
    int number;
    vector<int> v1, v2;
    
    scanf("%d", &totalCases);
    for(int tempCase = 1; tempCase <= totalCases; tempCase++)
    {
        v1.clear();
        v2.clear();
        
        /* First row ******************************/
        scanf("%d", &row);
        // Discard rows until chosen row
        currRow = 1;
        while(currRow++ < row)
            scanf("%d %d %d %d\n", &temp, &temp, &temp, &temp);
        // Fill vector with chosen row
        scanf("%d", &temp);
        v1.push_back(temp);
        scanf("%d", &temp);
        v1.push_back(temp);
        scanf("%d", &temp);
        v1.push_back(temp);
        scanf("%d", &temp);
        v1.push_back(temp);
        // Discard other rows
        while(currRow++ <= 4)
            scanf("%d %d %d %d\n", &temp, &temp, &temp, &temp);
        
        /* Second row *****************************/
        scanf("%d", &row);
        // Discard rows until chosen row
        currRow = 1;
        while(currRow++ < row)
            scanf("%d %d %d %d\n", &temp, &temp, &temp, &temp);
        // Fill vector with chosen row
        scanf("%d", &temp);
        v2.push_back(temp);
        scanf("%d", &temp);
        v2.push_back(temp);
        scanf("%d", &temp);
        v2.push_back(temp);
        scanf("%d", &temp);
        v2.push_back(temp);
        // Discard other rows
        while(currRow++ <= 4)
            scanf("%d %d %d %d\n", &temp, &temp, &temp, &temp);
        // Compare vectors
        matches = 0;
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                if(v1.at(i) == v2.at(j))
                {
                    matches++;
                    number = v1.at(i);
                }
            }
        }
        cout << "Case #" << tempCase << ": ";
        switch(matches)
        {
            case 0:
                cout << "Volunteer cheated!" << endl;
                break;
            case 1:
                cout << number << endl;
                break;
            default:
                cout << "Bad magician!" << endl;
        }
    }
    return 0;
}

