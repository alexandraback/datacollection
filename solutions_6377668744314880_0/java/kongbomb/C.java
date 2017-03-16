package running;

import org.psjava.algo.geometry.convexhull.ConvexHullAlgorithm;
import org.psjava.ds.array.Array;
import org.psjava.ds.array.DynamicArray;
import org.psjava.ds.geometry.Point2D;
import org.psjava.ds.geometry.Polygon2D;
import org.psjava.ds.numbersystrem.LongNumberSystem;
import org.psjava.ds.set.Set;
import org.psjava.ds.set.SetFromIterable;
import org.psjava.formula.geometry.StraightOrder;
import org.psjava.goods.GoodConvexHullAlgorithm;
import org.psjava.util.SubSetIterable;
import org.psjava.util.ZeroTo;

import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.util.Scanner;

public class C implements Runnable {

	public static final ConvexHullAlgorithm CONVEX_HULL_ALGORITHM = GoodConvexHullAlgorithm.getInstance();
	public static final LongNumberSystem NS = LongNumberSystem.getInstance();

	@Override
	public void run() {
		Scanner in = new Scanner(System.in);
		int casen = in.nextInt();
		for(int casei : ZeroTo.get(casen)) {
			System.out.println("Case #" + (casei + 1) + ": ");

			int n = in.nextInt();
			DynamicArray<Point2D<Long>> points = DynamicArray.create();
			for(int i : ZeroTo.get(n))
				points.addToLast(Point2D.create(in.nextLong(), in.nextLong()));

			for(Point2D<Long> p : points) {
				int min = n-1;
				for (Iterable<Point2D<Long>> sub : SubSetIterable.create(points)) {
					Set<Point2D<Long>> subset = SetFromIterable.create(sub);
					int candidate = n - subset.size();
					if(subset.size() > 0 && candidate < min) {
						Polygon2D<Long> convexHull = CONVEX_HULL_ALGORITHM.calc(subset, NS);
						if(isOnHull(p, convexHull))
							min = candidate;
					}
				}

				System.out.println(min);
			}
		}
	}

	private boolean isOnHull(Point2D<Long> p, Polygon2D<Long> convexHull) {
		Array<Point2D<Long>> points = convexHull.getCCWOrderPoints();
		for(int k : ZeroTo.get(points.size()))
			if (StraightOrder.is(points.get(k), p, points.get((k + 1) % points.size()), NS))
				return true;
		return false;
	}

	public static void main(String[] args) throws Exception {
		System.setIn(new BufferedInputStream(new FileInputStream("solutions/running-io/C-small-attempt2.in")));
		new C().run();
	}

}
