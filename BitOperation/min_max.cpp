/*
 * 不使用比较运算符求较大值和较小值
 *
 * 考虑min函数：
 * 若x < y,则x - y < 0，进行左移32位后会变成-1（因为补码的表示规则，二进制里32个bit都为1）
 * 这时&操作得到的结果为x - y，返回的恰好是y + (x - y) = x
 * 同理，若x > y，则x - y > 0，左移后得到0，原式变为y + 0 = y
 *
 */

int min(int x, int y)
{
    return y + ((x - y) & ((x - y) >> (sizeof(int) * CHAR_BIT - 1)));
}

int max(int x, int y)
{
    return y - ((x - y) & ((x - y) >> (sizeof(int) * CHAR_BIT - 1)));
}

