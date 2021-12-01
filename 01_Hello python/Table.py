maxn = 1005
n = int(input())
cols = maxn * [0]
rows = maxn * [0]

zero_cols, zero_rows = n, n
full_col, full_row = 0, 0

for i in range(0, n*n):
    s = input()
    my_list = list(map(lambda x : int(x), s.strip().split(' ')))
    r, c = my_list[0], my_list[1]
    cols[c] += 1
    rows[r] += 1
    if (cols[c] == 1):
        zero_cols -= 1
    if (rows[r] == 1):
        zero_rows -= 1
    if (cols[c] == n):
        full_col = 1
    if (rows[r] == n):
        full_row =1
    if (zero_cols == 0 and zero_rows == 0 
        and full_col == 0 and full_row == 0):
        print("LOVELY")
    else :
        print("HIDEOUS")