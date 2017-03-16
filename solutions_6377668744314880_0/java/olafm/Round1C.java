import java.io.*;
import java.util.*; 

public class Round1C {
	static class Tree {
		long X;
		long Y;
		boolean cut;
		boolean boundary;
		int depth = Integer.MAX_VALUE;
	}
	
	int cases;
	int N;
	Tree[] trees;
	
	boolean calcBoundary(int depth) {
		boolean better = false;
		int minNotCut = 0;
		while (trees[minNotCut].cut)
			minNotCut++;
		int maxNotCut = N - 1;
		while (trees[maxNotCut].cut)
			maxNotCut--;
		for (int t = minNotCut; t <= maxNotCut; t++) {
			if (trees[t].X == trees[minNotCut].X)
				trees[t].boundary = true;
			else 
				break;
		}
		for (int t = maxNotCut; t >= minNotCut; t--) {
			if (trees[t].X == trees[maxNotCut].X)
				trees[t].boundary = true;
			else 
				break;
		}
		
		for (int t = minNotCut + 1; t < maxNotCut; t++) {
			if (trees[t].X == trees[minNotCut].X || trees[t].X == trees[maxNotCut].X)
				continue;
			long minSlopeRX = Integer.MIN_VALUE;
			long minSlopeRY = Integer.MAX_VALUE;
			long maxSlopeRX = Integer.MAX_VALUE;
			long maxSlopeRY = Integer.MIN_VALUE;
			boolean wasOver = false, wasUnder = false;
			for (int i = maxNotCut; i > t; i--) 
				if (!trees[i].cut) {
					long slopeX = trees[i].X - trees[t].X;
					long slopeY = trees[i].Y - trees[t].Y;
					if (slopeX == 0) {
						if (slopeY > 0)
							wasOver = true;
						else
							wasUnder = true;
					} else {
						if (slopeY * minSlopeRX < minSlopeRY * slopeX) {
							minSlopeRY = slopeY;
							minSlopeRX = slopeX;
						}
						if (slopeY * maxSlopeRX > maxSlopeRY * slopeX) {
							maxSlopeRY = slopeY;
							maxSlopeRX = slopeX;
						}
					}
				}
			
			long minSlopeLX = Integer.MIN_VALUE;
			long minSlopeLY = Integer.MAX_VALUE;
			long maxSlopeLX = Integer.MAX_VALUE;
			long maxSlopeLY = Integer.MIN_VALUE;
			for (int i = minNotCut; i < t; i++)
				if (!trees[i].cut) {
					long slopeX = trees[t].X - trees[i].X;
					long slopeY = trees[t].Y - trees[i].Y;
					if (slopeX == 0) {
						if (slopeY > 0)
							wasUnder = true;
						else
							wasOver = true;
					} else {
						if (slopeY * minSlopeLX < minSlopeLY * slopeX) {
							minSlopeLY = slopeY;
							minSlopeLX = slopeX;
						}
						if (slopeY * maxSlopeLX > maxSlopeLY * slopeX) {
							maxSlopeLY = slopeY;
							maxSlopeLX = slopeX;
						}
					}
				}

			trees[t].boundary = 
				!wasOver && maxSlopeRY * minSlopeLX <= minSlopeLY * maxSlopeRX ||
				!wasUnder && minSlopeRY * maxSlopeLX >= maxSlopeLY * minSlopeRX;
			//if (depth ==1)				System.out.println(t + " " + wasOver + " " +wasUnder + " " + ((double)minSlopeLY)/minSlopeLX +" " + ((double)minSlopeRY)/minSlopeRX +" "+((double)maxSlopeLY) / maxSlopeLX +" " + ((double)maxSlopeRY) /maxSlopeRX );
		}
		
		for (int t = minNotCut; t <= maxNotCut; t++) {
			if (trees[t].boundary && depth < trees[t].depth) {
				trees[t].depth = depth;
				better = true;
			}
		}
		return better;
	}
	
	void tryCut(int depth) {
		if (!calcBoundary(depth))
			return;
		if (depth < N - 1) {
			for (int t = 0; t < N; t++) {
				if (trees[t].boundary && !trees[t].cut) {
					//System.out.println("CUT " + t + " depth = " + depth);
					trees[t].cut = true;
					tryCut(depth + 1);
					trees[t].cut = false;
				}
			}
		}
	}
	
	void process(Scanner scanner, PrintStream out) throws IOException {
		cases = scanner.nextInt();
		scanner.nextLine();
		
		for (int n = 0; n < cases; n++) {
			N = scanner.nextInt();
			trees = new Tree[N];
			for (int i = 0; i < N; i++) {
				trees[i] = new Tree();
				trees[i].X = scanner.nextLong();
				trees[i].Y = scanner.nextLong();
			}
			
			Arrays.sort(trees, new Comparator<Tree>() {
				@Override
				public int compare(Tree o1, Tree o2) {
					return (int) (o1.X - o2.X);
				}				
			});
			
			tryCut(0);
			System.out.println("Case #" + (n + 1) + ":");
			out.println("Case #" + (n + 1) + ":");
			for (int t = 0; t < N; t++) {
				out.println(trees[t].depth);
			}
		}
	}
	
	Round1C() throws IOException {
		/*String sampleText = "2\r\n" + 
				"5\r\n" + 
				"0 0\r\n" + 
				"10 0\r\n" + 
				"10 10\r\n" + 
				"0 10\r\n" + 
				"5 5\r\n" + 
				"9\r\n" + 
				"0 0\r\n" + 
				"5 0\r\n" + 
				"10 0\r\n" + 
				"0 5\r\n" + 
				"5 5\r\n" + 
				"10 5\r\n" + 
				"0 10\r\n" + 
				"5 10\r\n" + 
				"10 10"; 
		Scanner in = new Scanner(sampleText);
		PrintStream out = System.out;*/
		
		
		Scanner in = new Scanner(new File("C:\\Users\\Olaf\\Downloads\\C-small-attempt1.in"));
		PrintStream out = new PrintStream("out-C-small.txt");
		
		/*
		Scanner in = new Scanner(new File("C:\\Users\\Olaf\\Downloads\\C-large.in"));
		PrintStream out = new PrintStream("out-C-large.txt");
		*/

		
		process(in, out);
		
		in.close();
		out.close();
	}	
	
	public static void main(String[] args) throws IOException {
		new Round1C();
	}	
	
}
