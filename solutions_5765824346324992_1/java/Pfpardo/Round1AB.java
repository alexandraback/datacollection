import java.io.*;

public class Round1AB {

	enum ProblemType{SAMPLE,SMALL,LARGE};
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		String roundPrefix = "Round1A";
		String problem = "B";
		ProblemType activeFile = ProblemType.LARGE;
		File file, outFile;
		String activeFileName;
		switch (activeFile) {
			case SAMPLE :
				activeFileName="sample";
				break;
			case SMALL:
				activeFileName="small-attempt1";
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
		 String rowText;
		 String [] bis;
		 String []ms;
		 long b,n,selected,m;
		 long [][]s;
		 double v;
	
		 for(int t=1;t<=testCases;t++){
			 System.out.printf("Test case %d...\n",t);

			 	rowText = br.readLine();
			 	b = Long.parseLong(rowText.split(" ")[0]);
			 	n = Long.parseLong(rowText.split(" ")[1]);
			 	s = new long [(int)b][2];
			 	bis = br.readLine().split(" ");
			 	if (n<=b) {
			 		selected = n;
			 	} else {
			 		v = 0.0;
			 		n-=b;
				 	for (int i=0; i< b; i++) {
				 		s[i][1] = Long.parseLong(bis[i]);
				 		v+= 1.0 / s[i][1];
				 	}
				 	m = (long)Math.floor(n/ v);
				 	for (int i=0; i< b; i++) {
				 		n-= m / s[i][1];
				 		s[i][0] = s[i][1] - (m % s[i][1]);
				 		if (s[i][0] == 0) {
				 			s[i][0] = s[i][1];
				 		}
				 	}
				 	selected = -1;

				 	if (n==0 ) {
				 		selected = b;
				 	}
				 	while ((selected == -1) && (n > 0)) {
				 		for (int i=0; i<b; i++) {
			 				s[i][0]--;
				 			if (s[i][0]==0) {
				 				n--;
				 				if(n==0) {
				 					selected = i+1;
				 					break;
				 				}
				 				s[i][0] = s[i][1];
				 			} 
				 		}
				 	}
			 	}			 	
			 	if (selected == -1) {
			 		throw new Exception("Fallo");
			 	}
			 StringBuilder caso = new StringBuilder();
			 caso.append("Case #");
			 caso.append(t);
			 caso.append(": ");
			 caso.append(selected);
			 caso.append("\n");
			 bw.write(caso.toString());
		 }
		 br.close();
		 bw.close();

	}

}
