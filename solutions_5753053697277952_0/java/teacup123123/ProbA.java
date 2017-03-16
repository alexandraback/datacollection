package jamC;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;

public class ProbA extends Prob{

	public static void main(String[] args) {
		System.out.println((int)'A');
		ProbA pa= new ProbA();
		pa.fromFile("C:\\Users\\tchang\\Downloads\\A-small-attempt0.in");
	}

	@Override
	public void load(BufferedReader br,BufferedWriter bw) {
		try{
			int T=Integer.parseInt(br.readLine());
			for(int cas=0;cas<T;cas++)
			{
				String ans="";
				int pNum=Integer.parseInt(br.readLine());
				String[] memStr=br.readLine().split(" ");
				int memInt[]=new int [pNum];
				int sum=0;
				int maxI=0;
				for(int i=0;i<pNum;i++)
				{
					memInt[i]=Integer.parseInt(memStr[i]);
					sum=sum+memInt[i];
				}
				int sumOrig=sum;
				while(sum>0)
				{
					maxI=0;
					for(int i=0;i<pNum;i++)
					{
						if(memInt[i]>memInt[maxI])
							maxI=i;
					}
					ans=ans+(char)(65+maxI)+((sum%2==0)?"":" ");
					memInt[maxI]--;
					sum--;
				}

				bw.write("Case #"+(cas+1)+": "+ans);
				bw.newLine();
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
