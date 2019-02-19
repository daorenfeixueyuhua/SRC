# Spring事务管理

## 1. 课程介绍

### 1.1. Spring事务管管理课程目标

- 事务回顾
- Spring事务管理的一组API
- Spring的编程式事务管理
- Spring的声明式事务管理

## 2. 概念介绍

### 2.1. 事务回顾

* **什么式事务：**

事务指的就是逻辑上一组操作，这组操作要么全部成功，要么全部失败。

* **事务：**

* **一起成功，一起失败**

* **事务的特性：**

1. 原子性、一致性、隔离性、持久性

1. 原子性是指事务是一个不可分割的工作单位。事务中的操作要命全部发生，要么全都不发生

2. 一致性指事务前后数据的完整性必须保持一致

3. 隔离性指多个用户并发访问数据库时，一个用户的事务不能被其他用户的事务所干扰，多个并发事务之间数据要相互隔离

4. 持久性是指一个事务一旦被提交，他对数据库的改变就是永久性的，及时数据库发生故障也不应该对齐有任何影响。



## 3. 事务API介绍

### 3.1. 接口介绍

PlatformTransactionManager 事务管理器

TransactionDefinition 事务定义信息（隔离、传播、超时、只读）

TransactionStatus 事务具体运行状态

### 3.2. PlatFormTRansactionManager接口介绍

* Spring为不同的持久化框架提供了不同的PlatformTransactionManager接口实现

事务 | 说明 
---------|----------|---------
 org.springframework.jdbc.dataSource.DataSourceTransacrion | 使用Spring Jdbc或ibatis进行持久化数据时使用
 org.springframework.orm.hibernate3.HIbernateTransactionManager | 使用Hibernate进行持久化数据时使用 
 org.springframework.orm.jpa.JpaTransactionManager | 使用Jpa进行持久化时使用
 org.springframework.jdo.JdoTransactionManager | 当持久化机制为JDo时使用
 org.springframework.transaction.jta.JtaTransactionManager | 使用一个jta实现来管理事务，在一个事务跨域多个资源时使用


### 3.3. TranscationDefinition定义事务隔离级别

**脏读：**

一个事务读取了另一个事务改写，但还未提交的数据，如果这些数据被会滚，则读到的数据时无效的。

**不可重复读：**

在同一个事务中，多次读取同一个数据返回的结果有所不同。

**幻读：**

一个事务读取了几行记录，另一个事务插入一些记录，幻读就发生了。再后来的查询中，第一个事务就会发现原来的记录。

隔离级别 | 含义
---------|----------
 DEFAULT | 使用后端数据库默认的隔离级别（spring中的选择源） 
 READ UNCOMMITED | 允许读取还未提交的数据，可能导致脏，幻，不可重复读 
 READ COMMITED | 允许在并发事务已经提交后读取，可防止脏读，但幻，不可重复读任可发生
 SERIALIZABLE | 完全服从ACID的隔离级别，确保不发生脏、幻，不可重复读。在所有隔离级别中式最慢的。是典型的通过完全锁定在事务中设计的数据表来实现。 


### 3.4. TransactionDefinition定义事务传播行为


事务传播行为类型 | 说明 
---------|----------
 propagation_required        | 不存在则新建
 propagation_requires_new t  | 若有事务存在，挂起当前事务
 propagation_nested          | 如果当前事务存在，则嵌套事务执行

### 3.5. TransactionStatus接口介绍

## 4. 转账环境搭建

### 4.1. 转账环境的搭建
* spring支持两种方式事务管理
> - 编程式事务管理
>> * 在实际应用中很少使用
>> * 通过TransactionTemplate手动管理事务
> - 使用xml配置声明式事务
>> * 开发中推荐使用（代码入侵性最小）
>> * Spring的声明式事务是通过AOP实现的。

## 5. 编程式事务管理

### 5.1. 编程式事务管理

## 6. 声明式事务管理

### 6.1. 基于TransactionProxyFacotryBeand的方式

### 6.2. 基于AspectJ的xml方式

### 6.3. 基于注解的方式

## 7. 课程总结