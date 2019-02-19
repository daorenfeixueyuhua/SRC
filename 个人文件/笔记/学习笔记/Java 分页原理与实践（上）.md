# Java分页原理与实践

# 1. 课程介绍

# 1.1 主要内容

* 概述
* 网页常见分页样式
* 分页实现比较
* 项目实战

# 2. 分页概述

## 2.1. 概述

## 2.2 分页的实现简介和对比

**网站常见分页：**

* 采用传统的分页模式，可以明确获取数据信息，如有多少条数据，分多少页等等。
* 采用下拉式的分页方式，一般无法获取明确的数据数量相关的信息，但是在分页操作后,任然可以看到之前查询的数据

**常见的分页实现方式**

* 使用list接口中的sublist(int startIndex, int endInde)方式实现分页

        List<T> sublist(int fromIndex, int toIndex);
        返回列表中指定[fromIndex, toIndex)之间的部分视图
* 直接使用数据库sql语句实现分页

1. mysql查询语句
        
        select * from t_student limit 0, 10;
    
2. PostagreSQl查询语句

        select * from t_student limit 10 offset 0;

3. Oracle查询语句

        select * from
        (
                select s.*, rownum rn from (select * from s_student) s where rownum<=20
        )
        where rn>=1

* 使用hibernate框架实现跨数据分页
        
> 创建Query或则Criteria对象，查询时，设置firstResult和maxResult属性
        
        String hql = "from Student;"
        Query q = session.createQuery(hsql);
        q.seyFirestResult(0);
        q.setMaxResult(10);
        List l =q.list();


实现方式 | 优点 | 缺点 | 使用场景
---------|----------|--------- | -----
 sbulist | 简单、易用 | 效率低 | 无法按需批量获取数据 
 sql语句 | 简单、直接、效率高 | 数据库兼容性差 | 不要求数据库兼容
 hibernate框架 | 面向对象、兼容性强 | 复杂查询性能低 | 兼容不同数据库


# 3. 准备


# 4. sublist分页

# 5. sql分页

# 6. 总结