delimiter $$

create function sum3_fn(n int)
returns int
no sql
begin
    declare sum int default 0;
    declare start int default 0;
    repeat
        set start = start + 1;
        set sum = sum + start;
    until start = n end repeat;
    return sum;
end;$$

delimiter ;

-- select sum3_fn(100);