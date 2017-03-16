package round1;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class A {
    public static void main(String[] args) throws FileNotFoundException {
        final Scanner scanner = new Scanner(new File("C:\\Users\\Samuel\\Downloads\\input.txt"));
        Integer cases = Integer.parseInt(scanner.nextLine());
        for (Integer i = 0; i < cases; i++) {
            String[] line = (scanner.nextLine()).split(" ");
            Integer NBarbers = Integer.parseInt(line[0]);
            Integer posInQ = Integer.parseInt(line[1]);
            String[] line2 = (scanner.nextLine()).split(" ");
            ArrayList<Integer> waitTimes = new ArrayList<Integer>();
            HashMap<Integer, Integer> currentWaitTimes = new HashMap<Integer, Integer>();
            Integer k = 0;
            for (String t : line2) {
                waitTimes.add(Integer.parseInt(t));
                currentWaitTimes.put(k, 0);
                k++;
            }
            Integer posToUse = 1;
            Integer time = 0;
            Boolean found = false;
            Integer LCM = lcm(waitTimes);
            Integer count = 0;
            for (Integer w : waitTimes) {
                count += LCM / w;
            }
            //System.out.println(posInQ);
            posInQ = (posInQ % count);
            if (posInQ == 0) {
                posInQ = count;
            }
//            System.out.println(posInQ);
            while (!found) {
                time++;
                Integer min = 999999999;
                for (Integer j = 0; j < currentWaitTimes.size(); j++) {
                    if (currentWaitTimes.get(j) < min) {
                        min = currentWaitTimes.get(j);
                    }
                }
                for (Integer j = 0; j < currentWaitTimes.size(); j++) {
                    currentWaitTimes.put(j, currentWaitTimes.get(j) - min);
                    if (currentWaitTimes.get(j) <= 0) {
                        currentWaitTimes.put(j, waitTimes.get(j));
                        if (posToUse.equals(posInQ)) {
                            System.out.println("Case #" + (i + 1) + ": " + (j + 1));
                            found = true;
                        }
                        posToUse++;
                    }
                }
            }
        }
    }

    private static Integer lcm(ArrayList<Integer> waitTimes) {
        Integer result = waitTimes.get(0);
        for(int i = 1; i < waitTimes.size(); i++) result = lcm(result, waitTimes.get(i));
        return result;
    }

    private static Integer lcm (Integer a, Integer b) {
        return a * (b / gcd(a, b));
    }

    private static Integer gcd(Integer a, Integer b)
    {
        while (b > 0)
        {
            Integer temp = b;
            b = a % b; // % is remainder
            a = temp;
        }
        return a;
    }
}
