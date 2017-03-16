import java.io.*;
import java.util.*;

public class Main {
  public static void main(String[] args) throws Exception {
    InputStreamReader isr = new InputStreamReader(System.in);
    BufferedReader br = new BufferedReader(isr);
    int T = Integer.parseInt(br.readLine());
    for (int t = 1; t <= T; t++) {
      
      int n = Integer.parseInt(br.readLine());
      Point[] p = new Point[n];
      for (int i = 0; i < n; i++) {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int x = Integer.parseInt(st.nextToken());
        int y = Integer.parseInt(st.nextToken());
        p[i] = new Point(x, y);
      }
      System.out.println(String.format("Case #%d:", t));
      for (int i = 0; i < n; i++) {
        int ans = n - 1;
        for (int j = 0; j < n; j++) {
          if (j != i) {
            Line line = new Line(p[i], p[j]);
            int left = 0, right = 0;
            for (int k = 0; k < n; k++) {
              int r = line.find(p[k]);
              if (r == -1) {
                left++;
              } else if (r == 1) {
                right++;
              }
            }
            ans = Math.min(ans, Math.min(left, right));
          }
        }
        System.out.println(ans);
      }
    }
  }

  private static class Point {
    int x, y;
    public Point(int x, int y) {
      this.x = x;
      this.y = y;
    }
  }

  private static class Line {
    boolean flag;
    double k, b;
    int x;
    public Line(Point p0, Point p1) {
      if (p0.x == p1.x) {
        flag = true;
        x = p0.x;
      } else {
        flag = false;
        double dx = p0.x - p1.x, dy = p0.y - p1.y;
        k = dy / dx;
        b = p0.y - p0.x * k;
      }
    }

    public int find(Point p) {
      if (flag) {
        if (p.x == x) {
          return 0;
        } else if (x < p.x) {
          return -1;
        } else {
          return 1;
        }
      } else {
        double r = p.y - k * p.x - b;
        if (Math.abs(r) < EPS) {
          return 0;
        } else if (r < 0) {
          return -1;
        } else {
          return 1;
        }
      }
    }

  }

  private static final double EPS = 1e-7;

  

  
}