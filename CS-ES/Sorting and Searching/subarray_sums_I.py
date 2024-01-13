

def main():
    n, x = [int(i) for i in input().split()]
    lst = [int(i) for i in input().split()]
    p1 = 0
    p2 = 0
    count = 0
    if len(lst) == 0:
        return 0
    my_sum = lst[0]
    while p1 < n and p2 < n:
        if p1 > p2:
            p2 += 1
            my_sum += lst[p2]
            continue
        if my_sum == x:
            count += 1
            my_sum -= lst[p1]
            p1 += 1
        elif my_sum < x:
            p2 += 1
            if p2 >= n:
                break
            my_sum += lst[p2]
        else:
            my_sum -= lst[p1]
            p1 += 1
    return count


print(main())
