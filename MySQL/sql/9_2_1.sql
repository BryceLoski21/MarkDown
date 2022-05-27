use choose;

-- 这种方法只能导出数据的内容, 不包括表的结构, 如果表的结构被损坏,必须要先恢复表结构.

-- 备份数据

-- 锁定数据表
LOCK table student READ;

-- 导出数据
select * into OUTFILE 'student.bak' from student;

-- 解锁表
UNLOCK table;

-- 恢复备份数据

-- 为表增加一个写锁
LOCK table student;
-- 如果指定了LOW_PRIORITY关键字, 就没必要对表上锁, 因为数据的导入会推迟到没有用户读表为止.
-- LOAD DATA LOW_PRIORITY INFILE 'student.bak' REPLACE INTO TABLE student;

-- 恢复数据
LOAD DATA INFILE 'student.bak' REPLACE INTO table student;

-- 解锁表
UNLOCK table;