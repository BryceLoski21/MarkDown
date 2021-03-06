<!-- 可能和好吗? --不可能 -->
<!-- 我还爱她吗? --不爱 -->
<!-- 那我在想什么呢? --为什么 -->
# MySQL存储过程

[TOC]

## 存储过程的概念

存储过程是一种数据库对象,它是由一组预先编译好的sql语句组成,为了实现某个特定的任务,将一组预编译的sql语句以存储单元的形式存储在数据库服务器上,由用户直接调用执行.
存储过程在第一次执行时进行编译,然后将编译好的代码保存在高速缓存中便于以后调用,一次编译,多次调用,提高了代码执行效率.

## 创建存储过程

语法格式:
> create procedure 存储过程名称(IN 参数 数据类型, OUT 参数 数据类型, ...)
> [存储过程选项]
> begin
> 存储过程语句块
> end;

说明:
**存储过程名称**: 符合标识符命名规则,其对数据库及其所有者唯一,建议加前缀"proc_"或后缀"_proc"
**参数**: 存储过程的参数实际上是局部变量,存储过程有3种参数
**IN参数**: 输入参数, 该参数的值必须由调用程序指定\
**OUT参数**: 输出参数, 该参数的值经过存储程序计算过后返回给调用程序
**INOUT参数**: 既是输入参数,也是输出参数, 该参数由调用程序指定,且经计算后返回给调用程序

**存储过程选项说明**:
> language sql
> | [not] deterministic | { contains sql | no sql | reads sql data | modifies sql data  }
> | sql security { definer | invoker } | comment '注释'

**language sql**: 默认选项, 说明存储过程语句块使用sql语言编写

**deterministic**(确定性): 默认为not deterministic, 如果存储过程总是对同样的输入参数产生同样的结果,则被认为是确定的,否则就是不确定的. 此选项是为了防止复制时的不一致性.

**contains sql**: 默认选项,表示存储过程中不包含读或写数据的语句(例如SET命令等)
**no sql**: 表示存储过程语句块中不包含sql语句
**reads sql data**: 表示存储过程语句块中包含select查询语句,但不包含更新语句
**modifies sql data**: 表示存储过程语句块中包含更新语句

**sql security**: 用于指定存储程序语句块的执行许可
**definer**: 表示该存储过程只能由创建者调用
**invoker**: 表示该存储过程可以被其它数据库用户调用
**comment**: 为存储程序添加功能说明等注释信息

创建存储过程时,其中的参数可以省略,也就是既没有输入参数也没有输出参数,存储过程也可以有多个输入参数和多个输出参数,如果存储过程的处理结果是一个列表,在定义存储过程时则不需要定义OUT参数.

创建存储过程时,如果需要保存存储过程的结果,要定义OUT输出参数,将结果赋值给OUT参数.

例子:
> delimiter \$\$
> create procedure s2_proc(IN bh char(10), OUT sm char(10))
> reads sql data
> begin
> select 图书名称 into sm from book where 图书编号 = bh;
> end;\$\$

## 调用存储过程

存储过程创建成功后,会经编译优化后保存到数据库服务器.
调用存储过程须使用CALL关键字, 调用时需要向存储过程的IN参数、OUT参数、INOUT参数传递数据，而且数据的个数和类型要一致。

> call c_proc('1906030636')

## 查看存储过程的定义

- 使用`show procedure status`命令查看存储过程的定义

- 查看某个数据库中的所有存储过程名
  > **mysql 8.0 版本以上是没有MySQL.proc表的, 已经由information_schema.routines表平替; 也可以拷贝data/mysql/proc.frm, proc.MYD, proc.MYI 三个文件到你的数据库data/mysql/ 目录下，重启数据库**
  > mysql 8.0以上版本使用语句:
  > select specific_name from information_schema.routines where routine_type = 'PROCEDURE';
  > 以下语句针对MySQL 5.6版本:
  > SELECT name FROM MySQL.proc WHERE DB = '数据库名' AND type = 'PROCEDURE';

- 使用`show create procedure 存储过程名;`可以查看指定数据库指定存储过程的详细信息

- 存储过程属于是数据库对象,存储过程的信息都保存在information_schema数据库中的routines表中,使用select语句查询存储过程的相关信息
  > select * from information_schema.routines where routine_name = 's1_proc()';

## 删除存储过程

> drop procedure 存储过程名;

## 存储过程和函数的比较

1. 存储过程与函数之间的相同点:
   - 调用存储过程或者函数时, 只需要提供存储过程名或者函数名,以及参数信息
   - 存储过程或者函数可以重复使用
   - 使用存储过程或者函数可以增强数据的安全访问控制,可以设定只有某些数据库用户才具有某些存储过程或者函数的执行权
2. 存储过程与函数之间的不同点:
   - 函数必须有且仅有一个返回值,且必须指定返回值的数据类型(返回值类型目前仅支持字符串、数值类型), 存储过程的返回值可有可无,且可以有多个返回值,返回值需要使用OUT参数或者INOUT参数定义
   - 函数体内可以使用select...into语句为某个变量赋值,但不能使用select语句返回结果集, 存储过程可以返回多个结果集
   - 函数可以嵌入到sql语句中使用, 存储过程一般需要单独调用,调用时需要使用CALL关键字
   - 函数中的函数体限制比较多, 函数体中不能以显式或隐式方式打开、开始、结束事务的语句;不能在函数体内使用预处理SQL语句. 存储过程的限制相对比较少, 基本上所有的SQL命令都可以在存储过程中使用
   - 应用程序(Java、PHP等应用程序)调用函数时，通常将函数封装到sql字符串（例如select语句）中进行调用；而调用存储过程时，必须使用call关键字进行调用，如果应用程序需要获取存储过程的返回值，应用程序必须给存储过程的OUT参数或者INOUT参数传递MySQL会话变量，才能通过该会话变量获取存储过程的返回值
