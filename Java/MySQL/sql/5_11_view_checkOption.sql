create view choose_view1
as
select * from choose where 成绩>60
with cascaded check option;

create view choose_local_view2
as
select * from choose_view1 where 成绩>50
with local check option; -- local只检查当前视图的条件

create view choose_cascaded_view3
as
select * from choose_view1 where 成绩>50
with cascaded check option; -- cascaded不仅检查当前视图的条件,还检查上一级视图的条件
