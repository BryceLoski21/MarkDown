delimiter $$
create procedure s1_proc()
reads sql data
begin
    select count(*) from student;
end;$$

-- 7_2
create procedure c_proc(in s_no char(10))
reads sql data
begin
    select 课程名称 from choose join course
    on choose.课程号 = course.课程号
    where 学号 = s_no;
end;$$

-- 7_3
create procedure c1_proc(in s_no char(10), out number int)
reads sql data
begin
    select count(*) into number from choose where 学号 = s_no;
end;$$

delimiter ;