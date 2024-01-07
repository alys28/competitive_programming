



def main():
    n = int(input())
    lst = [int(x) for x in input().split(" ")]
    lst.sort()
    for i in range(n-1):
        if lst[i] != i + 1:
            return i+1
    return n


print(main())