# String类与StringBuffer类

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

```
