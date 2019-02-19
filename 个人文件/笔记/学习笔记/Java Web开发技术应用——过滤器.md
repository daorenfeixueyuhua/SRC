# **Java Web开发技术应用——过滤器**
## **1. 过滤器简介**

### **1.1. Java web过滤器简介**
过滤作用，对从客户端向服务器发送的请求进行过滤，也可以对服务器返回的响应进行处理，可以改变request和修改response。Filter不是一个Servlet，它不可能产生一个response。但是可以在一个request到达servlet之前预处理request，也可以在response离开servlet后处理response。实际上，filter时客户端与servlet之间的一个传递者，且可以对要传递的内容进行修改。

**注意：** 过滤器是用来拦截请求和响应的，不能产生响应，而servlet是用来处理 请求并产生响应的。

## **2. 过滤器的工作原理和生命周期**
### **2.1.过滤器的工作原理**
* 当客户端发生请求后，在`HttpServletRequest`到达`Servlet`之前，过滤器拦截客户端的`HttpServletRequest`
* 根据需要检查HttpServletRequest，也可以修改HttpServletRequest头和数据。
* 在过滤器中调用doFilter方法，对请求进行放行。
* 在HTTP ServletResponse到达客户端之前，对HttpServletResponse进行拦截。
* 可以检查或修改HttpServletResponse。
* 最后HTTP Servlet Response到达客户端。

### 2.2.Filter的生命周期
**Filter的创建和销毁都又web服务器进行控制**

* 服务器启动时，web服务器创建Filter实例化对象，调用init()方法，完成对象初始化，filter只创建一次，init方法也调用一次
* 拦截到请求时，执行foFilter方法，可执行多次。
* 服务器关闭时，web服务器兄安徽Filter的实例对象。


## 3. 第一个过滤器实例
* init()方法：初始化参数，在创建Filter是自动调用。可以配置初始化参数
* doFilter()方法：对请求和响应进行处理。
* destroy()方法：在销毁Filter是调用


## 4. 过滤器链
一组过滤器对某些资源进行拦截是，这组过滤器就成为过滤器链。过滤器的拦截顺序与<filter-mapping>有关。


## 5. 过滤器分类
**Servlet 2.5:**
* **REQUEST:** 用户直接访问页面时，web容器将会调用过滤器
* **FORWARD:** 目标资源时通过RequestDisapatcher的forward时，该过滤器将被调用
* **INCLUDE:** 目标资源时通过RequestDispatcher的include方法调用时，该过滤器将被调用
* **ERROR:** 目标资源时通过申明时异常处理机制调用时，该过滤器将被调用

## 6. 过滤器应用

## 7. 总结