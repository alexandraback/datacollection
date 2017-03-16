#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
   //Eingabe des Dateinamens über Konsole oder Übergabe als Eingabeparameter
   char* filename;
   if(argc > 1)
   {
      filename = argv[1];
   }
   else
   {
      char buffer[256];
      cout << "Input file name (up to 255 Characters): " << endl;
      cin >> buffer;
      filename = buffer;
   }
   
   int T = 0;
   
   try
   {    
      ifstream datei(filename);
      if(!datei.is_open())
         throw 1;
      
      if(!datei.good())
         throw 2;
      datei >> T;
      if(T <= 0)
         throw 3;
      
      
      for(int k0 = 0; k0 < T; k0++)
      {
         cout << "Case #" << k0+1 << ": ";
         
         
         //start
         int N;
         datei >> N;
         
         int P[N];
         char A[N];
         int S = 0;
         for(int i = 0; i < N; i++)
         {
		 	datei >> P[i];
		 	S += P[i];
		 	A[i] = (char) ('A' + i);
		 }
		 
		 for(int i = 0; i < N; i++)
		 {
		 	int max = i;
		 	for(int j = i; j < N; j++)
		 	{
		 		if(P[j] > P[max])
		 		{
		 			max = j;
				}
			}
			int temp = P[i];
			P[i] = P[max];
			P[max] = temp;
			char temp2 = A[i];
			A[i] = A[max];
			A[max] = temp2;
		 }
		 
		 
		 while(S > 3)
		 {
			/*cout << "Stats: ";
			for(int i = 0; i < N; i++)
			{
				cout << A[i] << ": " << P[i] << ", ";
			}
			cout << endl;*/
		 	cout << A[0] << A[1] << " ";
		 	P[0]--;
		 	P[1]--;
		 	S -= 2;
		 	
		 	//resort
		 	for(int i = 2; i < N; i++)
		 	{
		 		if(P[i] < P[1])
		 		{
		 			int temp = P[1];
		 			P[1] = P[i-1];
		 			P[i-1] = temp;
		 			char temp2 = A[1];
		 			A[1] = A[i-1];
		 			A[i-1] = temp2;
		 			
		 			break;
				}
				if(i == N-1)
				{
					int temp = P[1];
		 			P[1] = P[i];
		 			P[i] = temp;
		 			char temp2 = A[1];
		 			A[1] = A[i];
		 			A[i] = temp2;
		 			
		 			break;
				}
			}
			
			for(int i = 1; i < N; i++)
		 	{
		 		if(P[i] < P[0])
		 		{
		 			int temp = P[0];
		 			P[0] = P[i-1];
		 			P[i-1] = temp;
		 			char temp2 = A[0];
		 			A[0] = A[i-1];
		 			A[i-1] = temp2;
		 			
		 			break;
				}
				if(i == N-1)
				{
					int temp = P[0];
		 			P[0] = P[i];
		 			P[i] = temp;
		 			char temp2 = A[0];
		 			A[0] = A[i];
		 			A[i] = temp2;
		 			
		 			break;
				}
			}
		 }
		 
		 if(S == 3)
		 {
		 	cout << A[0] << " " << A[1] << A[2];
		 }
		 else if(S == 2)
		 {
		 	cout << A[0] << A[1];
		 }
		 
         //end
         cout << endl;
      }
   }
   catch(int e)
   {
      cout << "Fehler (Nr. " << e << ") beim Einlesen der Datei.";
      int a;
      cin >> a;
      return 1;
   }
    
    //int a;
    //cin >> a;
    return 0;    
}
