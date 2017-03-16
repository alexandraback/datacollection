package trees;

import java.awt.Point;
import java.util.ArrayList;

public class TestTrees {
	
	private int N;
	private Point[] s;

	public TestTrees(int n, Point[] s) {
		N = n;
		this.s = s;
	}

	public int[] getResult () {
		int[] res = new int[N];
		for (int i=0; i<N; i++)
			res[i] = 0;
		
		if (N < 4)
			return res;
		
		for (int i=0; i<N; i++) {
			// pour chaque arbre, partir de chaque arbre et regarder à 180° à gauche et à droite
			Point current = s[i];
			int min = Integer.MAX_VALUE;
			for (int j=0; j<N; j++) {
				if (i==j) continue;
				Point target = s[j];
				Point line = new Point(target.x-current.x, target.y-current.y);
				ArrayList<Point> left = new ArrayList<Point>();
				ArrayList<Point> right = new ArrayList<Point>();
				for (int k=0; k<N; k++) {
					if (k==i || k==j) continue;
					Point looking = s[k];
					Point vector = new Point(looking.x-current.x, looking.y-current.y);
					int det = line.x*vector.y - line.y*vector.x;
					if (det > 0)
						left.add(looking);
					if (det < 0)
						right.add(looking);
				}
				min = Math.min(min, Math.min(left.size(), right.size()));
			}
			res[i] = min;
		}
		
		return res;
	}
	
	public int getN() {
		return N;
	}
	
}