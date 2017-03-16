import java.io.IOException;
import java.util.Arrays;
import java.awt.geom.Line2D;
import java.util.Locale;
import java.util.InputMismatchException;
import java.awt.geom.Point2D;
import java.util.ArrayList;
import java.util.Comparator;
import java.io.OutputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.File;
import java.io.FilenameFilter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		InputStream inputStream;
		try {
			final String regex = "C-(small|large).*[.]in";
			File directory = new File(".");
			File[] candidates = directory.listFiles(new FilenameFilter() {
				public boolean accept(File dir, String name) {
					return name.matches(regex);
				}
			});
			File toRun = null;
			for (File candidate : candidates) {
				if (toRun == null || candidate.lastModified() > toRun.lastModified())
					toRun = candidate;
			}
			inputStream = new FileInputStream(toRun);
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("c.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskC solver = new TaskC();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskC {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        out.println("Case #"+testNumber+":");
        int N = in.nextInt();
        Point2D points[] = new Point2D[N];

        for(int i = 0; i < N;i++ ) {
           points[i] = new Point2D.Double(in.nextInt(),in.nextInt());
        }

        int [] ans = new int[N];
        for(int i = 0; i < N ; i++) {
           int best = Integer.MAX_VALUE;
           for(int mask = 0; mask < (1<<N);mask++) {
              if(BitUtils.getBit(mask,i))
                   continue;
              int countRem = N - Integer.bitCount(mask);
               if(countRem<=2) {
                   best = Math.min(best, Integer.bitCount(mask));
                   continue;
               }
               ArrayList<Point2D> pr = new ArrayList<Point2D>();
               for(int j = 0; j < N ;j ++) {
                   if(BitUtils.getBit(mask,j)==false) {
                       pr.add(points[j]);
                   }
               }


               Point2D [] gg = new Point2D[pr.size()];
               for(int k =0;k<pr.size();k++) {
                   gg[k] = pr.get(k);
               }
               //out.println(gg.length);
               //out.flush();
               Point2D [] ps = ConvexHull.getConvexHull(gg);
               boolean ok = false;
               for(int j =0;j<ps.length;j++) {
                   Line2D l = new Line2D.Double(ps[j],ps[(j+1)%ps.length]);
                   if(l.ptLineDist(points[i].getX(),points[i].getY())<=1e-6 || points[i].equals(ps[j]) || points[i].equals(ps[(j+1)%ps.length]))
                       ok = true;
               }
               if(ok) {
                   best = Math.min(best, Integer.bitCount(mask));
               }

           }
            out.println(best);
        }

        Point2D points2[] = ConvexHull.getConvexHull(points);



     }
}

class InputReader {

    private InputStream stream;
    int curCharIndex = 0;
    int charsInBuf = 0;
     byte buf[] = new byte[16*1024];

    public InputReader(InputStream stream) {
        this.stream = stream;
    }


    public int readChar() {

        if (curCharIndex >= charsInBuf) {
            curCharIndex = 0;
            try {
                charsInBuf = stream.read(buf);
            } catch (IOException e) {
                throw new InputMismatchException();
            }
            if (charsInBuf <= 0)
                return -1;
        }
        return buf[curCharIndex++];
    }

    public void putCharBack(int c) {
        buf[--curCharIndex] = (byte) c;
    }


    public int nextInt() {

        int c;
        do {
            c = readChar();
        }while(isWhitespace(c));

        int sign = 1;
        if (c == '-') {
            c = readChar();
            sign = -1;

        }
        int res = 0;
        do {
            res *= 10;
            res += c - '0';
            c = readChar();
        } while (!isWhitespace(c) && c!=-1);
        if( c != -1) putCharBack(c);
        return sign * res;
    }


    public String nextToken() {
        int c;
        do {
            c = readChar();
        }while(isWhitespace(c));

        StringBuilder res = new StringBuilder();
        do {
            res.appendCodePoint(c);
            c = readChar();
        } while (!isWhitespace(c) && c!=-1);
        if( c != -1) putCharBack(c);
        return res.toString();
    }

    /*
    * For the purpose of compatibilty with Chelper Chrome extension
     */

    public String next() {
        return nextToken();
    }


    private boolean isWhitespace(int c) {
        return  c==' ' || c=='\n'|| c=='\r' || c=='\t';
    }
}

class BitUtils
{

    public static boolean getBit(long number,int bitIdx) {
        return (number & (1l << bitIdx))>0;
    }

}

class ConvexHull {


    public static Point2D[] getConvexHull(Point2D[] points) {
       if(points.length==1) {
           return Arrays.copyOf(points,points.length);
       }
       // sort all the points by x,y
        Arrays.sort(points, new PointComparator());
        // take the first and the last point
        Point2D pointF = points[0];
        Point2D pointL = points[points.length-1];
        // create stacks for  the upper part and the lower parts
        ArrayList<Point2D> upper = new  ArrayList<Point2D>();
        ArrayList<Point2D> lower = new  ArrayList<Point2D>();
        //add the first point to both upper and lower parts
        upper.add(pointF);
        lower.add(pointF);
        // start iterating over other points
        for(int i = 1;i<points.length;++i) {
            if(i == points.length-1 || Geometry.cw(pointF,points[i],pointL)) {
                // consider the point as a new candidate
               while (upper.size()>=2 && !Geometry.cw(upper.get(upper.size()-2),upper.get(upper.size()-1),points[i])) {
                   upper.remove(upper.size()-1);

               }
                upper.add(points[i]);
            }
            if(i == points.length-1 || Geometry.ccw(pointF,points[i],pointL)) {
                while(lower.size()>=2 && !Geometry.ccw(lower.get(lower.size()-2),lower.get(lower.size()-1),points[i])) {
                    lower.remove(lower.size()-1);
                }
                lower.add(points[i]);

            }
        }

        Point2D[]  result = new Point2D[upper.size()+lower.size()-2];


        for (int i=0; i<upper.size(); ++i)
            result[i] = upper.get(i);
        int idx = upper.size();
        for (int i=lower.size()-2; i>0; --i)
            result[idx++]=lower.get(i);
        return result;

    }


}

class PointComparator implements Comparator<Point2D> {

    public int compare(Point2D o1, Point2D o2) {
        final double eps = 1e-8;
        if(Math.abs(o1.getX()- o2.getX())>=eps) {
            return o1.getX()-o2.getX()>0?1:-1;
        }
        return o1.getY()-o2.getY()>0?1:-1;

    }
}

class Geometry
{

    public static boolean cw (Point2D a, Point2D b, Point2D c) {
        return a.getX()*(b.getY()-c.getY())+b.getX()*(c.getY()-a.getY())+c.getX()*(a.getY()-b.getY()) < 0;
    }
    public static boolean ccw (Point2D a, Point2D b, Point2D c) {
        return a.getX()*(b.getY()-c.getY())+b.getX()*(c.getY()-a.getY())+c.getX()*(a.getY()-b.getY()) > 0;
    }
}

