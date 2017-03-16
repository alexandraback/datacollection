
import java.io.*;
import java.util.ArrayList;
import java.util.List;

/**
 * Created by szeyiu on 5/2/15.
 */
public class A2B {

    public static void main(String[] args) throws IOException {
        BufferedReader r = new BufferedReader(new InputStreamReader(new FileInputStream(new File("A2B.in"))));
        BufferedWriter w = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(new File("A2B.out"))));
        int T = Integer.valueOf(r.readLine());
        A2B a2B = new A2B();
        for(int i=0; i<T; ++i){
            String line = r.readLine();
            //System.out.println(line);
            String[] splt = line.split(" ");
            int rr = Integer.valueOf(splt[0]);
            int cc = Integer.valueOf(splt[1]);
            int nn = Integer.valueOf(splt[2]);
            int rst = a2B.solve(nn, rr, cc);
            //System.out.println(rst);
            int c = i+1;
            w.write("Case #" + c + ": " + rst + "\n");
        }
        w.flush();
        w.close();
        r.close();
    }

    public int solve(int maxP, int r, int c){
        List<Integer> rst = new ArrayList<Integer>();
        rst.add(Integer.MAX_VALUE);
        dfs(maxP, r, c, 0, 0, new ArrayList<Integer>(), rst);
        return rst.get(0);
    }

    public void dfs(int maxP, int r, int c, int start, int curP, List<Integer> path, List<Integer> rst){
        if(curP>maxP) return;
        if(start==r*c && maxP==curP){
            int currst = cal(path, r, c);
            if(currst<rst.get(0)){
                rst.set(0,currst);
            }
            return;
        } else if(start>=r*c){
            return;
        }
        path.add(0);
        dfs(maxP,r,c,start+1,curP, path, rst);
        path.remove(path.size()-1);
        path.add(1);
        dfs(maxP,r,c,start+1,curP+1,path,rst);
        path.remove(path.size()-1);
    }

    public int cal(List<Integer> path, int r, int c){
        boolean[][] m = new boolean[r][c];
        for(int i=0; i<path.size(); ++i){
            int rr = i/c;
            int cc = i%c;
            m[rr][cc] = path.get(i)>0;
        }
        int count = 0;
        for(int i=0; i<r; ++i){
            for(int j=0; j<c; ++j){
                if(!m[i][j]) continue;
                if(i-1>=0 && m[i-1][j]){
                    count++;
                }
                if(j-1>=0 && m[i][j-1]){
                    count++;
                }
            }
        }
        return count;
    }
}
