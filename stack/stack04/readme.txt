stack04 说明:
stack03的实现方式存在以下两个问题：
1. Stack的实现臃肿：即使生成不带范围检查功能的栈，栈内也需要保存 RangCheckFlag, min, max 多余的结构体成员。浪费内存
2. 如果还想在栈内增加其他校验功能，就必须在结构体内在增加其他成员，push 函数的实现也会因为这下功能变得臃肿，
   最终导致栈越来越难以应对功能的增加。

stack04 的解决方式时将范围检查的部分从 Satck 中分离出去。  


在linux下执行以下命令编译、运行
$ gcc test.c stack.c -o test.out
& ./test.out