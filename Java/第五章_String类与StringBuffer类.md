<!-- 她到底爱不爱我啊! -->

# String类与StringBuffer类

[TOC]

## String类的初始化

- 使用字符串常量直接初始化一个String对象
  > String 变量名=字符串;
  > 初始化字符串常量对象时,既可以将字符串对象的初始值设为空,也可以初始化为一个具体的字符串

```java
String str1 = null; //初始化为空
String str2 = ""; //初始化为空字符串
String str3 = "abc"; //初始化为abc, 其中abc为字符串常量
```

- 使用String的构造方法初始化字符串对象
  > String 变量名 = new String("字符串");
  > 字符串可以为空或是一个具体的字符串

|方法声明|功能描述|
|:--:|:--:|
|String()|创建一个内容为空的字符串|
|String(String value)|根据指定的字符串内容创建对象|
|String(char[] value)|根据指定的字符数组创建对象|

```java
//以下代码为上表中3种方法的使用示例
public class Example01 {

    public static void main(String[] args) {

        String str1 = new String(); //创建一个空的字符串

        String str2 = new String("abc"); //创建一个内容为abc的字符串

        // 创建一个内容为字符数组的字符串
        char[] charArray = new char[] {'a', 'b', 'c'};

        String str3 = new String(charArray);

        //输出结果
        System.out.println("a" + str1 + "b");
        //Tips: Java中,如果+的两边操作数有一个为String类型,那么+就表示字符串连接运算符

        System.out.println(str2);

        System.out.println(str3);
    }
}
```

## String类的常见操作

|方法声明|功能描述|
|:--:|:--:|
|int indexOf(int ch)|返回指定字符在此字符串中第一次出现处的索引|
|int lastIndexOf(int ch)|返回指定字符串在此字符串中最后一次出现的索引|
|int indexOf(String str)|返回指定字符串在此字符串中第一次出现的索引|
|char charAt(int index)|返回字符串中index位置上的字符,其中index的取值范围是0~字符串长度-1|
|boolean endsWith(String suffix)|判断此字符串是否以指定的字符串结尾|
|int length()|返回字符串的长度|
|boolean equals(Object anObject)|将此字符串与指定字符串比较|
|boolean isEmpty()|当且仅当字符串长度为0时返回true|
|boolean startWith(String prefix)|判断此字符串是否以指定字符串开始|
|boolean contains(CharSequence cs)|判断此字符串中是否包含指定的字符序列|
|String toLowerCase()|使用默认语言环境的规则将String中的所有字符都转换为小写|
|String toUpperCase()|使用默认语言环境的规则将String中的所有字符都转换为大写|
|static String valueOf(int t)|返回int参数的字符串表示形式|
|char[] toCharArray()|将此字符串转换为一个字符数组|
|String replace(CharSequence oldStr, CharSequence newStr)|返回一个新的字符串,它是通过用newStr替换此字符串中的所有oldStr得到的|
|String[] split(Strng regex)|根据参数regex(regex是一个正则表达式,用来限定分隔规则)|
|String substring(int beginIndex)|返回一个新字符串,它包含从指定的beginIndex起始角标处开始,直到此字符串末尾的所有字符|
|String substring(int beginIndex, int endIndex)|返回一个新字符串,它包含从指定的beginIndex起始角标处开始,直到索引endIndex-1角标处的所有字符|
|String trim()|返回一个新字符串,它去除了原字符串首尾的空格|
Tips: [关于indexOf(int ch)为什么使用int类型作为参数](https://blog.csdn.net/dachengshi2016/article/details/78479407)

- 字符串的基本操作

```java
public class Example02 {

    public static void main(String[] args) {

        String s = "abcabcabcdba"; //初始化字符串

        System.out.println("字符串长度为:" + s.length());

        System.out.println("字符串中第一个字符:" + s.charAt(0));

        System.out.println("字符c第一次出现的位置:" + s.indexOf('c'));

        System.out.println("字符c最后一次出现的位置:" + s.lastIndexOf('c'));

        System.out.println("子字符串第一次出现的位置:" + s.indexOf("ab"));

        System.out.println("子字符串最后一次出现的位置:" + s.lastIndexOf("ab"));
    }
}
```

- 字符串的转换操作

```java
public class Example03 {

    public static void main(String[] args) {

        String str = "java";

        char[] charArray = str.toCharArray(); //字符串转换为字符数组

        System.out.print("将字符串转为字符数组的遍历结果:");

        for(int i = 0; i < charArray.length; i++) {

            if(i != charArray.length-1) {
                //如果不是数组的最后一个元素,在元素后面加逗号
                System.out.print(charArray[i] + ",");
            } else {

                //数组最后一个元素后面不加逗号
                System.out.println(charArray[i]);
            }
        }

        System.out.println("将int值转换为String类型之后的结果:" + String.valueOf(12));
        //String.valueOf()将一个int类型整数转换为字符串

        System.out.println("将字符串转换成大写之后的结果:" + str.toUpperCase());
    }
}
```

- 字符串的替换和去除空格操作

```java
public class Example03 {

    public static void main(String[] args) {

        String str1 = " https: //www.pronhub.com ";

        System.out.println("去除字符串两端空格后的结果:" +str1.trim());
        // 输出"https: //www.pornhub.com"

        System.out.println("去除字符串中所有空格后的结果:" +str1.replace(" ", ""));
        // 输出"https://www.pronhub.com"
    }
}
```

- 字符串的判断操作

```java
public class Example05 {

    public static void main(String[] args) {

        String s1 = "Starter"; //声明一个字符串

        String s2 = "St";

        System.out.println("s1是否以St开头:" + s1.startsWith("St"));

        System.out.println("s1是否以er结尾:" + s1.endsWith("er"));

        System.out.println("s1是否包含ar:" + s1.contains("ar"));

        System.out.println("s1是否为空" + s1.isEmpty());

        System.out.println("s1与s2字符串是否相等" + s1.equals(s2));
        /** "=="和"equals()"的区别
         * equals() 用于比较两个对象的值是否相等
         * == 用于比较两个对象的内存地址是否相等
         **/

    }
}
```

- 字符串的截取和分割

```java
public class Example06 {

    public static void main(String[] args) {

        String str = "2022-1-6";

        System.out.println("从第6个字符截取到末尾的结果:" + str.substring(5));

        System.out.println("从第6个字符截取到第7个字符的结果:" + str.substring(5, 7));
        
        System.out.println("分割后的字符串数组中的元素依次为:");

        String[] strArray = str.split("-");

        for(int count = 0; count < strArray.length; count++) {

            if(count != strArray.length-1) {
                
                System.out.print(strArray[count] + ".");

            }else{

                System.out.println(strArray[count]);
            }

        }
    }
}
```

Tips: String字符串在获取某个字符时会用到字符串的索引,当访问字符串中某个字符时,如果索引不存在,则会发生StringIndexOutOfBoundsException(字符串角标越界异常)

## StringBuffer类

Java中,String类是final类型的,使用String定义的字符串是一个常量,一旦建立,其内容和长度是不可改变的.

为了便于对字符串进行修改,JDK中提供了一个StringBuffer类(字符串缓冲区)来操作字符串,StringBuffer类定义的字符串(类似一个字符容器)其内容和长度是可变的.

|方法声明|功能描述|
|:--:|:--:|
|StringBuffer append(char c)|添加字符到StringBuffer对象中的末尾|
|StrigBuffer insert(int offset, String str)|在StringBuffer对象中的offset位置插入字符串str|
|StringBuffer deleteCharAt(int index)|移除StringBuffer对象中指定位置的字符|
|StringBuffer delete(int start, int end)|移除StringBuffer对象中指定范围的字符或字符串|
|StringBuffer replace(int start, int end, String s)|将StringBuffer对象中指定范围的字符或字符串用s进行替换|
|void setCharAt(int index), char ch|修改指定位置index处的字符|
|String toString()|返回StringBuffer缓冲区中的字符串对象|
|StringBuffer revese()|将此StringBuffer对象用其反转形式取代|

```java
public class Example08 {

    public static void main(String[] args) {

        System.out.println("1.添加--------------------------");

        add();

        System.out.println("2.修改--------------------------");

        update();

        System.out.println("3.删除--------------------------");

        delete();
    }

    public static void add() {
        
        StringBuffer sb = new StringBuffer(); //定义一个字符串缓冲区

        sb.append("ABC"); //添加字符串

        System.out.println("append添加结果:" + sb);

        sb.insert(3, "DE"); //在指定位置插入字符串

        System.out.println("insert添加结果:" + sb);
    }

    public static void update() {

        StringBuffer sb = new StringBuffer("ABAAA");

        sb.setCharAt(2, 'C'); //修改指定位置字符

        sb.replace(3, 5, "DE"); //替换指定位置字符串

        System.out.println("替换指定位置结果:" + sb);

        System.out.println("字符串翻转结果:" + sb.reverse());
    }

    public static void delete() {

        StringBuffer sb = new StringBuffer("ABCDEFG");

        sb.delete(3, 7);

        System.out.println("删除指定范围字符串结果:" + sb);

        sb.deleteCharAt(2);

        System.out.println("删除指定位置字符串结果:" + sb);

        sb.delete(0, sb.length());

        System.out.println("清空缓冲区结果:" + sb);
    }
}
```

多加注意:

1. String类定义的字符串是常量,一旦创建,其内容和长度都无法改变.StringBuffer表示字符容器,其内容和长度都可以随时修改.
2. String类重写了Object类的equals()方法, StringBuffer类没有重写Object类的equals()方法.String类的equals()方法比较值,StringBuffer类的equals()方法比较内存地址.
3. String类对象可以用操作符"+"进行连接,而StringBuffer对象之间不能.

- **StringBuilder类**

JDK1.5之后提供了一个StringBuilder类,功能与StringBuffer类似.
StringBuilder(异步)没有实现线程安全功能,所以性能略高.StringBuffer(同步)是线程安全的.
同步: 按顺序执行,一步一步来(synchronic)
异步: 接一个任务,直接给后台,**在**接下一个,谁先读取完谁先执行,没有顺序,可能导致上面代码还没出来,下面代码就出来了.
创建一个内容可变的字符串对象时,优先考虑StringBuffer类.
