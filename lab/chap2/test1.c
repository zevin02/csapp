#include <stdio.h>
#include <stdlib.h>

void test1()
{
    //验证溢出
    int a = 2147483647;    //最大的正数
    printf("%d\n", a + 1); //我们发现从最大的正数溢出成了最小的负数,-2147483648
    printf("%x\n", a + 1); //我们发现从最大的正数溢出成了最小的负数,0x80000000

    //验证位操作
    printf("%d\n", (~a) + 1); //取反+1，就变成该数对应的负数了-2147483637
}

unsigned LowBit(unsigned x)//这里返回的一定是2的倍数
{
    // 10101100,返回的是100
    unsigned a = x & ((~x) + 1); // x和它对应的负数，进行按位与
    //找到它最低位的1
    //只能用~ | &

    return a;
    //这个可以结合树状数组
}

//判断每个16进制位是不是字母

// x3,x2,x1,x0，这4位
//我们发现，x3,x2同时为1，或者x3,x1同时为1时，其他位无所谓，组成的一定是字母
// x3*(x1+x0),得出结论这就是一定是字母
unsigned Letter(unsigned x)
{
    //取处x0,4位中的最低位置
    // 0001
    unsigned x0 = x & 0x11111111;        //把每4位的最低位都取出来了
    unsigned x1 = x & 0x22222222;        //把每4位中的第2位都取出来了
    unsigned x3 = x & 0x88888888;        //把每4位中的最高位取出来了
    return (x3 >> 3) & (x0 | (x1 >> 1)); //这个取出来的结果是4位的一个答案，还要继续进行操作，移回去，再往右边移动4位，取第二个4位，判断如果都是1的话，就是字母

    // a=0,代表这个x并不是都是由字母组成的,a=1代表这个每一个位上都由字母，abdef这些就是字母
    //每4位都进行了比较，有一个其中4位不是，就不是
}

int main()
{
    printf("0x%x", LowBit(0xffffffff));
    //这就是通过lowbit，获得它的每个最小的10序列
    unsigned n=7;
    printf("S[%u]= \n",n);
    printf("  T[%u]\n",n);
    n=n-LowBit(n);
    printf("+T[%u]\n",n);
    n=n-LowBit(n);
    printf("+T[%u]\n",n);
    n=n-LowBit(n);
    printf("+T[%u]\n",n);


    printf("0x%x,is letter %u\n", 0xabcdefab, Letter(0xabcdefab));
    printf("0x%x,is letter %u\n", 0xabc11111, Letter(0xabc11111));
    return 0; //正常退出
}