/*
 * 交换二进制数中的若干位bit
 * 如x = 11100, p1 = 0, p2 = 3, n = 2
 * 即从0位开始，连续两位bit和从3位开始的连续两位bit进行交换
 * 得到结果00111，十进制数为7
 */
int swap_bits(int x, int p1, int p2, int n)
{
    if (p1 + n > p2)
        return x;
    int left = p1, right = p2;
    while (n--) {
        int bit1 = ((x >> left) & 1);
        int bit2 = ((x >> right) & 1);
        if (bit1 != bit2) {
            if (bit1 == 1) {
                x -= (1 << left);
                x += (1 << right);
            } else {
                x += (1 << left);
                x -= (1 << right);
            }
        }
        left++;
        right++;
    }
    return x;
}
