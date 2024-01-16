-- 既然不配, 那就努力让自己配得上!
-- 多提升自己, 少他妈沉迷女色!


-- 查看数据库
show databases;

-- 使用数据库
use database_name;

-- 查看表
show tables;

-- 查看表中的记录
select * from table_name;

-- 创建表
create table if not exists table1_name(
    column1 int primary key,
    column2 char(10) foreign key,
    column3 varchar(10) not null,
    index table1_index(column3(10)),
    constraint table1_table2_fk foreign key(column2) references table2_name(table2_column1)
)engine = InnoDB;

-- 插入数据
insert into table table1_name values(1234567890, '别谈恋爱屁事没有', '加强封印'),
                                    (0987654321, '沉迷恋爱是没有出息的', '每日一遍'),
                                    (1234123421, '多提升自己', '她说的对');

insert into table table1_name(column1, column3) values(1234567878, '西格瑞');

insert into table set column1 = 1234345678, column2 = 'something hella crazy', column3 = 'just bollshit';

-- 更新数据
update table table1_name set column1 = 5678567890 where column1 = 1234123421;

-- 删除数据
delete from table1_name;

delete from table1_name where column1 = 1234123421;

truncate table table1_name;

-- 查看表结构
desc table1_name;
show create table1_name;

--修改表结构 添加约束
alter table table1_name add constraint table1_unique unique(column2);

--修改表结构 添加字段
alter table table1_name add column4 int after column3;

-- 修改表结构 删除字段
alter table table1_name drop column4;

-- 修改表结构 修改字段数据类型
alter table table1_name modify column3 char(10);

-- 修改表结构 修改字段名
alter table table1_name change column3 column4 int;

-- 重命名表
rename table table1_name to table1;

-- 删除表
drop table table1;
drop table table1, table2;
drop table if exists table1_name;

-- 数据查询
select column1 as 主键 from table1_name 
where column3 like '%shit%'
group by column1
order by column1 asc
limit 3;

select * from table1_name where column2 != null and column3 != null;

select * from table1_name where column1 between 1234123456 and 7890789089;
 
select * from table1_name where column1 != null or column2 != null;

select * from table1_name where column1 not in (1234123421, 1234123454, 5678567856);

select distinct * from table1_name;

select count(*) as 总人数 from student;

select max(成绩) from choose where 课程号 = 1;

select 买家ID, SUM(下单数量), AVG(下单数量) from dingdan group by 买家ID;

select 学号, count(课程号) from choose group by 学号 having count(课程号) > 2;

create procedure proc_cursor_1()
modifies sql data 
begin
    declare state char(20);
    declare my_score int;
    declare my_stuid char(20);
    declare my_cursor cursor for select 考生号, 总成绩 from xsb;
    declare continue handler for not found set state = 'error';
    open my_cursor;
    ADD_NUM: repeat
        fetch my_cursor into my_stuid, my_score;
        if state = 'error' then leave ADD_NUM;
        end if;
        set my_score = my_score + 1;
        update xsb set 总成绩 = my_score where 考生号 = my_stuid;
    until state = 'error' end repeat;
    close my_cursor;
end;$$

create procedure proc_cursor_2()
modifies sql data 
begin
    declare state char(20);
    declare my_score int;
    declare my_stuid char(20);
    declare my_cursor cursor for select 考生号, 总成绩 from xsb;
    -- declare continue handler for not found set state = 'error';
    -- 注释掉会报错: ERROR 1329 (02000): No data - zero rows fetched, selected, or processed
    open my_cursor;
    repeat
        fetch my_cursor into my_stuid, my_score;
        set my_score = my_score + 1;
        update xsb set 总成绩 = my_score where 考生号 = my_stuid;
    until state = 'error' end repeat;
    -- close my_cursor;
end;$$

create procedure proc_cursor_3()
modifies sql data 
begin
    declare state char(20);
    declare my_score int;
    declare my_stuid char(20);
    declare my_cursor cursor for select 考生号, 总成绩 from xsb;
    declare continue handler for 1329 set state = 'error';
    open my_cursor;
    repeat
        fetch my_cursor into my_stuid, my_score;
        set my_score = my_score + 1;
        -- 不写if最后一条记录会加2
        update xsb set 总成绩 = my_score where 考生号 = my_stuid;
    until state = 'error' end repeat;
    -- close my_cursor;
end;$$

-- 2022.6.16

use database_name;

show tables;

select * from information_schema.routines\G

select * from
(select row_number() over (partition by 课程名称 order by 成绩 asc) as row_num,
                                                                         学号,
                                                                         成绩 
from choose join course.课程号 = choose.课程号) as temp
where row_num = 1;
