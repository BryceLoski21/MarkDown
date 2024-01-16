delimiter $$

create procedure re_proc(IN s_no CHAR(11), IN c_before INT, IN c_after INT, OUT state INT)
modifies sql data
begin
    declare s INT;
    declare status CHAR(7);
    set state = 0;
    set status = '未审核';
    
    if(c_before = c_after) then 
        set state = -1;
    else
        START TRANSACTION;
        select 状态 into status from course where 课程号 = c_after;
        select 可选人数 into s from course where 课程号 = c_after;
        if(s = 0 || status = '未审核') then
            set state = -2;
            elseif(state = 0) then
                update choose set 课程号 = c_after, 选课时间 = NOW() where 学号 = s_no and 课程号 = c_before;
                update course set 可选人数 = 可选人数 + 1 where 课程号 = c_before;
                update course set 可选人数 = 可选人数 - 1 where 课程号 = c_after;
                set state = c_after;
        end if;
        COMMIT;
    end if;
end;$$

-- SET @s_no = '2012002';

-- SET @c_before = 3;

-- SET @c_after = 1;

-- SET @state = 0;

-- CALL re_proc(@s_no, @c_before, @c_after, @state);

-- select @state;