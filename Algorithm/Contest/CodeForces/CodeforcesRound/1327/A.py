for _ in [0]*int(input()):
  n, k = map(int, input().split())
  print('YNEOS'[n-k&1 or  k*k>n::2])