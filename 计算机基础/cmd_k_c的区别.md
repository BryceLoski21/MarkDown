<!-- 因为害怕就不去做某件事，那也太愚蠢了吧！ -->
# 关于"cmd /k"与"cmd /c"的区别

<font size=4 color=red>win+r后, 在'运行'窗口中可以使用"cmd /k|/c 命令"的格式使cmd直接执行该命令</font>

- cmd /k 命令
  执行完命令后不关闭dos窗口
- cmd /c 命令
  执行完命令后关闭dos窗口

## 关于runas与cmd命令的组合使用

> runas /user:Administrator "cmd /c net start mysql"

运行此条命令, 输入Administrator的密码后, windows会打开一个dos窗口, 不管语句是否执行成功, windows都**会关闭**这个新打开的dos窗口

> runas /user:Administrator "cmd /k net start mysql"

运行此条命令,输入Administrator的密码后, windows会打开一个dos窗口, 不管语句是否执行成功, widows都**不会关闭**这个新打开的窗口

## 关于runas提升权限的问题

- <font color=red>普通权限下的wt窗口、cmd窗口、win+r运行窗口是不能直接运行"net start mysql"的</font>
- <font color=red>普通权限下的wt窗口(或者wtp)是不能以管理员权限打开wt(或者wtp)窗口的</font>
- <font color=red>普通权限下的wt窗口是可以以管理员权限打开一个cmd窗口的</font>
- <font color=red>普通权限下的win+r运行窗口、cmd窗口是可以以管理员权限打开一个新窗口的</font>
