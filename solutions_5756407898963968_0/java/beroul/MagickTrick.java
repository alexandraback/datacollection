import java.io.File;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.Scanner;


public class MagickTrick {


	String round="Qualification";
	String exercice="A";

	// global var
	int N1,N2;
	int[][] C1,C2;
	String sn;

	void log(String s) {
		System.out.println(s);
	}
	
	void error(String s) {
		System.out.println(s);
	}



	String solve(){
		int count=0;
		int res=0;
		
		
		for (int j=0;j<4;j++)
			for (int y=0;y<4;y++) {
				if (C1[N1-1][j]==C2[N2-1][y]) {
					count++;
					res=C1[N1-1][j];
				}
			}
		log("Count:"+count);
		if (count==0)
			return "Volunteer cheated!";
		if (count>1)
			return "Bad magician!";
		return ""+res;
	}





	void process() throws Exception {

	//	File inputFile=new File(round+"/test_"+exercice+".in");
		//PrintWriter outputFile= new PrintWriter(round+"/test_"+exercice+".out","UTF-8");


			File inputFile=new File(round+"/"+exercice+"-small-attempt1.in");
			PrintWriter outputFile= new PrintWriter(round+"/"+exercice+"-small-attempt1.out","UTF-8");
		//File inputFile=new File(round+"/"+exercice+"-large-practice.in");
		//PrintWriter outputFile= new PrintWriter(round+"/"+exercice+"-large-practice.out","UTF-8");


		Scanner scanner=new Scanner(inputFile);
		scanner.useLocale(Locale.US);
		int T = scanner.nextInt();
		System.out.println("Doing "+T+" cases");



		for (int t=1;t<=T;t++) {

			N1=scanner.nextInt();	
			
			
			C1=new int[4][4];
			C2=new int[4][4];
			for (int i=0;i<4;i++)
				for (int j=0;j<4;j++){
				C1[i][j]=scanner.nextInt();
			}
			N2=scanner.nextInt();	
			log("N1:"+N1+" N2:"+N2);
			for (int i=0;i<4;i++)
				for (int j=0;j<4;j++){
				C2[i][j]=scanner.nextInt();
			}
			
	
			String ss=""+solve();
			System.out.println("Case #"+t+": "+ss);

			outputFile.println("Case #"+t+": "+ss);
		}
		scanner.close();
		outputFile.close();

	}



	public static void main(String[] args) throws Exception {
		MagickTrick J=new MagickTrick();
		J.process();
	}


}

