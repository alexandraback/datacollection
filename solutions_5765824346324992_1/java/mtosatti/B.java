import java.util.Scanner;

public class B {
    
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int T, t, B, i;
        long N, bot, top, cur, min, free, gone, need;
        int m[];
        boolean s[];
        
        T = sc.nextInt();
        for (t = 1; t <= T; t++) {
            B = sc.nextInt();
            N = sc.nextLong();
            min = 1000000;
            m = new int[B];
            s = new boolean[B];
            for(i = 0; i < B; i++) { 
                m[i] = sc.nextInt();
                min = Math.min(m[i],  min);
            }
            
            bot = 0;
            top = (long) Math.ceil(N*min);
            cur = top;
            while(top > bot) {
                free = 0;
                gone = 0;
                for(i = 0; i < B; i++) {
                    gone += Math.ceil((double)cur/m[i]);
                    s[i] = (cur % m[i] == 0);
                    if(s[i]) free++;
                }
                if(gone < N && (gone + free >= N)) {
                    need = N - gone;
                    i = 0;
                    while (need > 0 && i < B) {
                        if(s[i]) { 
                            need--;
                            if(need <= 0) {
                                break;
                            }
                        }
                        i++;
                    }
                    if(need > 0) {
                        throw new Exception();
                    }
                    break;
                }
                if(gone >= N) {
                    top = cur;
                    cur = bot + (cur - bot) / 2;
                } else {
                    bot = cur;
                    cur += (top - cur) / 2;
                }
            }
            
            System.out.println("Case #" + t + ": " + (i+1));
        }
        sc.close();
    }
}
