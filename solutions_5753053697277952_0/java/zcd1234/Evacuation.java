package codejam2016;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

import tools.TT;

public class Evacuation {
	int N;
	int[] P;
	char[] a = new char[27];
	int sum;
	Evacuation(){
		for(int i=0;i<26;i++){
			a[i] = (char)('A' + i);
		}
	}
	public static void main(String[] args) throws IOException {
		new Evacuation().solve();
	}
	public void solve() throws IOException{
		String inputFile = TT.chooseFile();
		long startTime = System.currentTimeMillis();
		String outputFile = TT.getOutputName(inputFile);
		BufferedReader in = new BufferedReader(new FileReader(inputFile));
		PrintWriter out = new PrintWriter(outputFile);
		int T = Integer.parseInt(in.readLine());//first line
		for(int caseN=1; caseN<=T;caseN++){
			N = Integer.parseInt(in.readLine());
			P = TT.intArray(in.readLine(), " ");
			sum = 0;
			for(int p:P)
				sum += p;
			
			String output = "Case #"+caseN + ":";
			while(sum > 0)
				output += " " + getNext();
			System.out.println(output);
			out.println(output);
		}
		in.close();
		out.close();
		long timeUsed = System.currentTimeMillis()-startTime;
		TT.println("total execution time is "+timeUsed);
	}
	String getNext(){
		int i1 = findMax();
		P[i1]--;
		sum--;
		int i2 = findMax();
		P[i2]--;
		sum--;
		String s = "";
		if(!isValid()){
			P[i2]++;
			sum++;
			s = s+a[i1];
		}else{
			s = s+a[i1]+a[i2];
		}
		return s;
	}
	int findMax(){
		int index = 0;
		for(int i=1;i<N;i++){
			if(P[i] > P[index]){
				index = i;
			}
		}
		return index;
	}
	boolean isValid(){
		int i1 = findMax();
		return P[i1]*2<=sum;
	}
}
