# 第9章 顺序容器
> `顺序容器`为程序员提供了控制元素存储和访问顺序的能力  

+ 目录
    - [返回](../../menu.md)
    - [9.1 顺序容器概述](##9.1\ 顺序容器概述)  
    - [9.2 容器库概述](##9.2\ 容器库概述)  
    - [9.3 顺序容器操作](##9.2\ 顺序容器操作)  

## 9.1 顺序容器概述
+ 知识点: 
    - 顺序容器的类型

    |||
    |:---:|:---:|
    |`vector`|可变大小数组.支持快速随机访问.<br>在尾部之外的位置插入或删除元素可能很慢|
    |`deque`|双端队列.<br/>支持快速随机访问<br/>在头尾位置插入/删除的速度很快|
    |`list`|双端链表.<br/>只支持双向顺序访问<br/>在list中任何位置进行插入/删除操作速度都很快|
    |`forward_list`|单向链表<br/>只支持单项顺序访问<br/>在链表中任何位置插入/删除都很快|
    |`array`|固定大小数组<br/>支持快速随机访问<br/>不可以添加或删除元素|
    |`string`|与vector相似,专门用于保存字符<br/>随机访问快.<br/>在尾部插入/删除速度快|

    - 容器选择基本原则:  
        1.  除非你有很好的理由选择其他容器.否则应该使用vector  
        2.  如果你的程序有很多小的元素,且空间的额外开销很重要.则不要使用list或forward_list  
        3.  如果程序要求随机访问元素,应该使用vector或deque  
        4.  如果程序要求在容器中间插入或删除元素,应该使用list或forward_list  
        5.  如果程序需要在头尾位置插入或删除元素,而不会在中间位置进行插入或删除操作.则使用deque  
        6.  如果程序只有在读取是才需要在容器中间位置插入元素,随后需要随机访问元素,则:  
            - 首先 确定是否真的需要在容器中间添加元素.
            - 如果必须在中间位置插入元素,考虑在输入阶段使用list.一旦输入完成,将list中的数据拷贝到一个vector中.  
        7.  如果你不确定应该使用那种容器,那么可以在程序中只使用vector和list公共的操作:使用迭代器,不使用下标操作,避免随机访问.  

## 9.2 容器库概述  
+ 知识点:
    - 容器操作:

        |||
        |:---:|:---:|
        |类型别名||
        |`iterator`|此容器类型的迭代器类型|
        |`const_iterator`|可以读取元素,但不能修改元素的迭代器类型|
        |`size_type`|无符号整数类型,足够保存此种容器类型最大可能容器的大小|
        |`difference_type`|带符号的整数类型,足够保存两个迭代器之间的距离|
        |`value_type`|元素类型|
        |`reference`|元素的左值类型:`value_type&`含义相同| 
        |构造函数|| 
        |`C c;`|默认构造函数.构造空容器|
        |`C c1(c2);`|构造c2的拷贝c1|
        |`C c(b,e);`|构造c,将迭代器b和e指定的范围内的元素拷贝到c *array不支持*|
        |`C c{a,b,c,...};`|列表初始化c|
        |**赋值和swap**||
        |`c1=c2;`|将c1中的元素替换为c2中的元素|
        |`c1={a,b,c,...};`|将c1中的元素替换为列表中的元素 <br/>*不适用于array*|
        |`a.swap(b)`|交换a与b的元素|
        |`swap(a,b)`|与`a.swap(b)`等价|
        |**大小**||
        |`c.size()`|c中元素的数目 <br/> *不支持forward_list*|
        |`c.max_size()`|c可保存的最大元素数目|
        |`c.empty()`|对c判空|
        |**添加/删除元素(不适用于array)**|*在不同的容器中,这些操作的接口都不同*|
        |`c.insert(args)`|将args中的元素拷贝进c|
        |`c.emplace(inits)`|使用inits构造c中的一个元素|
        |`c.erase(args)`|删除args指定的元素|
        |`c.clear()`|清空c,返回void|
        |**关系运算符**||
        |`==  !=`|所有容器都支持|
        |`<  <=  >=  >`|无序关联容器不支持|
        |**获取迭代器**||
        |`c.begin() c.end()`|返回指向c的首元素和尾元素之后位置的迭代器|
        |`c.cbegin()  c.cend()`|返回`const_iterator`|
        |**反向容器的额外成员(不支持forward_list)**||
        |`reverse_iterator`|逆向寻址迭代器|
        |`const_reverse_iterator`|不可改逆向寻址迭代器|
        |`c.rbegin() c.rend()`|返回c的尾元素和首元素之前的迭代器|
        |`c.crbegin() c.crend()`|返回`const_reverse_iterator`|

    - 迭代器范围: 由一对迭代器表示,两个迭代器分别指向同一个容器中的元素或者是尾元素之后的位置  
    - 假如begin和end构成一个合法的迭代器范围,则:
        -  if begin==end ; then size == empty;
        -  if begin!= end ; then size >= 1 and begin is first;
        -  while begin++ till begin == end; 

+ 练习:
    - **9.2 定义一个list对象,其元素类型是int的deque**
        > `list<deque<int>> object;`  

    - **9.3 构成迭代器范围的迭代器有何限制?**
        > 范围自begin开始,至end之前结束.  
        > 迭代器begin和end必须指向相同的容器.  
        > end可以与begin指向相同的位置,但不能指向begin之前的位置 
    
    -  **9.4 编写函数,接受一对指向vector<int>的迭代器和一个int值. 在两个迭代器指定的范围中查找给定的值,返回一个bool来指出是否找到**
   

    ```c++
        bool FindTarget(
            vector<int>::iterator begin,                       
            vector<int>::iterator end,
            int target){
    
            while (begin!=end)
            {
                if(*begin==target) return true;
                begin++;
            }
            return false;
        }
    ```
    [完成程序](src/0904.cpp)  

    - **9.5  重写上一题的函数,返回一个迭代器指向找到的元素.注意,程序必须处理未找到给定值的情况**  

    - **9.6 下面的程序有何错误?如何修改?**
    ```c++
    list<int> list1;
    list<int>::iterator iter1=lst1.begin(),iter2=lst1.end();
    while(iter1<iter2)/**/
    ```

    > 应该改为 `while(iter!=iter2){iter++;/**/}`  

    - **9.7 为了索引int的vector中的元素,应该使用什么类型?**
    > `vector<int>::const_iterator`  
    - **9.8 为了读取string的list中的元素,应该使用什么类型?如果写入list,又该使用什么类型?**  
    > 读取元素可以用`list<string>::iterator`,写入可以用`list<string>::iterator `  

    - **9.9 begin和cbegin两个函数有什么不同**  
    > begin返回的是普通迭代器,cbegin返回的是const类型迭代器  

    - **9.10 下面四个对象分别是什么类型?**  
    ```c++
    vector<int> v1;
    const vector<int> v2;
    auto it1 = v1.begin(),it2=v2.begin();
    auto it3 = v1.cbegin(),it4=v2.cbegin();
    ```
    > v1,v3是 iterator
    > v2,v4 是 const_iterator  

    - **9.11 对6种创建和初始化vector对象的方法,每一种都给出一个实例.解释每个vector包含什么值**  
    > `vector<int> first;` : 一个空容器 ,没有元素  
    > `vector<int> second(first);` : 空容器,没有元素  
    > `vector<int> third {1,2,3,4,5};` : 1,2,3,4,5  
    > `vector<int> fourth={1,2,3,4,5};`: 1,2,3,4,5  
    > `vector<int> fifth(4,10)`:10,10,10,10  

    - **9.12 对于接受一个容器创建其拷贝的构造函数,和接受两个迭代器创建拷贝的构造函数,接受其不同**  
    
    - **9.13 如何从一个list<int>初始化一个vector<double>?从一个vector<int>又该如何创建?**  
    [完整程序0913](src/0913.cpp)  
    
    - **9.14 编写程序,将一个list中的char* 指针元素赋值给一个vector中的string**  
    
## 9.3 顺序容器操作  
+ 知识点:
    - 向顺序容器添加元素的操作  
        > 这些操作会改变容器的大小;array不支持这些操作.  
        > `forward_list`有专有版本的`insert`和`emplace`操作.  
        > `forward_list`不支持`push_back`和`emplace_back`.  
        > `vector`和`string`不支持`push_front`和`emplace_front`.  
        
    |||
    |:---:|:---:|
    |`c.push_back(t)`<br/>`c.emplace_back(args)`|在c的尾部创建一个值为t或由args创建的元素.<br/>返回void|
    |`c.push_front(t)`<br/>`c.emplace_back(args)`|在c的头部创建一个值为t或由args创建的元素,<br/>返回void|
    |`c.insert(p,t)`<br/>`c.emplace(p,args)`|在迭代器p指向的元素之前创建一个值为t或由args创建的元素.<br/>返回指向新添加的第一个元素的迭代器|
    |`c.insert(p,n,t)`|在迭代器p指向的与阿苏之前插入n个值为t的元素,<br/>返回指向新添加的第一个元素的迭代器;<br/>若n==0,则返回p|
    |`c.insert(p,b,e)`|将迭代器b和e指定范围内的元素插入到迭代器p指向的元素之前.<br/>b和e不能指向c中的元素.<br/>返回指向新添加的第一个元素的迭代器;若范围为空,则返回p|
    |`c.insert(p,il)`|il是一个花括号包围的元素值列表.将这些给定值代入到迭代器p指向的元素之前.<br/>返回指向新添加的第一个元素的迭代器;<br/>若列表为空,则返回p|

    - 向一个`vector`,`string`或`deque`插入元素会使所有指向容器的迭代器、引用和指针失效  
    - **容器元素是拷贝**:当我们用一个对象来初始化容器是,或将一个对象插入到容器中,实际上放入容器的不是对象本身,而是对象值的一个拷贝  
    

    [返回顶部](#第9章\ 顺序容器)  
    [返回目录](../../menu.md)  