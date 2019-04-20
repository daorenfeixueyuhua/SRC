# **1. Mybatis简介**

## **1.1 orm和mybatis**

### **1.1.1 ORM**
ORM的全称是Object/Realation Mapping，及对象/关系数据库映射。

### **1.1.2 基本映射方式**

1. **数据表映射**
2. **数据表的行映射对象（实例）**
3. **数据表的列（字段）映射对象的属性**

### **1.1.3 常见ORM框架**

1. **JPA**
2. **Hibernate**
3. **Mybatis**

### **1.1.4 Mybatis概述**

xxxxxxxx

## **1.2 Mybatis入门**

### **1.2.1 Mybatis下载和安装**

1. **mybatis下载：**

    mybatis管网：https://blog.mybatis.org/

2. **maven使用**

    依赖：
    ```xml
    <dependency>
        <groupId>org.mybatis</groupId>
        <artifactId>mybatis</artifactId>
        <version>3.4.6</version>
    </dependency>    
    ```

3. **案例**

    3.1. **sql文件**
    ```sql
    create table student
    (
        s_id   int auto_increment
        primary key,
        s_name varchar(20)     not null,
        s_age  int default '0' not null
    );
    ```
    3.2. **pom.xml**
    ```xml
    <?xml version="1.0" encoding="UTF-8"?>
    <project xmlns="http://maven.apache.org/POM/4.0.0"
            xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
            xsi:schemaLocation="http://maven.apache.org/POM/4.0.0 http://maven.apache.org/xsd/maven-4.0.0.xsd">
        <modelVersion>4.0.0</modelVersion>

        <groupId>com.example</groupId>
        <artifactId>mybatis01</artifactId>
        <version>1.0-SNAPSHOT</version>


        <dependencies>
            <dependency>
                <groupId>org.mybatis</groupId>
                <artifactId>mybatis</artifactId>
                <version>3.4.6</version>
            </dependency>

            <dependency>
                <groupId>junit</groupId>
                <artifactId>junit</artifactId>
                <version>4.12</version>
            </dependency>

            <dependency>
                <groupId>org.projectlombok</groupId>
                <artifactId>lombok</artifactId>
                <version>1.18.2</version>
            </dependency>
            <dependency>
                <groupId>log4j</groupId>
                <artifactId>log4j</artifactId>
                <version>1.2.17</version>
            </dependency>

            <dependency>
                <groupId>mysql</groupId>
                <artifactId>mysql-connector-java</artifactId>
                <version>8.0.12</version>
            </dependency>
        </dependencies>

        <build>
            <resources>
                <resource>
                    <directory>src/main/java</directory>
                    <includes>
                        <include>**/*.xml</include>
                    </includes>
                </resource>
            </resources>
        </build>

    </project>
    ```
    3.3 **Student.java**
    ```java
    @Setter
    @Getter
    @ToString
    public class Student {
        private Integer s_id;
        private String s_name;
        private Integer s_age;
        public Student(){};

        public Student(Integer s_id, String s_name, Integer s_age) {
            this.s_id = s_id;
            this.s_name = s_name;
            this.s_age = s_age;
        }
    }
    ```
    3.4 **mybatis-config.xml**
    ```xml
    <configuration>

        <!--mybatis配置文件日志的具体实现-->
        <settings>
            <setting name="logImpl" value="LOG4J"/>
        </settings>
        <!--环境配置-->
        <environments default="mysql">
            <environment id="mysql">
                <!--事务管理-->
                <transactionManager type="jdbc"/>
                <!--数据源配置-->
                <dataSource type="POOLED">
                    <property name="driver" value="com.mysql.cj.jdbc.Driver"/>
                    <property name="url" value="jdbc:mysql://localhost/dada?serverTimezone=GMT"/>
                    <property name="username" value="root"/>
                    <property name="password" value="root"/>
                </dataSource>
            </environment>
        </environments>
        <!--mapper配置-->
        <mappers>
            <!--如果test中出现相同包结构会报错-->
            <mapper resource="com/example/mapper/StudentMapper.xml"/>
        </mappers>
    </configuration>
    ```
    3.5 **Studentmapper.java**
    ```java
    public interface StudentMapper {
        public int addStudent(Student student);
    }
    ```
    3.6 **StudentMapper.xml**
    ```xml
    <mapper namespace="com.example.dao.StudentMapper">
        <insert id="addStudent" parameterType="com.example.domain.Student">
            insert into student(s_id, s_name, s_age) values(#{s_id}, #{s_name}, #{s_age});
        </insert>
    </mapper>
    ```

    3.7 **test**
    ```java
    public class mybatisTest {
        public static void main(String[] args) {
            SqlSession sqlSession = null;
            InputStream inputStream = null;
            Student student = new Student(9, "pengda", 19);
            try{
                // 加载mybatis配置文件
                inputStream = Resources.getResourceAsStream("mybatis-config.xml");
                try{
                    // 创建sqlSessionFactory
                    SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(inputStream);
                    sqlSession = sqlSessionFactory.openSession();
                    // 获取mapper
                    StudentMapper studentMapper = sqlSession.getMapper(StudentMapper.class);
                    studentMapper.addStudent(student);
                    sqlSession.commit();
                }catch (Exception e){
                    e.printStackTrace();
                }
            }catch (Exception e){
                e.printStackTrace();
                System.out.println("加载配置文件失败");
            }
        }
    }

    ```

    3.8 问题报错

    ```text
    错误1.
        日志：java.io.IOException:Could not find resource com/example/mapper/StudentMapper.xml
        原因：IDEA是不会编译src的java目录的xml文件，所以在Mybatis的配置文件中找不到xml文件！
        解决：
        在pom.xml中加入：
            <build>
            <resources>
                <resource>
                    <directory>src/main/java</directory>
                    <includes>
                        <include>**/*.xml</include>
                    </includes>
                </resource>
            </resources>
            </build>
    错误2：
        日志：The server time zone value 'ÖÐ¹ú±ê×¼Ê±¼ä' is unrecognized or represents more than one time zone.
        原因：
        使用的数据库是MySQL，驱动是6.0.3，这是由于数据库和系统时区差异所造成的，
        解决：
        在jdbc连接的url后面加上serverTimezone=GMT即可解决问题，如果需要使用gmt+8时区，需要写成GMT%2B8，否则会被解析为空。再一个解决办法就是使用低版本的MySQL jdbc驱动，5.1.28不会存在时区的问题。
    ```

4. **总结**

    **mybatis操作步骤**
    
    1. **编写PO和Mapper.xml**
    2. **获取SqlSessionFactory**
    3. **获取SqlSession** 
    4. **操作数据库**
    5. **关闭事务、关闭sqlSession**
                                                                              