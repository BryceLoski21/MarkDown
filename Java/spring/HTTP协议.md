# HTTP协议

[TOC]

## text01

- 概念
  > Hyper Text Transfer Protocol, 超文本传输协议, 规定了浏览器和服务器之间数据传输的规则

- 特点
  - 基于TCP协议: 面向连接, 安全
  - 基于请求\-响应模型: 一次请求对应一次响应
  - HTTP协议是无状态的协议: 对于事物处理没有记忆能力, 每次请求\-响应都是独立的
    - 缺点: 多次请求间不能共享数据
    - 优点: 速度快

## 请求协议

- 请求数据格式
  - 第一行: 请求行: 请求数据第一行(请求方式GET/POST/..., 资源路径, 协议)
  - 第二行: 请求头: 第二行开始, 格式key:value
    - Host: 请求的主机名
    - User\-Agent: 浏览器版本
    - Accept: 浏览器能接收的资源类型, 如text/\*, image/\*或者\*/\*表示所有
    - Accept\-Encoding: 浏览器支持的压缩类型
    - Content\-Type: 请求主体的数据类型
    - Content\-Length: 请求主体的大小(单位: 字节)
  - 第三行: 请求体: POST请求特有, 存放请求参数

- 请求方式\-GET: 请求参数在请求行中, 没有请求体, 如: /brand/findAll?name=OPPO&status=1。GET请求大小是有限制的
- 请求方式\-POST: 请求参数在请求体中, POST请求大小是没有限制的

## 响应协议

- 响应数据格式
  - 第一行: 响应行: 响应数据第一行(协议及版本, 状态码, 描述)
    - [状态码](https://cloud.tencent.com/developer/chapter/13553)
      - 1XX: 响应中\-临时状态码, 表示请求已经接收, 告诉客户机应该继续请求或者它已经完成则忽略
      - 2XX: 成功\-请求成功被接收, 处理已完成
      - 3XX: 重定向\-重定向到其它地方, 让客户再发起一次请求以完成整个处理
      - 4XX: 客户端错误\-处理发生错误, 责任在客户端, 如: 请求了不存在的资源, 客户端未被授权, 禁止访问等
      - 5XX: 服务器错误\-处理发生错误, 责任在服务端, 如: 程序抛出异常等
  - 第二行: 响应头: 第二行开始, 格式key:value
    - 响应头
      - Content\-Type: 表示响应内容的类型, 例如text/html, application/json等
      - Content\-Length: 表示响应内容的长度(字节数)
      - Content\-Encoding: 表示响应压缩算法,例如gzip
      - Cache\-Control: 指示客户端如何缓存, 例如max\-age=300表示最多缓存300秒
      - Set\-Cookie: 告诉浏览器为当前页面所在的域设置cookie
  - 第三行: 响应体: 最后一部分, 存放响应数据

## 协议解析

- ServerSocket
- TomCat

## 请求响应

- B/S架构: Browser/Server, 浏览器/服务器架构模式, 客户端只需要浏览器,应用程序的逻辑和数据都存储在服务端(维护方便, 体验一般)
  - 前端控制器: TomCat中的DispatcherServlet: 派发请求响应
  - 请求(HttpServletRequest): 获取请求数据
  - 响应(HttpServletResponse): 设置响应数据
- C/S架构: Client/Server, 客户端/服务器架构模式(开发维护麻烦, 体验不错)

### 请求

- 简单参数
  - 原始方式: 在原始的web程序中, 获取请求参数, 需要通过HttpServletRequest对象手动获取

    ```java
    @RestController
    public class RequestController{
        // 原始方式
        @RequestMapping("/simpleParam")
        public String simpleParam(HttpServletRequest request){
            // 获取请求参数
            String name = request.getParameter("name");
            String ageStr = request.getParameter("age");

            int age = Integer.parseInt(ageStr);
            System.out.println(name+ ": "+ age);
            return "OK";

        }
    }
    ```
  
  - Spring Boot方式

    ```java
    @RestController
    public class RequestController{
        // spring boot方式
        @RequestMapping("/simpleParam")
        public String simpleParam(String name, Integer age){ // String age会进行自动类型转换成Integer
           
            System.out.println(name+ ": "+ age);
            return "OK";

        }
    }
    ```

  - @RequestParam注解
    - 如果方法形参与请求参数名称不匹配, 可以使用@RequestParam完成映射
    - @RequestParam中的required属性默认为true, 代表该请求参数必须传递, 如果不传递会报错, 如果该参数是可选的, 可以将required属性设置成false

    ```java
        @RestController
        public class RequestController{
            // spring boot方式
            @RequestMapping("/simpleParam")
            public String simpleParam(@RequestParam(value = "name", required = false)String name, Integer age){ // String age会进行自动类型转换成Integer

                System.out.println(name+ ": "+ age);
                return "OK";

            }
        }
        ```

- 实体参数
  - 简单实体对象: 请求参数名与形参对象属性名相同, 定义POJO(Pure Ordinary Java Object)接收即可

    ```java
    // 伪代码
        @RequestMapping("/simpleParam")
        public String simpleParam(User user){ 
            // 需要保证实体对象和请求属性一致
            System.out.println(user);
            return "OK";

        }
    public class User{
        private String name;
        private String age;
    }
    ```
  
  - 复杂实体对象

    ```java
    // 伪代码
        @RequestMapping("/simpleParam")
        public String simpleParam(User user){ 
            // 需要保证实体对象和请求属性一致
            System.out.println(user);
            return "OK";

        }
    public class User{
        private String name;
        private String age;
        private Address address;
        // address.province属性
        // address.city属性
    }
    public class Address{
        private String province;
        private String city;
    }
    ```
