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
