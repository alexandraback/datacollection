import java.io.*;
import java.util.*;

public class ProblemA {	
    private static String solve(Scanner in){
    	String res="";
    	HashSet<Integer> set = new HashSet<Integer>();
    	int r1 = in.nextInt()-1; //zero based
    	for(int i=0 ; i<16 ; i++){
    		int row =  i/4;
    		if(row==r1){
    			set.add(in.nextInt());
    		}
    		else
    			in.nextInt();
    	}
    	int r2 = in.nextInt()-1;
    	for(int i=0 ; i<16 ; i++){
    		int row =  i/4;
    		if(row==r2){
    			int aux =  in.nextInt();
    			if(set.remove(aux)){
    				if(res.length()==0)
    					res+=aux;
    				else
    					res+="Bad magician!";
    			}
    		}
    		else
    			in.nextInt();
    	}
    	if(res.length()==0) return "Volunteer cheated!";
    	if(res.contains("Bad")) return "Bad magician!";
    	return res;
    	
    }

    public static void main(String[] args) {
    	String file = "Qualification\\ProblemAsmall";
    	try{
    		System.out.println(file);
    		Scanner in = new Scanner(new File(file + ".in"));
    		PrintWriter out = new PrintWriter(new File(file + ".out"));
    		int T = in.nextInt();  in.nextLine();
    		for (int i = 1; i <= T; i++) {
    			String s = "Case #" + i + ": " + ProblemA.solve(in);
    			out.println(s);
    			System.out.println(s);
    		}
    		out.close();
    	}catch(Exception e){ e.printStackTrace(); }
    }
}