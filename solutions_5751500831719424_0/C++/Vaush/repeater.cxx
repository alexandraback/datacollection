/*
 * senza nome.cxx
 * 
 * Copyright 2014 Vaush Wolf <healtyerslord@gmail.com>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <iostream>
#include <cstdio>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cstring>
#define ii pair<int,int>
#define iii pair<ii,int>
#define vi vector<int>
#define vii vector<ii>
#define viii vector<iii>
using namespace std;
vector<string> strings;
int** parts;
int** trans;
int** toInit;
int*** dist;
int partsV;
int n;
void initialize(){
	int idx = 0;
	idx++;
	for(int i = 1; i < (int)strings[0].size(); i++){
		if(strings[0][i] != strings[0][i-1]) idx++;
	}
	parts = new int*[n];
	trans = new int*[n];
	toInit = new int*[n];
	dist = new int**[n];
	for(int i = 0;i < n; i++){
		dist[i] = new int*[n];
		parts[i] = new int[idx];
		trans[i] = new int[idx];
		toInit[i] = new int[idx];
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < idx; j++){
			parts[i][j] = trans[i][j] = toInit[i][j] = 0;
		}
		for(int j = 0; j < n; j++){
			
			dist[i][j] = new int[idx];
			for(int k = 0; k < idx; k++) dist[i][j][k] = -1;
		}
	}
	partsV = idx;
}
string unique1(int idx){
	string s = strings[idx];
	
	int ind = 0;
	parts[idx][ind]++;
	string ret;
	/*for(int i = 0; i < partsV; i++){
		cout << parts[idx][i] << " ";
		
	}*/
	//cout << "///" << (int)s.size() << endl;
	for(int i = 1;i < (int)s.size(); i++){
		if(s[i] != s[i-1]){
			ret.push_back(s[i-1]);
			ind++;
			if(ind == partsV) return "---";
		}
		parts[idx][ind]++;
	}
	
	//cout << endl;
	return ret + s[s.size()-1];
}
int distance1(int i1, int i2, int part){
	
	if(dist[i1][i2][part] != -1){
		return dist[i1][i2][part];
	}
	dist[i1][i2][part] = dist[i2][i1][part] = abs(toInit[i1][part] - toInit[i2][part]);
	return abs(toInit[i1][part] - toInit[i2][part]);
}
int main(int argc, char **argv)
{
		freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int times;
	cin >> times;
	for(int time = 1; time <= times; time++){
		strings.clear();
		cin >> n;
		for(int i = 0; i < n; i++){
			string temp;
			cin >> temp;
			strings.push_back(temp);
		}
		initialize();
		string first = unique1(0);
		bool interr = false;
		for(int i = 1;i < n; i++){
			string cfr = unique1(i);
			if(first != cfr){
				interr = true;
				break;
			}
		}
		if(interr){
			cout << "Case #" << time << ": " << "Fegla Won" << endl;
			continue;
		}
		for(int i = 0;i < partsV; i++){
			trans[0][i] = 0;
		}
		for(int i = 1; i < n; i++){
			for(int j = 0;j < partsV; j++){
				trans[i][j] = parts[i][j] - parts[i-1][j];
			}
		}
		for(int i = 1; i < n; i++){
			for(int j = 0; j < partsV; j++){
				toInit[i][j] = toInit[i-1][j] + trans[i][j];
			}
		}
		/*for(int i = 0; i < n; i++){
			cout << "---- Num: " << i << endl;
			for(int j = 0; j < partsV; j++){
				cout << toInit[i][j] << " ";
			}
			cout << endl;
			for(int j = 0; j < partsV; j++){
				cout << trans[i][j] << " ";
			}
			cout << endl;
			for(int j = 0; j < partsV; j++){
				cout << parts[i][j] << " ";
			}
			cout << endl;
		}*/
		int* sol = new int[partsV];
		for(int i = 0;  i < partsV; i++){
			sol[i] = 1000000000;
		}
		int minimum = 0;
		for(int i = 0; i < partsV; i++){
			for(int j = 0; j < n; j++){
				int sum = 0;
				for(int k = 0; k < n; k++){
					if(k==j) continue;
					sum += distance1(j, k, i);
					//cout << "J: " << j << " K: " << k  << " I: " << i << " D: " << distance1(j,k,i) << endl;
				}
				if(sol[i] > sum) sol[i] = sum;
			}
			minimum += abs(sol[i]);
		}
		cout << "Case #" << time << ": " << minimum << endl;
	
	}
	return 0;
}

