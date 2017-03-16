import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Solver solver = new Solver();
        solver.solve();
    }
}

class Solver {

    int sum(List<Party> ls) {
        int sum = 0;
        for(Party p : ls) {
            sum += p.num;
        }
        return sum;
    }

    boolean hasMajor(List<Party> parties) {
        int sum = sum(parties);
        for(Party p : parties) {
            if (p.num > sum / 2) {
                return true;
            }
        }
        return false;
    }

    String solve(List<Party> parties) {
        // 모든 경우의 수를 시도한다.
        // 1명 or 2명
        // 최적이어야 한다는 조건은 없으므로 아무거나 하면 된다.
        // 그냥 가장 큰 것부터 빼면 될 듯
        // 1. 가장 큰 것을 빼거나
        // 2. 가장 큰 것과 그 다음 것을 빼거나
        // major가 존재하는지만 확인하면 된다.
        // sum의 절반보다 크면 major
        // n^2logn = 천만
        // 최악 시간복잡도 천만
        String result = "";

        System.err.println(parties);

        while(true) {
            Collections.sort(parties, new Comparator<Party>() {
                public int compare(Party a, Party b) {
                    return Integer.compare(a.num, b.num);
                }
            });
            Collections.reverse(parties);

            Party p1 = parties.get(0);

            if (p1.num == 0) {
                return result.trim();
            }

            p1.num--;
            result += p1.name;

            parties.get(1).num--;
            if (hasMajor(parties)) {
                // rollback
                parties.get(1).num++;
            } else {
                result += parties.get(1).name;
            }

            result += " ";
        }
    }

    class Party {
        String name;
        Integer num;
        public String toString() {
            return name + ":" + num;
        }
    }

    void solve() {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for(int j = 0; j < t; j++) {
            // DO
            int n = sc.nextInt();
            List<Party> parties = new ArrayList<>();
            for(int i = 0; i < n; i++) {
                Party p = new Party();
                p.name = "" + ((char)('A' + i));
                p.num = sc.nextInt();
                parties.add(p);
            }
            System.out.printf("Case #%d: %s%n", j + 1, solve(parties));
        }
    }
}
