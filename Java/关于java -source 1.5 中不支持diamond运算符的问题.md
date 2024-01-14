# 关于导入项目出现“java: -source 1.5 中不支持 diamond 运算符...”的问题

## Error:
- (107, 55) java: -source 1.5 中不支持 diamond 运算符
(请使用 -source 7 或更高版本以启用 diamond 运算符)

## 原因
- 没有详细配置java版本和构建文件时所使用的的编码

## 解决方案
- 在父工程的pom.xml中添加如下属性配置：

```
<properties>
        <java.version>1.8</java.version>
        <project.build.sourceEncoding>UTF-8</project.build.sourceEncoding>
        <maven.compiler.source>1.8</maven.compiler.source>
        <maven.compiler.target>1.8</maven.compiler.target>
</properties>
```
