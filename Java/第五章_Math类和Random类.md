# Math类和Random类

[TOC]

## Math类

Math类是一个工具类,主要用于完成复杂的数学运算,如求绝对值、三角函数、指数运算等。
由于其构造方法被定义成private，因此无法创建Math类的对象。
Math类中所有方法都是静态方法,可用直接通过类名来调用它们.
Math类中有两个静态常量PI和E,分别代表数字中的Π和e.

```java
//Math类中常用方法
public class Example15 {

    public static void main(String[] args) {

        System.out.println("计算绝对值的结果:" + Math.abs(-1));

        System.out.println("计算正弦的结果:" + Math.sin(1.57));

        System.out.println("计算余弦的结果:" + Math.cos(2.0));

        System.out.println("计算正切的结果:" + Math.tan(0.8));

        System.out.println("计算平方根的结果:" + Math.sqrt(4));

        System.out.println("计算立方根的结果:" + Math.cbrt(9));

        System.out.println("计算乘方的结果:" + Math.pow(2, 2));

        System.out.println("求大于参数的最小整数:" + Math.ceil(4.6));
        //ceil()和floor()返回的都是double类型的数
        System.out.println("求小于参数的最大整数:" + Math.floor(-5.2));

        System.out.println("对小数进行四舍五入后的结果:" + Math.round(-8.6)); //返回一个int类型的数

        System.out.println("求两个数的较大值:" + Math.max(5.1, 5.5));

        System.out.println("求两个数的较小值:" + Math.min(5.1, 5.5));

        System.out.println("生成一个大于等于0.0小于1.0的随机值:" + Math.random());
    }
}
```

## Random类

java.util包中,有一个Random类,它可以在指定范围内随机产生数字.

Random类中提供了两个构造方法:

|方法声明|功能描述|
|:--:|:--:|
|Random()|用于创建一个随机数生成器,每次实例化Random对象都会生成不同的随机数|
|Random(long seed)|使用一个long类型的seed(种子)创建伪随机数生成器,当seed相同时,每次实例化Random对象会生成相同的随机数|

第一个构造方法是无参的,通过它创建的Random实例对象每次使用的种子是随机的,因此每个对象所产生的随机数都不同.

相比于Math的random()方法而言,Random类中提供了更多方法来生成各种伪随机数.Random不仅可以生成整数类型的伪随机数,还可以生成浮点类型的伪随机数.

|方法声明|功能描述|
|:--:|:--:|
|boolean nextBoolean()|随机生成boolean类型的随机数|
|double nextDouble()|随机生成double类型的随机数|
|float nextFloat()|随机生成float类型的随机数|
|int nextInt()|随机生成int类型的随机数|
|int nextInt(int n)|随机生成[0,n)之间int类型的随机数(包括0,不包括n)|
|long nextLong()|随机生成long类型的随机数|

```java
import java.util.Random;


public class Example16 {

    public static void main(String[] args) {

        Random r = new Random();

        System.out.println("生成boolean类型的随机数:" + r.nextBoolean());

        System.out.println("生成double类型的随机数:" + r.nextDouble());

        System.out.println("生成float类型的随机数:" + r.nextFloat());

        System.out.println("生成int类型的随机数:" + r.nextInt());

        System.out.println("生成0到10之间int类型的随机数:" + r.nextInt(10));

        System.out.println("生成long类型的随机数:" + r.nextLong());
    }
}
```
