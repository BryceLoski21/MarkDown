# 自定义函数

[TOC]

## 创建自定义函数

创建自定义函数时, 开发人员需提供函数名、函数参数、函数体、返回值等信息，创建自定义函数的语法格式为：
> create function 函数名(参数1, 参数2, ...)
> returns 返回值数据类型
> [函数选项]
> begin
> &emsp;函数体;
> &emsp;return 语句;
> end;

`注: declare只能放在函数体的最前面, 不能放中间`

说明:
1.函数是数据库对象, 创建函数时, 需要打开(选择)数据库
2.函数名不允许重名, 不允许是关键字, 建议在函数名前加前缀"fn_"或后缀"_fn"
3.函数参数是局部变量, 且必须指定数据类型,若函数无参数则是空参数函数
4.函数必须指定返回值数据类型,且必须和returns语句中的返回值数据类型一致(字符串类型的长度可以不同)

5.函数选项由以下一项或几项组成:
> language sql
> | [not] deterministic
> | {contains sql | no sql | reads sql data | modifies sql data}
> sql security {definer | invoker}
> comment '注释'

函数选项说明:
**language sql**: 默认选项, 说明函数体使用sql语言编写

**deterministic**(确定性): 该选项是为了防止"复制"时的不一致性。如果函数总是对同样的输入参数产生同样的结果，则被认为是“确定的”，否则就是“不确定的”，默认是not deterministic

**contains sql**: 默认选项, 表示函数体中不包含读或写数据的语句(例如set命令)
**no sql**: 表示函数体中不包含sql语句
**reads sql data**: 表示函数体中包含select查询语句, 但不包含更新语句
**modifies sql data**: 表示函数体包含更新语句
**sql security**: 用于指定函数的执行许可

**definer**: 默认选项, 表示该函数只能由创建者调用
**invoker**: 表示该函数可以被其它数据库用户调用

**comment**: 为函数添加功能说明等注释信息

## 自定义函数的调用

调用自定义函数与调用系统函数的方法一致, 使用select语句。 如果自定义函数有参数, 需要传入参数并且参数的数量和数据类型需要与定义函数时保持一致. 空参数函数不需要传递参数.
例如:
> select sname_fn('1906030636')

## 自定义函数的删除

删除函数使用"drop function 函数名;"
例如:
> drop function sname_fn;

## 自定义函数的维护

函数的维护主要是查看函数的定义,常用方法有以下四种:

1. 查看当前数据库的所有的自定义函数的信息: **"show function status;"**
2. 查看指定数据库中所有自定义函数名,可以使用sql语句(MySQL 8.0版本是没有mysql.proc表的, 8.0以上该表已经由information_schema.routines表平替了, 下面语句供MySQL 5.6版本使用): **"select name from MySQL.PROC where DB='数据库名' and TYPE='FUNCTION';"**(Windows下的MySQL不区分表名大小写,这里是为了便于区分, 但是数据值是区分大小写的, 别写错了)
3. 查看指定自定义函数的详细信息: **"show create function 函数名;"**(建议结尾符使用\G)
4. 函数的信息都保存在information_schema数据库中的routines表中,使用select语句可以查询函数的相关信息: **"select * from INFORMATION_SCHEMA.ROUTINES where ROUTINE_NAME='函数名';"**(建议结尾符使用\G)

## 流程控制语句

MySQL中的流程控制语句包括条件控制语句和循环语句, 流程控制语句通常放在begin...end语句块中使用。
条件控制语句分为if语句和case语句，循环语句有where语句、repeat语句、loop语句。

### 条件控制语句

- if语句
  if语句用来进行条件判断，根据不同的条件执行不同的操作。if语句执行时，首先判断if语句后的条件是否为真，为真则执行then后的语句，为假就继续执行if，直到为真则执行then后语句，若都不满足，则执行else语句后的内容。
  > if 条件表达式1 then 语句块1;
  > [elseif 条件表达式2 then 语句块2;]
  > [elseif ...;]
  > [else 语句块n;]
  > end if;

  说明: 每个if与最近的end if匹配成if语句, end if后必须以";"结束

  根据判断条件不同, if语句的使用格式有以下几种;
  - 单个判断条件if语句:
    > if 条件表达式 then 语句块;
    > end if;
  - 两个判断条件if语句:
    > if 条件表达式1 then 语句块1;
    > else 语句块2;
    > end if;
  - 嵌套的if语句:
    > if 条件 then 语句块;
    > else if 条件 then 语句;
    > &emsp;else if 条件 then 语句; end if;
    > &emsp;end if;
    > end if;
- case语句
  case语句用于实现比if语句分支更为复杂的条件判断,与Java等高级语言不同,MySQL中的case语句不需要使用break跳出.
  如果CASE中是判断条件, 省略CASE后的表达式, 在WHEN后面写判断.
  > case 表达式
  > when value1 then 语句1;
  > when value2 then 语句2;
  > ...
  > else 语句n;
  > end case;

### 循环语句

MySQL提供了三种循环语句: while, repeat, loop.
MySQL还提供了iterate语句以及leave语句用于循环的内部控制.

- while语句
  条件表达式的值为true时,反复执行循环体,直到条件表达式的值为false
  > [循环标签:] while 条件表达式 do
  > 循环体;
  > end while[循环标签];

  说明: end while后必须以";"结束
<br/>

- repeat语句
  条件表达式的值为false时,反复执行循环体,直到条件表达式的值为true.
  > [循环标签:] repeat
  > 循环体;
  > until 条件表达式
  > end repeat [循环标签];

  说明: end repeat后必须以";"结尾
<br/>

- leave语句
  leave语句用于跳出当前的循环语句
  > leave 循环标签;

  说明: leave 循环标签后必须以";"结束

- iterate语句
  iterate语句用于跳出本次循环,继而进行下次循环
  > iterate 循环标签;

  说明: iterate 循环标签后必须以";"结束
<br/>

- loop语句
  loop循环本身没有停止循环的语句,因此loop通常使用leave语句跳出loop循环
  > [循环标签:] loop
  > 循环体;
  > if 条件表达式 then
  > leave 循环标签;
  > end if;
  > end loop;

  说明: end loop后必须以";"结束
