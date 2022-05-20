delimiter $$

create function sum1_fn(n int)
returns int
no sql
begin
    declare sum int default 0;
    declare i int default 0;
    while i < n do
        set i = i + 1;
        set sum = sum + i;
    end while;
    return sum;
end;$$

delimiter ;

-- select sum1_fn(50);