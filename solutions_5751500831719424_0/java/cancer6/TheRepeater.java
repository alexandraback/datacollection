import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

/**
 * Created by rohit.sharma on 03/05/14.
 */
public class TheRepeater {
    public static void main(String[] args){
        MyScanner sc = new MyScanner();
        int cases = sc.nextInt();
        for(int t=1; t<=cases; t++){
            int n = sc.nextInt();
            HashMap<Integer, List<Integer>> h = new HashMap<Integer, List<Integer>>();
            String[] s = new String[n];
            for(int i=0;i<n; i++){
                s[i] = sc.nextLine();
            }
            StringBuffer sb1 = new StringBuffer();
            StringBuffer sb2;
            int state = 0;
            for(int i=0; i<n; i++){
                char prev = s[i].charAt(0);
                sb2 = new StringBuffer();
                int count = 1, uniq = 0;
                for(int j=1; j<s[i].length(); j++){
                    if(prev != s[i].charAt(j)){
                        if(i == 0) sb1.append(prev);
                        sb2.append(prev);
                        //if(j != 0) {
                            if(!h.containsKey(uniq))
                                h.put(uniq, new ArrayList<Integer>());
                            h.get(uniq).add(count);
                        //}
                        prev = s[i].charAt(j);
                        count = 0;
                        uniq++;
                    } else {
                        count++;
                    }
                }
                if(!h.containsKey(uniq))
                    h.put(uniq, new ArrayList<Integer>());
                h.get(uniq).add(count);
                if(i == 0)
                    sb1.append(prev);
                sb2.append(prev);

                if(!sb1.toString().equals(sb2.toString())){
                    System.out.println("Case #" + t + ": Fegla Won");
                    state = 1;
                    break;
                }
            }
            if(state == 1) continue;
            int ans = 0;
            for(Map.Entry<Integer, List<Integer>> e : h.entrySet()){
                ans += getMinFor(e.getValue());
            }
            System.out.println("Case #" + t + ": " + ans);
        }
    }

    private static int getMinFor(List<Integer> l){
        int ans = Integer.MAX_VALUE;
        for(int target : l){
            int curr = 0;
            for(int p : l){
                curr += Math.abs(target - p);
            }
            ans = Math.min(ans, curr);
        }
        return ans;
    }

    public static class MyScanner {
              BufferedReader br;
              StringTokenizer st;

              public MyScanner() {
                 br = new BufferedReader(new InputStreamReader(System.in));
              }

              String next() {
                  while (st == null || !st.hasMoreElements()) {
                      try {
                          st = new StringTokenizer(br.readLine());
                      } catch (IOException e) {
                          e.printStackTrace();
                      }
                  }
                  return st.nextToken();
              }

              int nextInt() {
                  return Integer.parseInt(next());
              }

              long nextLong() {
                  return Long.parseLong(next());
              }

              double nextDouble() {
                  return Double.parseDouble(next());
              }

              String nextLine(){
                  String str = "";
        	  try {
        	     str = br.readLine();
        	  } catch (IOException e) {
        	     e.printStackTrace();
        	  }
        	  return str;
              }

           }
}
