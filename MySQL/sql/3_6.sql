create database if not exists choose default charset utf8; # 创建数据库choose

use choose; # 打开数据库choose

# 创建部门信息表
create table department(
    学院编号 int auto_increment primary key,
    学院名称 char(20) not null unique
)engine = InnoDB;

# 向department表插入数据
insert into department values(null, '机电工程学院');
insert into department values(null, '土木工程学院');
insert into department values(null, '计算机学院');
insert into department values(null, '管理工程学院');
insert into department values(null, '生物工程学院');

# 创建班级信息表classes
create table classes(
    班级编号 char(4) primary key, # 设置班级编号为主键
    班级名称 char(20) not null unique, # 设置班级名称不允许为空,且不允许重复
    学院编号 int,
    constraint department_classes_fk foreign key(学院编号) references department(学院编号)
)engine = InnoDB;

# 向classes表插入数据
insert into classes values('01', '19计算机科学与技术1班', 3);
insert into classes values('02', '19计算机科学与技术2班', 3);
insert into classes values('03', '19计算机科学与技术3班', 3);
insert into classes values('04', '19信息管理1班', 4),
                          ('05', '19机电1班', 1),
                          ('06', '19软件6班', 3),
                          ('07', '19生工1班', 5),
                          ('08', '19计算机应用技术8班', 3);

# 创建学生信息表student
create table student(
    学号 char(11) primary key, # 学号不允许重复
    姓名 char(10) not null, # 姓名不允许为空
    性别 enum('男', '女'),
    出生日期 datetime,
    班级编号 char(4),
    constraint student_classes_fk foreign key(班级编号) references classes(班级编号) # 设置班级编号为外键
)engine = InnoDB;

# 向学生信息表插入数据
insert into student values ('20201019', '仪宝', '女', '2001-02-25 00:00:00', '06'),
                           ('20220104', '猪头', '男', '2000-10-21 00:00:00', '08'),
                           ('01640401', '浅浅', '女', '2001-05-06 00:00:00', '01'),
                           ('01640402', '猴子', '男', '2000-02-20 00:00:00', '01'),
                           ('01640403', '魔兽', '男', '2000-02-20 00:00:00', '01'),
                           ('01640404', '英雄', '女', '1998-03-18 00:00:00', '02'),
                           ('01640405', '火王', '男', '1992-04-01 00:00:00', '03'),
                           ('01640406', '马浅', '女', '2001-03-04 00:00:00', '04'),
                           ('01640407', '田七', '男', '2002-03-04 00:00:00', '02');

# 创建课程信息表course
create table course(
    课程号 int auto_increment primary key, # 设置课程号为自动增长型,且为主键
    课程名称 char(10) not null, # 设置课程号不允许重复
    学分 int default 4, # 设置学分的默认值为4
    学院编号 int,
    constraint course_fk foreign key(学院编号) references department(学院编号)
)engine = InnoDB;

# 向course表插入数据
insert into course values(null, 'Java语言程序设计', 3, 1);
insert into course values(null, 'MySQL数据库', 2, 2);
insert into course values(null, 'C语言程序设计', 4, 1);
insert into course values(null, 'C++程序设计', 2, 2);
insert into course values(null, '系统管理', 2, 5);
insert into course values(null, '高等数学', 5, 1);

# 创建学生选课信息表choose
create table choose(
    学号 char(11),
    课程号 int,
    成绩 tinyint unsigned,
    选课时间 datetime default now(),
    constraint choose_pk primary key(学号, 课程号),
    constraint choose_student_fk foreign key(学号) references student(学号),
    constraint choose_course_fk foreign key(课程号) references course(课程号)
)engine = InnoDB;

# 向choose插入数据
insert into choose(学号, 课程号, 成绩) values ('01640401', 2, 40),
                                             ('01640401', 1, 50),
                                             ('01640401', 3, 60),
                                             ('01640402', 2, 70),
                                             ('01640403', 1, 80),
                                             ('01640403', 2, 90),
                                             ('01640404', 3, 0),
                                             ('01640405', 1, 0);

# 图书销售管理数据库
create table bookstore(
    书店id char(10) primary key,
    书店名 char(40) unique,
    书店地址 char(60) default '地址不详',
    书店电话 char(11) not null,
    书店面积 float
)engine = InnoDB;

# 插入数据
insert into bookstore values('1', '紫光书店', '武生院东区', '13623123542', 20.5);
insert into bookstore values('2', '黄菊书店', '武生院西区', '13624312542', 30.6);
insert into bookstore values('3', '绿荷书店', '武生院南区', '11452112542', 70.2);
insert into bookstore values('4', '蓝天书店', '武生院北区', '13123243542', 80.3);
insert into bookstore values('5', '红日书店', '武生院学子区', '11234543242', 90.5);

# 创建买家表buyer
create table buyer(
    买家id char(10) primary key,
    姓名 char(10) not null,
    性别 enum('男', '女') default '男',
    家庭住址 varchar(10),
    联系电话 char(11) unique
);

#插入数据
insert into buyer values('buyer1', '彭万里', '男', '武生院学子南 101', '157895614');
insert into buyer values('buyer2', '高大山', '男', '武生院学子南 102', '1592345435');
insert into buyer values('buyer3', '孙子涵', '女', '武生院东八 101', '18879451689');
insert into buyer values('buyer4', '孙丹', '女', '武生院东八 102', '18295621876');
insert into buyer values('buyer5', '马建国', '男', '武生院北一 101', '15984651894');
insert into buyer values('buyer6', '王卫国', '男', '武生院北一 102', '18879456213');
insert into buyer values('buyer7', '周利人', '男', '武生院柏园 101', '18879136513');

# 创建图书表book
create table book(
    图书编号 char(10) primary key,
    图书名称 char(20) not null unique,
    作者 varchar(18) not null,
    单价 decimal(5, 2) default 0,
    出版商 char(16)
)engine = InnoDB;

# 插入数据
insert into book values('a2018001', '围城', '钱钟书', 18, '晨光出版社');
insert into book values('a2018002', '鬼谷子', '奥里森·马丁', 42, '北方文艺出版社');
insert into book values('a2018003', '人性的弱点', '戴尔·卡耐基', 15, '人民出版社');
insert into book values('a2018004', '时间简史', '史蒂芬·霍金', 50, '科学技术出版社');
insert into book values('a2018005', '方与圆', '文德', 6.8, '海天出版社');
insert into book values('a2018006', '朗读者', '董卿', 10.5, '中国人民大学出版社');
insert into book values('a2018007', '巴黎圣母院', '维克多·雨果', 28, '人民文学出版社');
insert into book values('a2018008', '活着', '余华', 10.5, '人民邮电出版社');

# 创建在售表onsale
create table onsale(
    书店id char(10),
    图书编号 char(10),
    上架数量 int default 0,
    constraint onsale_bookstore_fk foreign key(书店id) references bookstore(书店id),
    constraint onsale_book_fk foreign key(图书编号) references book(图书编号)
)engine = InnoDB;

#插人数据
INSERT INTO onsale VALUES('1', 'a2018001', 425);
INSERT INTO onsale VALUES('1', 'a2018004', 360);
INSERT INTO onsale VALUES('1', 'a2018005', 125);
INSERT INTO onsale VALUES('1', 'a2018007', 285);
INSERT INTO onsale VALUES('2', 'a2018003', 389);
INSERT INTO onsale VALUES('2', 'a2018008', 500);
INSERT INTO onsale VALUES('3', 'a2018001', 444);
INSERT INTO onsale VALUES('3', 'a2018006', 310);
INSERT INTO onsale VALUES('3', 'a2018005', 428);
INSERT INTO onsale VALUES('4', 'a2018004', 205);
INSERT INTO onsale VALUES('4', 'a2018006', 466);
INSERT INTO onsale VALUES('4', 'a2018007', 400);
INSERT INTO onsale VALUES('5', 'a2018001', 405);
INSERT INTO onsale VALUES('5', 'a2018002', 410);
INSERT INTO onsale VALUES('5', 'a2018003', 330);
INSERT INTO onsale VALUES('5', 'a2018005', 445);
INSERT INTO onsale VALUES('5', 'a2018006', 421);
INSERT INTO onsale VALUES('5', 'a2018008', 460);

# 创建订单表dingdan
create table dingdan(
    订单id char(20) primary key,
    买家id char(10),
    书店id char(10),
    图书编号 char(10),
    下单数量 int,
    dingdan_time datetime not null,
    constraint dingdan_buyer_fk foreign key(买家id) references buyer(买家id),
    constraint dingdan_bookstore_fk foreign key(书店id) references bookstore(书店id),
    constraint dingdan_book_fk foreign key(图书编号) references book(图书编号)
)engine = InnoDB;

# 插入数据
INSERT INTO dingdan VALUES('a2018001', 'buyer1', '5', 'a2018001', 1, '2018-11-12 10:18:26');
INSERT INTO dingdan VALUES('a2018002', 'buyer2', '2', 'a2018002', 2, '2018-11-12 16:45:36');
INSERT INTO dingdan VALUES('a2018003', 'buyer3', '5', 'a2018003', 3, '2018-11-13 09:16:20');
INSERT INTO dingdan VALUES('a2018004', 'buyer4', '1', 'a2018004', 4, '2018-11-13 13:25:31');
INSERT INTO dingdan VALUES('a2018005', 'buyer5', '4', 'a2018005', 5, '2018=11-14 15:11:24');
INSERT INTO dingdan VALUES('a2018006', 'buyer6', '2', 'a2018006', 6, '2018-11-15 11:29:37');
INSERT INTO dingdan VALUES('a2018007', 'buyer7', '4', 'a2018008', 7, '2018-11-15 15:19:25');

