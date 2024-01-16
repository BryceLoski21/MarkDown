<!-- 我思故我在! -->
# 触发器

[TOC]

## 触发器概述

触发器是捆绑在基表上的预编译后存储在数据库中的一系列SQL语句集,通过这些SQL语句集系统自动执行相应的数据库操作,可以有效地保证数据库的完整性.
触发器不能被用户直接调用执行,它只能由事件触发而自动执行.

触发器由3个部分组成:

1. 事件: 对数据库的一些操作, 比如对表的修改、删除、添加等操作
2. 条件: 触发器执行前先对条件进行检查，满足条件则触发相应的操作
3. 动作: 如果触发器检查满足预定的条件, 则由DBMS执行这些动作

## 触发器的优点

1. 触发器是自动执行的, 它可以通过数据库中的相关表实现级联更新, 实现多个表之间数据的一致性和完整性
2. 触发器可以实现比CHECK约束更为复杂的数据完整性约束
3. 触发器也可以评估数据修改前后的表状态, 并根据其差异采取对策

## 触发器的创建

触发器是被绑定在数据表上的, 因此只能为某张表创建触发器:
> create trigger 触发器名 触发时间 触发事件 on 表名 for each row
> begin
> 触发程序
> end;

参数说明:

- **触发器名**: 符合标识符命名规范, 建议加前缀或者后缀"_trigger"
- **触发时间**: 触发器的触发时间有两种: BEFORE与AFTER
- **触发事件**: MySQL的触发事件有三种:
  - **insert**: 将新纪录插入表时激活触发程序
  - **update**: 更改某一行记录时激活触发程序
  - **delete**: 从表中删除某一行记录时激活触发程序
- **表名**: 当前数据库中的数据表
- **for each row**: 表示行级触发器(MySQL目前仅支持行级触发器),for each row表示更新操作影响的每一行记录都会执行一次触发程序

## 触发器的工作过程

触发器被创建时, 可以使用两个对象OLD对象和NEW对象.
OLD对象是只读的, 可以引用它, 但不能更改它。
在BEFORE触发程序中，可使用"set new.column_name = value"更改NEW记录的值。

1. insert触发器的工作过程
   在向已建有insert触发器的数据表插入数据时, insert触发器被触发执行, 当向表插入新记录时, 系统会将刚才的新纪录写入NEW对象中, NEW对象可以看作是一张逻辑表, 由系统在触发器激发时自动创建.一旦触发器执行结束, 该NEW对象就自动地被删除. 当需要访问新记录的某个字段时, 使用"NEW.字段名"的方式访问.
    <br/>
2. delete触发器的工作过程
   删除具有delete触发器的表中的数据时, delete触发器被触发执行, 在删除数据行的同时, 系统会自动地把刚删除的数据行写入OLD对象中. 与NEW对象一样, OLD对象也可以看作一张逻辑表, 由系统在触发器激活时自动创建. 一旦触发器执行结束, 该OLD对象就自动地被删除. 当需要访问旧记录的某个字段值时, 使用"OLD.字段名"的方式访问.
    <br/>
3. update触发器的工作过程
   修改表中的数据可以看作是由两个步骤完成的操作: 删除一条旧记录, 然后再插入新记录, 即先执行一条delete语句, 再执行一条insert语句. 所以, 对建有update触发器的表中的数据进行修改时, 系统会自动地将旧记录写入OLD对象中, 将新记录写入NEW对象中. 然后, 通过OLD和NEW对象中的数据完成触发程序

MySQL可以使用复合数据类型SET或者ENUM对字段的取值范围进行检查约束，使用复合数据类型可以实现离散的字符串数据的检查约束，对于数值型的数据不建议使用SET或者ENUM实现检查约束，可以使用触发器实现。

## 触发器的使用

- 使用触发器删除关联数据

```sql
use choose;
alter table choose drop foreign key choose_student_fk;
alter table choose add constraint student_course_fk
foreign key(学号) references student(学号) on delete cascade;
-- 级联删除即删除包含主键值的行的操作,
-- 该值由其它表的现有行中的外键列引用.
-- 在级联删除中,还删除其外键值引用删除的主键值的所有行.
-- 如果InnoDB引擎存储的数据表之间仅存在外键约束, 不存在级联选项, 这时触发器也能实现关联数据的删除操作.

-- 当student表中有学生被删除时,触发删除包含该学号的行的操作
delimiter $$
create trigger s_trigger before delete on student
for each row
begin
delete from choose where 学号=old.学号;
end;$$
delimiter ;
```

- 使用触发器更新数据

```sql
-- 触发器更新数据
use choose;
alter table course add 可选人数 int default 3;

-- 当有学生选修了某门课程时,该课程的可选人数值要减1
delimiter $$
create trigger ch_trigger before insert on choose
for each row
begin
update course set 可选人数=可选人数-1 where 课程号=new.课程号;
end;$$
delimiter ;

-- 当学生退课时,该课程的可选人数值要加1
delimiter $$
create trigger cho_trigger before delete on choose
for each row
begin
update course set 可选人数=可选人数+1 where 课程号=old.课程号;
end;$$
delimiter ;
```

- 使用触发器实现check约束

```sql
delimiter $$
create trigger s1_trigger before insert on student
for each row
begin
if(year(now()) - year(new.出生日期) <= 30) then
set new.出生日期 = new.出生日期;
else insert into mytable values(0);
-- mytable用于提示错误
end if;
end;$$
delimiter ;

use book_management;
create table aa(a int, b int);

delimiter $$
create trigger a1 before insert on aa
for each row
begin
if new.a < 10 then set new.a = new.a;
else insert mytable values(0);
end if;
end;$$
delimiter ;
```

## 查看触发器的定义

1. 使用`show triggers\G`命令查看触发器的定义
2. 查询information schema数据库中的triggers表,查看触发器的定义.
   `select * from information_schema.triggers\G`
3. 使用`show create trigger 触发器名称\G`命令来查看触发器定义.
4. 创建触发器后,MySQL自动在数据库目录下创建TRN以及TRG触发器文件,以记事本方式打开这些文件,可以查看触发器的定义.

## 删除触发器

使用drop trigger语句将该触发器删除,语法格式如下:
`drop trigger 触发器名称;`

## 使用触发器的注意事项

1. 触发程序中如果包含select语句, 该select语句不能返回结果集.
2. 同一个表不能创建两个具有相同触发时间、触发事件的触发程序(一个表最多设置6种类型的触发器).
3. 触发程序不能使用以显式或隐式方式打开、开始或结束事务的语句.
4. 批量更新记录时,引入触发器会导致更新操作性能降低.
5. MyISAM引擎中, 触发器不能保证原子性(指事务的不可分割性,一个事务的所有操作要么不间断地全部被执行，要么一个也没有执行。). InnoDB存储引擎支持事务,触发程序和更新操作是在同一个事务里完成.
6. InnoDB存储引擎实现外键约束关系时,建议使用级联选项(on delete/update cascade)来维护外键数据;MyISAM引擎虽然不支持外键约束关系, 但可以使用触发器实现级联修改和级联删除, 进而维护外键数据, 模拟实现外键约束关系.
7. 使用触发器维护InnoDB外键约束的级联选项时,应该先维护子表的数据再维护父表的数据.
8. MySQL的触发程序不能对本表使用更新语句(例如update语句).触发程序中的更新操作可以直接使用set代替, 否则可能出现错误信息, 甚至出现死循环.
9. before触发程序中,auto_increment字段的new值为0,不是实际插入新纪录时自动生成的自增型字段值.
10. 添加触发器后,建议对其进行详细的测试.
