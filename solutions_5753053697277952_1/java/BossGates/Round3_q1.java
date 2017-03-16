import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

/**
 * Created by BG2Air on 5/8/16.
 */
public class Round3_q1 {

    public static class Obj
    {
        char P;
        int num;
        public Obj(char P, int num)
        {
            this.num = num;
            this.P = P;
        }
    }

    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        int T = scanner.nextInt();
        for(int t=1;t<=T;t++)
        {
            int N = scanner.nextInt();
            PriorityQueue<Obj> minheap = new PriorityQueue<>(N, new Comparator<Obj>() {
                @Override
                public int compare(Obj o1, Obj o2) {
                    return o2.num-o1.num;
                }
            });

            int count_all = 0;
            for(int i=0;i<N;i++)
            {
                int num = scanner.nextInt();
                count_all += num;
                minheap.add(new Obj((char)(i+'A'), num));
            }

            String all_code = "";
            while(!minheap.isEmpty())
            {
                String code = "";

                Obj next =  minheap.poll();
                code += next.P;

                next.num --;
                count_all --;
                if(next.num > 0)
                    minheap.add(next);

                if(!minheap.isEmpty()) {
                    // Check top
                    if (minheap.peek().num > count_all / 2) {
                        next = minheap.poll();
                        code += next.P;
                        next.num--;
                        count_all--;
                        if (next.num > 0)
                            minheap.add(next);
                    }
                }

                all_code = all_code + code + " ";
            }

            System.out.printf("Case #%d: %s\n",t,all_code);
        }


    }
}
