import java.util.Scanner;

/**
 * Created by jarrett on 17/04/15.
 */
public class A {

    public static int getNextMax(int[] arr, int start){
        boolean check = false;
        int temp = start;

        while(!check){
            if(temp==0){
                return 0;
            }
            if(arr[temp-1] < arr[temp]){
                return  temp;
            }
            temp--;
        }
        return 0;
    }
    public static int getNextMin(int[] arr, int start){
        boolean check = false;
        int temp = start;

        while(!check){
            if(temp==0){
                return 0;
            }
            if(arr[temp-1] > arr[temp]){
                return  temp;
            }
            temp--;
        }
        return 0;

    }
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numCases = Integer.parseInt(in.nextLine());
        for (int i = 0; i < numCases; i++) {
            int numInterval= Integer.parseInt(in.nextLine());
            String[] input = in.nextLine().split(" ");
            int[] intervals = new int[input.length +1];
            intervals[0] = 0;
            int j;
            for(j=1;j<intervals.length;j++) {
                intervals[j] = Integer.parseInt(input[j-1]);

            }
            int nextMin = Integer.MAX_VALUE;
            int nextMax = getNextMax(intervals, intervals.length-1);
            int start = intervals.length-1;
            int count = 0;
            while(nextMin >0) {
                nextMax = getNextMax(intervals, start);
                nextMin = getNextMin(intervals,nextMax);
                count += (intervals[nextMax] - intervals[nextMin]);
                start = nextMin;
            }
            count -= intervals[intervals.length-1];
            int speed = 0;
            int count2 = 0;
            for(j=2; j<intervals.length;j++){
                if((intervals[j-1] - intervals[j]) > speed){
                    speed = intervals[j-1] - intervals[j];
                }
            }
            if(speed == 0){
                count2 = 0;
            }
            else {
                for (j = 1; j < intervals.length-1; j++) {
                    if (intervals[j] < speed){
                        count2 += intervals[j];
                    } else {
                        count2 += speed;
                    }
                }
            }


            System.out.println("Case #" + (i + 1) + ": " + count + " " + count2);

        }
    }
}

