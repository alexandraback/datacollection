package CodeJam20151A;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

public class B {
    private static Comparator<Barber> TimeComparator = new Comparator<Barber>() {

        @Override
        public int compare(Barber o1, Barber o2) {
            return Integer.compare(o1.timeleft, o2.timeleft);
        }
    };
    
    public static class Barber implements Comparable<Barber> {
        int pos;
        int totaltime;
        int timeleft;

        public Barber(int pos, int time) {
            this.pos = pos;
            this.totaltime = time;
            this.timeleft = 0;
        }

        @Override
        public int compareTo(Barber o) {
            return Integer.compare(this.pos, o.pos);
        }

        @Override
        public String toString() {
            return this.pos + " " + this.totaltime + " -- " + this.timeleft;
        }
    }
    
    public static void main(String[] args) throws FileNotFoundException, IOException {
        Scanner sc = new Scanner(new File("B-small-attempt1.in"));
        BufferedWriter bw = new BufferedWriter(new FileWriter(new File("out.txt")));
//        Scanner sc = new Scanner(System.in);
        //Scanner sc = new Scanner(new File("a.txt"));
        int T  = sc.nextInt();
        for (int i = 0; i < T; i++) {
            int B = sc.nextInt();
            int N = sc.nextInt();
            int m[] = new int [B];
            PriorityQueue<Barber> available = new PriorityQueue<>();
            PriorityQueue<Barber> busy = new PriorityQueue<>(B, TimeComparator);
            for (int j = 0; j < B; j++) {
                m[j] = sc.nextInt();
                available.add(new Barber(j, m[j]));
            }
            for (int j = 0; j < 1000000000; j++) {
                
            }
            int result = -1;
            ArrayList<Integer> lista = new ArrayList<>();
            for (int j = 0; j < N-1; j++) {
//                System.out.println(j);
                
//                System.out.println(j + " --------------------------------");
                if(available.isEmpty()){
                    Barber b = busy.peek();
                    int t = b.timeleft;
                    for (Barber barber : busy) {
                        barber.timeleft = barber.timeleft - t;
                    }
//                    System.out.println("BUSY 2"); 
//                    System.out.println(busy);
                    
                    while(!busy.isEmpty() &&  busy.peek().timeleft==0){
                        available.add(busy.poll());
                    }
                }
                if(busy.isEmpty() && j!=0){
                    result = 0;
                    break;
                }
                Barber b = available.poll();
                lista.add(b.pos);
                b.timeleft = b.totaltime;
                busy.add(b);
                
//                System.out.println("Available");
//                System.out.println(available);
//                System.out.println("BUSY");
//                System.out.println(busy);
//                System.out.println(" --------------------------------");
            }
            if(result == -1){
                if(available.isEmpty()){
                    result = (busy.peek().pos + 1);
                }else{
                    result = (available.peek().pos + 1);
                }
            }else{
                result = lista.get((N-1)%lista.size()) +1;
            }
            System.out.println("Case #" + (i+1) + ": " + result );
            bw.write("Case #" + (i+1) + ": " + result );
            bw.newLine();
            
        }
        bw.close();
    }
}
