---
layout: default
---

# 第六章 函数

## 6.1节练习

**6.1 实参和形参的区别是什么？**
- 形参只是一个占位符，并没有占用实际的内存空间。
- 实参是实际传递进函数的值。  

**6.2 请指出下列函数哪个有错误，为什么？应该如何修改这些错误呢？**  
  a.
    ```c++
    int f(){
        string s;
        // ...
        return s;
    }
    ```  
  b.
    ```c++
    f2(int i){/**/}
    ```  
  c. 
    ```c++
    int calc(int v1,int v1){/**/}
    ```  
  d. 
    ```c++
    double square(double x) return x*x;
    ```  

  >a. 返回值与类型不符，应该改成```int f(){ int s; /**/ return s}```或者```string f(){string s;/**/return s;}```  
  >b.没有返回值类型。应该改为```void f2(int i){/**/}```  
  >c.函数正确，但参数名称容易引发歧义，建议修改为不同的名称  
  >d.函数体必须用花括号，应该改为 ```double square(double x){return x*x;}```  

**6.3 编写自己的fact函数,上机检查是否正确**
```c++
uint64_t fact(uint64_t val) {
	uint64_t ret;

	for (ret=1;val>1;val--)
		ret *= val;

	return ret;
}
```  

**6.4 编写一个用户交互的函数,要求用户输入一个数字,计算生成该数字的阶乘。在main函数中调用该函数**  
[例程](src/rfact.cpp)
```c++
//
//题目要求的是逆向将一个数分解为它的阶乘数字
//思路就是逆向将一个数字从1开始除,并取得最大的数
uint64_t rfact(uint64_t val) {
	uint64_t ret;

	for (ret=1;ret<val;ret++)
	{
		val /= ret;
	}

	return ret;
} 
```  

**6.5 编写一个函数，求一个数的绝对值**  
[例程](src/testABS.cpp)  

### 6.1.1节练习
**6.6 说明形参、局部变量以及局部静态变量的区别。编写一个函数,同时用到这三种形式**  
[例程](src/life.cpp)

**6.7 编写一个函数,当它第一次被调用时返回0,以后每次调用返回值加1**  
[例程](src/incream.cpp)
```c++
//在外部进行循环调用
//然后进行递增
int incream(int count) {
	return count;
}
```  

### 6.1.2节练习 
**6.8 编写一个名为chapter06.h的头文件,令其包含6.1节练习的函数声明**  
[chapter06.h](src/chapter06.h)  

### 6.1.3节练习  
**练习6.9 编写你自己的fact.cc和factMain.cc,
这两个文件都应该包含上一小节的练习中编写的chapter06.h头文件。
通过这些文件,理解编译器是如何支持分离式编译的**  

### 6.2.1节练习

**6.10 编写一个函数,使用指针形参交换两个整数的值**  
[swapByPtr.cpp](src/swapByPtr.cpp)
```c++
void mySwap(int* first,int* second) {
	int temp;			//中间变量
	temp = *first;		//保存first的初始值
	*first = *second;	//把second的值给first
	*second = temp;		//把first的初始值给second
}
```  

### 6.2.2节练习
**6.11 编写并验证自己的reset函数,使其作用于引用类型的参数**  
[passByReference.cpp](src/passByReference.cpp)  
```c++
//传引用
void reset(int& num) {
	
	num = 0;
}
```  

**6.12 改写6.2.1节中练习6.10的程序,使用引用而非指针交换两个整数的值。你觉得哪种方法更易于使用？
为什么？**  
[passByReference.cpp](src/passByReference.cpp)
```c++
void mySwap(int* first,int* second) {
	int temp;			//中间变量
	temp = *first;		//保存first的初始值
	*first = *second;	//把second的值给first
	*second = temp;		//把first的初始值给second
}
```  
  > 使用传引用更加易用，不需要每次都写一个取地址运算符了。  

**6.13 假设T是某种类型的名字，说明以下两个函数声明的区别**
- `void f(T)` : 参数为T类型，无返回值  
- `void f(&T)` ： 参数为对T类型的引用，

**6.14 举一个形参应该是引用类型的例子,再举一个形参不能是引用类型的例子**  
   >- 当函数需要交换两个数位置的时候就需要进行引用传值，比如冒泡算法。  
   >- 当仅仅是对两个数进行比较而不需要进行数值交换的时候，就不能使用引用传值。  

**6.15 说明find_char函数中的三个形参为什么是现在的类型,特别说明为什么s是常量引用
而occurs是普通引用？为什么s和occurs是引用类型而c不是？如果令s是普通引用会引发什么情况？
如果令occurs是常量引用会引发什么情况？**  

```c++
//返回s中c第一次出现的位置索引
//引用形参负责统计c出现的总次数
string::size_type 
find_char(const string& s,char c,string::size_type& occurs){
    auto ret=s.size(); //第一次出现的位置(如果有的话)
    occurs=0;           //设置表现出现次数形参的值
    for(decltype(ret)i =0;i!=s.size();++i){
        if(s[i]==c){
            if(ret==s.size())
                ret=i;  //记录c第一次出现的位置
            ++occurs;   //将出现的次数加一
        }
    }    
    return ret;         //出现次数通过occurs隐式地返回
}
```  

  >- s作为被统计的字符串，在函数中是不可以改变的，而occurs的作用是作为目标字符的索引位置，需要进行修改
  >- s和occurs需要源字符串的地址，而c只是作为一个普通的参照物，而不需要对原始字符进行操作  
  >- s如果是普通引用将会改变源字符串的内容  
  >- occurs如果是常量引用，将无法对索引进行查找   

### 6.2.3节练习
**6.16 下面这个函数虽然合法,但是不算特别有用。指出其局限性并设法改善**  
`bool is_empty(string& s){ return s.empty();}`  

  >empty()方法本身就代表数组已经空了，所以并不能作为一个返回值。需要修改为:  
```
    bool is_empty(string& s){
        return s.empty()?true:false;
    }
```  

**6.17 编写一个函数,判断string对象是是否含有大写字母。编写另外一个函数，把string对象全部改写
成小写字母**  
[replace.cpp](src/replace.cpp)

```c++
// 判断字符串中是否存在大写
//
//	@param source 需要检测的源字符串
//	@return 如果没有大写，则返回true，否则返回false
bool isAnyUpper(const string& source) {
	auto ret = source.size();
	for (int index=0;index!=source.size();++index)
		if (std::isupper(source[index])) //判断是否存在大写
			return true;
	return false;
}

```  

```c++
// 将字符串中所有字母都转化成小写
// 
//      @param source 需要转换的源字符串
//      @return 转换完成的字符串
string convertToLower(string& source) {
	for (int index=0;index!=source.size();++index) //遍历字符串
		 source[index]=std::tolower(source[index]); //将所有字母都转换成小写字母
		
	return source;
}

```

**6.18 为下面的函数编写函数声明,从给定的名字中推测函数具备的功能**  
  a.  名为compare的函数,返回布尔值,两个参数都是matrix类的引用.  
        > `bool compare(matrix&)`  
        > 用于对参数指定的类进行一些判断类操作  

  b.  名为chang_val的函数,返回`vector<int>`的迭代器,有两个参数:一个是int,另一个是`vector<int>`的迭代器  
        > `vector<int>::iterator change_val(int,vector<int>::iterator)`  
        > 将指定的的值替换为int参数的值  
       
**6.19 假定有如下声明,判断哪个调用合法,哪个调用不合法,对于不合法的函数调用,说明原因**  

```c++
double calc(double);
int count(const string&,char);
int sum(vector<int>::iterator,vector<int>::iterator,int);
vector<int> vec(10);
```  
  a) calc(23.4,55.1);  
        
   > 不合法，因为函数只接受一个参数  
        
  b) count("abcda",'a');
   
   >  合法  
   
  c) calc(66);
   
   > 合法  

  d) sum(vec.begin(),vec.end(),3.8);  
   > 不合法，第二个参数接受的是int值而不是double值  
 
**6.20 引用形参什么时候应该是常量引用？如果形参应该是常量引用,而我们将其设为了普通引用,会发生什么情况？**  
  > 如果这个引用不应该修改原有的对象，就需要设置为常量引用
  > 如果将其设置为了普通引用，那么操作将会修改原有对象  
 

### 6.2.4节练习  

**6.21 编写一个函数，令其接受两个参数:一个int,另一个int指针,函数比较int的值和指针所指的值,返回较大的那个.
在函数中指针的类型应该是什么？**  

```c++
// 比较两个数字的大小，并返回较大值
//
//	@param first 第一个参数是普通变量
//	@param second 第二个参数是指针
//	@return 返回较大的一个数字
int compare(int first, int* second) {
	int result;
	
	if (first > *second)
		result = first;
	else
		result = *second;
	return result;
}

```

**6.22 编写一个函数，令其交换两个int指针**  
[swap_ptr.cpp](src/swap_ptr.cpp)  

```c++
//交换两个指针
//
//	@param first 第一个指针
//	@param second 第二个指针
void swap_ptr(int *&first, int *&second) {
	int* temp;
	temp = first;
	first = second;
	second = temp;
}

```

### 6.2.6节练习  

**6.27 编写一个函数，它的参数是`initializer_list<int>`类型的对象,函数的功能是计算列表中所有元素的和**  
[sum.cpp](src/sum.cpp)

```c++
//求初始化列表的数值总和
//
//		@param numbers 初始化列表
//		@return 列表数据总和
int sum(initializer_list<int> numbers) {

	initializer_list<int>::iterator num_iter;
	int result = 0;

	for (num_iter = numbers.begin(); num_iter != numbers.end(); ++num_iter)
		result += *num_iter;
	return result;
}
```

**6.28 在error_msg函数的第二个版本中包含ErrCode类型的参数,其中循环内的elem是什么类型？**  
```c++
void error_msg(ErrCode e,initializer_list<string> li){
    cout<<e.msg()<<": ";
    for(const auto &elem:li)
        cout<<elem<<" ";
    cout<<endl;
}
```  
  > elem是string类型  

**6.29 在范围for循环中使用initializer_list对象时,应该将循环控制变量声明成引用类型吗？为什么？**  
  > 不需要，因为initializer_list的元素本身就是不会改变的常量  

### 6.3.2节练习

**6.30 编译str_subrange函数,看看编译器是如何处理函数中的错误的**  
  >编译器报错``` error: return-statement with no value, in function returning 'bool' [-fpermissive]```

**6.31 什么情况下返回的引用无效？什么情况下返回常量的引用无效？**
  >如果引用所引的是函数的局部变量，则随着函数结束局部变量也失效了，此时返回的引用无效。

**6.32 下面的函数合法吗？如果合法,说明其功能;如果不合法,修改其中的错误并解释其原因**  
```c++
int& get(int* array,int index){return array[index];}

int main(){
    int ia[10];
    for(int i=0;i!=10;++i)
        get(ia,i)=i;
}
```

> 作用是取出数组中索引指定位置的元素  

**6.33 编写一个递归函数，输出vector对象的内容**  

```c++
void print_vector(vector<int> &ivec) {
	static auto sz = ivec.size();
	if (sz != 0) {
		cout << ivec[--sz];
		print_vector(ivec);
	}
}
```  

**6.34 如果factorial函数的停止条件如下所示,将会发生什么情况？**  
`if(val!=0)`

```c++
//factorial函数
int factorial(int val){
    if(val>1)
        return factorial(val-1)*val;
    return 1;
}
```
  > 结果会输出0

**6.35 在调动factorial函数时，为什么我们传入的值是val-1而非val--**  
  > 因为factorial的参数是一个整数

### 6.3.3节练习  

**6.36 编写一个函数的声明,使其返回数组的引用并且该数组包含10个string对象。不要使用尾置返回类型、decltype或者类型别名**  
 > `string (&(fun()))[10]`

**6.37 为上一题的函数再写3个声明,一个使用类型别名,另一个使用尾置返回类型,最后一个使用decltype关键字。
你觉得哪种形式最好？为什么？**  
  > 类型别名: 
  > ```c++ 
  >  typedef string strT[10];
  >  using strT = string[10];
  >  strT& fun(); 
  >```

  > 后置类型： 
  > ```c++  
  > auto func()->string(&)[10];
  >```

  > decltype: 
  > ```c++
  >  decltype(strT) &fun();
  >```

**6.38 修改arrPtr函数，使其返回数组的引用**  
```c++
int odd[]={1,3,5,7,9};
int even[]={0,2,4,6,8};

decltype(odd) &addPtr(int i){
    return （i%2)? odd:even;
}
```  

### 6.4节练习
**6.39 说明在下面的每组声明中第二条声明语句是何含义。如果有非法的声明,请指出来**  
  1) 
   ```c++ 
    int calc(int,int);
    int calc(const int,const int);    
   ```  
  > 重复声明了， 

  2) 
   ```c++
    int get();
    double get();
   ```
  > 返回一个double值  

  3) 
   ```c++
    int *reset(int*);
    double* reset(double*); 
   ```
  > 重置一个double数组 


## 6.5节

### 6.5.1节练习  
**6.40 下面哪个声明是错误的？为什么？**  
  1. `int ff(int a,int b= 0,int c = 0);`  
  2. `char *init(int ht = 24,int wd,char bckrnd);`

### 6.5.2节练习  
**6.43 你会把下面哪个声明和定义放在头文件中？哪个放在源文件中？为什么？**  
a)  `inline bool eq(const BigInt&,const BigInt&){...}`  
b)  `void putValues(int *arr,int size);`  

> 声明a适合放在头文件中,因为是内联函数  

**6.44**
>```c++
>//比较两个string对象的长度
> inline bool isShorter(const string& s1,const string& s2)
>{
>   return s1.size()<s2.size(); 
>}
>``` 