import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;

public class ProblemA{
	static int t,n,count,sum,op,i1,i2,min,current;
	static int[]a,b,val;
	static char c;
	static String[]s;
	static String line;
	static String[] row;
	static boolean error;
	
	public static void main(String [ ] args) throws IOException{
		int i,j,k;
		BufferedReader br = new BufferedReader(new FileReader("A-small-attempt3.in"));
	    try {
	    	File file = new File("aaa.out");
    		
    		if (!file.exists()) {
    			file.createNewFile();
    		}
    		
    		FileWriter fw = new FileWriter(file.getAbsoluteFile());
    		BufferedWriter bw = new BufferedWriter(fw);
    		
	        line = br.readLine();
	        t = Integer.valueOf(line);
	        
	        for(i = 0; i < t; i++){
	        	line = br.readLine();
        	
	        	n = Integer.valueOf(line);
	        	s = new String[n];
	        	a = new int[n];
	        	b = new int[n];
	        	val = new int[n];
	        	
	        	for (j=0;j<n;j++){
		        	line = br.readLine();
		        	s[j] = line;
		        	a[j] = s[j].length();
		        	b[j]=0;
	        	}
	        	op=0;
	        	
		        for (;b[0]<a[0];){
		        	//grab char
		        	error=false;
		        	c = s[0].charAt(b[0]);
		        	//lookahead
		        	for (k=0;k<n;k++){
		        		val[k]=0;
		        		while(!error && b[k]<a[k]){
		        			if(s[k].charAt(b[k])==c){
		        				//System.out.println(""+c);
		        				b[k]++;
		        				val[k]++;
		        			} else {//eos or diff char
		        				if(val[k]==0) //error
		        					error=true;
		        				break;
		        			}
		        		}
		        		if(val[k]==0) error=true;
		        	}
		        	if(error) break;
		        	//decide operation based on val[]
		        	min=Integer.MAX_VALUE;
		        	//find min distance
		        	for(i1=0;i1<k;i1++){
		        		//System.out.println(""+val[i1]);
		        		current = 0;
		        		for(i2=0;i2<k;i2++)
		        			current+=Math.abs(val[i2]-val[i1]);
		        		if(current<=min) min = current;
		        	}
		        	op+=min;
	        		//System.out.println("min:"+min+"op"+op);
		        }
		        //final check there are no strings left;
		        for(i1=0;i1<n;i1++){
		        	if(b[i1]!=a[i1]) error=true;
		        }
		        if(!error)
		        	bw.write("Case #"+(i+1)+": "+op+"\n");
		        else
		        	bw.write("Case #"+(i+1)+": Fegla Won\n");
	        }
	        
			bw.close();

	    } finally {
	        br.close();
	    }
	}
	
	
}
