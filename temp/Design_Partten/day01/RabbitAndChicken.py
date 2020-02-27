for rabbit in range(0, 31):
  for chicken in range(0, 31):
    if rabbit+chicken == 30 and rabbit*4 + chicken*2==88:
      print("rabbit:", rabbit, "chicken:", chicken)
