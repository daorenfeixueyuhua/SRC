基于filter设计权限管理系统

对象：

resource
privilege
role
user

relation:

```txt
privilege---> resource
    1             n

role ----> privilege
    n             n

role <--------> user
    n             n
```

domain:

```java
class Privilege{
    private String id;
    private String name; // 添加分类...的权限
    private String description;
}

class Resource {
    private String id;
    private String uri; // /day20/Servlet1
    private String description;
    private Privilege privilege;
}

class Role {
    private String id;
    private String name;
    private String description;
    private Set<Privilege> privileges = new HashSet<Privilege>();
}

class User{
    private String id;
    private String username;
    private String password;
    private String description;
    private Set<Role> roles = new HashSet<Role>();
}

```