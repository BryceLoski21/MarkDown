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
常用字符集有gbk,gb2312, utf8, big5等,MySQL默认字符集latin1是单字节编码,而汉字gbk等是双字节编码,UTF8mb3/UTFmb4是3字节编码(MySQL8.0以上版本UTF8默认是mb3,版本更高的默认是mb4),字符集选用不对可能导致乱码.
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

|类型|字节数|取值范围(有符号)|取值范围(无符号UNSIGNED)|说明|
|:--:|:--:|:--:|:--:|:--:|:--:|
|TINYINT|1字节|-128~127|0~255|最小整数|
|SMALLINT|2字节|-32768~32767|0~65535|小型整数|
|MEDIUMINT|3字节|-8388608~8388607|0~16777215|中型整数|
|INT|4字节|-2147483648~2147483647|0~4294967295|标准整数|
|BIGINT|8字节|-922372036854775808~922372036854775807|0~18446744073709551615|大整数|

- 浮点数类型（小数点后数字位数不确定）

|数据类型|单位|取值范围|说明|
|:--:|:--:|:--:|:--:|
|float|8或4字节|+(-)3.402823466E + 38|单精度浮点数|
|double|8字节|+(-)1.797693148623157E + 308 // +(-)2.225072014E - 308|双精度浮点数|

- 定点数类型（小数点后位数确定）

decimal(length, precision)用于表示精度确定的小数类型, length决定了该小数的最大位数, precision用于设置精度(小数点后的位数).
例如:
decimal(5, 2): 总位数5,小数点后2位,取值范围为-999.99 ~ 999.99

|数据类型|单位|取值范围|说明|
|:--:|:--:|:--:|:--:|
|decimal|自定义长度|可变|小数位数确定的小数|

- 字符串类型

MySQL字符串类型主要支持6种: char、varchar、tinytext、text、mediumtext、longtext.

|常规字符串类型|取值范围|说明|
|:--:|:--:|:--:|
|char(n)|0~255个字符|固定长度为n的字符串,其中n的取值范围为0~255,英文一个字节,汉字两个字节|
|varchar(n)|0~65535个字符(与字符集编码有关)|长度可变,最多8000个英文,4000个汉字|
|text||长度可变,超大数据,只能保存字符数据|

MySQL数据库的默认引擎是innodb, innodb必须记录varchar真实占用的字节数L,innodb最多分配2个字节(16bit)的空间去记录这个L.不同字符集的字符需要的字节数存在差异.

- 二进制数据类型(存储二进制数据的数据类型)

|类型|取值范围|说明|
|:--:|:--:|:--:|
|binary|0~255|固定长度,存储二进制数|
|varbinary||可变长度,存储二进制数|
|bit|1~64|固定长度,存储二进制数|
|tinyblob|0~255|可变长度,存储二进制数|
|blob|0 ~ 2^16-1|可变长度,存储图片、声音|
|mediumblob|0 ~ 2^24-1|可变长度,存储图片、声音、视频|
|longblob|0 ~ 2^32-1|可变长度,存储图片、视频、声音|

- 日期与时间类型

|类型|取值范围|说明|
|:--:|:--:|:--:|
|date|1000-01-01 ~ 9999-12-31|日期,格式为YYYY-MM-DD|
|time|-838:59:59 ~ 838:59:59|时间,格式为HH:MM:SS|
|datetime|1000-01-01 00:00:00 ~ 9999-12-31 23:59:59|日期和时间,格式为YYYY-MM-DD HH:MM:SS|
|timestamp|1970-01-01 00:00:00 ~ 2037年的某个时刻|时间戳,在处理报告时使用,显示格式取决于M的值|
|year|1901 ~ 2155|年份可指定两位数字和四位数字的格式|

- enum枚举类型(单选)与set集合类型(复选)

|类型|最大值|说明|
|:--:|:--:|:--:|
|enum("value1", "value2", ...)|65535|该类型的字段只能容纳所列值之一或为NULL(单选)|
|set("value1", "value2", ...)|64|该类型的字段可以容纳一组值或为NULL(多选)|
