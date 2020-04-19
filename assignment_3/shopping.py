def shop_spree(items, cap, prc, wgt):
  total = 0
  # create matrix
  matrix = []
  for i in range(items + 1):
    matrix.append([])
    for j in range(cap + 1):
      matrix[i].append(0)
  
  # fill out the matrix
  i = 0
  while i <= items:
    w = 0
    while w <= cap:
      if i == 0 or w == 0:
        matrix[i][w] = 0
      elif wgt[i - 1] <= w:
        matrix[i][w] = max(matrix[i - 1][w], prc[i - 1] + matrix[i - 1][w - wgt[i - 1]])
      else:
        matrix[i][w] = matrix[i - 1][w]
      w += 1
    i += 1
    
  total += matrix[i - 1][w - 1]
  
  i, j = items, cap
  item_list = []
  item_list.append(total)
  
  while i > 0 and j > 0:
    if matrix[i][j] == matrix[i - 1][j]:
      i -= 1
    else:
      item_list.insert(1, ("%s " % i)) 
      i -= 1
      j = j - wgt[i]

  item_list.append("\n")

  return item_list
 
with open("shopping.txt", "r") as f:
  # initially creating the file to start fresh
  f_out = open("results.txt", "w")
  f_out.close()
  
  # ignore multiple test cases for now
  cases = int(f.readline())
  
  c = 0
  while c < cases:
    prc, wgt = [], []
    items = int(f.readline())
    i, j = 0, 0 
  
    while i < items:
      p, w = f.readline().split()
      prc.append(int(p))
      wgt.append(int(w))
      i += 1
    
    item_list = []
  
    ppl = int(f.readline())
    while j < ppl:
      cap = int(f.readline())
      item_list.append(shop_spree(items, cap, prc, wgt))
      j += 1
  
    n, total = 0, 0
  
    while n < ppl:
      total += item_list[n][0]
      item_list[n][0] = "%s: " % (n + 1)
      n += 1
    
    f_out = open("results.txt", "a")
    f_out.write("Test Case %s\n" % (c + 1))
    f_out.write("Total Price %s\n" % total)
    f_out.write("Member Items\n")
  
    n = 0
    while n < ppl:
      f_out.writelines(item_list[n])
      n += 1
  
    f_out.close()
    c += 1
