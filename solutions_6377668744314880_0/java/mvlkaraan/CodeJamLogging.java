import java.util.*;
import java.io.*;

public class CodeJamLogging{
    public static class Point implements Comparable<Point>{
        int x, y, id;
        
        public Point(int a, int b, int c){
            x = a;
            y = b;
            id = c;
        }
        
        public int compareTo(Point other){
            if(other.x == this.x) return this.y - other.y;
            return this.x - other.x;
        }
    }

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder out = new StringBuilder();
        int t = Integer.parseInt(br.readLine());
        for(int k = 1; k <= t; k++){
            int n = Integer.parseInt(br.readLine());
            Point[] p = new Point[n];
            int[] ans = new int[n];
            Arrays.fill(ans,-1);
            for(int i = 0; i < n; i++){
                StringTokenizer st = new StringTokenizer(br.readLine());
                p[i] = new Point(Integer.parseInt(st.nextToken()),Integer.parseInt(st.nextToken()),i);
            }
            Arrays.sort(p);
            ArrayList<Point> hull = new ArrayList<Point>();
            for(int i = 0; i < n; i++){
                while(hull.size() >= 2 && CCW(hull.get(hull.size()-2),hull.get(hull.size()-1),p[i]) < 0) hull.remove(hull.size()-1);
                hull.add(p[i]);
            }
            int lim = hull.size() + 1;
            for(int i = n-2; i >= 0; i--){
                while(hull.size() >= lim && CCW(hull.get(hull.size()-2),hull.get(hull.size()-1),p[i]) < 0) hull.remove(hull.size()-1);
                hull.add(p[i]);
            }
            if(hull.size() > 1) hull.remove(hull.size() - 1);
            /*for(int i = 0; i < hull.size(); i++){
                out.append("(" + hull.get(i).x + " " + hull.get(i).y + ") ");
            }
            out.append("\n");*/
            for(int i = 0; i < hull.size(); i++) ans[hull.get(i).id] = 0;
            for(int i = 0; i < n; i++){
                if(ans[p[i].id] == 0) continue;
                int min = hull.size()-1;
                for(int j = 0; j < hull.size(); j++){
                    int num = 1;
                    for(num = 1; ; num++){
                        if(CCW(hull.get(j),p[i],hull.get((j+num)%hull.size())) >= 0) break;
                    }
                    //out.append(num + "\n");
                    min = Math.min(min,num);
                }
                ans[p[i].id] = min-1;
            }
            //out.append(hull.size());
            out.append("Case #" + k + ":\n");
            for(int i = 0; i < n; i++) out.append(ans[i] + "\n");
        }
        System.out.print(out);
    }
    
    public static long CCW(Point p1, Point p2, Point p3){
        return ((long)(p1.x)*(long)(p2.y) + (long)(p2.x)*(long)(p3.y) + (long)(p3.x)*(long)(p1.y)) - ((long)(p1.y)*(long)(p2.x) + (long)(p2.y)*(long)(p3.x) + (long)(p3.y)*(long)(p1.x));
    }
}