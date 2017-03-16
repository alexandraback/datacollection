import java.util.*;

public class Repeater {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int numCases = sc.nextInt();
        int curCase = 1;

        while (numCases > 0) {
            int numStrs = sc.nextInt();
            sc.nextLine();
            boolean fwon = false;
            List<List<Pair>> pls = new ArrayList<List<Pair>>(numStrs);

            for (int i = 0; i< numStrs; i++) {
                String a = sc.nextLine();
                pls.add(mkPairList(a));
            }
            for (List<Pair> a : pls) {
                if (!compPL(a,pls.get(0))) {
                    fwon = true;
                }
            }
            if (!fwon) {
                int numMoves = 0;

                List<List<Integer>> nums = new ArrayList<List<Integer>>();
                List<Pair> a = pls.get(0);
                int numChars = a.size();
                for (int i = 0; i< numChars; i++) {
                    nums.add(new ArrayList<Integer>());
                }
                for (List<Pair> l : pls) {
                    for (int i = 0; i< numChars; i++) {
                        nums.get(i).add(l.get(i).y);
                    }
                }
                for (int i = 0; i<numChars; i++) {
                    List<Integer> curList = nums.get(i);
                    Collections.sort(curList);
                    if (numStrs % 2 == 0) {
                        int numMoves1 = 0;
                        int numMoves2 = 0;
                        int med1 = curList.get(numStrs/2);
                        int med2 = curList.get(numStrs/2 - 1);
                        for (int j = 0; j < numStrs; j++) {
                            numMoves1 += Math.abs(curList.get(j) - med1);
                        }
                        for (int j = 0; j < numStrs; j++) {
                            numMoves2 += Math.abs(curList.get(j) - med2);
                        }
                        //System.err.format("%d %d\n", numMoves1, numMoves2);
                        if (numMoves1 < numMoves2) {
                            numMoves += numMoves1;
                        }
                        else {
                            numMoves += numMoves2;
                        }
                    }
                    else {
                        int med = curList.get(numStrs/2);
                        for (int j = 0; j < numStrs; j++) {
                            numMoves += Math.abs(curList.get(j) - med);
                        }
                    }
                }
           
                System.out.format("Case #%d: %d\n", curCase, numMoves);
            }
            else {
                System.out.format("Case #%d: Fegla Won\n", curCase);
            }
            curCase++;
            numCases--;
        }
    }

    public static List<Pair> mkPairList(String s) {
        int l = s.length();
        List<Pair> pl = new ArrayList<Pair>(l);
        int last = 0;
        pl.add(new Pair(s.charAt(0),1));
        for (int i = 1; i<l; i++) {
            if (s.charAt(i) == pl.get(last).x) {
                pl.get(last).y++;
            }
            else {
                last++;
                pl.add(new Pair(s.charAt(i),1));
            }
        }

        return pl;
    }

    public static boolean compPL(List<Pair> a, List<Pair> b) {
        if (a.size() != b.size()) { return false; }
        for (int i = 0; i<a.size(); i++) {
            if (a.get(i).x != b.get(i).x) {
                return false;
            }
        }
        return true;
    }
        
    public static class Pair {
        public char x;
        public int y;
        public Pair(char x, int y) {
            this.x = x;
            this.y = y;
        }
        public boolean equals(Object oth) {
            if (this == oth) { return true; }
            if (oth == null || !(getClass().isInstance(oth))) {
                return false; 
            }
            Pair other = getClass().cast(oth);
            return ((x == other.x) && (y==other.y));
        }
    }
}
