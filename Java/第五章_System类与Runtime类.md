# System类与Runtime类

[TOC]

## System类

System类定义了一些与系统相关的属性和方法,它所提供的属性和方法都是静态的.引用这些属性和方法,直接使用System类调用即可.

|方法声明|功能描述|
|:--:|:--:|
|static void exit(int status)|该方法用于终止正在运行的Java虚拟机,status表示状态码,若status非0,则表示异常终止|
|static void gc()|运行垃圾回收器,并对垃圾进行回收|
|static native long currentTimeMillis()|返回以毫秒为单位的当前时间|
|static void arraycopy(Object src, int srcPos, Object dest, int destPos, int length)|从src引用的指定源数组拷贝到dest引用的数组,拷贝从指定的位置开始,到目标数组的指定位置结束|
|static Properties getProperties()|取得当前的系统属性|
|static String getProperty(String key)|获取指定键描述的系统属性|

1. getProperties()方法

    System类的getProperties()方法用于获取当前属性的全部属性,该方法会返回一个Properties对象,其中封装了系统的所有属性,这些属性以键值对的形式存在.

    ```java
    import java.util.*;

    public class Example09 {

        public static void main(String[] args) {
            
            //获取当前系统属性
            Properties properties = System.getProperties();

            System.out.println(properties);

            //获取所有系统属性的key(属性名),返回Set对象
            Set<String> propertyNames = properties.stringPropertyNames();

            for(String key : propertyNames) {

                //获取当前键key(属性名)所对应的值(属性值)
                String value = System.getProperty(key);

                System.out.println(key + "-->" + value);
            }

            /** 实现获取当前系统属性的功能:
             * 首先通过System的getProperties()获取封装了系统属性的Properties集合
             * 然后对Properties集合进行迭代,并将所有系统属性的键及值打印出来
             **/
        }
    }
    ```

2. currentTimeMillis()

    currentTimeMillis()方法返回一个long类型的值,该值表示当前时间与1970年1月1日0点0分0秒之间的时间差,单位是毫秒,通常也将该值称为时间戳

    ```java
    public class Example10 {

        public static void main(String[] args) {

            long startTime = System.currentTimeMillis(); //循环开始时的当前时间

            int sum = 0;

            for(int i = 0; i < 100000000; i++) {

                sum += i;
            }

            long endTime = System.currentTimeMillis(); //循环结束时的当前时间

            System.out.println("程序运行时间为:" +(endTime - startTime) +"毫秒");
            //由于处理器性能等原因,程序运行时间会有所不同
        }
    }
    ```

3. arraycopy(Object src, int srcPos, Object dest, int destPos, int length)

    arraycopy()方法用于将一个数组中的元素快速拷贝到另一个数组,其中参数列表说明如下:
    (1) src: 表示源数组
    (2) dest: 表示目标数组
    (3) srcPos: 表示源数组中拷贝元素的起始位置
    (4) destPos: 表示拷贝到目标数组的起始位置
    (5) length: 表示拷贝元素的个数

    ```java
    public class Example11 {

        public static void main(String[] arg) {

            int[] srcArray = {101, 102, 103, 104, 105, 106}; //源数组

            int[] destArray = {201, 202, 203, 204, 205}; //目标数组

            System.arraycopy(scrArray, 2, destArray, 0, 4); //拷贝数组元素

            //打印目标数组中的元素
            for(int i = 0; i < destArray.length; i++) {
                
                System.out.println(i + ":" +  destArray[i]);
            }
        } 
    }
    ```

    - 使用arraycopy()进行数组元素拷贝时,一定要保证源数组元素类型和目标数组元素类型一致,否则程序会出现ArrayStoreException异常
    - length不能超过截取的源数组从指定位置srcPos开始剩余元素的个数;length不能超过目标数组从指定位置destPos开始可容纳的元素个数;否则程序运行会出现ArrayIndexOutOfBoundsException异常

## Runtime类

Runtime类用于表示Java虚拟机运行时的状态,它用于封装Java虚拟机进程.
使用java命令启动java虚拟机时都会对应一个Runtime实例,应用程序通过该实例与其运行时的环境相连.
应用程序不能创建自己的实例,若想在程序中获得一个实例,可以通过getRuntime()获取与之相关的Runtime对象:

> Runtime run = Runtime.getRuntime();

```java
//由于Runtime封装了java虚拟机进程,
//因此可以通过该类的实例对象来获取当前虚拟机的相关消息

public class Example12 {

    public static void main(String[] args) {

        Runtime rt = Runtime.getRuntime(); //获取java程序关联的运行时对象

        System.out.println("处理器个数:" + rt.availableProcessors() + "个");

        System.out.println("空闲内存大小:" + rt.freeMemory() /1024 /1024 + "M");
        //空余内存数以及最大可用内存数都是以字节为单位计算的,换算为兆为单位的值
        System.out.println("最大可用内存大小:" + rt.maxMemory() /1024 /1024 + "M");
    }
}
```

```java
import java.io.IOException;

//Runtime类中提供了一个exec()方法,该方法用于执行一个DOS命令,
//从而实现和在命令行窗口中输入DOS命令同样的效果

public class Example13{

    public static void main(String[] args) throws IOException{

        Runtime rt = Runtime.getRuntime(); //创建Runtime实例对象

        /** Runtime类的exec()方法会返回一个Process对象,
         * 该对象表示操作系统的一个进程,
         * 通过Process对象可以对产生的新进程进行管理
         **/

        Process process = rt.exec("notepad.exe");
        //调用exec()方法,并将"notepad.exe"作为参数传递给exec(),
        //运行"notepad.exe"命令打开一个Windows自带的记事本,notepad.exe是一个新进程
        
        Tread.sleep(3000); //程序休眠3秒

        process.destroy(); //关闭进程
    }
}
```
