delimiter $$

create procedure tr2_proc(IN from_account CHAR(7), IN to_account CHAR(7), IN money INT)
modifies sql data
begin
    declare continue handler for 1670
    begin
        ROLLBACK;
    end;
    START TRANSACTION;
    update account set balance = balance + money where account_no = to_account;
    update account set balance = balance - money where account_no = from_account;
    COMMIT;
    end;$$

delimiter ;

-- select * from account;

-- call tr2_proc('甲一', '玛丽', 700);

-- select * from account;