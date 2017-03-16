using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

namespace GoogleCodeJam
{
    public static class MathHelper
    {
        //      converts string to int
        public static int ConvertToInt(this string numberAsString)
        {
            return Convert.ToInt32(numberAsString);
        }

        //      converts string to int´s, with given separator
        public static IEnumerable<int> ConvertToInts(this string numberAsString, char separator)
        {
            return numberAsString.Split(separator).Select(x => Convert.ToInt32(x));
        }

        //      123  ->  {1,2,3}, first element is 1, second is 2, ...
        public static IEnumerable<int> ToDigits(this int number)
        {
            var allDigits = new List<int>();
            while (number > 0)
            {
                allDigits.Add(number % 10);

                number = number / 10;
            }

            allDigits.Reverse();

            return allDigits;
        }

        //      123  ->  3
        public static int CountDigits(this int number)
        {
            return number.ToDigits().Count();
        }

        //     123  ->  321
        public static int ToReverseNumber(this int number)
        {
            var asDigits = number.ToDigits().ToList();

            var result = 0;
            for (int i = 0; i < asDigits.Count(); i++)
            {
                result += asDigits[i] * 10.ToPower(i);
            }

            return result;
        }

        //      MathPow for ints
        public static int ToPower(this int baseNumber, int exponent)
        {
            return (int)Math.Pow(baseNumber, exponent);
        }

        //      get integer range from zero to end (including)
        public static IEnumerable<int> RangeTo(this int end)
        {
            return RangeFromTo(0, end);
        }

        //      get integer range from start to end, both including
        public static IEnumerable<int> RangeFromTo(int start, int end)
        {
            return Enumerable.Range(start, end - start + 1);
        }

        //      true if potentialDivisor divides number, false otherwise
        public static bool DoesDivide(this int potentialDivisor, int number)
        {
            return number % potentialDivisor == 0;
        }

        //      get divisors for number, including one and number itself
        public static IEnumerable<int> GettAllDivisors(this int number)
        {
            var halfOfNumber = number / 2;

            return Enumerable.Range(1, halfOfNumber)
                .Where(x => number % x == 0).Union(new[] { number });
        }

        //      get real divisors for number, excluding one and number itself
        public static IEnumerable<int> GettAllRealDivisors(this int number)
        {
            return number.GettAllDivisors().Except(new[] { 1, number });
        }

        //      true if number is prime, false otherwise
        public static bool IsPrime(this int number)
        {
            if (number == 1)
            {
                return false;
            }

            if (number == 2)
            {
                return true;
            }

            var square = (int)Math.Ceiling(Math.Sqrt(number));

            return Enumerable.Range(1, square)
                .Where(x => number % x == 0)
                .Count() == 1;
        }

        //      generates all primes below and including limit
        public static IEnumerable<int> GetAllPrimesUpTo(int limit)
        {
            var bits = new BitArray(limit + 1, true);
            bits[0] = false;
            bits[1] = false;

            for (int i = 0; i * i <= limit; i++)
            {
                if (bits[i])
                {
                    for (int j = i * i; j <= limit; j += i)
                    {
                        bits[j] = false;
                    }
                }
            }

            for (int i = 0; i < bits.Count; i++)
            {
                if (bits[i])
                {
                    yield return i;
                }
            }            
        }

        //      generates all primes between start and end (both including)
        public static IEnumerable<int> GetAllPrimesBetween(int start, int end)
        {
            var allPrimes = GetAllPrimesUpTo(end);

            return allPrimes.Where(x => x >= start);
        }

        //      2  ->  (f,f), (f,t), (t,f), (t,t)
        public static IEnumerable<IEnumerable<bool>> GetBoolFooOfLength(this int length)
        {
            var v = 2.ToPower(length);

            for (int outer = 0; outer < v; outer++)
            {
                var currentNumber = outer;

                var foo = new List<bool>();
                for (int inner = length - 1; inner >= 0; inner--)
                {
                    var value = 2.ToPower(inner);
                    if (currentNumber >= value)
                    {
                        foo.Add(true);
                        currentNumber -= value;
                    }
                    else
                    {
                        foo.Add(false);
                    }
                }

                yield return foo;
            }
        }

        //      generates the power set, {0,1}  ->  {{},{0},{1},{0,1}}
        public static IEnumerable<IEnumerable<T>> ToPowerSet<T>(this IEnumerable<T> input)
        {
            var inputAsList = input.ToList();
            
            foreach (var item in GetBoolFooOfLength(inputAsList.Count()))
            {
                var itemList = item.ToList();

                var result = new List<T>();
                for (int i = 0; i < inputAsList.Count(); i++)
                {
                    if (itemList[i])
                    {
                        result.Add(inputAsList[i]);
                    }
                }

                yield return result;
            }
        }
    }
}
