import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.TreeSet;



public class solver {
    BufferedReader in;
    PrintWriter out;
    StringTokenizer tok;
    
    String readString() throws IOException{
        while (tok==null || !tok.hasMoreTokens()){
            try{
                tok=new StringTokenizer(in.readLine());             
            }
            catch(Exception e){
                return null;
            }            
        }
        return tok.nextToken();
    }
    int readInt() throws NumberFormatException, IOException{
        return Integer.parseInt(readString());
    }
    long readLong() throws NumberFormatException, IOException{
        return Long.parseLong(readString());
    }
    double readDouble() throws NumberFormatException, IOException{
        return Double.parseDouble(readString());
    }
    
    final static boolean OJ=System.getProperty("ONLINE_JUDGE")!=null;
    
    
    void init() throws FileNotFoundException{        
        if (OJ){
            in=new BufferedReader(new InputStreamReader(System.in));
            out=new PrintWriter(System.out);  
        }else{
        	in=new BufferedReader(new FileReader("A-small-attempt0.in"));            
            out=new PrintWriter("output.txt");  
        }
    }    
    int[] iMas(int n) throws NumberFormatException, IOException{
        int[] a=new int[n];
        for (int i=0;i<n;i++){
            a[i]=readInt();
        }
        return a;
    }
    
    
    int gcd (int a, int b) {
    	if (b == 0)
    		return a;
    	else
    		return gcd (b, a % b);
    }   
    
    
    
    class Pair implements Comparable<Pair>{
    	int b;
    	int d;
    	int num;
    	Pair(int x,int y,int i){
    		b=x;
    		d=y;
    		num=i;
    	}
    	    	
    	@Override
    	public int compareTo(Pair o) {    		
    		return b-o.b;
    	}   	    	    	
    }
    
    
    
    
        
    void solve() throws IOException{
    	int t=readInt();
    	for (int test=1;test<=t;test++){
    		TreeSet<Integer> set=new TreeSet<Integer>();
    		int x=readInt();
    		for (int i=1;i<=4;i++){
    			if (x==i){
    				set.add(readInt());
    				set.add(readInt());
    				set.add(readInt());
    				set.add(readInt());
    			}else{
    				readInt();
    				readInt();
    				readInt();
    				readInt();   				
    			}
    		}
    		x=readInt();
    		TreeSet<Integer> answer=new TreeSet<>();
    		for (int i=1;i<5;i++){
    			if (x==i){
    				for (int j=0;j<4;j++){
    					int z=readInt();
    					if (set.contains(z)) answer.add(z); 
    				}    				   				
    			}else{
    				readInt();
    				readInt();
    				readInt();
    				readInt();    				
    			}
    		}
    		
    		if (answer.size()==0){
    			out.println("Case #"+test+": Volunteer cheated!");
    			continue;
    		}
    		if (answer.size()>1){
    			out.println("Case #"+test+": Bad magician!");
    			continue;
    		}
    		out.println("Case #"+test+": "+answer.first());
    		
    		
    	}
    	
    	
    }
    
    
    void run() throws NumberFormatException, IOException{
        init();
         long h=System.currentTimeMillis();        
        solve();
         System.err.println(System.currentTimeMillis()-h);
        out.close();
    }
    
    
    

    
    public static void main(String[] args) throws NumberFormatException, IOException {
        new solver().run();
    }

}