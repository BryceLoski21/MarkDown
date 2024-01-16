# JDBC

- jdbc: Java DataBase Connectivity, 就是使用Java语言操作关系型数据库的一套API(各个数据库厂商去实现这套接口, 提供数据库驱动jar包, 程序员面向接口编程)

- 注册驱动
  
  ```java
  Class.forName("com.mysql.cj.jdbc.Driver");
  ```

- 获取连接对象

  ```java
  String url = "jdbc:mysql://localhost:3306/mybatis";
  String username = "root";
  String password = "1234";
  Connection connection = DriverManager.getConnection(url, username, password);
  ```

- 获取执行SQL的对象Statement, 执行SQL, 返回结果

  ```java
  String sql = "select * from user";
  Statement statement = connection.createStatement();
  ResultSet resultSet = statement.executeQuery(sql);
  ```

- 封装数据结果
  
  ```java
  List<User> userList = new ArrayList<>();
  while(resultSet.next()){
      int id = resultSet.getInt("id");
      String name = resultSet.getString("name");
      short age = resultSet.getShort("age");
      short gender = resultSet.getShort("gender");
      String phone = resultSet.getString("phone");

      User user = new User(id, name, age, gender, phone);
      userList.add(user);
  }
  ```

- 释放资源

  ```java
  statement.close();
  connection.close(); // 顺序不能反
  ```
