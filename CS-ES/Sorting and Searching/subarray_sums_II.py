def main():
    n, x = [int(i) for i in input().split()]
    lst = [int(i) for i in input().split()]
    count = 0
    prefix = [0]
    prefix_store = {0: 1}
    # setup the prefix
    for i in range(n):
        prefix.append(prefix[i] + lst[i])
    for j in range(n):
        if (prefix[j+1] - x) in prefix_store:
            count += prefix_store[prefix[j+1] - x]
        if prefix[j+1] in prefix_store:
            prefix_store[prefix[j+1]] += 1
        else:
            prefix_store[prefix[j+1]] = 1
    return count
print(main())