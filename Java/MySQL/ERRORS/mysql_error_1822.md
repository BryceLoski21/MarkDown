<!-- 你也会偶尔想起我吗？ -->
<!-- 你会后悔吗？ -->
# ERROR 1822 (HY000)

## 报错信息

- ERROR 1822 (HY000): Failed to add the foreign key constraint. Missing index for constraint 'c_fk' in the referenced table '学生信息'

## 问题原因

- 外键对应的字段在主表中不是主键字段

## 解决方案

- 检查无法建立的外键所对应的主表字段是否为主表的主键
- 还应检查主键字段与外键字段的数据类型一致性，以及字段列表一致性
