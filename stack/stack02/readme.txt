stack02:
stack01的实现方法中仅仅有一个栈，当我们想实现多个栈的时候就不合适了。
于是使用结构体将数据结构和代码块分离开来。这样可以方便地构造出多个栈。

在linux下执行以下命令编译、运行
$ gcc test.c stack.c -o test.out
& ./test.out
