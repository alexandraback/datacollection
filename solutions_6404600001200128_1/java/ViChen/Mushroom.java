import java.io.*;
import java.util.*;

class Mushroom {
  public static void main (String [] args) throws IOException {
	Mushroom solver = new Mushroom();
	solver.solveProblem();
  }
  public void solveProblem() throws IOException {
	BufferedReader f = new BufferedReader(new FileReader("Mushroom.in"));
	PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("Mushroom.out")));
	
	int T = Integer.parseInt(f.readLine());
	for(int i = 0; i < T; i++) {
	  int N = Integer.parseInt(f.readLine());
	  int[] shrooms = new int[N];
	  StringTokenizer st = new StringTokenizer(f.readLine());
	  for(int k = 0; k < N; k++) {
		shrooms[k] = Integer.parseInt(st.nextToken());
	  }
	  out.println("Case #" + (i+1) + ": " + case1(shrooms) + " " + case2(shrooms));
	}
	
	
	f.close();
	out.close();
	System.exit(0);
  }
  
  public int case1(int[] shrooms) {
	int sum = 0;
	for(int i = 0; i < shrooms.length-1; i++) {
	  if(shrooms[i] > shrooms[i+1]) {
		sum += shrooms[i] - shrooms[i+1];
	  }
	}
	return sum;
  }
  
  public int case2(int[] shrooms) {
	int maxDistance = 0;
	for(int i = 0; i < shrooms.length-1; i++) {
	  if(shrooms[i] > shrooms[i+1]) {
		int newDistance = shrooms[i] - shrooms[i+1];
		if(newDistance > maxDistance) {
		  maxDistance = newDistance;
		}
	  }
	}
	
	int count = 0;
	int currShrooms = shrooms[0];
	for(int i = 1; i < shrooms.length; i++) {
	  if(currShrooms - maxDistance < 0) {
		count += currShrooms;
		currShrooms = 0;
	  }
	  else {
		count += maxDistance;
		currShrooms -= maxDistance;
	  }
	  
	  currShrooms = shrooms[i];
	}
	return count;
  }
}
