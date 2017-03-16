package round1C;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class SenateEvacuation {
    public static void main(String[] args) {
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int t = in.nextInt(); 
        for (int i = 1; i <= t; ++i) {
            int n = in.nextInt();
            int[] parties = new int[n];
            int senatorsleft = 0;
            for (int j=0; j<n; ++j){
                parties[j] = in.nextInt();
                senatorsleft += parties[j];
            }
            System.out.print("Case #" + i + ": ");
            while (senatorsleft>0){
                String e = "";
                e += getHighest(parties);
                if (senatorsleft==3 || senatorsleft == 1){
                    senatorsleft -= 1;
                } else {
                    e += getHighest(parties);
                    senatorsleft -= 2;
                }
                System.out.print(e+" ");
            }
            System.out.println();
        }
        in.close();
    }
    
    public static char getHighest(int[] parties){
        int maxi = -1, max = 0;
        for (int i=0; i<parties.length; ++i){
            if (parties[i] > max){
                maxi = i;
                max = parties[i];
            }
        }
        parties[maxi]--;
        return (char)('A'+maxi);
    }
}