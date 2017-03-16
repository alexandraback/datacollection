import java.io.*;

public class Round1AA {

	enum ProblemType{SAMPLE,SMALL,LARGE};
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		String roundPrefix = "Round1A";
		String problem = "A";
		ProblemType activeFile = ProblemType.LARGE;
		File file, outFile;
		String activeFileName;
		switch (activeFile) {
			case SAMPLE :
				activeFileName="sample";
				break;
			case SMALL:
				activeFileName="small-attempt0";
				break;
			case LARGE:
				activeFileName="large";
				break;
			default:
				throw new RuntimeException("Problem type not supported");
		}
		 file = new File(String.format("files/%s/%s-%s.in",roundPrefix,problem,activeFileName));
		 outFile = new File(String.format("files/%s/%s-%s.out",roundPrefix,problem,activeFileName));
		
//		 File file = new File(Paths.get(roundPrefix + "/files/A-sample.in").toAbsolutePath().toString());
//		 File outFile = new File("Qualy2014/files/A-sample.out");
		 //File file = new File(Paths.get("files/A-small-practice.in").toAbsolutePath().toString());
		 //File outFile = new File("files/A-small-practice.out");
		 //File file = new File(Paths.get("files/A-large-practice.in").toAbsolutePath().toString());
		 //File outFile = new File("files/A-large-practice.out");

		
		//File file = new File("..\\files\\A-small-practice.in");
		// File outFile = new File("..\\files\\A-small-practice.out");
		    //File file = new File("F:\\A-large-practice.in");
		    //File outFile = new File("F:\\A-large-practice.out");
		 BufferedReader br = new BufferedReader(new FileReader(file));
		 BufferedWriter bw = new BufferedWriter(new FileWriter(outFile));
		 int testCases = Integer.parseInt(br.readLine());
	
		 //Specific for the problem
		 int n;
		 
		 String rowText;
		 String []ms;
		 long max,eA,eB,mi,mj;
	
		 for(int t=1;t<=testCases;t++){
			 	eA = 0;
			 	eB = 0;
			 	max = 0;
				 n = Integer.parseInt(br.readLine());
				 ms = br.readLine().split(" ");
				 mi= Long.parseLong(ms[0]);
				 for (int i = 1 ; i <= ms.length -1; i++){
					 mj = Long.parseLong(ms[i]);
					 if (mi > mj) { 
						 eA += mi-mj;
						 if (mi-mj>max) {
							 max = mi-mj;
						 }
					 }
					 mi=mj;
				 }
				 mi=Long.parseLong(ms[0]);
				 for (int i = 0 ; i <= ms.length -2; i++) {
					 mi = Long.parseLong(ms[i]);
					 eB += (max < mi) ? max : mi; 
				 }

			 StringBuilder caso = new StringBuilder();
			 caso.append("Case #");
			 caso.append(t);
			 caso.append(": ");
			 caso.append(eA);
			 caso.append(" ");
			 caso.append(eB);
			 caso.append("\n");
			 bw.write(caso.toString());
		 }
		 br.close();
		 bw.close();

	}

}
