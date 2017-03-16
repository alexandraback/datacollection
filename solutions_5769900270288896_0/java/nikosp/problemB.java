package r1b_2015;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Scanner;
import java.util.SortedSet;
import java.util.TreeSet;

public class problemB {
	
	private static int inst;

	public static void main(String[] args) {

        //String input = "/Users/npapa/Documents/codejam/input2";
        String input = "/Users/npapa/Documents/codejam/B-small-attempt0.in";
        String output = "/Users/npapa/Documents/codejam/output";
		try {
            Scanner sc = new Scanner(new FileReader(input));
			PrintWriter pw = new PrintWriter(output);

            int n = sc.nextInt();
            sc.nextLine();
            for (int c = 0; c < n; c++) {
                System.out.println("Test case " + (c + 1) + "...");
                pw.print("Case #" + (c + 1) + ": ");
                checkInsatnce(sc, pw);
                pw.println();
            }
            pw.println();
            pw.flush();
            pw.close();
            sc.close();
        } catch (FileNotFoundException ex) {
        	ex.printStackTrace();
        } catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	private static void checkInsatnce(Scanner sc, PrintWriter pw) throws IOException {
		int r = sc.nextInt();
		int c = sc.nextInt();
		int n = sc.nextInt();
		
		System.out.println(r+" "+c+" "+n);
	  	int res = solve(r,c,n);
	  	
    	System.out.println(res);
    	pw.print(res);
		
	}

	private static int solve(int r, int c, int n) {
		int size=r*c;

		BitSet b = new BitSet(size);
		for (int i = 1; i <= size; i++) {
			b.set(i);
		}
		SizePowerSet p = new SizePowerSet(b, n);
		BitSet b1;
		int minn = Integer.MAX_VALUE;
		while((b1 = p.next())!=null){
			boolean[][] building = new boolean[r][c];
			int noise=0;
			//System.out.println(b1);
			for (int i = b1.nextSetBit(0); i >= 0; i = b1.nextSetBit(i+1)) {
				int th = i-1;
				int cr=th/c;
				int cc=th%c;
				//System.out.println("r: "+cr+" c: "+cc);
				building[cr][cc]=true;
				if(inrange(cr-1,cc,r,c) && building[cr-1][cc])
					noise++;
				if(inrange(cr,cc-1,r,c) && building[cr][cc-1])
					noise++;
				if(inrange(cr,cc+1,r,c) && building[cr][cc+1])
					noise++;
				if(inrange(cr+1,cc,r,c) && building[cr+1][cc])
					noise++;
			}
			if(noise<minn){
				minn=noise;
			}
		}
		/*
		int cr=0,cc=0;
		int noise=0;
		for (int i = 0; i < n; i++) {
			if(!building[cr][cc]){
				building[cr][cc]=true;
			}
			else{
				
			}
		}*/
		return minn;
	}

	private static boolean inrange(int cr, int cc, int r, int c) {
		
		return cr>=0 && cc>=0 && cr<r && cc<c;
	}


}
