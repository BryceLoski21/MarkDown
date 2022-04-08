create table book(
    isbn char(20) primary key, # 定义ISBN为主键
    name char(20) not null,
    brief_introduction text not null,
    price decimal(5, 2),
    publish_time date not null,
    unique index isbn_unique(isbn),
    # 为isbn创建唯一索引
    index name_index(name(20)),
    # 为name创建普通索引
    fulltext index brief_fulltext(name, brief_introduction),
    # 为字段name, brief_introduction创建全文索引
    index complex_index(price, publish_time)
    # 为price, publish_time创建普通索引
)engine = MyISAM;