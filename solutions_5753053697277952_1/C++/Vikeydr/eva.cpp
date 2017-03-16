#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int main(){
	int t;
	ifstream in("A-large.in");
	ofstream out("eva.out");
	in >> t;
	for (int tt = 0; tt < t; tt++){
		int n;
		int p[26];
		int sum = 0;
		in >> n;
		for (int i = 0; i < n;i++) {
				in >> p[i];
				sum += p[i];
			}
		vector<int> half;
		string res = "";
		int maxv, semaxv,maxi,semaxi;
		cout << tt << " " << sum << endl;
		while (sum >0){
		//	cout << sum << " " << res << endl;
		//	system("pause");
			half.clear();
			maxv = 0;semaxv = 0;
			for (int i = 0; i <n;i++){
				if (p[i] > maxv){
					semaxv = maxv;
					semaxi = maxi;
					maxi = i;
					maxv = p[i];
				}else if(p[i] > semaxv){
					semaxv = p[i];
					semaxi = i;
				}
				if (p[i] == sum /2) half.push_back(i);
			}
			if (half.size() > 0 && half.size() <= 2){
				for (int i = 0;i < half.size();i++){
					res += char(half[i]+65);
					p[half[i]] --;
				}
				res += " ";
				sum  = sum -half.size();
				continue;
			}
			if (half.size() > 2){
				res += char(maxi +65);
				p[maxi] --;
				res += " ";
				sum --;
				continue;
			}
			//cout << maxi << " " << semaxi << endl;
			res += char(maxi+65);
			res += char(semaxi+65);
			res += " ";
			p[maxi]--;p[semaxi]--;
			sum = sum-2;								
		}
		out << "Case #" << tt+1 << ": " << res << endl;
	
	}
	in.close();
	out.close();
	return 0;
}
