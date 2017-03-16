import java.util.PriorityQueue;
import java.util.Scanner;

/**
 * Created with IntelliJ IDEA.
 * User: chenbin
 * Date: 4/18/15
 * Time: 9:25 AM
 * To change this template use File | Settings | File Templates.
 */
public class B {

    public static void main(String... args) {
        B b = new B();
        Scanner scanner = new Scanner(System.in);
        int caseNum = scanner.nextInt();
        for(int i=0; i< caseNum; i++) {


            int B = scanner.nextInt();
            long N = scanner.nextLong();
            int[] time = new int[B];
            for(int j=0; j< B; j++) {
                time[j] = scanner.nextInt();
            }


            System.out.println(String.format("Case #%d: %d", i+1, b.solution(time, N)));
        }
    }


    public int solution(int[] input, long N) {
        int time =0;
        int B = input.length;

        int common =input[0];
        for(int i=0; i<input.length -1; i++) {
            common = helper(common, input[i+1]);
        }

        int total = 0;
        for(int i=0; i< input.length; i++) {
            total += common / input[i];
        }

        PriorityQueue<Barber> queue = new PriorityQueue<Barber>(B);
        for(int i=0; i< B; i++) {
            Barber barber = new Barber(0, i+1);
            queue.add(barber);
        }

        long N2 = N % total;

        for(int i=1; i<= N2; i++) {
            Barber barber = queue.poll();
            if(i== N2) {
                return barber.num;
            }

            barber.setNextTime(barber.nextTime + input[barber.num-1]);
            queue.add(barber);
        }

        //last one
        for(int i=B; i>=1; i--) {
            if(total % i ==0) {
                return i;
            }
        }
        return 0;
    }

    private int helper(int m, int n) {
        if(m<n)
        {
            int t=m;
            m=n;
            n=t;
        }
        for(int i=n;i<=m*n;i++)
        {
            if(i%m==0 && i%n==0) {
                return i;
            }
        }
        return 0;
    }

    class Barber implements Comparable<Barber>{
        int num;
        int nextTime;


        Barber(int nextTime, int num) {
            this.nextTime = nextTime;
            this.num = num;
        }

        @Override
        public int compareTo(Barber o) {
            if(nextTime != o.nextTime) {
                return nextTime - o.nextTime;
            } else {
                return num - o.num;
            }

        }

        int getNum() {
            return num;
        }

        void setNum(int num) {
            this.num = num;
        }

        int getNextTime() {
            return nextTime;
        }

        void setNextTime(int nextTime) {
            this.nextTime = nextTime;
        }
    }
}
