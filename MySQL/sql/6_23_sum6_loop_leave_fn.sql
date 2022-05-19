delimiter $$

create function sum6_fn(n int)
returns int
no sql
begin
    declare sum int default 0;
    declare start int default 0;
    add_num:loop
            set start = start + 1;
            if(start % 6 = 0 and start % 7 = 0) then set sum = sum + start;
            end if;
            if(start = n) then leave add_num;
            end if;
    end loop;
    return sum;
end;$$

delimiter ;

-- select sum6_fn(100);