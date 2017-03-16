#include "main.h"
#include <fstream>

using namespace std;

bool getLines(const string& filename, vector<string>& lines) {
   lines.clear();
   ifstream infile(filename);
   if (!infile.is_open())
      return false;
   string line;
   while(getline(infile, line)) {
      lines.push_back(line);
   }
   return true;
}

vector<string> split(const string& str, char delim) {
   size_t start = 0;
   size_t end = 0;
   vector<string> vs;
   while (end != string::npos) {
      end = str.find(delim, start);
      vs.push_back(str.substr(start, end-start));
      start = end+1;
   }
   return vs;
}

void splitAsInt(const string& str, char delim, vector<int>& into) {
   size_t start = 0;
   size_t end = 0;
   while (end != string::npos) {
      end = str.find(delim, start);
      into.push_back(stoi(str.substr(start, end-start)));
      start = end+1;
   }
}

int main(int argc, char** argv) {
   if (argc != 2) {
      ERROR("Specify the input file!");
   }
   string inputfilename = argv[1];
   vector<string> lines;
   bool gotLines = getLines(inputfilename, lines);
   if (!gotLines || lines.empty()) {
      ERROR("Couldn't open input file, or input file was empty.");
   }

   string outputfilename = inputfilename.substr(0, inputfilename.find('.')) + ".out";
   cout << "Putting output in " << outputfilename << endl;
   ofstream outputfile(outputfilename);
   if (!outputfile.is_open()) {
      ERROR("Couldn't open output file for writing.");
   }

   size_t numTests = stoi(lines[0]);
   TRACE(numTests << " tests");

   size_t startingIndex = 1;
   for (size_t i = 0; i < numTests; i++) {
      string res;
      size_t linesUsed = 0;
      TRACE("Running Test #" << i+1);
      if (solveTest(lines, startingIndex, res, linesUsed)) {
         startingIndex += linesUsed;
         outputfile << "Case #" << i+1 << ": " << res << endl;
         TRACE("  Solution: " << res);
      } else {
         ERROR("Couldn't read case " << i+1);
      }
   }

   return 0;
}