# MySQL游标

[TOC]

## 游标的概念

游标是一种对从表中检索出的数据进行操作的灵活手段, 就本质而言,游标实际上是一种能从包括多条数据记录的结果集中每次提取一条记录的机制.
游标总是与一条sql选择语句相关联,因为游标由结果集和结果集中指向特定记录的游标位置组成.

## 游标的使用

游标的使用可以概括为声明游标、打开游标、从游标中提取数据、关闭游标.

- 声明游标
  `declare 游标名 cursor for select 语句;`
  此时select语句并未执行.

- 打开游标
  `open 游标名;`
  此时select语句将被执行.

- 从游标中提取数据
  `fetch 游标名 into 变量名1, 变量名2, ...;`
  变量名的个数必须与声明游标时使用的select语句结果集中的字段个数保持一致.
  每次fetch语句从结果集中提取一条记录,当使用fetch语句从游标中提取最后一条记录后,再次执行fetch语句时,将产生"ERROR 1327(02000): NO DATA TO FETCH"错误信息,开发人员可以针对MySQL错误代码1327自定义错误处理程序(游标错误处理程序应该放在声明游标语句之后).

- 关闭游标
  `close 游标名;`

例子:

```sql
delimiter $$

create procedure update_cursor_score_proc(IN c_no int)
modifies sql data
begin

declare s_no int;
declare grade int;
declare state char(20);
-- 声明游标
declare score_cursor cursor for select 学号, 成绩 from choose where 课程号 = c_no;
-- 声明错误处理程序
declare continue handler for 1327 set state = 'ERROR';

-- 打开游标
open score_cursor;

-- 在repeat循环中使用fetch提取记录
repeat

fetch score_cursor into s_no, grade;
set grade = grade + 5;
if(grade > 70) then set grade = 70; end if;
if(grade >= 55 && grade <= 57) then set grade = 60; end if;
update choose set 成绩 = grade where 学号 = s_no and 课程号 = c_no;

until state = 'ERROR' end repeat;

close score_cursor;
end;$$

delimiter ;

```
