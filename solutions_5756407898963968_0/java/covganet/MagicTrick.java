import java.io.*;
import java.util.*;

public class MagicTrick {
	static PrintWriter pw = null;
	
	public static void main(String[] args) throws Exception {
	  BufferedReader br = new BufferedReader(new FileReader("A-small-attempt0.in"));
	  pw = new PrintWriter(new FileWriter("out1.txt"));
	  int nrTests = Integer.parseInt(br.readLine());
	  for(int test = 1; test <= nrTests; test++) {
	  	int ans1 = Integer.parseInt(br.readLine());
	  	int[][] map1 = new int[4][4];
	  	for (int i = 0; i < map1.length; i++) {
	      String[] strs = br.readLine().split(" ");
	      for (int j = 0; j < strs.length; j++) {
	        map1[i][j] = Integer.parseInt(strs[j]);
        }
      }
	  	int ans2 = Integer.parseInt(br.readLine());
	  	int[][] map2 = new int[4][4];
	  	for (int i = 0; i < map2.length; i++) {
	      String[] strs = br.readLine().split(" ");
	      for (int j = 0; j < strs.length; j++) {
	        map2[i][j] = Integer.parseInt(strs[j]);
        }
      }
	  	
	  	int[] posRes1 = map1[ans1 - 1];
	  	int[] posRes2 = map2[ans2 - 1];
	  	int gres = -1;
	  	String res = "Volunteer cheated!";
	  	for(int i = 0; i < posRes2.length; i++) {
	  		boolean found = false;
	  		for(int j = 0; j < posRes1.length; j++) {
	  			if(posRes2[i] == posRes1[j]) {
	  				found = true;
	  				break;
	  			}
	  		}
	  		if(found) {
	  			if(gres == -1) {
	  				gres = posRes2[i];
	  			} else {
	  				gres = -2;
	  				res = "Bad magician!";
	  				break;
	  			}
	  		}
	  	}
	  	
	  	if(gres >= 0) {
	  		res = String.valueOf(gres);
	  	}
	  	
	  	writeOut(test, res);
	  }
	  
	  pw.close();
  }
	
	static void writeOut(int testNr, String res) {
		pw.println("Case #" + testNr + ": " + res);
	}
}
