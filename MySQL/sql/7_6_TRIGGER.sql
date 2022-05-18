--  修短随化, 终期于尽

-- 触发器删除关联数据
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

-- 创建两张表: ORGANIZATION(父表)和MEMBER(子表)
    -- 创建数据库book_management
delimiter ;
create database book_management;
use book_management;

create table ORGANIZATION(
    O_NO int not null auto_increment,
    O_NAME varchar(32) default '',
    primary key(O_NO)
)engine=InnoDB;

create table MEMBER(
    M_NO int not null auto_increment,
    M_NAME varchar(32) default '',
    O_NO int,
    primary key(M_NO),
    constraint ORGANIZATION_MEMBER_FK foreign key(O_NO) references ORGANIZATION(O_NO)
)engine=InnoDB;

    -- 向两张表插入记录
insert into ORGANIZATION(O_NO, O_NAME) values
(null, 'AA'),
(null, 'BB');
insert into MEMBER(M_NO, M_NAME, O_NO) values
(null, '张', 1),
(null, '王', 1),
(null, '李', 1),
(null, '赵', 2),
(null, '孙', 2);

    -- 创建触发器DELETE_TRIGGER: 当删除ORGANIZATION中某条记录前,先删除MEMBER中相关信息
delimiter $$
create trigger delete_trigger before delete on ORGANIZATION for each row
begin
delete from MEMBER where O_NO=OLD.O_NO;
end;$$

delimier ;


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


-- 使用触发器实现check约束
delimiter $$
create trigger s1_trigger before insert on student
for each row
begin
if(year(now()) - year(new.出生日期) <= 30) then
set new.出生日期 = new.出生日期;
else insert into mytable values(0);
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