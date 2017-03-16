import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;


public class A {
	public static void main(String[] args) throws Exception{
		int t = readInt();
		for(int i = 1; i <= t; i++){
			int[][] first = new int[4][4];
			int[][] snd = new int[4][4];
			ArrayList<Integer> possible = new ArrayList<Integer>();
			int f = readInt()-1;
			for(int j = 0; j < 4; j++){
				for(int k = 0; k < 4; k++){
					first[j][k] = readInt();
				}
			}
			int s = readInt()-1;
			for(int j = 0; j < 4; j++){
				for(int k = 0; k < 4; k++){
					snd[j][k] = readInt();
				}
			}
			for(int j = 0; j < 4; j++){
				for(int k = 0; k < 4; k++){
					if(first[f][j] == snd[s][k]){
						possible.add(first[f][j]);
					}
				}
			}
			if(possible.size() == 0){
				System.out.println("Case #" + i + ": Volunteer cheated!");
			}
			else if(possible.size() > 1){
				System.out.println("Case #" + i + ": Bad magician!");
			}
			else{
				System.out.println("Case #" + i + ": " + possible.get(0));
			}
		}
	}
	
	static BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st = new StringTokenizer(" ");
	static String readString() throws Exception{
		while(!st.hasMoreTokens()){
			st = new StringTokenizer(stdin.readLine());
		}
		return st.nextToken();
	}
	static int readInt() throws Exception {
		return Integer.parseInt(readString());
	}
	static long readLong() throws Exception {
		return Long.parseLong(readString());
	}
}
