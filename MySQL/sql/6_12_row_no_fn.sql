delimiter $$

create function row_no_fn()
returns int
no sql
begin
    if(@row_no is null) then set @row_no = 0;
    end if;
    set @row_no = @row_no + 1;
    return @row_no;
end;$$

delimiter ;

-- select row_no_fn() as 序号, 学号, 姓名 from student;

-- 使用此条语句前需先声明@row_no: set @row_no = 0;
-- 每次在查询中使用此函数后需要清除@row_no的值: set @row_no = 0