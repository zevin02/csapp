void swap();

int buf[2]={1,2};

//定义全局的main符号
int main()
{
    int a=1;
    swap();//这里我们引用了一个全局的符号swap
    return 0;
}