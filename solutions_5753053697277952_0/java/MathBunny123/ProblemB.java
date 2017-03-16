/* Programming Competition - Template (Horatiu Lazu) */

import java.io.*;
import java.util.*;
import java.lang.*;
import java.awt.*;
import java.awt.geom.*;
import java.math.*;
import java.text.*;


class Main{
	BufferedReader in;
	StringTokenizer st;
	
	public static void main (String [] args){
		new Main();
	}
	
	public boolean hasMajority(int [] arr, int left){
		for(int x = 0; x < arr.length; x++){
			if (arr[x] > left/2 || arr[x] < 0){
				//System.out.println("invalid option:" + arr[x] + " " + (left/2) + "..");
				return true;
			}	
		}
		return false;
	}

	public Main(){
		try{
			in = new BufferedReader(new FileReader("aSmall.in"));
			PrintWriter out = new PrintWriter(new FileWriter("out.txt"));
			int T = nextInt();
			for(int q = 0; q < T; q++){
				String output = "";
				int N = nextInt();
				int [] arr = new int[N];
				int numPeople = 0;
				for(int x =0 ; x < N; x++){
					arr[x] = nextInt();	
					numPeople += arr[x];
				}
				//greedily remove people in order ?
				int left = numPeople;
				while(numPeople > 0){
					if (numPeople > 1){
						loop:{
							for(int x = 0; x < N; x++){
								for(int y = 0; y < N; y++){
									arr[x]--;
									arr[y]--;	
									if (hasMajority(arr, left-2) == false){
										output += (char)('A'+x) + "" + (char)('A'+y) + " ";
										left -=2;
										numPeople-= 2;
										break loop;
									}
									else{
										System.out.println("(" + x + ", " + y + ")" + output);
										arr[x]++;
										arr[y]++;
									}
								}	
							}
							for(int y = 0; y < N; y++){
								arr[y]--;	
								if (hasMajority(arr, left-1) == false){
									left -=1;
									output += (char)('A'+y) + " ";
									numPeople-= 1;
									break loop;
								}
								else{
									arr[y]++;
								}
							}	
						}	
					}
					else{
						for(int y = 0; y < N; y++){
							arr[y]--;	
							if (hasMajority(arr, left-1) == false){
								left--;
								output += (char)('A'+y) + " ";
								numPeople-= 2;
								break;
							}
							else{
								arr[y]++;
							}
						}	
					}
				}	
				System.out.println(output);
				out.println("Case #" + (q+1) + ": " + output);
			}
			
			out.close();
		}
		catch(IOException e){
			System.out.println("IO: General");
		}
	}
	
	String next() throws IOException {
		while (st == null || !st.hasMoreTokens())
	   	 	st = new StringTokenizer(in.readLine().trim());
		return st.nextToken();
	}

	long nextLong() throws IOException {
		return Long.parseLong(next());
	}

	int nextInt() throws IOException {
		return Integer.parseInt(next());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	String nextLine() throws IOException {
		return in.readLine().trim();
	}
}