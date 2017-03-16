import java.util.Scanner;

public class Barber{
    public static int gcd(int a, int b){
        int temp;
        while(b > 0){
            temp = b;
            b = a%b;
            a = temp;
        }
        return a;
    }
    
    public static int lcm(int a, int b){
        return b/gcd(a,b)*a;
    }
    
    public static int lcm(int[] array){
        if(array.length == 1){
            return array[0];
        }
        int currentLcm = lcm(array[0], array[1]);
        for(int i = 2; i < array.length; i++){
            currentLcm = lcm(currentLcm, array[i]);
        }
        return currentLcm;
    }
    
    /* Returns the number of people needed to reset to the starting state */
    public static int findWrappingPoint(int[] barberTimes){
        int barberLcm = lcm(barberTimes);
        
        int sumOfSeen = 0;
        
        for(int i = 0; i < barberTimes.length; i++){
            sumOfSeen += barberLcm/barberTimes[i];
        }
        
        return sumOfSeen;
    }
    
    public static long findIncrement(long time, int[] barberTimes){
        long minIncrement = barberTimes[0];
        for(int i = 0; i < barberTimes.length; i++){
            int diff = (int) (time%barberTimes[i]);
            //^ how much past this time the next time is
            long temp = barberTimes[i] - diff;
            if(temp < minIncrement){
                minIncrement = temp;
            }
        }
        
        return minIncrement;
    }
    
    public static int findBarber(int position, int[] barberTimes){
        long time = 0;
        int peopleSeen = 0;
        position = position+1;
        //System.out.println(position);
        while(true){
            for(int i = 0; i < barberTimes.length; i++){
                if(time%barberTimes[i] == 0){
                    peopleSeen++;
                    if(peopleSeen == position){
                        return i+1; //one-indexed
                    }
                }
            }
            
            //There could be a thousand barbers, so we don't want to waste iters
            time += findIncrement(time, barberTimes);
        }
    }
    
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        
        int numberTests = scan.nextInt();
        for(int test = 0; test < numberTests; test++){
            int B = scan.nextInt(); //# barbers
            int N = scan.nextInt(); //my place in line
            if(B == 1){
                scan.nextInt(); //need to gobble that integer
                System.out.println("Case #" + (test+1) + ": " + 1);
            } else {
                int[] barberTimes = new int[B];
                for(int i = 0; i < B; i++){
                    barberTimes[i] = scan.nextInt();
                }
                int peopleWrappingPoint = findWrappingPoint(barberTimes);
                int barber = findBarber((N-1)%peopleWrappingPoint, barberTimes);
                System.out.println("Case #" + (test+1) + ": " + barber);
            }
        }
    }
}
