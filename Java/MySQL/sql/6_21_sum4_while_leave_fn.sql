delimiter $$

create function sum4_fn(n int)
returns int
no sql
begin
    declare sum int default 0;
    declare start int default 0;
    add_num:while true do
            set start = start + 1;
            set sum = sum + start;
            if(start = n) then leave add_num;
            end if;
    end while;
    return sum;
end;$$

delimiter ;

-- select sum4_fn(100);