#include <stdio.h>
#include <string.h>


// 测试整形的函数
void test_int(void)
{
    // sizeof 出来的结果都是long int，占8个字节
    int a;
    printf("%d，地址为%p",a,&a);
}

// 测试scanf函数

void test_scanf(void)
{
    // scanf的本质是读取缓缓冲区，比如说要读取两个int，当一开始输入了用空格隔开的两个数字，直接运行了两个scanf，如果一开始输入一个数字后直接回车，则要输入两个
    // 注意，输入之间要用空格隔开，不能用其他的字符，否则其他字符会判断是不是数字，不是IDE话就用初始化值。
    // 注意，scanf不匹配不会消耗缓冲区的内容
    // 字符不能用空格，因为空格也是字符
    // 总之我们在终端输入的都是字符，回车也是，不同的是看程序怎么解析，如果连续的数字字符会被组合为数字类型
    // 只有回车不会被解析为数字字符
    int a=0;
    int b=0;
    char c;
    char d;
    printf("test scanf\n");
    scanf("%c",&d);
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%c",&c);
    printf("d=%c,a=%d,b=%d,c=%c\n",d,a,b,c);
}


// 测试float

void test_float(void)
{
    float a =1.222333444;
    double b=10.222333444;
    long double c = 11.222222222222l;
    //默认输出6个小数
    //%e是小数
    //浮点数要赋值0.0
    // float是4个字节
    // double为8个字节
    // long double为16个字节 ,打印时候必须写L
    // 用.10打印10位小数
    // 10.2f,总共用10个字符显示
    // float有效数位为7位
    printf("测试浮点数\n");
    printf("a=%.8f,b=%.12lf，c=%Le\n",a,b,c);
    printf("a所占内存%ld,b所占内存%ld,c所占内存大小为%ld\n",sizeof(a),sizeof(b),sizeof(c));
}


// 测试补码

void test_complement(void)
{   
    // 正数的补码为原码
    // 负数的补码为反码加1 如 -64 原码为1100 0000 反码 1011 1111 补码 1100 0000
    int a = 64;
    int a_6 = (a&(1<<6))>>6;
    int a_7 = (a&(1<<7))>>7;

    char b = -64;
    int b_6 = (b&(1<<6))>>6;
    int b_7 = (b&(1<<7))>>7;

    printf("a的6位为%d\n",a_6);
    printf("6的7位为%d\n",a_7);

    printf("b的6位为%d\n",b_6);
    printf("b的7位为%d\n",b_7);
    
}


// 自增自减

void test_selfAdd(void)
{   
    // 前置++是运算完后参与其他计算
    //后置++是本身不变
    //共同点是运行完++语句后，值都加了1
    // 同个语句中同个变量的自加与自减不能出现多次

    // b =a++; <=> c = a;a = a+1;b=c; 在赋值前a已经自加了1
    // b = ++a; <=> a = a+1;c =a; b=c; 在复制前a已经自家了1
    
    printf("测试自增自减\n");
    int a =0;
    int b = 0;

    printf("前置++为%d,后置++为%d\n",(++a),(b++));
    printf("运行完后a为%d,运行完后b为%d\n",a,b);
    
}


// 测试while

void test_while(void)
{   
    printf("test while\n");

    int b=10;
    //循环110次
    while (b--)
    {
        printf("%d\n",b);
        
    }
    printf("b=%d",b);
    int c=10;
    printf("-----------------------\n");
    // 循环9次
    while (--c)
    {
        printf("%d\n",c);
        
    }
    // 死循环 简写时候条件后面直接写；号

    while (1);
    
    
}


// 测试短路语句

void test_shortCode(void)
{   
    int a =0;
    int b =0;

    (a = 2>1)||(b=2);

    printf("a=%d,b=%d\n",a,b);

    (a = 2>1)&&(b=2);
    printf("a=%d,b=%d\n",a,b);


    
}


// 测试for
void test_for(void)
{   
    printf("start test for\n");

    for(int a=0;a<=5;a++){
        printf("%d\n",a);
    }
    // printf("%d",a); 如果循环变量是在循环内申明，则不能在外面调用

    int b;
    for(b=0;b<=5;b++){
        printf("%d\n",b);
    }
    printf("b=%d\n",b);
}


// test 一维数组

void test_oneDemonsionArray(void)
{

    printf("start test_oneDemonsionArray\n");

    //声明数组
    // 有个公式 a[2] = *(a+2)
    // 数组名字就是数组首元素的地址
    // 如果数组初始化长度大于字符串，”hello“和{'h','e','l','l','o'}没区别，因为初始化时候都会被填0；
    // 如果数组不初始化长度，则”hello“会自动在末尾填0，这样在%s读取时候会遇到0停止，而{'h','e','l','l','o'}不会，输出函数会一直打印，知道遇到0
    int a[10] = {1,2};
    char b[10] = {'h','e','l','l','o'};
    char c[] ="hello";
    char d[] = {'h','e','l','l','o'};
    
    for(int i=0;i<=9;i++)
    {
        printf("%d %d %c %c %c\n",a[i],*(a+i),b[i],c[i],d[i]);
    }
    printf("%s\n",c);
    printf("%s\n",d);

    printf("%p,%p,%p\n",a,a+1,a+2);


}

// test 二维数组

void test_twoDemonsionArray(void)
{

    printf("start test_twoDemonsionArray\n");

    // 对于二维叔祖来说，数组的首地址就是里面的一维数组，所依首地址加1为里面一位数组的长度
    // 所以要获取二维信息，必须在子元素中在获取。
    // 总之，指针就是地址，地址就是指针，指针加一是加了元素所占空间的距离
    // 数组名a就代表首元素的地址
    int a[3][2] ={1,2,3,4,5,6};

    printf("%ld\n",sizeof(a));
    printf("数组首地址为%p\n",a);
    printf("第一个元素地址：%p,第二个元素地址：%p,第三个元素地址：%p\n",a,a+1,a+2);

    printf("第一个元素地址的第一个元素地址：%p,第一个元素地址的第二个元素地址：%p\n",&a[0][0],&a[0][1]);

    for(int i=0;i<6;i++)
    {
        printf("%d\n", *(&a[0][0]+i));
    }
    // 介绍mencpy
    printf("memory copy\n");
    int c[5];
    for(int i=0;i<6;i++)
    {
        printf("%d\n",c[i]);
    }

    // c语言中全不会判断是不是越界，全靠自觉
    memcpy(c,a,sizeof(a));
     printf("memory copy after\n");
    for(int i=0;i<6;i++)
    {
        printf("%d\n",c[i]);
    }


}


// test 指针

static void test_point_func(int a)
{
    a = 100;
}

static void test_point_func2(int *a)
{
    *a = 100;
}

static int test_point_func3(int a)
{
    a = 0;
    return a;
}



void test_point(void)
{

    printf("start test_point\n");
    // 指针就是装在地址类型的数据
    // *b,就是获取到装宰的地址的值
    int a =10;
    int *b = &a;
    *b =20;
    printf("%ld\n",sizeof(b));
    printf("a的地址是%p,%p，a的值为%d\n",&a,b,*b);

    // 基本数据类型为什么要用指针呢，主要是在函数调用里，我们知道传参的时候是传值，比如说传一个int的值，其实是在栈区空间新开辟了一个值
    printf("未改变时候的值为%d\n",a);
    test_point_func(a);
    printf("改变时候的值为%d\n",a);

    printf("未改变时候的值为%d\n",a);
    test_point_func2(b);
    printf("改变时候的值为%d\n",a);

    //利用返回值去改变
    printf("未改变时候的值为%d\n",a);
    a = test_point_func3(a);
    printf("改变时候的值为%d\n",a);




}



// static test_secondPoint_1(int **)




// 测试2级指针
void test_secondPoint(void)
{
    // 要装载装有地址的指针就是二级指针
    printf("start test_secondPoint\n");
    int a =10;
    int *b = &a;
    int **c = &b;
    // 那么问题来了，二级指针有什么用？
    printf("a=%d,%d,%d\n",a,*b,**c);
}