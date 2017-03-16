#include <iostream>
#include <string>

int a[100][100];
std::string s[100];
std::string newS[100];
int N;
int T;
int compute();
int main(int argc, const char* argv[]) {
   std::cin >> T;
   for (int i = 1; i <= T; i++) {
      std::cin >> N;
      for (int j = 0; j < N; j++)
         std::cin >> s[j];
      for (int j = 0; j < N; j++) {
         newS[j] = "";
         int index = 0;
         while (index < s[j].size()) {
            char c = s[j][index];
            int k = index;
            while ((k < s[j].size()) && (s[j][k] == c)) {
               ++k;
            }
            a[j][newS[j].size()] = k - index;
            newS[j] = newS[j] + c;
            index = k;
         }
       }
       std::string S = newS[0];
       bool stop = false;
       for (int j = 0; j < N; j++)
          if (S != newS[j]) {
             stop = true;
             std::cout << "Case #" << i << ": Fegla Won" << std::endl;
             break;
          }

       if (stop) continue;
       std::cout << "Case #" << i << ": " << compute() << std::endl;
    }
    return 0;
}


int compute() {
   int M = newS[0].size();
   int result = 0;
   for (int i = 0; i < M; i++) {
      int min = 10000;
      for (int j = 0; j < N; j++) {
         int count = 0;
         for (int k = 0; k < N; k++) {
            if (k != j) {
               if (a[k][i] > a[j][i]) {
                  count += a[k][i] - a[j][i];
               }
               else if (a[k][i] < a[j][i]) {
                  count += a[j][i] -  a[k][i] ;
               }
            }
         }
         if (min > count) min = count;
      }
      result += min;
    }
    return result;
}
