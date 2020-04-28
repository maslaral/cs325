def makechange(c, k, n):
    total = 0

    matrix = [[0 for x in range(2)] for y in range(k + 1)]

    i = 0

    for i in range(k + 1):
        matrix[i][0] = pow(c, i)
        matrix[i][1] = 0

    j = k

    while total < n:
        if(matrix[j][0] + total <= n):
            total += matrix[j][0]
            matrix[j][1] += 1
        else:
            j -= 1

    f_out = open("change.txt", "a")
    f_out.write("Data input: c = %d, " % c)
    f_out.write("k = %d, " % k)
    f_out.write("n = %d\n" % n)

    x = k

    while x >= 0:
        f_out.write("Denomination: %d " % matrix[x][0])
        f_out.write("Quantity: %d\n" % matrix[x][1])
        x -= 1

    f_out.write("\n")
    f_out.close()


f_out = open("change.txt", "w")
f_out.close()

# makechange(3, 5, 80)

with open("data.txt") as f_input:
    for line in f_input:
        data = line.split()
        c = int(data[0])
        k = int(data[1])
        n = int(data[2])
        makechange(c, k, n)
