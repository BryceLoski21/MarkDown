# untitled

[TOC]

## Spring

- [官网](spring.io)
- Spring已形成了一种开发生态圈, Spring提供了若干子项目, 每个项目用于完成特定的功能
- Spring
  - Spring Framework (底层框架)
  - Spring Boot (配置简洁)
  - Spring Data
  - Spring Cloud
  - Spring Security

## Spring Boot Web

- 步骤
  - 创建Spring Boot工程, 勾选Web开发相关依赖
    - 创建完后, 删除mvn等不需要的文件夹/文件(pom.xml中的maven插件不用删)
  - 定义Controller类, 添加方法, 添加注解
    - @RestController声明是请求处理类, @RequestMapping("/hello")指定处理的请求
  - 运行测试
    - http\://localhost:8080/hello 默认端口8080
  
- 起步依赖
  - spring\-boot\-starter\-web
  - spring\-boot\-starter\-test
  - [starter](https://docs.spring.io/spring-boot/docs/2.7.4/reference/htmlsinge/#using.build-systems.starters)

- 内嵌TomCat服务器
  > 基于SpringBoot开发的Web应用程序, 内置了TomCat服务器, 当启动类运行时, 会自动启动内嵌的TomCat服务器
