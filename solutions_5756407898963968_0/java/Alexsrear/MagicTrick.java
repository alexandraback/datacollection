package codejam;

import java.io.RandomAccessFile;
import java.util.StringTokenizer;

public class MagicTrick {
	
	public int answer1, answer2;
	public int[][] arrange1 = new int[4][4];
	public int[][] arrange2 = new int[4][4];
	             
	public MagicTrick(RandomAccessFile rafin) throws Exception{
		String inputline;
		StringTokenizer st;
		
		inputline = rafin.readLine();
		st = new StringTokenizer(inputline," ");
		answer1 = Integer.parseInt(st.nextToken()) - 1;
		for (int i=0; i<4; i++) {
			inputline = rafin.readLine();
			st = new StringTokenizer(inputline," ");
			for (int j=0; j<4; j++) {
				arrange1[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		inputline = rafin.readLine();
		st = new StringTokenizer(inputline," ");
		answer2 = Integer.parseInt(st.nextToken()) - 1;
		for (int i=0; i<4; i++) {
			inputline = rafin.readLine();
			st = new StringTokenizer(inputline," ");
			for (int j=0; j<4; j++) {
				arrange2[i][j] = Integer.parseInt(st.nextToken());
			}
		}
	}
	
	public MagicTrick() {
		// TODO Auto-generated constructor stub
	}

	public String getStatus() {
		int x=-1;
		int xcount = 0;
		
		for (int i=0; i<4; i++) {
			for (int j=0; j<4; j++) {
				if (arrange1[answer1][i] == arrange2[answer2][j]) {
					xcount++;
					x = arrange1[answer1][i];
				}
			}
		}
		
		if (xcount==0)
			return "Volunteer cheated!";
		else if (xcount==1)
			return x+"";
		else
			return "Bad magician!";
	}
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try {
			/*
			MagicTrick bull = new MagicTrick();
			bull.radius = 2;
			bull.t = 4;
			System.out.println(bull.getStatus());
			
			if (true) return;
			*/
			String infilename="d:/codejam/data/A-small-attempt0.in";
			String outfilename="d:/codejam/data/A-small-attempt0.out";
			RandomAccessFile rafin = new RandomAccessFile(infilename, "r");
			RandomAccessFile rafout = new RandomAccessFile(outfilename, "rw");
			rafout.setLength(0);
			
			int count = Integer.parseInt(rafin.readLine().trim());
			MagicTrick o;
			System.out.println(count + " cases.");
			for (int i=1; i<=count; i++) {
				o = new MagicTrick(rafin);
				rafout.writeBytes("Case #" + i + ": " + o.getStatus());
				if (i<count)
					rafout.writeBytes("\r\n");
				System.out.println("Case " + i + " dealed!");
				System.gc();
			}
			
			rafin.close();
			rafout.close();
		} catch (Exception e) {
			e.printStackTrace(System.out);
		}

	}

}
