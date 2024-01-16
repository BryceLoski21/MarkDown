delimiter $$
create function sname_fn(a char(10))
returns char(10)
reads sql data
begin
    declare s char(10);
    select 姓名 into s from student where 学号 = a;
    return s;
end;$$