# WIN11系统激活问题

## 问题描述

今天打开电脑突然发现电脑右下角多了“请激活Windows”等字样，电脑系统是windows 11专业版，之前激活过一次，正好这次又出现了这个问题，就写一篇blog,免得下次又忘记:cry:

## 解决方法

1. 以管理员权限打开Windows Terminal
2. 新建一个power shell窗口
3. 卸载产品密钥输入: `slmgr /upk`
4. 安装产品密钥: `slmgr /ipk W269N-WFGWX-YVC9B-4J6C9-T83GX`
5. 重命名此台电脑: `slmgr /skms kms.03k.org`
6. 查看激活状态: `slmgr /ato`
7. :smile::ok:

其他问题:
    在重命名这步, 有的博客是**zh.us.to**,但是我的电脑不行;
    卸载和安装这一步, 有的博客使用的命令是**slmgr.vbs**,不知道有无影响;
    产品密钥网上很多,我试了几个win7/win8的密钥,没有成功,产品密钥为:
    TPJ6C-YY8KK-Y7XHQ-GDW7H-DFQJV
    TPJ6C-YY8KK-Y7XHQ-GDW7H-DFQJV
    BMBXP-J4MHQ-4K76K-C9VV8-248C9
    PW48G-MNG8W-B9978-YWBRP-76DGY
