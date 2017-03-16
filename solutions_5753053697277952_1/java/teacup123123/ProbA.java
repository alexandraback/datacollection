package jamA;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;

public class ProbA extends Prob{

	public static void main(String[] args) {
		ProbA pa= new ProbA();
		pa.fromFile("C:\\Users\\user\\Downloads\\A-large-practice.in");
	}

	@Override
	public void load(BufferedReader br,BufferedWriter bw) {
		try{
			int T=Integer.parseInt(br.readLine());
			for(int cas=0;cas<T;cas++)
			{
				String str=br.readLine(),cur="";
				for(char c:str.toCharArray())
				{
					String s1=""+c+cur;
					String s2=cur+c;
					if (s1.compareTo(s2)>0)
						cur=s1;
					else
						cur=s2;
				}
				bw.write("Case #"+(cas+1)+": "+cur);
				bw.newLine();
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
