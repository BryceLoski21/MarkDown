delimiter $$

create function get_week_fn(week_no int)
returns char(10)
no sql
begin
    declare week char(10);
    CASE week_no
        when 1 then set week = '星期一';
        when 2 then set week = '星期二';
        when 3 then set week = '星期三';
        when 4 then set week = '星期四';
        when 5 then set week = '星期五';
        when 6 then set week = '星期六';
        when 7 then set week = '星期天';
        else set week = '今天休息';
    end CASE;
    return week;
end;$$

delimiter ;

-- select get_week_fn(7);


create function get_grade_fn(score int)
returns char(10)
no sql
begin
    declare grade char(10);
    CASE
        when score < 60 then set grade = '不及格';
        when score < 70 then set grade = '中等';
        when score < 80  then set grade = '良好';
        when score < 90 then set grade = '上等';
        when score <= 100 then set grade = '满分';
        when score < 0 then set grade = '';
        else set grade = '重开吧';
    end CASE;
    return grade;
end;$$