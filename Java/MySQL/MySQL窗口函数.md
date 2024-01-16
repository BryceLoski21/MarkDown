<!-- 由于时间问题,以及系统函数的优先级不高,我决定先写窗口函数,系统函数先放放 -->
# 窗口函数

[TOC]

## ROW_NUMBER()

row_number()(分组)排序编号,按照表中某一字段分组,再按照某一字段排序,对已有的数据生成一个编号. 也可以不分组,对整体进行排序,生成一个编号.
> row_number() over(partition by 字段名 order by 字段名) as 编号;

例子:
> select * from
> (select row_number() over(partition by 课程名称 order by 成绩 desc) as row_num, 学号, 课程名称, 成绩
> from choose join course on choose.课程号 = course.课程号) t
> where row_num = 1;

## rank()

rank()类似于row_number(), 也是排序功能, 如果表中有两条完全一样的数据,row_number()编号的时候, 这两条数据被编了两个不同的号; 而rank()在排序条件一样的情况下,其编号也一样.

例如:
> select * from
> (select rank() over (partition by 课程号 order by 成绩 desc) as row_num, 学号, 课程号, 成绩 from choose) t where row_num = 1;

## AVG、SUM等聚合函数在窗口函数中的增强

可以在聚合函数中使用窗口函数，比如SUM(amount) OVER (PARTITION BY user_no ORDER BY create_date) AS sum_amount;实现一个累积计算SUM的功能

## NTILE(n)

ntile(n)将数据按照某些排序分成n组, 在n组数据中获取其中一部分数据.
例如,按照学生选课表choose中的成绩倒序排列,将学生成绩分成上中下3组,如果要获取上中下3个组中一部分数据,可使用ntile(3)来实现

## LAG、LEAD函数

lag(column, n)获取当前按照某种规则排序的数据行中的某个字段的上n行数据;
lead(column, n)获取当前按照某种规则排序的数据行中的某个字段的下n行数据.

## CTE公用表表达式

CTE公用表表达式有两种用法,非递归的CTE和递归的CTE.
非递归的CTE可以用来增加代码的可读性,增加代码的结构化表达.

使用CTE(非递归):

1. 将sql语句做成一个CTE
2. 对上面的CTE进行查询

> with cte as(
> select row_number() over(partition by user_no order by create_date desc) as row_num, order_id, user_no, amount, create_date from order)
> select * from cte where row_num = 1;
