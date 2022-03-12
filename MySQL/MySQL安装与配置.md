<!-- 细细算来,大概是有一年多没去图书馆了,算是继往开来了,长路漫漫,道阻且长,切忌重蹈覆辙 -->
<!-- 当她和她新男友在一起时碰到你? -->
# MySQL数据库应用教程

[TOC]

## SQL语言

SQL语言是结构化查询语言(Structured Query Language)的简称,它是一种"关系型"的数据库语言,主要用于管理数据库中的数据,如存取数据,查询数据,更新数据等.

- 数据定义语言(DDL): CREATE和DROP,对应在数据库中创建表或删除表为表加入索引等操作.
- 数据操作语言(DML): INSERT,UPDATE,DELETE,分别用于添加,修改和删除表中的行.
- 数据查询语言(DQL): SELECT,从表中获得数据并确定数据在应用程序或终端的输出形式.
- 数据控制语言(DCL): 通过GRANT或REVOKE获得许可,确定单个用户组对数据库对象的访问权限.
- 事务处理语言(TPL): BEGIN TRANSACTION,COMMIT,ROLLBACK,是一类可以确保被多个DML语句影响的若干表的所有行都能及时得到更新的可以这些DML语句要么都执行要么都不执行的"事务"处理类语句.

## MySQL的体系结构

MySQL是一种基于客户机/服务器(Client/Server,C/S)的关系型数据库管理系统.由服务器端软件和客户端软件两大部分组成.
网络环境下运行的软件,还常使用另一种体系结构: B/S结构,即Browser/Server结构,这种结构只需要在服务器安装相关软件.

MySQL的优点:
> 1.体积小, 易安装
> 2.功能齐全, 性能极佳
> 3.支持跨平台, 多用户
> 4.开源, 免费

# MySQL的安装与使用

MySQL的版本:
GA(General Availability),是官方推崇广泛使用的版本;
RC(Release Candidate),候选版本,最接近正式版本的版本;
Alpha版本, 内测版本;
Bean版本, 公测版本;

## MySQL的安装

注意: 在安装MySQL Server前应先安装 Microsoft Visual C++ 2015.

如果以MySQL安装包文件方式启动安装, 选择安装类型时:

Typical表示典型安装,只安装常用的MySQL组件;
Custom表示定制安装,可由用户选择要安装的MySQL组件;
Complete表示完全安装,表示安装所有MySQL组件;

如果以压缩包方式进行解压安装:

1. 将压缩包解压在你想安装的目录下.
2. 配置MySQL的环境变量, 找到系统变量下的Path变量, 新增一行解压后的MySQL文件夹下的bin目录(例如"C:\Program Files\MySQL\MySQL Server 5.6\bin;")作为其值,并注意";"结尾.
3. 在MySQL的根目录(bin同级)下创建一个my.ini(附文末), 注意my.ini里的目录斜杠需要使用转义符,"\\"写成"\\\".
4. 管理员权限下打开Windows Terminal, 使用cd命令切换到MySQL的bin目录下(如 cd C:\Program Files\MySQL\MySQL Server 5.6\bin).
5. mysqld --initialize --console  这一步要复制默认密码, 出现error时,注意根目录下是否已存在data目录,若有就将其删掉.
6. mysqld --install  如果安装不成功或者服务已存在, 输入 sc query mysql   ->   sc delete mysql   ->  mysqld --remove
7. net start mysql 启动MySQL服务.
8. mysql -uroot -p   ->  EnterPassword: "复制的密码".
9. 成功进入服务后修改密码    ALTER USER 'root'@'localhost' IDENTIFIED WITH mysql_native_password BY '新密码';
10. 这一步非必选, 创建任意IP可访问的用户 create user 'name'@'%' identified with mysql_native_password by "密码";

```txt
[client]
# client下的"port"用来说明客户端连接MySQL使用的TCP/IP端口,默认3306
port=3306
[mysql]
# default-character-set表示客户端使用的默认字符集,可取gbk,gb2312,utf8等
default-character-set=utf8mb4
[mysqld]
# mysqld下的"port"用来说明服务器端使用的TCP/IP监听端口
port=3306
# basedir用来设置mysql的安装目录
basedir=D:\\Program Files\\mysql-8.0.25-winx64\\mysql-8.0.25-winx64
# datadir用来设置mysql数据库的数据的存放目录
datadir=D:\\Program Files\\mysql-8.0.25-winx64\\mysql-8.0.25-winx64\\Data
# 允许最大连接数
max_connections=200
# 允许连接失败的次数。
max_connect_errors=10
# 服务端使用的字符集默认为utf8mb4
character-set-server=utf8mb4
# 创建新表时将使用的默认存储引擎
default-storage-engine=INNODB
# 创建临时表时默认使用的引擎
default-tmp-storage-engine=INNODB
# SQL模式
sql-mode="STRICT_TRANS_TABLES,NO_AUTO_CREATE_USER,NO_ENGINE_SUBSTITUTION"
# 最大连接数
max_connections=100
# 查询缓存
query_cache_size=0
# 设置可以打开表的总数
table_cache=256
# 设置可以存储临时表的最大值
tmp_table_size=8
# 设置可以保留的客户端连接线程数
thread_cache_size=8
# 重建索引时允许的最大临时文件大小
myisam_max_sort_file_size=100G
# 重建索引时允许的最大缓存大小
myisam_sort_buffer_size=35M
# 最大关键字缓存大小
key_buffer_size=25M
# 全扫描MyISM表时的缓存大小
# 可插入排序时数据的缓存大小
read_buffer_size=64K
read_rnd_buffer_size=256K
# 用户排序时缓存大小
sort_buffer_size=256K
# ***INNODB存储引擎参数设置
# 引擎数据根目录设置
innodb_data_home_dir="D:\\Program Files\\mysql-8.0.25-winx64\\mysql-8.0.25-winx64\\bin\\"
# 附加内存池大小
innodb_additional_mem_pool_size=2M
# 提交日志的时机
innodb_flush_log_at_trx_commit=1
# 存储日志数据缓存的缓存区大小
innodb_log_pool_size=1M
# 缓存池中缓存区的大小
innodb_buffer_pool_size=47M
# 日记文件大小
innodb_log_file_size=24M
# 允许线程最大数
innodb_thread_concurrency=10
# 默认使用“mysql_native_password”插件认证
# mysql_native_password
default_authentication_plugin=mysql_native_password

```

bin文件夹为MySQL的命令文件所在文件夹, mysqld.exe是用来加载或卸载MySQL服务的, mysql.exe是用来登录连接MySQL服务器的.

my.ini以及其它ini文件分别是MySQL的标准配置文件和备用配置文件, 针对不同情况可选择使用不同的的配置文件:
> my-huge.ini 超大型数据库使用
> my-innodb-heavy-4G.ini 存储引擎为innoDB,内存不小于4G时使用
> my-large.ini 大型数据库使用
> my-medium.ini 中型数据库使用
> my-small.ini 小型数据库使用
> my-template.ini 配置文件模板

## 连接MySQL服务器及语法

Windows Terminal中(有时需要管理员权限,一般情况用户权限就可以)输入`net start mysql`启动MySQL服务,然后输入`mysql [-h hostname] -u username -p [password] [-P port]`登录服务器.

(1).MySQL命令(语句)输入结束,应使用分号";"结束.
(2).Windows平台下,MySQL语句关键字和函数名等不区分大小写.
(3).取消当前MySQL语句的输入可使用"\c".
(4).退出MySQL可使用"quit"或"\q".

MySQL服务器上,information_schema、mysql、performance_schema是系统已有的数据库(若版本不同,系统已有数据库可能还会有test或sys数据库).
