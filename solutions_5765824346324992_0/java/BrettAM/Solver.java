import java.io.*;
import java.util.*;
import java.math.*;

public class Solver {
    static Scanner input;
    static Writer  output;
    public static void main(String args[]) {
        if(args.length != 1){
            System.out.println("Please specify the input file");
            return;
        }

		String filename = args[0];
		File f = new File(filename);
		BufferedReader br;

        if (!f.exists()) {
            System.out.println("Couldn't find file "+filename);
            return;
        } else if (f.isDirectory()) {
            System.out.println(filename+" is a directory");
            return;
        }

        try {
			br = new BufferedReader (new FileReader (f));
			input = new Scanner(br);
        } catch (IOException iox){
		    System.out.println("Problem reading " + filename );
        }

        try {
            output = new BufferedWriter(
                        new OutputStreamWriter(
                            new FileOutputStream(filename+".out"), "utf-8"));
            solve();
        } catch (IOException ex) {
            System.out.println("Couldn't open an output file");
            return;
        }

        try{
            output.close();
            input.close();
        } catch (IOException ex) {
        }
    }

    static class Barber{
        int barberNum;
        BigInteger mySpeed;
        BigInteger finishTime;
        public Barber(){
            barberNum = 0;
        }
        public Barber(int b, BigInteger speed){
            barberNum = b;
            mySpeed = speed;
            finishTime = speed;
        }
        void incr(BigInteger curTime){
            finishTime = curTime.add(mySpeed);
        }
        void incr(){
            finishTime = finishTime.add(mySpeed);
        }
        BigInteger fTime(){
            return finishTime;
        }
        BigInteger speed(){
            return mySpeed;
        }
        Integer barberNumber(){
            return (Integer) barberNum;
        }
    }
    static class BarberCompare implements Comparator<Barber>
    {
        public int compare(Barber b1, Barber b2)
        {
            int cmp = (b1.fTime()) .compareTo( (b2.fTime()) );
            if(cmp == 0) return (b1.barberNumber()) .compareTo( (b2.barberNumber()) );
            return cmp;
        }
    }

    public static void solve() throws IOException {
        int T = input.nextInt();
        for(int caseNum=0; caseNum<T; caseNum++){
            int  B = input.nextInt(); //number of barbers
            BigInteger N = BigInteger.valueOf(input.nextInt()); //your place in line
            BigInteger[] barbs = new BigInteger[B];
            for (int i=0; i<B; i++) {
                barbs[i] = BigInteger.valueOf(input.nextLong());
            }

            //special case where N is less than B
            if(N.compareTo(BigInteger.valueOf(B)) != 1){
                System.out.println("I think its "+N);
                output.write("Case #"+(caseNum+1)+": ");
                output.write(""+N);
                output.write("\n");
                continue;
            }
            N=N.subtract(BigInteger.valueOf(B));//these people immediatly get serviced




            BigInteger lcm = barbs[0];
            for(int i=1; i<B; i++){
                BigInteger itr = barbs[i];
                BigInteger tmp = lcm.multiply(itr);
                lcm = tmp.divide(lcm.gcd(itr));
            }
            BigInteger servicedInLCM = BigInteger.ZERO;
            for (int i=0; i<B; i++) {
                servicedInLCM = servicedInLCM.add( lcm.divide(barbs[i]) );
            }
            N = N.mod(servicedInLCM);
            if(N.compareTo(BigInteger.ZERO)==0) N = servicedInLCM;
            System.out.println("lcm: "+lcm+" Serviced: "+servicedInLCM+" new N: "+N);





            PriorityQueue<Barber> p = new PriorityQueue<Barber>(B,new BarberCompare());
            for(int i=0; i<B; i++){
                p.add(new Barber(i+1, barbs[i]));
            }

            Barber nextUp=new Barber();
            while(N.compareTo(BigInteger.ZERO)>0){
                N = N.subtract(BigInteger.ONE);
                nextUp = p.poll();
                //System.out.println("Barber "+nextUp.barberNumber()+" takes a job");
                nextUp.incr();
                p.add(nextUp);
            }

            //get lowest numbered ready barber - fixed in compare func

            System.out.println("I think its "+nextUp.barberNumber());
            output.write("Case #"+(caseNum+1)+": ");
            output.write(""+nextUp.barberNumber());
            output.write("\n");
        }
    }
}

