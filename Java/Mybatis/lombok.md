# lomobok

- Lombok是一个实用的Java类库, 能通过注解的形式自动生成构造器, getter/setter, equals, hashcode, toString等方法, 并可以自动化生成日志变量, 简化Java开发, 提高效率

|注解|作用|
|:--|:--|
|@Getter/@Setter|为所有属性提供get/set方法|
|@ToString|给类自动生成易阅读的toString方法|
|@EqualsAndHashCode|根据类所拥有的非静态字段自动重写equals方法和hashCode方法|
|@Data|提供更综合的生成代码功能(@Getter+@Setter+@ToString+EqualsAndHashCode)|
|@NoArgsController|为实体类生成无参的构造器方法|
|@AllArgsController|为实体类生成除了static修饰的字段之外带有各参数的构造器方法|

- 引入依赖

```xml
<dependency>
  <groupId>org.projectlombok</groupId>
  <artifactId>lombok</artifactId>
  <!-- 不用指定版本号, 因为spring boot父工程已经统一进行了管理 -->
</dependency>
```

- Lombok会在编译时, 自动生成对应的Java代码, 我们使用Lombok时, 还需要安装一个Lombok的插件(IDEA自带)
