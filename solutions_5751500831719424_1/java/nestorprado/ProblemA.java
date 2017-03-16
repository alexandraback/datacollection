package Round1B;

import java.io.*;
import java.util.*;

public class ProblemA {
  
	public static double mean(int[] m) {
	    double sum = 0;
	    for (int i = 0; i < m.length; i++) {
	        sum += m[i];
	    }
	    return sum / m.length;
	}
	
  private static int calc(String a[]){
	  int at[]= new int[a.length];
	  int r[]= new int[a.length];
	  int conta = 0;
	  while(true){
		  Arrays.fill(r, 1);
		  char c = a[0].charAt(at[0]);
		  for(int j=1; j<a.length; j++){
			  char aux = a[j].charAt(at[j]);
			  if(aux!=c) return -1;
		  }
		  for(int j=0; j<a.length; j++){
			  while(at[j]+r[j]<a[j].length() && a[j].charAt(at[j]+r[j])==c) r[j]++;
		  }
		  int end=0;
		  for(int j=0; j<a.length; j++){
			  at[j]+=r[j];
			  if(at[j]==a[j].length()) end++;
		  }
		  while(true){
			  Arrays.sort(r);
			  if(r[0]==r[a.length-1]) break;
			  double m=mean(r);
			  double sb=Math.abs(r[0]-m);
			  double se=Math.abs(r[a.length-1]-m);
			  if(sb<se) r[a.length-1]--;
			  else r[0]++;
			  conta ++;
		  }
		  if(end==0) continue;
		  if(end!=a.length) return -1;
		  return conta;
	  }
  }
  
  private static String solve(Scanner in){
  	int n = in.nextInt();
  	String sa[] = new String[n];
  	for(int i=0 ; i< n ; i++){
  		sa[i]=in.next();
  	}
  	int aux = calc(sa);
  	if (aux<0) return "Fegla Won";
  	return "" + aux;
  }

  public static void main(String[] args) {
  	String file = "Round1B\\ProblemAlarge";
  	try{
  		System.out.println(file);
  		Scanner in = new Scanner(new File(file + ".in"));
  		PrintWriter out = new PrintWriter(new File(file + ".out"));
  		int T = in.nextInt(); in.nextLine();
  		for (int i = 1; i <= T; i++) {
  			String s = "Case #" + i + ": " + ProblemA.solve(in);
  			out.println(s);
  			System.out.println(s);
  		}
  		out.close();
  	}catch(Exception e){ e.printStackTrace(); }
  }
}