# **1. SpringBoot简介**

# **2. SpringBoot 入门**

## **2.1 环境准备**

## **2.2 起步依赖**

### **2.2.1 创建一个maven工程**

### **2.2.2 添加依赖**

**pom.xml:**
```xml
<?xml version="1.0" encoding="UTF-8"?>
<project xmlns="http://maven.apache.org/POM/4.0.0" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
    xsi:schemaLocation="http://maven.apache.org/POM/4.0.0 https://maven.apache.org/xsd/maven-4.0.0.xsd">
    <modelVersion>4.0.0</modelVersion>

    <groupId>com.example</groupId>
    <artifactId>myproject</artifactId>
    <version>0.0.1-SNAPSHOT</version>

    <!-- Inherit defaults from Spring Boot -->
    <parent>
        <groupId>org.springframework.boot</groupId>
        <artifactId>spring-boot-starter-parent</artifactId>
        <version>2.2.0.BUILD-SNAPSHOT</version>
    </parent>

    <!-- Add typical dependencies for a web application -->
    <dependencies>
        <dependency>
            <groupId>org.springframework.boot</groupId>
            <artifactId>spring-boot-starter-web</artifactId>
        </dependency>
    </dependencies>

    <!-- Package as an executable jar -->
    <build>
        <plugins>
            <plugin>
                <groupId>org.springframework.boot</groupId>
                <artifactId>spring-boot-maven-plugin</artifactId>
            </plugin>
        </plugins>
    </build>

    <!-- Add Spring repositories -->
    <!-- (you don't need this if you are using a .RELEASE version) -->
    <repositories>
        <repository>
            <id>spring-snapshots</id>
            <url>https://repo.spring.io/snapshot</url>
            <snapshots><enabled>true</enabled></snapshots>
        </repository>
        <repository>
            <id>spring-milestones</id>
            <url>https://repo.spring.io/milestone</url>
        </repository>
    </repositories>
    <pluginRepositories>
        <pluginRepository>
            <id>spring-snapshots</id>
            <url>https://repo.spring.io/snapshot</url>
        </pluginRepository>
        <pluginRepository>
            <id>spring-milestones</id>
            <url>https://repo.spring.io/milestone</url>
        </pluginRepository>
    </pluginRepositories>
</project>
```

## **2.3 变更jdk版本**

## **2.4 引导类**

编写springboot的启动类（引导类）：

@SpringBootAppliction表明当前类是springboot的引导类

使用SpringApplication.run(Application.class, args)启动运行

扫描当前包以及子包

```Java
@SpringBootApplication
public class Example {
    public static void main(String[] args) {
        SpringApplication.run(Example.class, args);
    }
}
```


## **2.5 入门程序**

```java
@RestController
@RequestMapping("/index")
public class HelloController {
    @RequestMapping("/hello")
    public String hello(){
        return "hello, Spring Boot";
    }
}
```

### **2.5.1 原来的实现**

### **2.5.2 SpringBoot的实现**

## **2.6 热部署**

## **2.7 项目打包**

在增加pom.xml中使用：

```xml
<build>
    <plugins>
        <plugin>
            <groupId>org.springframework.boot</groupId>
            <artifactId>spring-boot-maven-plugin</artifactId>
        </plugin>
    </plugins>
</build>
```

打包命令：mvn package

运行命令：java -jar target/myproject-0.0.1-SNAPSHOT.jar

# **3. SpringBoot整合**

## **3.1 整合SpringDataJpa**

### **3.1.1 需求**
### **3.1.2 环境准备**

#### **3.1.2.1 建数据库**

```sql
-- auto-generated definition
create table sys_user
(
  user_id       bigint(32) auto_increment
  comment '用户id'
    primary key,
  user_code     varchar(32) not null
  comment '用户账号',
  user_name     varchar(64) not null
  comment '用户名称',
  user_password varchar(32) not null
  comment '用户密码',
  user_state    char        not null
  comment '1:正常,0:暂停'
);

```

#### **3.1.2.2 建maven项目**
新增pom.xml
```xml
        <dependency>
            <groupId>org.springframework.boot</groupId>
            <artifactId>spring-boot-starter-data-jpa</artifactId>
        </dependency>
        <!--MySQL驱动-->
        <dependency>
            <groupId>mysql</groupId>
            <artifactId>mysql-connector-java</artifactId>
        </dependency>
```


#### **3.1.2.3 加入spring-boot配置文件**

```properties
#DB Configuration
spring.datasource.driver-class-name=com.mysql.jdbc.Driver
spring.datasource.url=jdbc:mysql://localhost:3306/dada
spring.datasource.username=root
spring.datasource.password=root


#jpa Configuration
spring.jpa.database=mysql
spring.jpa.show-sql=true
spring.jpa.generate-ddl=true
spring.jpa.hibernate.naming.implicit-strategy=org.springframework.boot.orm.jpa.hibernate.SpringImplicitNamingStrategy
```

### **3.1.3 后端实现**

#### **3.1.3.1 创建实体类**

```java
@Setter
@Getter
@Entity
@Table(name = "sys_user")
public class SysUser implements Serializable {
    @Id
    @Column(name = "user_id")
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Integer userId;
    @Column(name = "user_code")
    private String userCode;
    @Column(name = "user_name")
    private String userName;
    @Column(name = "user_password")
    private String userPassword;
    @Column(name = "user_state")
    private Character userState;
}
```

#### **3.1.3.2 创建dao**

```java
@Repository("userDao")
public interface UserDao extends JpaRepository<SysUser, Integer> {
}
```

#### **3.1.3.3 创建service**
```java
@Service
public class UserServerImpl implements UserServer {
    @Autowired
    private UserDao userDao;
    @Override
    public List<SysUser> findAllUser() {
        return userDao.findAll();
    }
}
```
#### **3.1.3.4 创建controller**
```java
@RestController
@RequestMapping("/user")
public class UserController {
    @Autowired
    private UserServer userServer;
    @RequestMapping("/findAll")
    public List<SysUser> findAllUser(){
        List<SysUser> userList = userServer.findAllUser();
        return userList;
    }
}
```
#### **3.1.3.5 创建引导类**

```java
@SpringBootApplication
public class Application {
    public static void main(String[] args) {
        SpringApplication.run(Application.class, args);
    }
}

```

## **3.2. 整合Mybatis**

### **3.2.1 加入依赖**

```xml
<!--整合mybatis-->
<dependency>
    <groupId>org.mybatis.spring.boot</groupId>
    <artifactId>mybatis-spring-boot-starter</artifactId>
    <version>1.3.2</version>
</dependency>
```
### **3.2.2 编写Mapper**

```java
@Mapper
public interface UserMapper {
    @Select("select * from sys_user where user_name = #{userName}")
    List<SysUser> findAllUser(@Param("userName") String userName);
}
```
### **3.2.3 编写Service和Controller**
```java

@Service
public class UserServerImpl implements UserServer {
    @Autowired
    private UserDao userDao;

    @Autowired
    private UserMapper userMapper;
    @Override
    public List<SysUser> findAllUser(String userName) {
        return userMapper.findAllUser(userName);
    }
}
```
```java

@RestController
@RequestMapping("/user")
public class UserController {
    @Autowired
    private UserServer userServer;
    @RequestMapping("/findAll/{userName}")
    public List<SysUser> findAllUser(@PathVariable("userName") String userName){
        List<SysUser> userList = userServer.findAllUser(userName);
        return userList;
    }
}

```
### **3.2.4 测试**

使用mybatis时实体要和数据库一致

## **3.3 整合redis**
### **3.3.1 注解方式实现添加缓存**
#### **3.3.1.1 加入依赖**
```xml
<dependency>
    <groupId>org.springframework.boot</groupId>
    <artifactId>spring-boot-starter-redis</artifactId>
    <version>1.4.7.RELEASE</version>
</dependency>
```
#### **3.3.1.2 修改引导类**
```java
//开启springboot支持缓存
@SpringBootApplication
@EnableCaching
public class Application {
    public static void main(String[] args) {
        SpringApplication.run(Application.class, args);
    }
}
```
#### **3.3.1.3 设置实现序列化接口**
#### **3.3.1.4 实现添加/删除缓存**

## **3.4 整合junit**
### **3.4.1 加入依赖**
```xml
<dependency>
    <groupId>org.springframework.boot</groupId>
    <artifactId>spring-boot-starter-test</artifactId>
    <scope>test</scope>
</dependency>
```
### **3.4.2 编写测试类**



