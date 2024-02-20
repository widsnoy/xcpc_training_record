t = int(input())
for tt in range(t) : 
    x = int(input())
    x = int(input())
    ans = 0
    while (x > 0) :
        ans += x
        x //= 10
    print(ans)
