/*
ID: vlchen81
LANG: JAVA
TASK: 
 */
import java.io.*;
import java.util.*;

class Haircut {
  public static void main (String [] args) throws IOException {
	Haircut solver = new Haircut();
	solver.solveProblem();
  }
  public void solveProblem() throws IOException {
	BufferedReader f = new BufferedReader(new FileReader("Haircut.in"));
	PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("Haircut.out")));
	
	int T = Integer.parseInt(f.readLine());
	for(int t = 0; t < T; t++) {
	  StringTokenizer st = new StringTokenizer(f.readLine());
	  int B = Integer.parseInt(st.nextToken());
	  int N = Integer.parseInt(st.nextToken());
	  
	  int[] barbers = new int[B];
	  st = new StringTokenizer(f.readLine());
	  int product = 1;
	  for(int i = 0; i < B; i++) {
		barbers[i] = Integer.parseInt(st.nextToken());
		product *= barbers[i];
	  }
	  
	  int numPeopleCutted = 0;
	  
	  for(int i = 0; i < B; i++) {
		numPeopleCutted += product/barbers[i];
	  }
	  
	  //System.out.println("Case #" + (t+1) + ": " + numPeopleCutted);
	  
	  N %= numPeopleCutted;
	  if(N==0) {
		N = numPeopleCutted;
	  }
	  
	  int[] barberWork = new int[B];
	  boolean notFound = true;
	  while(notFound) {
		for(int i = 0; i < B; i++) {
		  if(barberWork[i] == 0) {
			N--;
			barberWork[i] = barbers[i];
			if(N==0) {
			  notFound = false;
			  out.println("Case #" + (t+1) + ": " + (i+1));
			  break;
			}
		  }
		  if(barberWork[i] > 0) {
			barberWork[i]--;
		  }
		}
	  }
	  
	}
	
	f.close();
	out.close();
	System.exit(0);
  }
  
  
}
