delimiter  $$

create function sum5_fn(n int)
returns int
no sql
begin
    declare sum int default 0;
    declare start int default 0;
    add_num:while start < n do
            set start = start + 1;
            if(start % 9 = 0) then set sum = sum + start;
            else iterate add_num;
            end if;
    end while add_num;
    return sum;
end;$$

delimiter ;

-- select sum5_fn(100);