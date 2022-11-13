# 关于导入项目maven找不到依赖包的问题

## ERROR
- Could not transfer artifact org.springframework.boot:spring-boot-starter-parent:pom:2.2.4.RELEASE...

## 解决办法
- 使用maven构建项目时,install命令注入pom中的依赖,可能由于证书问题导致访问服务器失败,所以需要在设置<b>(build_tools - maven - runner - VM_Options)</b>里忽略证书检查,命令如下:
```
-Dmaven.wagon.http.ssl.insecure=true -Dmaven.wagon.http.ssl.allowall=true
```
然后使用maven的clean命令清除缓存,然后reload就好
- pom.xml中出现报错的部分,用dependencies更换几个版本试试
- 如果maven插件有问题,reload,还是有问题就检查一下maven插件本身是不是有问题,还不行就换自己的maven包

还有手动导入证书的方法,参考[https://blog.csdn.net/FungLi_notLove/article/details/104469940?ops_request_misc=&request_id=&biz_id=102&utm_term=Could%20not%20transfer%20artifact%20or&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduweb~default-1-104469940.142^v63^control,201^v3^control_1,213^v2^t3_control1&spm=1018.2226.3001.4187]
