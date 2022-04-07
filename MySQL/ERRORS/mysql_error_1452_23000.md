# MySQL Error 1452 (23000)

- 错误代码:

    ![错误提示](/images/mysql/mysql_error_1452_23000.png)
    **ERROR 1452 (23000): Cannot add or update a child row: a foreign key constraint fails (`choose`.`student`, CONSTRAINT `student_classes_fk` FOREIGN KEY (`班级编号`) REFERENCES `classes` (`班级编号`))**

<br/>

- 相关代码:

    课程表classes:
    ![classes表](/images/mysql/mysql_error_1452_23000_table_classes.png)

    学生表student:
    ![student表](/images/mysql/mysql_error_1452_23000_table_student.png)

    向student表中插入数据:
    ![向student表中插入数据](/images/mysql/mysql_error_1452_23000_insertData_student.png)

<br/>

- 错误原因: 插入外键字段的字段值在主键字段中不存在。

<br/>

- 解决办法: `检查插入数据或更新数据的语句, 注意检查次表中外键字段的值对应主表中的主键字段中是否存在.`
