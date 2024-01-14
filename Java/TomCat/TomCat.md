# TomCat

[TOC]

## 简介

- Web服务器是一个软件程序, 对HTTP协议的操作进行封装, 使得程序员不必直接对协议进行操作, 让Web开发更加便捷
  - 主要功能: 部署Web项目, 提供网上信息浏览服务
- TomCat
  - 概念: TomCat是Apache旗下一个开源免费的轻量级Web服务器, 支持Servlet/JSP少量JavaEE规范
  - JavaEE: Java Enterprise Edition, Java企业版, 指Java企业级开发的技术规范总和, 包含13项技术规范: JDBC, JNDI, EJB, RMI, JSP, Servlet, XML, JMS, Java IDL, JTS, JTA, JavaMail, JAF
  - TomCat也被称为Web容器, Servlet容器。Servlet程序需要依赖于TomCat才能运行
  - [TomCat官网](https://tomcat.apache.org/)
  
## 安装与使用

- 安装: 直接解压
  - TomCat目录说明
    - bin: 可执行文件
    - conf: 配置文件
    - lib: TomCat依赖的jar包(TomCat基于Java开发)
    - logs: 日志文件
    - temp: 临时文件
    - webapps: 应用发布目录
    - work: 工作目录
- 卸载: 直接删除
- 启动: bin/startup.bat
  - 控制台乱码: 修改conf/logging.properties
    > java.util.logging.ConsoleHandler.level = FINE
    > java.util.logging.ConsoleHandler.formatter = org.apache.juli.OneLineFormatter
    > java.util.logging.ConsoleHandler.encoding = GBK
- 部署项目: 直接把项目放在webapps目录下即可
- 关闭
  - x掉: 强制关闭
  - bin\shutdown.bat: 正常关闭
  - Ctrl+C: 正常关闭
- 配置TomCat端口号(conf/server.xml)
  - HTTP协议默认端口号是80, 如果将TomCat端口号改为80, 则访问TomCat时不用输入端口号
  
  ```xml
  <Connectoer port="8080" protocol="HTTP/1.1"
              connectionTimeOut="20000"
              redirectPort="8443" />
  ```
