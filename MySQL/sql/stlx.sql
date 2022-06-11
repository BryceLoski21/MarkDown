/*
SQLyog Ultimate v11.24 (32 bit)
MySQL - 5.6.5-m8 : Database - stsj
*********************************************************************
*/


/*!40101 SET NAMES utf8 */;

/*!40101 SET SQL_MODE=''*/;

/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;
CREATE DATABASE /*!32312 IF NOT EXISTS*/`stsj` /*!40100 DEFAULT CHARACTER SET gbk */;

USE `stsj`;

set names gbk;

/*Table structure for table `bjb` */

DROP TABLE IF EXISTS `bjb`;

set names gbk;

CREATE TABLE `bjb` (
  `班级代号` char(10) DEFAULT NULL,
  `班级名称` char(20) DEFAULT NULL,
  `班主任` char(10) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `bjb` */

insert  into `bjb`(`班级代号`,`班级名称`,`班主任`) values ('130101','13动画','张峰'),('130102','19环境设计','王海'),('130201','19计算机','刘波'),('130301','19土木工程','薄古'),('130401','19生物工程','孙平'),('130501','19制药工程','周芳'),('130601','19机械设计','吴敏'),('130701','19电子商务','李丽'),('130801','19园林','陈庆');

/*Table structure for table `xsb` */

DROP TABLE IF EXISTS `xsb`;

set names gbk;

CREATE TABLE `xsb` (
  `考生号` char(14) DEFAULT NULL,
  `姓名` char(20) DEFAULT NULL,
  `性别` char(2) DEFAULT NULL,
  `出生日期` date DEFAULT NULL,
  `专业` varchar(20) DEFAULT NULL,
  `班级代号` char(10) DEFAULT NULL,
  `总成绩` decimal(5,2) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `xsb` */

insert  into `xsb`(`考生号`,`姓名`,`性别`,`出生日期`,`专业`,`班级代号`,`总成绩`) values ('13422802130074','刘御','女','1993-08-27','动画','130101','486.00'),('13422802130165','陈缺','男','1995-06-18','动画','130101','473.00'),('13422802170146','付蕊','男','1993-06-18','环境设计','130102','477.00'),('13429401130207','王御','男','1994-10-20','动画','130101','474.00'),('13429501130319','付红','女','1995-09-28','环境设计','130102','498.00'),('13429501130342','周生','女','1995-08-10','视觉传达设计','130103','446.00'),('13429501130647','刘蕊','男','1995-07-16','动画','130101','442.00'),('13429501170037','李茹','男','1993-02-27','环境设计','130102','480.00'),('13429601130340','郑方','男','1994-11-10','环境设计','130102','470.00'),('13429601170054','陈帆','女','1996-01-01','环境设计','130102','450.00'),('13429601170161','马军','男','1994-08-28','环境设计','130102','463.00'),('13420281850124','蒋茹','男','1995-04-04','环境设计','130102','473.00'),('13420281850175','郑御','男','1993-12-13','计算机科学与技术','130201','463.00'),('13420321850029','李缺','男','1993-09-15','土木工程（建筑工程）','130301','460.00'),('13420321850093','吴方','男','1994-10-29','土木工程（建筑工程）','130301','461.00'),('13420527850007','徐花','女','1995-04-24','生物工程','130401','461.00'),('13420528810016','马成','女','1993-04-01','土木工程（建筑工程）','130301','487.00'),('13420528850189','赵成','男','1995-01-16','制药工程','130501','494.00'),('13420528850354','钱花','男','1994-07-08','土木工程（建筑工程）','130301','469.00'),('13420528850377','彭茹','女','1994-05-08','土木工程（建筑工程）','130301','476.00'),('13420582850144','付生','女','1995-08-13','制药工程','130501','464.00'),('13420583850061','彭明','女','1994-12-05','机械设计制造及其自动化','130601','461.00'),('13420583850079','王花','男','1994-12-21','机械设计制造及其自动化','130601','467.00'),('13420601851104','钱军','女','1993-08-26','土木工程（建筑工程）','130301','494.00'),('13420601851153','赵彪','女','1994-08-08','土木工程（建筑工程）','130301','493.00'),('13420624850032','孙生','男','1995-06-28','土木工程（建筑工程）','130301','461.00'),('13420701850130','孙锐','男','1994-08-08','机械设计制造及其自动化','130601','462.00'),('13420802810003','郑成','女','1996-06-04','制药工程','130501','477.00'),('13420881850123','王帆','男','1994-12-04','计算机科学与技术','130201','463.00');

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;


create view view1
as
select 考生号,姓名,总成绩 from xsb where 总成绩 < 470;

create view view2
as
select 考生号,xsb.姓名,xsb.班级代号,bjb.班主任,总成绩 from xsb join bjb on xsb.班级代号 = bjb.班级代号;

-- query ok,但是无记录变更,因为view1的条件是<470
update view1 set 总成绩 = (select 总成绩 from (select 总成绩 from view1 where 姓名 = '付红') as temp) where 姓名 = '郑成';