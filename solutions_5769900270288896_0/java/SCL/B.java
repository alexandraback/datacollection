import java.util.*;
import java.io.*;

public class B {
	static PrintWriter pw;
	public static void main(String args[]) throws Exception{
		BufferedReader input = new BufferedReader(new FileReader("../GoogleCodeJam2015R1B/io/B-small-attempt0.in"));
		pw = new PrintWriter(new FileWriter("../GoogleCodeJam2015R1B/io/output.txt"));
		int T = Integer.parseInt(input.readLine());
		for(int i = 0 ; i < T ; i++){
			String[] shys = input.readLine().split(" ");
			int min = Integer.MAX_VALUE;
			int R = Integer.parseInt(shys[0]);
			int C = Integer.parseInt(shys[1]);
			int N = Integer.parseInt(shys[2]);
			int max = (int)Math.pow(2, R * C) - 1;
			for(int j = 0 ; j <= max ; j++){
				String s = Integer.toBinaryString(j);
				while(s.length() != R * C){
					s = "0"+s;
				}
				int index = 0;
				int count = 0;
				boolean[][] rc = new boolean[R][C];
				for(int k = 0 ; k < R ; k++){
					for(int l = 0 ; l < C ; l++){
						if(s.charAt(index) == '1'){
							rc[k][l] = true;
							count++;
						}
						index++;
					}
				}
				if(count != N)continue;
				int tmpc = 0;
				for(int k = 0 ; k < R ; k++){
					for(int l = 0 ; l < C ; l++){
						if(!rc[k][l])continue;
						if((l + 1) != C){
							if(rc[k][l + 1]){
								tmpc++;
							}
						}
						if(k + 1 != R){
							if(rc[k + 1][l]){
								tmpc++;
							}
						}
						index++;
					}
				}
				min = Math.min(min, tmpc);
			}
			
			pw.println("Case #"+(i+1)+": "+min);
		}
		pw.flush();
		input.close();
		pw.close();
	}
}
