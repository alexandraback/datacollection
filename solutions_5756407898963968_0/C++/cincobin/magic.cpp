#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
int main(){
	FILE *fin;
    ofstream fout;
    vector<vector<int> > x;
    x.resize(4);
    for(int i = 0; i < 4; i++)
        x[i].resize(4);
    vector<vector<int> > y;
    y.resize(4);
    for(int i = 0; i < 4; i++)
        y[i].resize(4);
	fin=fopen("magic.in","r");
    fout.open("magic.out",std::ofstream::out); 
    int count, result, last;
	fscanf(fin, "%d", &count);
    for(int i = 0;  i < count; i++)
    {
        last = result = 0;
        int p, q;
		fscanf(fin, "%d", &p);
        for(int j = 0; j < 4; j++)
			fscanf(fin, "%d %d %d %d", &x[j][0], &x[j][1], &x[j][2], &x[j][3]);
		fscanf(fin, "%d", &q);
        for(int j = 0; j < 4; j++)
			fscanf(fin, "%d %d %d %d", &y[j][0], &y[j][1], &y[j][2], &y[j][3]);
        for(int j = 0; j < 4; j++)
            for(int k = 0; k < 4; k++)
            {
                if(x[p-1][j] == y[q-1][k])
                {
                    result ++;
                    last=x[p-1][j];
                }
            }
        if(result == 0)
            fout<<"Case #"<<i+1<<": "<<"Volunteer cheated!"<<endl;
        if(result == 1)
            fout<<"Case #"<<i+1<<": "<<last<<endl;
        if(result > 1)
            fout<<"Case #"<<i+1<<": "<<"Bad magician!"<<endl;
    }
	fclose(fin);
    fout.close();
    return 0;
}
