import javafx.scene.layout.Priority;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Scanner;

/**
 * Created by juanc on 08-May-16.
 */
public class SenateEvacuation {

    private static Scanner sn;
    private static PrintWriter writer;
    private final static boolean INLINE = true;
    private final static String INPUT = "A-small-attempt0.in";
    private final static String OUTPUT = "answer";


    public static void main(String[] args) throws IOException {
        sn = Input.getScanner("resources/" + INPUT);
        writer = new PrintWriter("resources/" + OUTPUT);
        int T = Integer.parseInt(sn.nextLine());
        for(int i = 1; i<=T; i++){
            if(INLINE)
                writer.print("Case #" + i + ": ");
            else
                writer.println("Case #" + i + ":");
            SenateEvacuationMain();
        }
        writer.close();

    }

    private static void SenateEvacuationMain(){
        int N = sn.nextInt();
        System.out.println("N: " + N);
        int[] sen = new int[N];
        LinkedList<Senator> queue = new LinkedList<>();
        for(int i = 0; i< N ; i++){
            queue.add(new Senator(i, sn.nextInt()));
        }
        queue.sort((a,b)->b.cant-a.cant);
        StringBuilder ans = new StringBuilder();
        while(N>0){
            Senator first = queue.getFirst(), second = queue.get(1);
            System.out.println(N);
            if(N!=3 || second.cant>1){
                ans.append(first.letter);
                ans.append(second.letter);
                ans.append(' ');

                if((first.cant--)==1)
                    N--;
                if((second.cant--)==1)
                    N--;

            }else {
                ans.append(first.letter);
                ans.append(' ');

                if((first.cant--)==1)
                    N--;
            }
            queue.sort((a,b)->b.cant-a.cant);
        }
        writer.println(ans.toString());
    }

    public static class Senator{
        public char letter;
        public int cant;

        public Senator(int pos, int cant){
            letter = (char) ('A' + pos);
            this.cant = cant;
        }
    }
}
