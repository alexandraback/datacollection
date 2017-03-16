import java.util.*;
import java.io.*;

public class Main {

	public static void main(String args[]) throws Exception{
		BufferedReader input = new BufferedReader(new FileReader("../GoogleCodeJam2014/io/A-small-attempt0.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("../GoogleCodeJam2014/io/output.txt"));
		int n = Integer.parseInt(input.readLine());
		
		for(int i = 0 ; i < n ; i++){
			int[][] cp = new int[4][4];
			int start = Integer.parseInt(input.readLine());
	        for(int j = 0 ; j < 4 ; j++){
	        	String[] st = input.readLine().split(" ");
	        	for(int k = 0 ; k < 4 ; k++){
	        		cp[j][k] = Integer.parseInt(st[k]);
	        	}
	        }
	        int goal = Integer.parseInt(input.readLine());
			int[][] cp2 = new int[4][4];
	        for(int j = 0 ; j < 4 ; j++){
	        	String[] st = input.readLine().split(" ");
	        	for(int k = 0 ; k < 4 ; k++){
	        		cp2[j][k] = Integer.parseInt(st[k]);
	        	}
	        }
	        pw.print("Case #"+(i+1)+": "+isOk(cp,cp2,start,goal));
	        pw.println();
			pw.flush();
		}
		input.close();
		pw.close();
	}
	
	public static String isOk(int[][] cp,int[][] cp2,int start,int goal){
		int[] st = new int[4];
		int[] en = new int[4];
		for(int i = 0 ; i < 4 ; i++){
			st[i] = cp[start-1][i];
		}
		for(int i = 0 ; i < 4 ; i++){
			en[i] = cp2[goal-1][i];
		}
		int answer = 0;
		int count = 0;
		for(int i = 0 ; i < 4 ; i++){
			for(int j = 0 ; j < 4 ; j++){
				if(st[i] == en[j]){
					count++;
					answer = st[i];
				}
			}
		}
		if(count > 1){
			return "Bad magician!";
		}else if(count == 1){
			return answer+"";
		}else{
			return "Volunteer cheated!";
		}
	}
}