n=long(input())
print [-1,10**(n-1)+(210-((10**(n-1))%210))%210][n>2]