
def main():
    n, m = [int(i) for i in input().split()]
    weights = sorted([int(i) for i in input().split()])
    count = 0
    i = 0
    j = n-1
    while i <= j:
        # print(i, j)
        if weights[i] + weights[j] <= m:
            count += 1
            i += 1
            j -= 1
        else:
            count += 1
            j -= 1
    return count


print(main())