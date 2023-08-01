//声明外部的全局数组,这是一个外部的 external symbol
//buf是一个外部变量,所以编译器不会在当前的文件中去找他的定义
extern int buf[];

//定义全局符号
int *bufp0=&buf[0];

//bufp1是一个weak symbol因为他是一个没有被初始化的符号
int *bufp1;

//定义全局的swap符号
void swap()
{
    //交换数组的前两个元素
    int temp;
    bufp1=&buf[1];
    temp=*bufp0;
    *bufp0=*bufp1;
    *bufp1=temp;
}

void f()
{
    //本地的static 变量存储在.data（已初始化全局变量段）或者.bss（未初始化全局变量段）
    //而并没有在栈中
    //x.1
    static int x=0;
    
}

//虽然两个的变量名一样，但是编译器会在.data中为x的定义各自分配空间
//并且赋予不同的名字来消除歧义


void g()
{
    //x.2
    static int x=1;
}