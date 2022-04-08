# mysql: Charset is not found

- 错误信息:
  **mysql: Character set 'odingMarkDownMySQLsql5_1.sql;' is not a compiled character set and is not specified in the 'C:\Program Files\MySQL\MySQL Server 8.0\share\charsets\Index.xml' file Charset is not found**

- 原因分析:
  可能是因为my.ini中没有设置字符集目录, 也可能是字符集文件丢失.

- 解决方案:
  - 设置字符集目录(不设置的话, 默认是C:\Program Files\...):
    > character-sets-dir=D:\Program Files\mysql-8.0.25-winx64\mysql-8.0.25-winx64\share\charsets
  - 然后重启mysql服务
    > mysql\> exit;
    > net stop mysql
    > net start mysql

<br/>

- 附言:
  使用WindowsTerminal关闭和重启MySQL服务:
  > runas /noprofile /user:Administrator wt
  
  系统提示:
  **"发生系统错误
  5, 拒绝访问"**
  
  以为是用户权限不够, 运行此行命令提升权限:
  > runas /user:Administrator wt
  
  系统提示:
  **"试图将 wt 作为用户 "DESKTOP-IL8T9KS\Administrator" 启动...
  RUNAS 错误: 无法运行 - wt
  5: 拒绝访问。"**
  没有找到原因...
  给不了wt管理员权限, 我就直接用cmd运行命令了
  > runas /noprofile /user:Administrator "net stop mysql"
  > runas /user:Administrator "net start mysql"

注: wt.exe在C:\Program Files\WindowsApps\Microsoft.WindowsTerminal_1.11.3471.0_x64__8wekyb3d8bbwe\wt.exe
