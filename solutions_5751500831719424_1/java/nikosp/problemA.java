package round2014_1a;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.BitSet;
import java.util.List;
import java.util.StringTokenizer;


public class problemA {

	private static int inst;
	private static char c;

	/**
	 * @param args
	 */
	public static void main(String[] args) {
	    try {
			FileWriter w = new FileWriter("/home/nikos/output");
			BufferedWriter out = new BufferedWriter(w);
	    	//BufferedReader br = new BufferedReader(new FileReader("/home/nikos/input"));
	    	BufferedReader br = new BufferedReader(new FileReader("/home/nikos/Downloads/A-large.in"));
	        StringBuilder sb = new StringBuilder();
	        String line;
	        line = br.readLine();
	        int size = Integer.parseInt(line);
	        for (inst = 1; inst < size+1; inst++) {
	        	checkBoard(out,br);
			}
			out.close();
	        br.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally {
	    }
	}

	private static void checkBoard(BufferedWriter out, BufferedReader br) throws IOException {
		List<String> l = new ArrayList<String>(); 
    	String line = br.readLine();
        int N = Integer.parseInt(line);
        //System.out.println("N: "+N);
        List<List<Integer>> count =  new ArrayList<List<Integer>>(N);
        for (int i = 0; i < N; i++) {
        	line = br.readLine();
        	char cur = line.charAt(0);
        	int c=1,index=0;
			if(i==0){
				l.add(cur+"");
			}
			else{
				if(index>=l.size() || l.get(index).charAt(0)!=cur){
					//System.out.println("wrong pattern "+l.get(index).charAt(0)+" "+cur);
					out.write("Case #"+inst+": Fegla Won\n" );
					for (int k = i+1; k < N; k++) {
			        	line = br.readLine();
					}
					return;
				}
			}
			List<Integer> lc = new ArrayList<Integer>();
        	for (int j = 1; j < line.length(); j++) {
				char next = line.charAt(j);
				if(next!=cur){
					index++;
					if(i==0){
						l.add(next+"");
					}
					else{
						if(index>=l.size() || l.get(index).charAt(0)!=next){
							//System.out.println("wrong pattern "+l.get(index).charAt(0)+" "+next);
							out.write("Case #"+inst+": Fegla Won\n" );
							for (int k = i+1; k < N; k++) {
					        	line = br.readLine();
							}
							return;
						}
					}
					lc.add(c);
		        	c=0;
					cur=next;
				}
				c++;
			}
        	if(index!=l.size()-1){
        		out.write("Case #"+inst+": Fegla Won\n" );
				for (int k = i+1; k < N; k++) {
		        	line = br.readLine();
				}
				return;
        	}
			lc.add(c);
        	count.add(i, lc);
		}
    	//System.out.println(l);
    	//System.out.println(count.get(0));
    	//System.out.println(count.get(1));
    	
    	//check
    	int moves=0;
    	for (int i = 0; i < l.size(); i++) {
    		int[] tl = new int[N]; 
    		for (int j = 0; j < N; j++) {
    			//System.out.println(i+" "+j);
				tl[j]=count.get(j).get(i);
			}
    		Arrays.sort(tl);
    		int minmoves=Integer.MAX_VALUE;
    		if(tl[0]==tl[tl.length-1]){
    			minmoves=0;
    		}
    		for (int j = tl[0]; j < tl[tl.length-1]; j++) {
				int tmoves=0;
				for (int k = 0; k < tl.length; k++) {
					tmoves+=Math.abs(j-tl[k]);
				}
				if(tmoves<minmoves){
					minmoves=tmoves;
				}
			}
    		//System.out.println("min: "+minmoves);
			moves+=minmoves;
		}
		System.out.println(moves);
    	
    	
		out.write("Case #"+inst+": "+moves+"\n" );
	}
}
