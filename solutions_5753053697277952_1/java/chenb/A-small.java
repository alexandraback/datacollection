import java.util.*;


public class Main {

    public static void main(String... args) {
        Main a = new Main();
        Scanner scanner = new Scanner(System.in);
        int caseNum = scanner.nextInt();
        for(int i=0; i< caseNum; i++) {
            int count = scanner.nextInt();
            int[] nums = new int[count];
            for(int j=0; j<count; j++) {
                nums[j] = scanner.nextInt();
            }
//            a.solve(nums,count);
            System.out.println(String.format("Case #%d: %s",i+1, a.solve(nums,count)));
        }
    }

    class Party implements Comparable<Party>{
        int count;
        char name;

        @Override
        public int compareTo(Party o) {
            return o.count - this.count;
        }

        Party(int count, char name) {
            this.count = count;
            this.name = name;
        }


    }

    public String solve(int[] nums,  int count) {
        Party[] parties = new Party[count];
        int total = 0;
        for(int i=0; i<count; i++) {
            total += nums[i];
            parties[i] = new Party(nums[i], (char)('A' + i));
        }
        StringBuffer sb = new StringBuffer();

        while (total >=4) {
            Arrays.sort(parties);
            sb.append(parties[0].name);
            parties[0].count --;

            Arrays.sort(parties);
            sb.append(parties[0].name);
            parties[0].count --;

            sb.append(' ');
            total -=2;
        }

        if (total==3) {
            Arrays.sort(parties);
            sb.append(parties[0].name);
            parties[0].count --;
            sb.append(' ');
            total--;
        }


        Arrays.sort(parties);
        sb.append(parties[0].name);
        parties[0].count --;

        Arrays.sort(parties);
        sb.append(parties[0].name);
        parties[0].count --;


        return sb.toString();
    }





}