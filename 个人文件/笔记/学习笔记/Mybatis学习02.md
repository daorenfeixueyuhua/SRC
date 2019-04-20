# **1. Mybatis基本用法**

## **1.1 Mybatis体系**

### **1.1.1 SqlSessionFactory**

1. SqlSessionFactory可用SqlSessionFactoryBuidler对象创建。
2. 其实例是存在于整个程序生命周期，所有建立使用单例模式。
3. SqlSession可有SqlsessionFactory创建

### **1.1.2 Sqlsession**

1. Sqlseesion是持久化操作的对象，类似于jdbc中的Connection
1. SqlSession常用方法
```java
int insert(String statement);// 插入方法，其参数为mapper中<insert../>的id，返回所影响的行数。

int insert(String statement, Object parameter);// ...，parameter是要插入的参数，同时是Object或Map

int update(Stirng statement);// 更新方法

int update(String statement, Object parameter);

int delete(String statement);

int delete(String statement, Object parameter);

<T> T selectOne(String statement);// 查询方法。返回执行sql查询结果的泛型方法， 通常查询结果为一条时才使用

<T> T selectOne(String statement, Object parameter);

<E> List<E> selectList(String statement);// ...， 返回查询结果的泛型对象的集合

<E> List<E> selectList(String statement, Object paramter);

<E> List<E> selectList(String statement, Object parmater, RowBounds rowBounds);// ...， RowBounds对象用于分页，属性：offset指查询页数；limit指当前页显示多少条数据。

<K, V> Map<K, V> selectMap(String statement, String mapKey); // ...， keyMap是返回数据中一个列名。结果会被封装称一个Map， key为参数mapKey, value为封装对象。

<K, V> Map<K, V> selectMap(String statement, Object parameter, String mapKey);

<K, V> Map<K, V> selectMap(String statement, Object parameter, String mapKey, RowBounds rowBounds);

void select(String statement, ResultHandler handler);// ...， ResultHandler用来处理查询返回的复杂结果集，长用于多表查询

void select(String statement, Object parameter, ResultHandler handler);

void select(String statement, Object parameter, RowBounds rowBounds, ResultHandler handler);

void commit();// 提交事务

void rollback();// 回滚事务

void close();// 关闭Sqlsession

Connection getConnection();// 返回JDBC的数据库连接对象

<T> T getMapper(Classes<T> type);// 返回mapper接口的代理对象，该对象直接关联了SqlSession， 可以直接通过该对象调用方法操作数据库， type为Mapper接口类型。

```
