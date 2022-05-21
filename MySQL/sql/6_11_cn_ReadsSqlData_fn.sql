delimiter $$

create function cn_fn(a char(10))
returns int
reads sql data
begin
    declare s int;
    select count(学号) into s from classes 
    join student on classes.班级编号 = student.班级编号
    where 班级名称 = a;
    return s;
end;$$

delimiter ;

-- select cn_fn(a '19计应8班');