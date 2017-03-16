// Author: Alejandro Sotelo Arevalo
package round1;

import java.io.*;
import java.util.*;

public class C_Logging {
  // --------------------------------------------------------------------------------
  private static String ID="C";
  private static String NAME="small-attempt1";
  private static String STAGE="round1";
  private static boolean STANDARD_OUTPUT=false;
  // --------------------------------------------------------------------------------
  private static BufferedReader reader=null;
  private static PrintStream output=null;
  // --------------------------------------------------------------------------------
  public static void main(String[] args) throws Throwable {
    try (BufferedReader bufferedReader=reader=new BufferedReader(new FileReader(new File("data/"+STAGE+"/"+ID+"-"+NAME+".in")))) {
      try (PrintStream printStream=output=STANDARD_OUTPUT?System.out:new PrintStream(new File("data/"+STAGE+"/"+ID+"-"+NAME+".out"))) {
        process();
      }
    }
  }
  // --------------------------------------------------------------------------------
  private static void process() throws Throwable {
    for (int c=1,T=Integer.parseInt(reader.readLine()); c<=T; c++) {
      int N=Integer.parseInt(reader.readLine());
      double points[][]=new double[N][2];
      for (int i=0; i<N; i++) {
        StringTokenizer st=new StringTokenizer(reader.readLine());
        points[i][0]=Integer.parseInt(st.nextToken());
        points[i][1]=Integer.parseInt(st.nextToken());
      }
      output.println("Case #"+c+":");
      for (int k=0; k<N; k++) {
        int answer=Integer.MAX_VALUE;
        for (int g=0,G=1<<N; g<G; g++) {
          if (((g>>>k)&1)!=1) continue;
          List<double[]> list=new ArrayList<>();
          for (int i=0; i<N; i++) {
            if (((g>>>i)&1)==1) list.add(points[i]);
          }
          double[][] ch=convexHullGS(list.toArray(new double[0][]),false);
          double minDist=Double.POSITIVE_INFINITY;
          for (int i=0; i<ch.length; i++) {
            double[] pa=ch[i],pb=ch[i+1==ch.length?0:i+1];
            if (Math.sqrt(ds(pa,pb))<1e-4) {
              minDist=Math.min(minDist,Math.sqrt(ds(pa,points[k])));
            }
            else {
              minDist=Math.min(minDist,distPS(pa,pb,points[k]));
            }
          }
          if (minDist<1e-4) {
            answer=Math.min(answer,points.length-list.size());
          }
        }
        output.println(answer);
      }
    }
  }
  static double ds(double[] a, double[] b) {
    return (b[0]-a[0])*(b[0]-a[0])+(b[1]-a[1])*(b[1]-a[1]);
  }
  static double distPL(double[] p1, double[] p2, double[] p) {
    return Math.abs((p2[0]-p1[0])*(p1[1]-p[1])-(p2[1]-p1[1])*(p1[0]-p[0]))/Math.sqrt(ds(p1,p2));
  }
  static double distPS(double[] p1, double[] p2, double[] p) {
    double dP=ds(p1,p2),d1=ds(p1,p),d2=ds(p2,p);
    return (d2+dP<d1||d1+dP<d2)?Math.sqrt(Math.min(d1,d2)):distPL(p1,p2,p);
  }
  static int sgn(double x) {
    return Math.abs(x)>9.9e-12?(x<0?-1:1):0;
  }
  static double cruz(double[] a, double[] b) {
    return a[0]*b[1]-a[1]*b[0];
  }
  static double cruz(double[] a, double[] b, double[] c) {
    return cruz(a,b)+cruz(b,c)+cruz(c,a);
  }
  @SuppressWarnings("null")
  static double[][] convexHullGS(double[][] pt, boolean bd) { // bd: con borde?
    int h=pt.length,i=h,t=0;
    double v[]=null,w[],r[][]=new double[h][];
    for (double[] p:pt)
      if (v==null||p[1]<v[1]||(p[1]==v[1]&&p[0]>v[0])) v=p;
    v=v.clone();
    for (double[] p:pt) {
      p[0]-=v[0];
      p[1]-=v[1];
    }
    Arrays.sort(pt,new Comparator<double[]>() {
      @Override
      public int compare(double[] a, double[] b) {
        double cz=cruz(b,a);
        return sgn(sgn(cz)!=0?cz:a[0]*a[0]+a[1]*a[1]-b[0]*b[0]-b[1]*b[1]);
      }
    });
    if (bd) while (i-1>=0&&cruz(pt[h-1],pt[i-1])==0)
      i--;
    if (bd) for (int k=i; k<(i+h)/2; k++) {
      w=pt[k];
      pt[k]=pt[h-1-k+i];
      pt[h-1-k+i]=w;
    }
    for (double[] p:pt) {
      while (t>=2&&sgn(cruz(r[t-1],p,r[t-2]))<(bd?0:1))
        t--;
      r[t++]=p;
    }
    for (double[] p:pt) {
      p[0]+=v[0];
      p[1]+=v[1];
    }
    return Arrays.copyOfRange(r,0,t);
  }
}
