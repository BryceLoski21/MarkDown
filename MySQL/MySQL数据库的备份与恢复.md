<!-- 5 feet apart -->
# MySQL数据库的备份与恢复

[TOC]

## 使用SQL语句备份与恢复

使用select into outfile语句备份数据, 并用load data infile语句恢复数据.

语法为:
> select  *  into {oufile | dumpfile} 'file_name'  from  table_name
> load  data  [low_priority]  [local]  infile 'file_name.txt'  [replace | ignore]
> into  table  table_name;

说明:
select * into outfile 'file_name' 将选择的记录写入一个文件. 文件在服务器主机上创建.
load data infile 语句从一个文本中以很高的速度读取到一个表中. 指定local关键字,从客户主机读文件; local没有指定,文件必须位于服务器上.

备份一个数据表的步骤:

1.锁定数据表,避免备份过程中表被更新
> lock tables tbl_name read;

2.导出数据
> select * into outfile 'table_name.bak' from table_name;

3.解锁表
> unlock tables;

恢复备份数据的步骤:

1.为表增加一个写锁
> lock tables tables_name write;

2.恢复数据
> load data infile 'table_name.bak' replace into table table_name;

3.解锁表
> unlock tables;

如果在步骤2指定一个low_priority关键字, 就没必要对表进行上锁,因为数据的导入将被推迟到没有用户读表为止. 命令为:
> load data low_priority infile 'table_name' replace into table table_name;
