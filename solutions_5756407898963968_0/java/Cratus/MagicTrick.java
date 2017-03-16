import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class MagicTrick {
	
	static String infile = "G:/Dev/workspace/CodeJam14/ProblemA/input.in", outfile = "G:/Dev/workspace/CodeJam14/ProblemA/output.out";
	static String prefix = "Case #", suffix1 = ": Bad magician!", suffix2 = ": Volunteer cheated!";
	static BufferedReader br;
	static BufferedWriter bw;
	
	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new FileReader(infile));
		bw = new BufferedWriter(new FileWriter(outfile));
		solve();
		bw.flush();
		bw.close();
		br.close();
	}
	
	static void solve() throws IOException {
		
		int T = Integer.parseInt(getNextLine());
		for(int i=1;i<=T;i++) {
			int first = Integer.parseInt(getNextLine());
			String firstLine = "";
			for(int j=1;j<=4;j++) {
				String next = getNextLine();
				if(j==first)
					firstLine = next; 
			}
			int second = Integer.parseInt(getNextLine());
			String secondLine = "";
			for(int j=1;j<=4;j++) {
				String next = getNextLine();
				if(j==second)
					secondLine = next;
			}
			String[] firstsplit = firstLine.split(" "), secondsplit = secondLine.split(" ");
			int[] firstInts = new int[4], secondints = new int[4];
			for (int j=0;j<4;j++) {
				firstInts[j] = Integer.parseInt(firstsplit[j]);
				secondints[j] = Integer.parseInt(secondsplit[j]);
			}
			int match = 0, matchCard = 0;
			for(int j=0;j<4;j++) {
				for(int k=0;k<4;k++) {
					if(firstInts[j]==secondints[k]) {
						match++;
						matchCard = firstInts[j];
					}
				}
			}
			if(match==0) {
				writeLine(prefix + i + suffix2);
			} else if(match>1) {
				writeLine(prefix + i + suffix1);
			} else {
				writeLine(prefix + i + ": " + matchCard);
			}
		}
	}
	
	static void writeLine(String next) throws IOException {
		bw.write(next);
		bw.write("\n");
	}
	
	static String getNextLine() throws IOException {
		String next = br.readLine();
		if(next==null) return null;
 		while(next!=null && next.trim().isEmpty()) {
			next = br.readLine();
		}
 		return next;
	}

}
