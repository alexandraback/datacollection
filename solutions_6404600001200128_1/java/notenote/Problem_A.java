package GoogleCodeJamRound1;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Problem_A {

	public static int nn(int n, int[] m){
		int result = 0;
		for(int i = 0; i < n-1; i++){
			if(m[i] > m[i+1]){
				result += m[i] - m[i+1];
			}
		}
		return result;
	}
	
	public static int mm(int n, int[] m){
		int max = 0; 
		int result = 0;
		for(int i = 0; i < n-1; i++){
			if(m[i] > m[i+1]){
				int dif = m[i]- m[i+1];
				if(max < dif) max = dif;
			}
		}
		for(int i = 0; i < n-1; i++){
			if(m[i] >= max) result += max;
			else result += m[i];
		}
		return result;
	}
	
	
	public static void main(String[] args) {
		String inFile = "//Users//lixuefei//Documents//JavaWorkspace//Interview//src//GoogleCodeJamRound1//inin.txt";
		String outFile = "//Users//lixuefei//Documents//JavaWorkspace//Interview//src//GoogleCodeJamRound1//result.txt";
		int n = 0;
		String line;
		try {
			FileReader fileReader = new FileReader(inFile);
			BufferedReader br = new BufferedReader(fileReader);
			FileWriter fileWriter = new FileWriter(outFile);
			BufferedWriter bw = new BufferedWriter(fileWriter);
			line = br.readLine();
			n = Integer.parseInt(line);
			for(int i = 0; i < n ; i++){
				line = br.readLine();
				int N = Integer.parseInt(line);
				int[] M = new int[N];
				line = br.readLine();
				String[] parts = line.split(" ");
				for(int j = 0; j < N; j++){
					M[j] = Integer.parseInt(parts[j]);
				}
								
				int result1 = nn(N, M);
				int result2 = mm(N, M);
				bw.write("Case #" + (i+1) + ": " + result1 + " "+ result2 +"\n");
				
			}
			br.close();
			bw.close();
		} catch (IOException ex) {
			ex.printStackTrace();
		}

	}
}

