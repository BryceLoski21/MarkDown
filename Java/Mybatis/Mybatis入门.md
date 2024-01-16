# Mybatis入门

- 使用Mybatis查询所有用户数据
  - 准备工作（创建spring boot工程、数据库表、实体类）
  - 引入Mybatis相关依赖(Mybatis Framework, MySQL Driver/Oracle Driver)，配置Mybatis(数据库连接信息)
  - 编写SQL语句（注解/XML）

    ```properties
    spring.datasource.driver-class-name = com.cj.jdbc.Driver
    spring.datasource.url = jdbc:mysql://localhost:3306/mybatis
    spring.datasource.username = root
    spring.datasource.password = 1234

    ```

    ```java
    // 注解方式
    @Mapper
    public interface UserMapper{
        @Select("select * from user")
        public List<User> list();
    }
    ```

    - @Mapper注解: 在运行时, 会自动生成该接口的实现类对象(代理对象), 并且将该对象交给IOC容器管理
      - @SpringBootTest注解: 在运行某个测试方法(给方法加上@Test注解)时会加载整个SpringBoot项目, 并且可以用@AutoWired注解自动装配Mapper的实现类对象

    ```java
    @SpringBootTest
    class SpringbootMybatisQuickStartApplicationTests{
        @Autowired
        private UserMapper userMapper;

        @Test
        public void test1(){
            List<User> userList = userMapper.list();
            userList.stream().foreach(user -> {
                System.out.println(user);
            })
        }
    }
    ```
