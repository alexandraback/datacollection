#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;
ofstream fout;

void solve(int* cand1, int* cand2){
   bool found = false;
   int answer;
   for(int i = 0; i < 4; i++){
      for(int j = 0; j < 4; j++){
         if(cand1[i] == cand2[j]){
            if(!found){
	       answer = cand1[i];
               found = true;
	    }
	    else{
	         fout << "Bad magician!\n";
		 return;
	    }
	 }  
      }
   }
   if(found)
      fout << answer << "\n";
   else
      fout << "Volunteer cheated!\n";
}

int main(){
   ifstream fin("A-small-attempt0.in");

   string buf;

   getline(fin, buf);
   int num = atoi(buf.c_str());
   int row1, row2;
   int cand1[4], cand2[4];


   fout.open("A-small-attempt0.out");
   int i, j;
   for(i = 0; i < num; i++){
      fout << "Case #" << (i + 1) << ": ";

      //1st
      getline(fin, buf);
      row1 = atoi(buf.c_str());
      for(j = 0; j < row1 - 1; j++){
         getline(fin, buf);
      }
      getline(fin, buf, ' ');
      cand1[0] = atoi(buf.c_str());
      getline(fin, buf, ' ');
      cand1[1] = atoi(buf.c_str());
      getline(fin, buf, ' ');
      cand1[2] = atoi(buf.c_str());
      getline(fin, buf, '\n');
      cand1[3] = atoi(buf.c_str());
      for(; j < 3; j++ ){
         getline(fin, buf);
      }

      //2nd
      getline(fin, buf);
      row2 = atoi(buf.c_str());
      for(j = 0; j < row2 - 1; j++){
         getline(fin, buf);
      }
      getline(fin, buf, ' ');
      cand2[0] = atoi(buf.c_str());
      getline(fin, buf, ' ');
      cand2[1] = atoi(buf.c_str());
      getline(fin, buf, ' ');
      cand2[2] = atoi(buf.c_str());
      getline(fin, buf, '\n');
      cand2[3] = atoi(buf.c_str());
      for(; j < 3; j++ ){
         getline(fin, buf);
      }

      solve(cand1, cand2);
   }

   fin.close();
   fout.close();
}
