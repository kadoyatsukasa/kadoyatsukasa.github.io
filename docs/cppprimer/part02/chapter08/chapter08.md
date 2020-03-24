---
layout: default
---

# 第八章 IO库

## 8.1 IO类
+ 知识点: 
    - IO库类型和头文件 
        
        |||
        |:---:|:---:|
        |头文件|类型|
        |iostream|istream,wistream  从流读取数据<br/> ostream,wostream 向流写入数据<br/> iosream,wiostream 读写流|
        |fstream|ifstream,wifstream 从文件读取数据<br/> ofstream,wostream 向文件写入数据<br/> fstream,wfstream 读写文件|
        |sstream|istringstream,wistringstream 从string读取数据<br/>ostringstream,wostringstream 向string写入数据<br/>stringstream,wstringstream 读写string| 

    - IO对象无拷贝或赋值  
    
    - IO库条件状态  
        
        |||
        |:---:|:---:|
        |`strm::iostate`|`strm`是一种IO类型.<br/>iostate是一种机器相关的类型,提供了表达条件状态的完整功能|
        |`strm::badbit`|用来指出流已经崩溃|
        |`strm::failbit`|用来指出一个IO操作已经失败|
        |`strm::eofbit`|用来指出流到达了文件结尾|
        |`strm::goodbit`|用来指出流未处于错误状态,此值保证为0|
        |`s.eof()`|若流s的eof置位,则返回true|
        |`s.fail()`|若流s的failbit或badbit置位,则返回true|
        |`s.bad()`|若流s的badbit置位,则返回true|
        |`s.good()`|若流s有效,则返回true|
        |`s.clear()`|将流s中的所有条件状态复位,将流的状态设置为有效,返回void|
        |`s.clear(flags)`|根据给定的flags标志位,将流s中对应条件状态复位.flags的类型为`strm::iostate`.返回void| 
        |`s.setstate(flags)`|根据给定的flags标志位,将流s中对应条件状态置位.flags的类型为`strm::iostate`,返回void|
        |`s.rdsate()`|返回流s的当前条件状态,返回值类型为`strm::iostate`| 

    - 导致缓冲刷新的原因有很多:  
        - 程序正常结束,作为main函数的return操作的一部分,缓冲刷新被执行.  
        - 缓冲区满时,需要刷新缓冲,而后刷新的数据才能继续写入缓冲区.  
        - 我们可以使用操作符来显示刷新缓冲区.  
        - 在每个输出操作之后,可以使用操作符`unitbuf`设置流的内部状态,来清空缓冲区.  
            - 默认情况下,对cerr是设置`unitbuf`的,因此写道cerr的内容都是立即刷新的.  
        - 一个输出流可能被关联到另一个流.
            - 在这种情况下,当读写被关联时,关联到的流的缓冲区会被刷新.  
            - 当一个输入流被关联到一个输出流的时候,任何试图从输入流读取数据的操作都会先刷新关联的输出流  
            - 交互式系统通常应该关联输入流和输出流  
        - 如果程序崩溃,输出缓冲区不会被刷新  

    
+ 练习:
    - **8.1 编写函数,接收一个istream& 参数,返回值类型也是istream& 类型.此函数须从给定流中读取数据,直到遇到文件结束标识时停止.它将读取的数据输出到标准输出上.完成这些操作后,在返回流之前,对流进行复位,使其处于有效状态.**  
    - **8.2 测试函数,参数为cin**  
    [0801](src/0801.cpp)  

    - **8.3 什么情况下,下面的while循环会终止**  
    ```c++
    while(cin>>i)
    //...
    ```
    > 当输入流遇到结束信号的时候,while循环就会停止  

## 8.2 文件输入输出 
+ 知识点
    - fstream特有的操作  
    
    |||
    |:---:|:---:|
    |`fstream fstrm`|创建一个未绑定的文件流.<br/> `fstream`是`头文件fstream`中定义的一个类型|
    |`fstream fstrm(s);`|创建一个fstream,并打开名为s的文件<br/>s是string类型,或者是一个指向一个C风格字符串的指针.这些构造函数都是`explicit`的.默认的文件模式mode依赖于fstream的类型|
    |`fstream fstrm(s,mode)`|按指定的mode打开文件|
    |`fstrm.open(s)`|打开名为s的文件,并将文件与fstrm绑定<br>s可以是一个string或者是指向一个C风格字符串的指针<br>默认文件mode依赖于fstream的类型,返回void|  
    |`fstrm.close()`|关闭于fstrm绑定的文件,返回void|
    |`fstrm.is_open()`|返回一个bool值,指出与fstrm关联的文件是否成功打开且尚未关闭|

    - 文件模式:

    |||
    |:---:|:---:|
    |in|读文件|
    |out|写文件|
    |app|每次写前定位到文件末尾|
    |ate|打开文件定位到文件末尾|
    |trunc|截断文件|
    |binary|以二进制方式进行IO|
    |||

    - 规则   
        - 只能对`ofstream`或`fstream`对象设定`out`模式  
        - 只能对`ifstream`或`fstream`对象设定`in`模式  
        - 只有当out也被设定时才能设定trunc模式  
        - 只要没设定trunc,就可以设定app模式.  
          在app模式下,即使没有显示指定out模式,文件也总是以输出方式被打开  
        - 默认情况下,即使我们没有指定trunc,以out模式打开的文件也会被截断.  
            为了保留以out模式打开的文件的内容,我们必须同时指定app模式,这样只会将数据追加写到文件末尾,或者同时指定in模式,即打开文件同时进行读写操作  
        - ate和binary模式可以用于任何类型的文件流对象,且可以与其他任何文件模式组合使用  


+ 练习  
    **8.4 编写函数,以读模式打开一个文件,将其内容读入一个string的vector中,将每一行作为一个独立的元素存于vector中**  
    ```c++
    // 从指定文件读取字符串并存放到vector中
    // @param filePath 指定文件的路径
    // @return 返回存储的容器
    vector<string> readFileToVector(string filePath){
        vector<string> fileString;
        string text;
        ifstream input(filePath); //建立文件关联
        input.open(filePath,ios_base::in); //以读的形式打开指定文件


    //如果没有达到文件结尾
    //就持续读文件
        if(input){
            while (!input.eof())
            {
                std::getline(input,text);
                fileString.push_back(text); //将内容保存到vector之中
            }
        }
    
        fileString.pop_back();
        input.close();
        return fileString;
    }
    
    ```

    **8.5 重写上面的程序,将没个单词作为一个杜立德元素进行存储**  
    **8.6 重写书店程序,从一个文件中读取交易记录,将文件名作为一个参数传递给main**  
    **8.7 修改书店程序,将结果保存到一个文件中.将输出文件名作为第二个参数传递给main函数**  
    **8.8 修改上一题,将结果追加到文件莫问.对同一个输出文件,运行程序至少两次,季铵盐数据是否得以保**  

## 8.3 String 流  
+ 知识点:  
    - istringstream特有操作  
    
    |||
    |:---:|:---:|
    |`sstream strm;`|strm是一个未绑定的stringstream对象.<br>sstream是头文件sstream中定义的一个类型|
    |`sstream strm(s)`|strm是一个sstream对象,保存string s的一个拷贝.此构造函数是explicit的|
    |`strm.str()`|返回strm所保存的string的拷贝|
    |`strm.str(s)`|将string s拷贝到strm中.返回void|
    |||

    - 使用istringstream  

    ```c++
        /**
         * 程序读取文件,并创建一个PersonInfo的vector用于保存文件
        */

        string line,word;                       //分别保存来自输入的一行和单词
        vector<PersonInfo> people;              //保存来自输入的所有记录
        
         //逐行从输入读取数据,直至cin遇到文件尾或者其他错误
        while(getline(cin,line)){
            PersonInfo info;                    //创建一个保留此记录数据的对象
            istringstream record(line);         //将记录绑定到刚输入的行
            record>>info.name;                  //读取姓名
            while(record>>word)                 //读取电话记录
                info.phones.push_back(word);    //保存电话记录
            people.push_back(info);             //将记录追加到people末尾
        }
    ```  

    - 使用ostringstring

    ```c++
    for(const auto& entry:people){
        ostringstream formatted,badNums;
        for(const auto &nums:entry.phones){
            if(!valid(nums)){
                badNums<<" "<<nums;
            }else
                formatted<<" "<<format(nums);
        }
        if(badNums.str().empty())
            os<<entry.name<<" "<<formatted.str()<<endl;
        else
            cerr<<"input error: "<<entry.name
                <<" invalid number(s)"<<badNums.str()<<endl;
    }
    ```