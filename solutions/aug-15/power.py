def power(x,y):
    res = 1;
    for i in range(y):
        res *= x
    return res

x = power(70, 301)
y = power(71, 300)
print x - y
print y - x

for j in range(1,310):
    x = power(70, j+1)
    y = power(71, j);
    #if (x - y < 0):
    print j, j+1, (x-y)


