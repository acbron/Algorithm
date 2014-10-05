/*
 * 不使用算术运算符做加法
 */

// 循环
int add(int x, int y)
{
    while (y) {
        int carry = (x & y);
        x ^= y;
        y = (carry << 1);
    }
    return x;
}

// 递归
int add_recursion(int x, int y)
{
    if (!y)
        return x;
    return add_recursion((x ^ y), ((x & y) << 1));
}


