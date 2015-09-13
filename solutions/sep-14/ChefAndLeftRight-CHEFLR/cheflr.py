def leftright(n):
    c = 'r'
    num = 1
    unmodded_num = 1
    modofunmodnum = 1
    level = 1
    MODNUM = 1000000007
    diff = 1
    for i in range(1,n+1):
        num *= 2
        unmodded_num *= 2
        if ((level % 2) != 0): 
            # (c == 'l') is just 2 * num
            if (c == 'r'):
                num += 2; 
                unmodded_num += 2; 
        else:
            # even level: L = 2 * num - 1; R = 2 * num + 1;
            if (c == 'l'):
                num -= 1
            else:
                num += 1

            if (c == 'l'):
                unmodded_num -= 1
            else:
                unmodded_num += 1
            
        num %= MODNUM;
        modofunmodnum = unmodded_num % MODNUM;
        #print "Debug ", "i=", i, "c=", c, "num=", num, "unmodded_num=", unmodded_num, "modofunmod=", modofunmodnum, "diff=", modofunmodnum - num
        #if (c == 'l'):
        #    c = 'r'
        level += 1
    return (num, unmodded_num, modofunmodnum)
            
print leftright(100)
print leftright(1000)
print leftright(10000)
print leftright(100000)
