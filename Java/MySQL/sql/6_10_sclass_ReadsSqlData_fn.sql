use choose;

delimiter $$

create function sclass_fn(a char(20))
returns char(20)
reads sql data
begin
    declare s char(10);
    select 班级名称 into s from course where 班级编号 = (select 班级编号 from student where 学号 = a);
    -- TODO: choose数据库中的course表并无"班级名称"和"班级编号"字段
    return s;
end;$$

delimiter ;

-- select sclass_fn('')