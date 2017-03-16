import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;

public class A{
	static final String inFile="A-small.in";
	static final String outFile="A.out";
	
	static int t;
	static String line,str;
	static String[] row;
	static int[] a,b;
	static boolean debug = false;
	static long sum,maj,rem;
	
	public static void main(String [ ] args) throws IOException{
		new A().run();
	}
	
	private void run() throws IOException{
		int i,k,l,n;
		
		BufferedReader br = new BufferedReader(new FileReader(inFile));
	    try {
	    	File file = new File(outFile);
    		if (!file.exists()) {file.createNewFile();}
    		FileWriter fw = new FileWriter(file.getAbsoluteFile());
    		BufferedWriter bw = new BufferedWriter(fw);
    		
	        line = br.readLine();
	        t = Integer.valueOf(line); //1 <= T <= 100
	        
	        for(l=0;l<t;l++){

	        	bw.write("Case #"+(l+1)+": ");
	        	
	        	line = br.readLine(); //S
	        	n = Integer.valueOf(line);
	        	a = new int[n];
	        	Arrays.fill(a, 0);
	        	sum = 0;
        		line = br.readLine(); //S
        		row = line.split("\\s");
	        	for(i=0;i<n;i++){
		        	a[i] = Integer.valueOf(row[i]);
		        	sum+=a[i];
	        	}
	        	rem = sum;
	        	maj = sum/2;
	        	int max,pos1,pos2;
	        	for(;rem>0;){
	        		max=-1;pos1=-1;pos2=-1;
	        		
		        		for(i=0;i<n;i++){
		        			if(a[i]>max){
		        				max = a[i];
		        				pos1=i;
		        			}
		        		}
		        		//2nd
		        		for(i=0;i<n;i++){
		        			if(a[i] == max && i!=pos1){
		        				pos2=i;
		        			}
		        		}
		        	if(pos2>-1 && rem==3) pos2=-1;
	        		
	        		if(pos2>-1){
	        			bw.write(""+(char)('A'+pos1)+""+(char)('A'+pos2));
	        			a[pos1]--;
	        			a[pos2]--;
	        			rem-=2;
	        		} else {
	        			bw.write(""+(char)('A'+pos1));
	        			a[pos1]--;
	        			rem-=1;
	        		}
		        	
		        	if(rem>0) bw.write(" ");
		        	
		        	//check
		        	max=-1;
		        	for(i=0;i<n;i++){
			        	max = (a[i]>max)?a[i]:max;
		        	}
		        	if (max > rem/2) {
		        		System.out.println("Problem!");
		        	}
	        	}
	        	
	        	bw.write("\n");	
	        }
			bw.close();
	    } finally {br.close();}
	}
}
	
