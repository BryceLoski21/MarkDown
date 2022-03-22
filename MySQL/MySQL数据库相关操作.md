# MySQL数据库相关操作

[TOC]

## 字符集的设置及写入操作

- 修改my.ini配置文件,可修改MySQL默认的字符集.

> 修改[mysql]选项组下的default_character_set的值可以同时改变character_set_client, character_set_connection, character_set_database的值
> 修改[mysql]选项组下的character_set_server的值可同时改变character_set_database, character_set_server的值

- 在MySQL命令行通过以下命令临时修改当前会话的字符集以及字符序

```sql
set character_set_client = gbk;
set character_set_connection = gbk;
set character_set_database = gbk;
set character_set_results = gbk;
set character_set_server = gbk;
set collation_connection = gbk_chinese_ci;
set collation_database = gbk_chinese_ci;
set collation_server = gbk_chinese_ci;
```

- 连接MySQL服务器时可指定字符集

> mysql -default-character-set = 字符集 -h 服务器IP地址 -u 账户名 -p 密码

- 写入脚本(SQL文件)

> \\.C:\mysql\init.sql
> source C:\mysql\init.sql

## MySQL数据库的选择

使用命令`USE 数据库名;`选择数据库

## 查看MySQL数据库

`SHOW DATABASES [like 通配字符串];`

可选参数like 通配字符串] 表示模糊匹配, 有\"%\"和\"\_\"两种语法,其中\"%\"代表多个字符, 而\"\_\"只能代表一个字符

## MySQL数据库的创建

`CREATE DATABASE [if not exists] 数据库名 [charset 字符集名称];`

可选参数[if not exists] 表示当指定数据库在不存在时即创建,若已存在指定数据库不创建也不会出错.
数据库名若是关键字或非英文字符应用反引号(数字1左边的字符\`)定界.

可选参数[charset 字符集名称] 可指定用哪个字符集来创建数据库.
常用字符集有gbk,gb2312, utf8, big5等,MySQL默认字符集latin1是单字节编码,而汉字gbk等是双字节编码,字符集选用不对可能导致乱码.
一种字符集可能有多种字符序,通常以`"字符集名称开头,中间用国家名,最后用ci, cs或bin结束"`来对字符集进行命名, 其中以**ci结尾的对大小写不敏感**, **以cs结尾的对大小写敏感**, **以bin结尾的表示按二进制值进行比较**.

## 显示MySQL数据库的创建信息

`SHOW CREATE DATABASE 数据库名;`

## MySQL数据库的修改

`ALTER DATABASE 数据库名 charset 字符集名称;`

## MySQL数据库的删除

`DROP DATABASE [if not exists] 数据库名;`

## MySQL的存储引擎与数据类型

### MySQL的存储引擎

- 查看MySQL支持的存储引擎

> 格式一: SHOW ENGINES;
> 格式二: SHOW ENGINES\g
> 格式三: SHOW ENGINES\G
> (区别在于使用的"结束符"不同,显示的格式和信息不同, 推荐格式三)

使用;和\g作用相同,仅简单显示各个存储引擎的信息, \G的显示效果最好,对所支持的各种存储引擎会从"引擎名称""是否支持该引擎""关于该引擎的说明评论""是不是支持事务""该引擎支持的分布式是否支持XA规范""是否支持事务处理中的保存点"等方面逐个的、详细到显示出来.

- 查看当前MySQL支持的存储引擎

`SHOW VARIABLES LIKE '%storage_engine%';`

- 临时更改默认的存储引擎

`set default_storage_engine = MyISAM;`

"="右边可选存储引擎可为MyISAM, InonoDB, Memory.

- 永久地更改默认的存储引擎

在my.ini配置文件中的[mysqld]选项组中更改default_storage_engine的值

- 常见引擎种类

1. MyISAM
   特点: 不支持事务, 不支持外键, 访问速度快, 占用空间小.
   MyISAM存储引擎的表存储成3个文件,文件名字与表名相同.
   以.frm为扩展名的文件存储表的结构;
   以MYD为扩展名的文件存储数据(my data);
   以MYI为拓展名的文件存储索引(my index);
   MyISAM存储引擎的表支持3种存储格式: 静态,动态,压缩.
   静态模式和动态模式根据是否使用xBLOB、xTEXT、varchar来自动选择;压缩模式只能使用Myisampack工具来创建.
2. InnoDB
   InnoDB具有较强的事务处理能力及较好的事务安全性并且支持外键.
   不足之处在于读写效率稍差,占用数据空间相对较大.
3. MEMORY
   它使用存储在内存中的内容来创建表,而且所有数据也都放在内存中,其特点是访问速度快,但安全上没有保障.
   每个基于MEMORY存储引擎的表实际对应一个磁盘文件,该文件的文件名与表名相同,类型为frm类型,该文件中只存储表的结构,而其数据文件都存储在内存中.

### MySQL中的数据类型

- 整数类型
- 浮点数类型
- 定点数类型
- 字符串类型
- 二进制数据类型
- 日期与时间类型
- enum枚举类型(单选)与set集合类型(复选)
