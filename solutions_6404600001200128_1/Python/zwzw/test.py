import sys
sys.stdin=open('input.txt', 'r'); sys.stdout=open('output.txt', 'w')

R=lambda:map(int,raw_input().split())
for _ in range(input()):
	n=input()
	a=R()
	ans1=ans2=rate=cnt=0
	for i in range(1,n):
		if a[i-1]>a[i]:
			ans1+=a[i-1]-a[i]
			rate=max(rate,a[i-1]-a[i])

	for i in range(1,n):
		ans2+=max(min(rate,a[i-1]), a[i-1]-a[i])
	print 'Case #%d: %s %s' % (_+1, ans1, ans2)