import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashSet;

public class MagicTrick {

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		MagicTrick me = new MagicTrick();
		FileReader fr = new FileReader("A-small-attempt0.in");
		BufferedReader br = new BufferedReader(fr);
		FileWriter fw = new FileWriter("out");
		BufferedWriter bw = new BufferedWriter(fw);

		int T = Integer.valueOf(br.readLine());
		int r1 = 0;
		int r2 = 0;
		int[][] m1 = new int[4][4];
		int[][] m2 = new int[4][4];
		String[] tokens = null;
		String result  = null;
		for (int i = 1; i <= T; i++) {

			r1 = Integer.valueOf(br.readLine());
			for (int m = 0; m < 4; m++) {
				tokens = br.readLine().split(" +");
				for (int n = 0; n < 4; n++) {
					m1[m][n] = Integer.valueOf(tokens[n]);
				}
			}

			r2 = Integer.valueOf(br.readLine());
			for (int m = 0; m < 4; m++) {
				tokens = br.readLine().split(" +");
				for (int n = 0; n < 4; n++) {
					m2[m][n] = Integer.valueOf(tokens[n]);
				}
			}
		
		
		result = me.getResult(r1, r2, m1, m2);
		bw.write("Case #" + i + ": " + result);
		bw.write('\n');
		}

		br.close();
		fr.close();
		bw.close();
		fw.close();

	}

	public String getResult(int r1, int r2, int[][] m1, int[][] m2) {
		HashSet<Integer> all = new HashSet<Integer>();
		HashSet<Integer> h1 = new HashSet<Integer>();
		HashSet<Integer> h2 = new HashSet<Integer>();
		
		for(int i = 0;i< 4;i++){
			all.add(m1[r1-1][i]);
			all.add(m2[r2-1][i]);
			
			h1.add(m1[r1-1][i]);
			h2.add(m2[r2-1][i]);
		}
		
		if(all.size()==8) return "Volunteer cheated!";
		else if(all.size()<7) return "Bad magician!";
		else{
			
			for(int i=0;i<4;i++){
			if(h2.contains(m1[r1-1][i])) return String.valueOf(m1[r1-1][i]);	
			}
		}
		return "Error";
	}

}
