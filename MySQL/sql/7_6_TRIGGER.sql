--  修短随化, 终期于尽


use choose;
alter table choose drop foreign key choose_student_fk;
alter table choose add foreign key student_course_fk
foreign key(学号) references student(学号) on delete cascade;
-- 级联删除即删除包含主键值的行的操作,
-- 该值由其它表的现有行中的外键列引用.
-- 在级联删除中,还删除其外键值引用删除的主键值的所有行.

-- 当student表中有学生被删除时,触发删除包含该学号的行的操作
delimiter $$
create trigger s_trigger before delete on student
for each row
begin
delete form choose where 学号=old.学号;
end;$$

-- 创建两张表: ORGANIZATION(父表)和MEMBER(子表)
    -- 创建数据库book_management
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
create trigger delete_trigger before delete on ORGANIZATION for each row
begin
delete from MEMBER where O_NO=OLD.O_NO;
end;$$

delimier ;