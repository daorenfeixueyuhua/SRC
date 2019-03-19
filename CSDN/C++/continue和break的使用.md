# **Continue和break的区别使用**

在c++中想要结束循环，则有两种方式，一是循环自然结束；二是使用关键字**continue**和**break**结束循环，而两个关键字的使用是有区别的：

**continue : 结束此次循环，直接进入下一次循环；**

**break : 循环完全结束；**

举个栗子：

```c++
int i;
for(i = 0;i<10;++i){
    if(i==5){
        cout << "i == 5" << endl;
        continue; // 会跳到第2行
    }
}
cout << i << endl; // 此时i为10

int j;
for(j=0;i<10;++j){
    if(j==5){
       cout << "j == 5" << endl;
       break; // 会跳到第17行
    }
}
cout << j << endl; // 此时j为5

```