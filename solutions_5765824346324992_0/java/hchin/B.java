import java.util.*;

public class B
{
    public static void main (String [] args)
    {
        Scanner sc = new Scanner(System.in);
        int noCase = sc.nextInt();
        for(int ind =1; ind<=noCase; ind++)
        {
            int B = sc.nextInt();
            long N = sc.nextLong();
            LinkedList<barb> freeQ = new LinkedList<barb>();
            LinkedList<barb> busyQ = new LinkedList<barb>();
            LinkedList<Long> temp = new LinkedList<Long>();
            for(int i=1; i<=B; i++)
            {
                temp.add(sc.nextLong());
                freeQ.add(new barb(i,temp.getLast()));
            }

            Collections.sort(freeQ); 
            Collections.sort(temp);
            long P = 1;
            for(Long L : temp)
                P = LCM(L, P);
          //  System.out.println(P);
            long cum = 0;
            for(Long L:temp)
                cum += P/L;
           // System.out.println(cum);
            N= N%cum;
            if(N==0) N = cum; 
            int soln = 0;
            TreeSet<Long> time = new TreeSet<Long>();
            time.add(0L);
DONE:
            while(N>0)
            {
               long T = time.pollFirst();

                for(barb Br: busyQ)
                    Br.dec(T);
                Iterator<barb> iter = busyQ.iterator();
                while(iter.hasNext())
                {
                    barb curB = iter.next();
                    if(curB.done())
                    {
                        freeQ.add(curB);
                        iter.remove();
                    }
                }

                Collections.sort(freeQ);
             //   System.out.println("time"+T);
              //  System.out.println(busyQ);
               //System.out.println(freeQ);

                
                while(freeQ.size()>0)
                {
                    barb curB = freeQ.pop();
                    N--;
                    if(N==0)
                    {
                        soln = curB.id;
                        break DONE;
                    }
                    curB.useBarb(T);
                    busyQ.push(curB);
                    time.add(T+curB.M);
                }
                
                //
            }
            
            

            System.out.printf("Case #%d: %d\n", ind, soln);
        }
    }

    static long GCD(long a, long b)
    {
        return a == 0 ? b : GCD(b%a, a);
    }
    static long LCM(long a, long b)
    {
        long g = GCD(a,b);
        return (a*b)/g;
    }


    static class barb implements Comparable<barb>
    {
        long M, cur;
        long time;
        int id;
        public barb(int id, long M)
        {
            this.id = id;
            this.M = M;
        }

        public int compareTo(barb B)
        {
            return id-B.id;
        }

        public void useBarb(long t)
        {
            cur = M;
            time = t;
        }

        public void dec(long t)
        {
            cur -= (t-time);
            time = t;
        }

        public boolean done()
        {
            return cur<=0;
        }

        public String toString()
        {
            return String.format("(%d: %d>,%d,%d) ",id, M, cur, time);
        }
    }
}
