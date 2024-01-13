# 下载与安装maven

- [官网下载](https://maven.apache.org/download.cgi)
- 安装
  1. 解压文件
  2. 配置解压路径作为MAVEN_HOME环境变量
  3. 配置解压后的bin目录为PATH环境变量
  4. 新建一个mvn_repo作为本地仓库(建议与bin目录同级)
  5. 设置conf/setting.xml中的\<repository\>标签
  6. 设置conf/setting.xml中的\<mirror\>标签
  7. 输入命令行mvn -v测试安装是否成功(需要JDK支持)

```xml
<settings xmlns="http://maven.apache.org/SETTINGS/1.2.0"
          xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
          xsi:schemaLocation="http://maven.apache.org/SETTINGS/1.2.0 https://maven.apache.org/xsd/settings-1.2.0.xsd">

<!-- 部分标签省略 -->

  <localRepository>D:\maven\apache-maven-3.9.6-bin\apache-maven-3.9.6\mvn_repo</localRepository>
<!-- 说明本地仓库的位置, xml文件中的repository标签初始是注释掉的 -->
<!-- 可以配置多个镜像源 -->
  <mirrors>
    <mirror>
      <id>alimaven</id>
      <mirrorOf>central</mirrorOf>
      <name>ailiyun maven</name>
      <url>http://maven.aliyun.com/nexus/content/groups/public/</url>
      <!-- <blocked>true</blocked> -->
    </mirror>
  </mirrors>

</settings>
```

# IDEA新建maven

- IDEA设置(全局设置)
  1. 设置maven路径以及setting.xml路径和repository路径
  2. 设置Java compiler,设置JDK版本和目标language版本(反正保证JDK版本一致就行)

- 新建项目
  1. 新建空项目Project
  2. 新建模组module
    > 新建模组步骤根据idea版本不同有所差异
    > IDEA 2023 1.3 直接new module更简洁 test目录下缺失resource可直接新建
    > 更高版本的IDEA可以选择maven archetype, archetype setting 可选择 quick start 或 webapp

- 测试一遍hello world通过即可

# IDEA导入maven

- 方式一
  1. IDEA右侧maven面板
  2. "+" add module
  3. 找到要添加的项目的pom.xml文件点击ok即可(maven项目要在工作目录下)

- 方式二
  1. project structure
  2. modules
  3. "+" add module
  4. 找到要添加的项目的pom.xml文件点击ok即可(maven项目要在工作目录下)

- 删除
  - remove module(实际上文件还在, 即在资源管理器中还是能够看见maven项目)
