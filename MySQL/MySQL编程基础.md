# MySQL编程基础

[TOC]

## MySQL常量

- 数值型常量
  数值型常量分为整数常量和小数常量, 整数常量如123, 0, -12等, 小数常量如2.25, -10.21, -32.68E, 0.12E等.
  数值型常量在使用时不需要加引号.
- 十六进制常量
  十六进制常量是由数字"0"到"9"及字母"a"/"A"到"f"/"F"组成, 表示方法有两种:
  第一种: 前缀为"0x",紧跟十六进制数(不加单引号),十六进制数不区分大小写.
  第二种: 前缀为"X"/"x",紧跟十六进制数(须加单引号').
  HEX()可以将一个字符串或者数字转换为十六进制的字符串.
- 二进制常量
  二进制常量由数字"0"和"1"组成.
  二进制常量的表示方法为前缀为"b",后面紧跟二进制字符串(需要加单引号').
  BIN()函数可以将一个字符串或数字转换为二进制数.
- 字符串常量
  字符串常量指的是加单引号或双引号的字符序列.
  字符串中的转义字符:

  |转义字符|含义|
  |:--:|:--:|
  |\0|一个ASCII 0(NUL, 一个零值字节, 与null不同,NULL代表没有值)字符|
  |\n|一个新行符|
  |\r|一个回车符(windows中使用\r\n作为新行标志)|
  |\t|一个定位符|
  |\b|一个退格符|
  |\'|一个单引号("'")|
  |\"|一个双引号"""|
  |\\|一个反斜杠符("\\")|
  |\%|一个"%"符,它用于在正文中搜索"%"的文字实例,否则这里的"%"将解释为一个通配符|
  |\_|一个"\_"符,它用于在正文中搜索"_"的文字实例,否则这里的"%"将解释为一个通配符|
- 日期时间常量
  日期时间常量是一个含有特殊格式的字符串,使用时要加单引号或双引号.
  例如: '2022-01-24 17:49:00'
- 布尔值
  True和false, false的数字值是0, true的数字值是1.
- NULL值
  NULL值可适用于各种类型, 通常用来表示"没有值""无数据"等意义,并且不同于数字类型的0和字符串类型的"\0"空字符串.

## 变量

客户机连接服务器生成MySQL数据库实例时, 需要定义变量保存当前MySQL数据库实例的属性、特征等内容。
MySQL数据库中的变量分为系统变量（以@@开头）和用户自定义变量。

- 系统变量
  系统变量分为全局系统变量（global system variable）和会话系统变量（seesion system variable）。
  每一个客户机成功连接MySQL服务器后，都会产生与之对应的会话。会话期间，MySQL服务实例会在MySQL服务器内存中生成与该会话对应的会话系统变量，这些会话系统变量的初始值是全局系统变量值的拷贝。
  - 全局系统变量
    全局系统变量影响服务器整体操作, 全局系统变量作用于SERVER的整个生命周期,但是不能跨重启.
    查看MySQL服务器中所有的全局系统变量信息:
    > show global variables;

    修改全局系统变量:
    > set @@global.sort_buffer_size = 25000;

    要想让全局系统变量在重启后继续生效,需要更改相应的服务器配置文件.

  - 会话系统变量
    会话系统变量只适用于当前的会话,大多数会话系统变量的名字和全局系统变量的名字相同,会话启动时,会话系统变量的值也和同名的全局系统变量的值相同,会话系统变量的值是可以改变的,不过这个值只适用于正在运行的会话,不适用于其它的会话.
    > set @@session.sql_select_limit = 10;
    > set @@character_set_server = GBK;

- 用户自定义变量
  用户自定义变量分为用户会话变量(以@开头)和局部变量(不以@开头).
  - 局部变量
    局部变量必须定义在存储程序中(函数、触发器、存储过程以及事件中)，一般用在sql语句中，使用前用declare命令定义局部变量及其数据类型，例如“declare c char(20)”。局部变量仅作用于存储程序中。
  - 用户会话变量
    用户会话变量是MySQL客户机与数据库服务器在会话期间使用的变量，作用范围只和客户机相关。客户机1定义了会话变量，会话期间其一直有效，与服务器断开连接或关闭客户机后， 客户机1定义的所有会话变量都会自动释放以节省服务器的内存空间。
    用户会话变量与系统会话变量的区别：
    1. 用户会话变量一般以@开头，系统会话变量以@@开头。
    2. 系统会话变量无须定义可以直接使用，用户会话变量需要定义与赋值（一般同时进行）。
    用户会话变量的定义与赋值方法：
    > set @user_variable1 = 值1 [, @user_variable2 = 值2, ...];
    > select @user_variable1 := 值1 [, @user_variable2 := 值2, ...];
    > select 值1 into @user_variable1 [, 值2 into  @user_variable2, ...];
  - 局部变量与用户会话变量的区别
    1. 用户会话变量名以@开头,局部变量名前没有@符号
    2. 局部变量先用declare命令定义(存储过程参数,函数参数除外), 定义时必须指明局部变量的数据类型, 定义后才能使用set命令或者select语句为其赋值. declare命令尽量写在begin...end语句块中; 用户会话变量不能使用declare命令定义, 且不需要指明数据类型.
    3. 用户会话变量的作用范围与生存周期大于局部变量. 局部变量如果作为存储过程或函数的参数,此时在整个存储过程或函数内有效, 如果定义在存储程序中的begin...end语句块中, 此时仅在begin...end语句块中有效. 用户会话变量在本次会话期间一直有效,直至关闭服务器连接.
    4. 如果局部变量嵌入到sql语句中, 由于局部变量名前没有@符号, 这就要求局部变量名不能与表字段名相同,否则将出现无法预期的结果.

## 运算符

运算符是数据操作的符号,表达式是操作数用运算符按照一定的规则连接起来的有意义的式子.

- 算术运算符
  |运算符|含义|
  |:--:|:--:|
  |+|加法运算|
  |-|减法运算|
  |*|乘法运算|
  |/|除法运算|
  |%|求余运算|
  |DIV|除法运算,返回商,同"/"|
  |MOD|求余运算,返回余数,同"%"|

- 比较运算符
  |运算符|名称|示例|
  |:--:|:--:|:--:|
  |=|等于|null=null(结果为null)|
  |<=>|等于|null<=>null(结果为1)|
  |>|大于|ID>5|
  |<|小于|ID<5|
  |>=|大于等于|ID>=5|
  |<=|小于等于|ID<=5|
  |!=或<>|不等于|ID!=5|
  |is null|是否为空|ID is null|
  |between and|是否在区间中|ID between 1 and 15
  |in|是否在集合中|ID in(3, 4, 5)|
  |like|模式匹配|name like '印%'|

  '='与'<=>'的区别: '='不把null视为有效结果,'<=>'把null视为有效结果, 即null=null的结果是null,null<=>null的结果是1
<br/>
- 逻辑运算符
  |运算符|含义|
  |:--:|:--:|
  |&&或and|逻辑与|
  |\|\|或or|逻辑或|
  |!或not|逻辑非|
  |xor|逻辑异或|

- 位运算符
  |运算符|含义|
  |:--:|:--:|
  |&|按位与, 在二进制数每位上进行与运算|
  |\||按位或, 将操作数化为二进制数后, 每位进行或运算|
  |\~|按位取反, 将操作数化为二进制数后,每位进行取反运算|
  |\^|按位异或, 二进制数的每位进行异或运算|
  |\<\<|按位左移,"m << n"表示m的二进制数左移n位,右边补上n个0|
  |\>\>|按位右移,"m >> n"表示m的二进制数右移n位,左边补上n个0|

- 运算符的优先级(从高到低,从左到右,优先级相同则左边优先)
  |优先级|运算符|
  |:--:|:--:|
  |1|!|
  |2|~|
  |3|^|
  |4|*, /, DIV, %, MOD|
  |5|+, -|
  |6|>>, <<|
  |7|&|
  |8|\||
  |9|=, <=>, <, <=, >, >=, !=, <>, in, is null, like|
  |10|between and|
  |11|not|
  |12|&&, and|
  |13|\|\|, or, xor|
  |14|:=|
