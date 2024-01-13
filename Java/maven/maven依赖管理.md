# 依赖管理

[TOC]

## 依赖配置

- 依赖: jar包, 一个pom.xml中可以有多个依赖
- 配置: dependencies 标签
  - dependency 子标签 [根据依赖名称查找配置代码](https://mvnrepository.com/)
    - groupId 组织名
    - artifactId 模块名
    - version 版本号(更换版本右侧maven面板reload一下)

```xml
<dependencies>

    <dependency> 
        <groupId> </groupId>
        <artifactId> </artifactId>
        <version> </version>
    </dependency>

</dependencies>
```

## 依赖传递

- 依赖具有传递性(类似继承)
  - 直接依赖: 当前项目中通过依赖配置建立起来的依赖关系
  - 间接依赖: 被依赖的资源如果依赖其它资源, 当前项目间接依赖其它资源
  - pom.xml中右键点击diagrams, 选择show dependencies以图表方式查看依赖
- 排除依赖: 主动断开依赖的资源, 被排除的资源无需指定版本
  - exclusions标签 写在 dependency标签 里面
    - exclusion 子标签
      - groupId
      - artifactId

```xml
<dependencies>

    <dependency> <!--依赖 -->
        <groupId> </groupId>
        <artifactId> </artifactId>
        <version> </version>

        <exclusions> <!--被排除的依赖 -->

            <exclusion> <!--不需要版本号 -->
                <groupId> </groupId>
                <artifactId> </artifactId>
            </exclusion>

        </exclusions>

    </dependency>

</dependencies>
```

- 继承: 继承一个父工程, 使用parent标签

```xml
<parent> 
  <groupId>org.springframework.boot</groupId>
  <artifactId>spring-boot-starter-parent</artifactId>
  <version>2.7.4</version>
  <relativePath/> <!-- lookup parent from repository  -->
</parent>
```

## 依赖范围

- 依赖的jar包, 默认可以在任何地方使用, scope标签可以设置依赖的作用范围
- 作用范围:
  - 主程序范围内有效 (main文件夹范围内)
  - 测试程序范围内有效 (test文件夹范围内)
  - 是否参与打包运行 (package指令范围内)

```xml
<dependency> 
    <groupId> </groupId>
    <artifactId> </artifactId>
    <version> </version>
    <scope> </scope> <!-- default: compile -->
</dependency>
```

- scope取值范围
  - compile: 默认值 全范围有效
  - test: test
  - provided: main和test
  - runtime: test和打包运行

## maven的生命周期

- maven的生命周期是为了对所有maven项目构建过程进行抽象和统一
  > 生命周期/阶段是抽象的, 并不执行具体的操作, 操作是由与其绑定的maven插件完成的
- 3套相互独立的生命周期Lifecycle
  - clean: 清理工作
    - **clean**: 移除上一次构建生成的target
  - default: 核心工作: 编译, 测试, 打包, 安装, 部署等
    - **compile**: 编译项目源代码
    - **test**: 使用合适的单元测试框架进行测试(junit)
    - **package**: 将编译后的文件打包, 如: jar, war等
    - **install**: 安装项目到本地的maven仓库
  - site: 生成报告, 发布站点等
- **同一套生命周期**中, 运行后面的阶段时, 前面的阶段都会执行

- 生命周期的执行
  - IDEA右侧maven面板
  - 命令行中通过命令执行: mvn compile (切换到项目路径下执行)
