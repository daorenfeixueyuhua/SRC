# **Python中除法那些坑**

最近刷了一个cf题目，被python中的出发机制坑的不要不要的。
这是链接:

## **python中//和/的区别与使用**

    a // b 会获取值的整数部分，小数部分会丢失
    a / b 会返回完整的值
    举个栗子：
    5 // 2 = 2
    5 / 2 = 2.5

## **那么问题来了? int(a/b) 和 a//b 的区别在哪里呢？**

    例1：
    int(7/3)=2
    7//3=2

既然如此讨论它们意义在上面地方呢？看看例二

    例二:
    int(999999999999999997/5)=200000000000000000
    999999999999999997//5=199999999999999999

