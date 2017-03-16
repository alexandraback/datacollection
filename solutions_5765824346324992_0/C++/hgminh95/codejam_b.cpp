#include <cstdio>
#include <iostream>

#define MAX_TIME 1000000000000000LL

using namespace std;

int b, n;
int m[1111];
int freePeopleCount;
int free[1111];

long long number_of_people(long long time) {
  freePeopleCount = 0;
  long long count = 0;
  for (int i = 0; i < b; i++) {
    count = count + time / (long long) m[i];
    if (time % (long long) m[i] == 0) {
      free[freePeopleCount] = i;
      freePeopleCount++;
    }
    else {
      count = count + (long long) 1;
    }
  }

  return count;
}

int find_out(long long min_time, long long max_time, int pos) {
  long long result = -1LL;
  while (min_time <= max_time) {
    long long mid_time = (min_time + max_time) / (long long) 2;
    long long people_count = number_of_people(mid_time);
    long long free_people = (long long) freePeopleCount;

    if (people_count > pos) {
      max_time = mid_time - 1LL;
      continue;
    }

    result = mid_time;
    min_time = mid_time + 1LL;
  }

  if (result == -1)
    cout << "ERROR result == -1" << endl;

  long long people_count = number_of_people(result);
  long long free_people = (long long) freePeopleCount;

  if (people_count + free_people < pos || free_people == 0LL)
    cout << "ERROR pp: " << people_count << " free: " << free_people <<  " time = " << result << endl;

  return free[int((long long) pos - people_count)];
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int nTest;
  scanf("%d", &nTest);

  for (int test = 1; test <= nTest; test++) {
    scanf("%d %d", &b, &n);
    for (int i = 0; i < b; i++) {
      scanf("%d", &m[i]);
    }

    int result = find_out(0LL, MAX_TIME, n - 1) + 1;

    printf("Case #%d: %d\n", test, result);
  }

  return 0;
}
