---
layout: default
---

# 第二章 变量和基本类型 

## 2.1节

### 2.1.1 节练习  

**2.1 类型int、long、long long和short的区别是什么？无符号类型和带符号类型的区别是什么?
float和double的区别是什么？**  

**2.2 计算按揭贷款时,对于利率、本金和付款分别选用何种数据类型？说明理由**
> 因为利率需要使用百分数,而且数值相对较小,所以使用float类型即可 
> 本金和付款数额较大，需要使用double类型  

**2.3 读程序写结果**
**2.4 编写程序验证**
```c++
unsigned u =10,u2=42;
std::cout<<u2-u<<std::endl;
std::cout<<u-u2<<std::endl;

int i=10,i2=42;
std::cout<<i2-i<<std::endl;
std::cout<<i-i2<<std::endl;
std::cout<<i-u<<std::endl;
std::cout<<u-i<<std::endl;
```

> 输出结果：
> 32  
  4294967264  
  32  
  -32  
  0  
  0  

### 2.1.3节练习  
**练习2.5 指出下述字面值的数据类型并说明每一组内几种字面值的区别**  
(a) 'a',L'a',"a",L"a"  
(b) 10,10u,10L,10uL,012,OxC  
(c) 3.14,3.14f,3.14L
(d) 10,10u,10.,10e-2

> (a) char,wchar_t,char[],wchar_t[]  
> (b) int, unsigned int,long,unsigned long,int,int  
> (c) double,float,long double  
> (d) int,unsigned int,double,float  

**2.6 下面两组定义是否有区别，如果有，请叙述**  
```c++
    int month=9,day=7;
    int month=09,day=07;
```
> 第一组声明的是十进制数,第二组声明的是八进制数  

**练习2.7 下述字面值表示何种含义？它们各自的数据类型是什么？**  
(a) "Who goes with F\145rgus?\012"  
(b) 3.14e1L  
(c) 1024f  
(d) 3.14L  

> (a) char[]  
> (b) long double  
> (c) float  
> (d) long double

**2.8 利用转义序列编写一段程序,要求先输出2M,然后转到新的一行.
修改程序,使其先输出2,然后输出制表符,再输出M，最后转到新一行**  
[0208](src/0208.cpp)  

## 2.2节  
### 2.2.1节练习  
**练习2.9 解释下列定义的含义,对于非法的定义,请说明错在何处并将其改正**  
(a) std::cin>>int input_value;  
(b) int i = {3.14};
(c) double salary = wage = 999.99;  
(d) int i = 3.14;

> (a) 不对，不能在右值处声明变量  
> ```c++
>   int input_value;
>   std::cin>>input_value;
> ```
> 
>(b) 合法的初始化列表赋值  
>
>(c) 不可以，C++中不允许这样的连续赋值  
>```c++
>   double salary , wage;
>   wage=999.99;
>   salary=wage;
>```
>  
>(d) 不可以，非法的类型转换。
>`` float i =3.14`  

**2.10 下列变量的初值分别是什么**  
```c++
std::string global_str;
int global_int;
int main(){
    int local_int;
    std::string local_str;
}
```

>Default initializers  
 global_str =  
 global_int = 0 
 local_int = 380981285  
 local_str =   

### 2.2.2节练习  
**练习2.11 指出下面的语句是声明还是定义**  
(a) extern int ix = 1024;  
(b) int iy;  
(c) extern int iz;

> (a)是定义，(b)(c)是声明  

### 2.2.3节练习 
**练习2.12 请指出下面的名字中哪些是非法的？**  
(a) int double = 3.14;  
(b) int _;  
(c) int catch-22;
(d) int 1_or_2 = 1;
(e) double Double = 3.14;

> (a)(b)(c)都是非法的  

### 2.2.4节练习  
**练习2.13 下面程序中的j值是多少？**  
```c++
int i=42;
int main(){
    int i = 100;
    int j = i;
}
```
> j的值为100,局部变量的i的值覆盖了全局变量i的值,所以j的值为100  

**练习2.14  下面的程序合法吗？如果合法,它将输出什么？**  
```c++
int i=100,sum=0;
for(int i = 0;i!=10;++i) 
    sum+=i;
std::cout<<i<<" "<<sum<<std::endl;
```
> 程序合法.输出为
 `100 45`  

## 2.3节  

### 2.3.1节练习  
**练习2.15 下面哪个定义是不合法的？为什么？**  
(a) int ival = 1.01;  
(b) int &rval1 = 1.01;  
(c) int &rval2 = ival;  
(d) int &rval3;  

> &rval3并非一个定义,只是一个声明  
  ival是int类型，不能赋值为一个double类型

**练习2.16 以下哪些赋值不合法？为什么？哪些赋值合法？执行了什么操作？**  
```c++
int i=0,&r1=i;
double d=0,&r2=d;
```
(a) r2 = 3.14159;  
(b) r2 = r1;  
(c) i = r2;  
(d) r1 = d;  

> (a)把r2定义为3.14159的引用,覆盖了原引用  
> (b)把r2作为对r1的引用  
> (c)非法赋值,不能将引用赋值给普通变量  
>（d)非法引用，不能将double类型的引用赋值给int类型的引用  

**练习2.17 执行下面的代码段将输出什么结果？**  
```c++
int i , &ri = i;
i = 5;
ri = 10;
std::cout<<i<<"  "<<ri<<std::endl;
```

> 输出结果为 `10 10`  

### 2.3.2节练习  
**练习2.18 编写代码分别更改指针的值以及指针所指对象的值**  

[0218](src/0218.cpp)  

**练习2.19 说明指针和引用的主要区别**  
> 指针保存的是对象的地址。而引用只是变量的别名。
  修改指针会影响到对象的内容，对象消失之后指针不会消失。
  而引用相当于一个标签，对象消失之后，引用的也会跟着消失  

**练习2.20 请叙述下列代码的作用**  
```c++
int i =42;
int *p1 = &i;
int *p1=*p1 * *p1;
```

> 将变量i赋值为42，然后将其指针p1指向i，最后求平方  

**练习2.21 请解释下述定义。在这些定义中有非法的吗？如果有，为什么？**  

`int i = 0;`  

(a) double *dp = &i;    
(b) int *ip = i;  
(c) int *p = &i;  

> dp和p都是对i的引用, ip是指向i的指针  

**练习2.22 假设p是一个int类型的指针,请说明下述代码的含义**  
```c++
    if(p) //...
    if(*p) //...
```

> 第一段是如果p不为空，则执行。第二段是如果对象的值不为假则执行  

**练习2.23 给定指针p,你能知道它是否指向了一个合法的对象吗？
如果能,叙述判断的思路;如果不能,也请说明原因.**  
> 通过if进行条件判定，如果对象合法，则编译器会给对象分配内存空间，
  这样定义的指针就不会为空指针，通过if判断就可以知道该对象是否合法  

**练习2.24 在下面这段代码中，为什么p合法而lp非法？**  
```c++
int i = 42;
void *p = &i;
long *lp = &i;
```  

> 因为p是void指针,可以指向任意类型的对象。而lp已经是long类型的指针  

### 2.3.3节练习  
**练习2.25 说明下列变量的类型和值**  
(a) `int* ip,i,&r=i;`   
(b) `int i,*ip = 0;`  
(c) `int* ip ,ip2;`  

> (a) ip是int类型指针, i是一个int值,r是对i的引用    
> (b) i是一个int值，ip是一个指向空的int类型指针  
> (c) ip是一个int类型的指针,ip2是int值  

## 2.4节  
### 2.4节练习  
**练习2.26 下面哪些句子是合法的,如果有不合法的句子,请说明为什么？**  
(a) `const int buf;`  
(b) `int cnt = 0;`  
(c) `const int sz = cnt;`  
(d) `++cnt;++sz;`  

> (a)不合法，这是个没有初始化的常量，常量必须被初始化  

### 2.4.2节 指针和const
+ 知识点  
    - *指向常量的指针*不能用于改变其所指对象的值  
    - *常量指针*必须被初始化，而且一旦初始化完成,它的值就不能再改变了  
+ 练习  
   - **2.27 下面哪些初始化是合法的？请说明原因**  
    (a) `int i = -1,&r = 0;`  
    (b) `int* const p2 = &i2;`  
    (c) `const int i = -1,&r = 0;`  
    (d) `const int *const p3 = &i2;`  
    (e) `const int i2 = i , &r=i;`
    (f) `const int &const r2;`  
    (g) `const int *p1 = &i2;`  

    - **2.28 说明下面这些定义是什么意思？挑选出其中不合法的**  
    (a) `int i,*const cp;`  
    (b) `int *p1,*const p2;`  
    (c) `const int ic,&r=ic;`
    (d) `const int *const p3;`
    (e) `const int *p;`  

        > (a)声明了一个int变量i和一个int类型的指针常量cp  
        > (b)声明了一个int指针p1和一个指向int类型对象的常量指针  
        > (c)声明了一个int常量ic和对该常量的引用r  
        > (d)声明了一个指向常量对象的常量指针p3  
        > (e)不合法  
    
    - **2.29 假设已有上一个练习中定义的那些变量,则下面的那些语句是合法的？请说明理由**  
    (a) `i = ic;`  
    (b) `p1 = p3;`    
    (c) `p1 = &ic;`  
    (d) `p3 = &ic;`  
    (e) `p2 = p1;`  
    (f) `ic = *p3;`

        > (a) 合法赋值语句,将常量ic的值赋给了变量i   
          (b) 合法，将普通int指针p1指向了常量指针p3  
          (c) 合法，指针p1指向了常量ic  
          (d) 合法，指向常量的常量指针p3，指向了常量ic  
          (e) 不合法，常量指针不能指向普通指针 
          (f) 不合法，ic不是指针  

### 2.4.3节 顶层const  
+ 知识点:  
    - 顶层const: 表示指针本身是个常量  
    - 底层const: 表示指针所指的对象是一个常量   


+ 练习:  
    - **2.30 对于下面这些语句,请说明对象被声明成了顶层const还是底层const**  
    ```c++
      const int v2 = 0;
      int v1 = v2;
      int *p1 = &v1,&r1 = v1;
      const int *p2 = &v2,*const p3 = &i,&r2 = v2;
    ``` 
    > p1非const,p2是顶层const，p3顶层const  
    
    - **假设已有上一个练习中所做的那些声明,则下面的哪些语句是合法的？
    请说明顶层const和底层const在没个例子中有何体现**
    ```c++
      r1=v2;  //r1底层const
      p1=p2;  //p1底层const
      p2=p1;  //p2同为底层const和顶层const，p1仍为底层const
      p1=p3;  //p1底层const
      p2=p3;  //p2 p3同为底层const和顶层const
    ```  

### 2.4.4 constexpr和常量表达式  
+ 知识点：
    - 常量表达式: 值不会改变并且在编译过程中就能得到计算结果的表达式  
    - constexpr变量：C++11新标准规定,
                    允许将变量声明为constexpr类型
                    以便编译器来验证变量的值是否是一个常量表达式。  
                    - 声明为constexpr的变量一定是一个常量,而且必须用常量表达式初始化  


+ 练习：  
    - **2.32 下面的代码是否合法？如果非法,请设法将其修改正确**  
    ```c++
      int null = 0,*p = null;
    ```  
    > `int *p=null;`

## 2.5 处理类型 
### 2.5.1 类型别名
+ 知识点： 
    - 类型别名是一个名字,它是某种类型的同义词.  
    - 两种定义类型别名的方法:  
        - 传统方法`typedef`  
        - c++11: 使用*别名声明*: using typeAlias = type;

### 2.5.2 auto类型说明符  
+ 知识点： 
    - C++11 引入了auto类型说明符,让编译器替我们去分析表达式所属类型  
    - 编译器推断出来的auto类型有时候和初始值的类型并不完全一样,编译器会适当地改变结果类型使其更符合初始化规则 

+ 练习: 
    - **2.33 利用本节定义的变量，判断下列语句的运行结果**  
    ```c++
      a=42;b=42;c=42;
      d=42;e=42;g=42;
    ```  
    >对d e g的赋值编译器不通过，会报错   

    - **2.35 判断下列定义推断出的类型是什么,然后编写程序进行验证**  
    ```c++
      const int i = 42;
      auto j = i ;
      const auto &k = i;
      auto *p = &i;
      const auto j2 = i;
      const auto &k2 = i;
    ```
  
  ### 2.5.3 decltype类型指示符  
  + 知识点: 
    - decltype: 作用是选择并返回操作数的数据类型  
    - 如果decltype使用的表达式是一个变量,则decltype返回该变量的类型  
    - 如果