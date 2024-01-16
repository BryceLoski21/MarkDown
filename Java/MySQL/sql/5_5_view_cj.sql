create view view_cj
as
select student.学号, student.姓名, classes.班级名称 -- choose.课程号, choose.成绩,
from classes join student on classes.班级编号 = student.班级编号
-- join choose on student.学号 = choose.学号
-- join choose on course.课程号 = choose.课程号;

# 这里为了避免数据库表名称重复的问题, 将3_6中的数据库名改为了choose_database(并无卵用)
# 还有另外一种解决办法: 将etc目录下的my\.cnf下的lower_case_table_name变量的值设置为0(并无卵用,设置其他值MySQL无法启动)
# [关于lower_case_table_name变量的官方解释](https://dev.mysql.com/doc/refman/8.0/en/identifier-case-sensitivity.html)
