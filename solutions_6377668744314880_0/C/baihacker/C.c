const int maxp = 100000;
#include <pe>
static inline int Rint()
{
    struct X{ int dig[256]; X(){
    for(int i = '0'; i <= '9'; ++i) dig[i] = 1; dig['-'] = 1;
    }};
    static     X fuck;int s = 1, v = 0, c;
    for (;!fuck.dig[c = getchar()];);
    if (c == '-') s = 0; else if (fuck.dig[c]) v = c ^ 48;
    for (;fuck.dig[c = getchar()]; v = v * 10 + (c ^ 48));
    return s ? v : -v;
}

typedef int64 Ct;
struct Pt
{
	Pt(Ct _x = 0, Ct _y = 0) : x(_x), y(_y){}
	Ct x, y;
  int id;
};
inline Pt operator - (const Pt& a, const Pt& b) 
{
	return Pt(a.x-b.x, a.y-b.y);
}
inline Pt operator + (const Pt& a, const Pt& b)
{
	return Pt(a.x+b.x, a.y+b.y);
}
inline Ct cross(const Pt& a, const Pt& b)
{
	return a.x * b.y - a.y * b.x;
}
inline Ct cross(const Pt& a, const Pt& b, const Pt& c)
{
	return cross(b-a, c-a);
}
struct covex_hull
{
	int cal(Pt* input, int size, Pt* output)
	{
		sort(input, input+size, cmp_y_x);
		if (size <= 2)
		{
			copy(input, input+size, output);
			return size;
		}
		output[0] = input[0], output[1] = input[1];
		int top = 1;
		for (int i = 2; i < size; ++i)
		{
			while (top && cross(output[top-1], output[top], input[i]) < 0)
			--top;
			output[++top] = input[i];
		}
		int len = top;
		output[++top] = input[size-2];
		for (int i = size - 3; i >= 0; --i) 
		{
			while (top != len && cross(output[top-1], output[top], input[i]) < 0)
			--top;
			output[++top] = input[i];
		}
		return top;
	}
	static int cmp_y_x(const Pt& a, const Pt& b)
	{
		if (a.y != b.y) return a.y < b.y;
		return a.x < b.x;
	}
};

Pt data[15];
int ans[15];
int main()
{
  covex_hull cv;
  const int T = Rint();
  for (int id = 1; id <= T; ++id)
  {
    const int n = Rint();
    for (int i = 0; i < n; ++i)
    {
      data[i].x = Rint();
      data[i].y = Rint();
      data[i].id = i;
    }
    fill(ans, ans+n, 2000000000);
    const int limit = 1 << n;
    for (int i = 1; i < limit; ++i)
    {
      Pt input[32];
      Pt output[32];
      int del = 0;
      int cnt = 0;
      for (int j = 0; j < n; ++j)
      if (i & (1<<j)) input[cnt++] = data[j];
      else ++del;
      cnt = cv.cal(input, cnt, output);
      for (int j = 0; j < cnt; ++j)
      {
        int who = output[j].id;
        cmin(ans[who], del);
      }
    }
    printf("Case #%d:\n", id);
    for (int i = 0; i < n; ++i)
    printf("%d\n", ans[i]);
  }
  return 0;
}