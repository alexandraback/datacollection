        #include <fstream>
        #include <iostream>
        #include <string>
        #include <stdio.h>
        #include <math.h>
        #include <limits>
        
        
        using namespace std;
        
        int main()
        {
            ofstream fout ("2014gcj1out.txt");
            ifstream fin ("2014gcj1in.txt");
            
            
            
            int t, n;
            int m;
            char aux;
            int res[100];
            int aux2;
            int res2;
            int v;
            
           
            fin >> t;
            
            for(int i=0; i<t; i++)
            {
            
            fin >> n;
            
            int pos[n];
            int auxres[n];
            int auxres2[n];
            int u[n];
            
            for(int j=0; j<n; j++)
            pos[j]=0;
            
            for(int j=0; j<n; j++)
            auxres[j]=0;
            
            string string[n];
            
            for(int j=0; j<n; j++)
            fin >> string[j];
            
            
            
            
            m = string[0].length();
            
            for(v=0; pos[0]<m; v++)
            {
            char aux = string[0][pos[0]];
            
            
            aux2 = 0;
            for(int k=0; k<n; k++)
            auxres[k]=0;
            
            for(int k=0; k<n; k++)
            auxres2[k]=0;
            
            for(int k=0; k<n; k++)
            u[k] = string[k].length();
            
            
            
            
            for(int k=0; k<n; k++)
            {
            if(string[k][pos[k]] != aux )
            {
            aux2=1;
            break;
            }
            else
            {
            for(; pos[k]<string[k].length();)
            {
            if(string[k][pos[k]] == aux)
            {
            pos[k]++;
            auxres[k]++;
            }
            else
            break;
            }
            }
                       
            
            }
            
            
            
            
            
            
            if(aux2==1)
            break;
            else
            {
            for(int k=0; k<n; k++)
            for(int l=0; l<n; l++)
            {
            if(auxres[k] > auxres[l])
            auxres2[k] = auxres2[k]+auxres[k]-auxres[l];
            else
            auxres2[k] = auxres2[k] + auxres[l] - auxres[k];
            }
            }
            
            
            
            res[v]=auxres2[0];
            
            for(int k=0; k<n; k++)
            if(auxres2[k] < res[v])
            res[v] = auxres2[k];
            }
            
            res2=0;
            
            for(int k=0; k<n; k++)
            if(pos[k] < string[k].length())
            aux2=1;
            
            for(int j=0; j<v; j++)
            res2 = res2+res[j];
            
            if(aux2==1)
            fout << "Case #" << i+1 << ": Fegla Won" << endl;
            else
            fout << "Case #" << i+1 << ": " << res2 << endl;
            
            
            }
            
            return 0;
              
        }
        
        
