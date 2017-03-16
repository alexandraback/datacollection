import java.util.Scanner;

/**
 * Created by jarrett on 17/04/15.
 */
public class B {
    public static int listMin(int[] in){
        int min = Integer.MAX_VALUE;
        int blah = -1;
        int j;
        for(j=0;j<in.length;j++){
            if(in[j]<min){
                blah = j;
                min = in[j];
            }
        }
        return min;
    }
    public static int lcm(int[] in){
        int i;
        int lcm = in[0];
        for(i=1;  i < in.length;i++){
            if(!(lcm %in[i] == 0)){
                lcm = lcm*in[i];
            }
        }
        int reduced = 0;
        for(i=0;  i < in.length;i++){
            reduced  += lcm/in[i];
        }
        return reduced;
    }
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numCases = Integer.parseInt(in.nextLine());
        for (int i = 0; i < numCases; i++) {
            String[] input = in.nextLine().split(" ");
            int numBarb = Integer.parseInt(input[0]);
            int place = Integer.parseInt(input[1]);
            input = in.nextLine().split(" ");
            int[] barbTimes = new int[numBarb];
            int[] barbTracker = new int[numBarb];
            int j;
            for(j=0;j<barbTimes.length;j++) {
                barbTimes[j] = Integer.parseInt(input[j]);
                barbTracker[j] = 0;
            }
            int l = lcm(barbTimes);
            int ahead = place -1;
            ahead = ahead %l;
            place = ahead +1;
            outer: while(place>1){
                int smallest  = listMin(barbTracker);

                if(place <= numBarb) {
                    for (j = 0; j < barbTimes.length; j++) {
                        if (barbTracker[j] == 0) {
                            place--;
                            barbTracker[j] = barbTimes[j];
                            if (place == 1) {
                                break outer;
                            }
                        }
                    }
                    for (j = 0; j < barbTimes.length; j++) {
                        barbTracker[j]--;
                    }
                }
                else{
                    for (j = 0; j < barbTimes.length; j++) {
                        barbTracker[j] -= smallest;
                    }
                    for (j = 0; j < barbTimes.length; j++) {
                        if(barbTracker[j] == 0) {
                            place--;
                            barbTracker[j] = barbTimes[j];
                        }
                    }
                }
            }

            int min = Integer.MAX_VALUE;
            int blah = -1;
            for(j=0;j<barbTracker.length;j++){
                if(barbTracker[j]<min){
                    blah = j;
                    min = barbTracker[j];
                }
            }




            System.out.println("Case #" + (i + 1) + ": " + (blah + 1));

        }
    }
}
