import java.util.*;
import java.io.*;

public class CodeJamNeighbors{
    public static class Obj implements Comparable<Obj>{
        int i, j, n;
        public Obj(int a, int b, int c){
            i = a;
            j = b;
            n = c;
        }
        
        public int compareTo(Obj other){
            if(other.n == this.n) return this.hashCode() - other.hashCode();
            return other.n - this.n;
        }
        
        @Override
        public int hashCode(){
            return i*10001 + j;
        }
        
        public boolean equals(Obj other){
            if(this.i == other.i && this.j == other.j) return true;
            return false;
        }
    }

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder out = new StringBuilder();
        int t = Integer.parseInt(br.readLine().trim());
        for(int k = 1; k <= t; k++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int r = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            int n = Integer.parseInt(st.nextToken());
            if(2*n <= r*c+1) out.append("Case #" + k + ": " + 0 + "\n");
            else{
                int count = r*(c-1) + (r-1)*c;
                PriorityQueue<Obj> pq = new PriorityQueue<Obj>();
                Obj[][] grid = new Obj[r][c];
                for(int i = 0; i < r; i++){
                    for(int j = 0; j < c; j++){
                        int temp = 4;
                        if(i == 0) temp--;
                        if(i == r-1) temp--;
                        if(j == 0) temp--;
                        if(j == c-1) temp--;
                        Obj o = new Obj(i,j,temp);
                        pq.add(o);
                        grid[i][j] = o;
                    }
                }
                while(n < r*c){
                    Obj o = pq.poll();
                    int i = o.i;
                    int j = o.j;
                    count -= o.n;
                    if(i > 0){
                        if(pq.remove(grid[i-1][j])){
                            grid[i-1][j].n--;
                            pq.add(grid[i-1][j]);
                        }
                    }
                    if(i < r-1){
                        if(pq.remove(grid[i+1][j])){
                            grid[i+1][j].n--;
                            pq.add(grid[i+1][j]);
                        }
                    }
                    if(j > 0){
                        if(pq.remove(grid[i][j-1])){
                            grid[i][j-1].n--;
                            pq.add(grid[i][j-1]);
                        }
                    }
                    if(j < c-1){
                        if(pq.remove(grid[i][j+1])){
                            grid[i][j+1].n--;
                            pq.add(grid[i][j+1]);
                        }
                    }
                    //out.append(i + " " + j + " " + o.n + "\n");
                    //out.append(pq.size() + "\n");
                    /*for(int ii = 0; ii < r; ii++){
                        out.append(Arrays.toString(grid[ii]) + "\n");
                    }*/
                    n++;
                }
                /*while(pq.size() > 0){
                    Obj o = pq.poll();
                    Obj temp = new Obj(o.i,o.j,0);
                    out.append(o.equals(temp));
                    out.append(o.i + " " + o.j + " " + o.n + "**");
                }
                out.append("\n");*/
                out.append("Case #" + k + ": " + count + "\n");
            }
        }
        System.out.print(out);
    }
}