delimiter $$
create function compare_fn(a int, b int)
returns int
no sql
begin
    if a > b then return a;
    else return b;
    end if;
end;$$