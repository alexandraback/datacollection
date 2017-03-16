package haircut;

import java.math.BigInteger;
import java.util.ArrayDeque;
import java.util.Collection;
import java.util.Deque;
import java.util.Scanner;
import java.util.TreeMap;

public class Haircut {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int numTestCases = sc.nextInt();
    for (int testCase = 1; testCase <= numTestCases; ++testCase) {
      int numBarbers = sc.nextInt(), placeInLine = sc.nextInt();
      Deque<Barber> barberTimes = new ArrayDeque<>();
      for (int i = 0; i < numBarbers; ++i)
        barberTimes.add(new Barber(i + 1, sc.nextInt()));
      System.out.printf("Case #%d: %d\n", testCase, whichBarber(barberTimes, placeInLine));
    }
  }

  private static int whichBarber(Deque<Barber> barbers, int placeInLine) {
    TreeMap<Long, Deque<Barber>> barbersReadyAtTime = new TreeMap<>();
    int customersAhead = placeInLine - 1;

    double netRateUpperBound = 0;
    for (Barber barber : barbers)
      netRateUpperBound += barber.getRateUpperBound();

    System.err.println("total " + customersAhead);
    double totalDurationLowerBound = customersAhead / netRateUpperBound;
    for (Barber barber : barbers) {
      int myHaircutsLowerBound = (int) (barber.getRateLowerBound() * totalDurationLowerBound);
      System.err.println("removing " + myHaircutsLowerBound);
      long timeReady = myHaircutsLowerBound * barber.timeTaken;
      if (!barbersReadyAtTime.containsKey(timeReady))
        barbersReadyAtTime.put(timeReady, new ArrayDeque<>());
      barbersReadyAtTime.get(timeReady).addLast(barber);
      customersAhead -= myHaircutsLowerBound;
    }
    System.err.println("remaining " + customersAhead);

    for (int t = 0; t < customersAhead; ++t) {
      Long nextTime = barbersReadyAtTime.firstKey();
      Deque<Barber> deque = barbersReadyAtTime.get(nextTime);
      Barber barber = nextBarber(deque);
      deque.remove(barber);
      if (deque.isEmpty())
        barbersReadyAtTime.remove(nextTime);

      long nextAvailable = nextTime + barber.timeTaken;
      if (!barbersReadyAtTime.containsKey(nextAvailable))
        barbersReadyAtTime.put(nextAvailable, new ArrayDeque<>());
      barbersReadyAtTime.get(nextAvailable).addLast(barber);
    }

    return nextBarber(barbersReadyAtTime.firstEntry().getValue()).number;
  }

  private static Barber nextBarber(Collection<Barber> barbers) {
    Barber winner = barbers.iterator().next();
    for (Barber barber : barbers) {
      if (barber.number < winner.number)
        winner = barber;
    }
    return winner;
  }

  private static class Barber {
    static final double EPSILON = 0.0001;

    final int number;
    final int timeTaken;

    Barber(int number, int timeTaken) {
      this.number = number;
      this.timeTaken = timeTaken;
    }

    double getRateLowerBound() {
      return (1 - EPSILON) / timeTaken;
    }

    double getRateUpperBound() {
      return (1 + EPSILON) / timeTaken;
    }
  }

  private static class Rational {
    final BigInteger numerator;
    final BigInteger denominator;

    Rational(BigInteger numerator, BigInteger denominator) {
      this.numerator = numerator;
      this.denominator = denominator;
    }
  }
}
