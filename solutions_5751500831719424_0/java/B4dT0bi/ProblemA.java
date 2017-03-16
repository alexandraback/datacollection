import java.io.BufferedReader;
import java.io.FileReader;
import java.util.Arrays;

public class ProblemA {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new FileReader(args[0]));
        int anzTC = Integer.parseInt(br.readLine());
        for (int tc = 0; tc < anzTC; tc++) {
            int anzString = Integer.parseInt(br.readLine().trim());

            String tmp[] = new String[anzString];
            for (int i = 0;i<anzString;i++) {
                tmp[i] = br.readLine();
            }
                solve(tc + 1, tmp);
        }
        br.close();
    }

    private static void solve(int tc, String [] strings) {
        if (!preCheck(strings)) {
            System.out.println("Case #" + tc + ": Fegla Won");
            return;
        }
        Arrays.sort(strings);
        System.out.println("Case #" + tc + ": " + countActions(strings));
    }
    private static int countActions(String [] strings) {
        boolean diff = false;
        for (int i = 1;i<strings.length;i++) {
            if (!strings[0].equals(strings[i])) diff = true;
        }
        if (!diff) return 0;
        int result = 0;
        char [] arr = reduce(strings[0]).toCharArray();
        int [][] anz = new int [arr.length][strings.length];
        for (int i=0;i<strings.length;i++) {
            int crrChar = 0;
            for (int n=0;n<strings[i].length();n++) {
                if (n==0) {
                    anz[crrChar][i]=1;
                }
                else {
                if (strings[i].charAt(n)==strings[i].charAt(n-1)) {
                    anz[crrChar][i]++;
                }
                else {
                    crrChar++;
                    anz[crrChar][i]=1;
                }}
            }
        }
        for (int i=0;i<arr.length;i++){
            result += minMoves(anz[i]);
        }
        return result;
    }
    private static int minMoves(int [] cnt) {
        boolean diff=false;
        for (int i=1;i<cnt.length;i++) {
            if (cnt[i]!=cnt[i-1])diff=true;
        }
        if (!diff) return 0;
        Arrays.sort(cnt);
        int max = cnt[cnt.length-1];
        int [] anz = new int [max];
        for (int i=0; i<cnt.length;i++) {
            for (int n=0;n<anz.length;n++) {
                int amt=cnt[i]-1-n;
                if (amt<0) amt=amt*-1;
                anz[n]+=amt;
            }
        }
        Arrays.sort(anz);
        for (int i=0;i<anz.length;i++) {
            if (anz[i]!=0) return anz[i];
        }
        return anz[0];
    }
    private static boolean preCheck(String [] strings) {
        String first = reduce(strings[0]);
        for (int i = 1; i< strings.length;i++) {
            if (!first.equals(reduce(strings[i]))) return false;
        }
        return true;
    }
    private static String reduce(String text) {
        StringBuffer sb = new StringBuffer();
        sb.append(text.charAt(0));
        for (int i=1;i<text.length();i++) {
            if (text.charAt(i-1)!=text.charAt(i))sb.append(text.charAt(i));
        }
        return sb.toString();
    }
}
