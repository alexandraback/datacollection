package problem.b;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class ProblemB {

	/**
	 * @param args
	 */
	public static int commonDivisor(int n,int m){
		//辗转相除是用大的除以小的。如果n<m，第一次相当n与m值交换
		while(n%m!=0){
		int temp=n%m;
		n=m;
		m=temp;
		}
		return m;
		}
	
	public static int commonMultiple(int n,int m){
		return n*m/commonDivisor(n,m);
		}

	public static void main(String[] args) {
		long startTime=System.currentTimeMillis();//Start time
		try {
			BufferedReader in = new BufferedReader(new FileReader("B-small-attempt4.in"));
			BufferedWriter out = new BufferedWriter(new FileWriter("B-small-attempt4.out"));
			String line = null;
			line = in.readLine();
			int R=0;
			int T = Integer.parseInt(line);
			for(int i=0;i<T;i++){
				line = in.readLine();
				String [] tokens = line.split(" ");	
				
				int B = Integer.parseInt(tokens[0]);
				int K = Integer.parseInt(tokens[1]);
				line = in.readLine();
				tokens = line.split(" ");				
				int [] M = new int [B];
				int [] RT = new int [B];//Remaining time
				//int [] R = new int [K];//result
				
				int CM=1;//commonMultiple
				for (int k=0;k<B;k++){
					M[k]= Integer.parseInt(tokens[k]);
					CM=commonMultiple(M[k],CM);
				}
				int group=0;
				for (int k=0;k<B;k++){
					group=group+CM/M[k];
				}
				K=K%group+group;
				for (int k=0;k<B;k++){
					RT[k]= 0;
				}
				int bb=0;
				int idle=0;
				for (int k=0;k<K;k++){//k-th individual
					//int min=-1000000;
					idle=0;
					for (int j=0;j<B;j++){//j-th barber
						if (RT[j]==0 ){//& M[j]>min
							bb=j;
							//min=M[j];
							idle=1;
							break;
						}
					}
					//R[k]=bb+1;
					R=bb+1;
					RT[bb]=RT[bb]+M[bb];
					idle=0;
					for (int j=0;j<B;j++){
						if (RT[j]==0){
							idle=1;
							break;
						}
					}
					while (idle==0){
						for (int j=0;j<B;j++){
							RT[j]=RT[j]-1;
							if (RT[j]==0){
								idle=1;
							}
						}
					}
				}
				
				System.out.println("Case #" + (i+1) +": " + R);	
				out.write("Case #" + (i+1) +": " + R + "\n");
			}
			in.close();	
			out.close();
		} catch (FileNotFoundException e) {
			System.out.println("File not found");
			e.printStackTrace();
		} catch (IOException e) {
			System.out.println("IOException");
			e.printStackTrace();
		}
		long endTime=System.currentTimeMillis();//End time
		System.out.println("Running time is "+(endTime-startTime)+"ms");

	}

}
