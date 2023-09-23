# Script file 'D:\Anaconda3\Scripts\pip-script.py' is not present

pip升级失败

- 原因
  > 上面的命令是直接把pip或所需的依赖包直接删掉了，所以在用pip下载其他安装包时，出现错误

- 解决办法
  > 进入anaconda安装路径下的Scripts目录下,
  > 运行`easy_install pip`

easy_install和pip都是用来下载安装Python一个公共资源库PyPI的相关资源包的，pip是easy_install的改进版，提供更好的提示信 息，删除package等功能。老版本的python中只有easy_install，没有pip。
easy_install 打包和发布 Python 包
pip 是包管理
