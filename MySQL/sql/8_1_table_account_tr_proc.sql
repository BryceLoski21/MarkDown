use choose;

-- 创建account表
create table account(
    account_no INT auto_increment PRIMARY KEY,
    -- 客户账户设置为主键
    account_name CHAR(7) NOT NULL,
    -- 客户姓名不为空
    account_contact CHAR(11) NOT NULL,
    -- 联系方式不为空
    balance INT UNSIGNED
    -- 余额为无符号整数
)engine = InnoDB;

-- 向account表中插入数据
insert into account values(null, '甲一', '176xxxx6282', 700),
                          (null, '玛丽', '153xxxx9501', 1200);


-- 创建tr_proc存储过程: 甲一向玛丽的账户转账
delimiter $$

create procedure tr_proc(IN from_account CHAR(7), IN to_account CHAR(7), IN money INT)
modifies sql data
begin
    update account SET balance = balance + money where account_name = to_account;
    update account SET balance = balance - money where account_name = from_account;
end;$$

delimiter ;

-- select * from account;

-- call tr_proc('甲一', '玛丽', 700);

-- select * from account;

-- call tr_proc('甲一', '玛丽', 700);
-- ERROR 1690 (22003): BIGINT UNSIGNED value is out of range in ...

-- select * from account;