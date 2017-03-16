// Java Shell by Matthew Savage

import java.io.*;
import java.math.*;
import java.util.*;

public class A{
	public static void main (String [] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		
		int cases = nextInt(br);
		
		for(int t = 1; t <= cases; t++){			
			int choice = nextInt(br);
			
			HashSet<Integer> possible = new HashSet<Integer>();
			
			for(int i = 1; i <= 4; i++){
				if(i == choice){
					StringTokenizer st = getst(br);
					for(int j = 0; j < 4; j++){
						possible.add(nextInt(st));
					}
				} else {
					br.readLine();
				}
			}
			
			choice = nextInt(br);
			
			int card = 0;
			
			for(int i = 1; i <= 4; i++){
				if(i == choice){
					StringTokenizer st = getst(br);
					for(int j = 0; j < 4; j++){
						int c = nextInt(st);
						if(possible.contains(c)){
							if(card > 0){
								card = -1;
								break;
							}
							card = c;
						}
					}
				} else {
					br.readLine();
				}
			}
			
			pw.print("Case #" + t + ": ");
			
			if(card == -1){
				pw.println("Bad magician!");
			} else if(card == 0){
				pw.println("Volunteer cheated!");
			} else {
				pw.println(card);
			}
		}
		
		br.close();
		pw.close();
	}
	
	public static int nextInt(BufferedReader br) throws Exception{
		return Integer.parseInt(br.readLine());
	}
	
	public static int nextInt(StringTokenizer st) throws Exception{
		return Integer.parseInt(st.nextToken());
	}
	
	public static StringTokenizer getst(BufferedReader br) throws Exception{
		return new StringTokenizer(br.readLine(), " ");
	}
}