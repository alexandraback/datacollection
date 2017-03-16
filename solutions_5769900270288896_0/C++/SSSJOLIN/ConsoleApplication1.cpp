#include "stdafx.h"
#include <cmath>
#include <cstdio>
#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <set>
using namespace std;

int minunhappy;

void DFS(vector<vector<int>> &rooms,int index,int cells,int n,int R,int C){
    if (n == 0){
        int unhappy = 0;
        for (int i = 0; i < R; ++i){
            for (int j = 0; j < C; ++j){
                if (rooms[i][j]){
                    if (j < C - 1)
                        unhappy += rooms[i][j + 1];
                    if (i < R - 1)
                        unhappy += rooms[i + 1][j];
                }
            }
        }
        minunhappy = min(minunhappy, unhappy);
        return;
    }

    for (int i = index; i < cells; ++i){
        rooms[i / C][i%C] = 1;
        DFS(rooms,i+1,cells,n-1,R,C);
        rooms[i / C][i%C] = 0;
    }
}


int main(){
    int file = 1;
    ifstream fin;
    fin.open("F:/B-small-attempt1 (1).in");
    ofstream fout;
    fout.open("F:/output1.txt");

    int T;
    if (file)fin >> T;
    else
        cin >> T;
    for (int i = 0; i < T; ++i){
        int R, C, n;
        if (file)fin >> R>>C>>n;
        else
            cin >> R >> C >> n;

        int cells = R*C;
        
            vector<vector<int>> rooms(R, vector<int>(C, 0));
            minunhappy = INT_MAX;
            DFS(rooms, 0, cells, n, R, C);
        

        if (file)
            fout << "Case #" << i + 1 << ": " << minunhappy << endl;
        else
            cout << "Case #" << i + 1 << ": " << minunhappy << endl;
    }
    fin.close();
    fout.close();

    return 0;

}