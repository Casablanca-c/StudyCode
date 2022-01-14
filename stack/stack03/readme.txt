stack03 :
这是一个带有范围检查功能的栈的简单实现
通过增加结构体成员来实现
typedef struct 
{
    int top;
    const int size;
    int* const pBuf;
	 
	// add for range check
    const bool RangCheckFlag;
    const int min;
    const int max;
} Stack;


在linux下执行以下命令编译、运行
$ gcc test.c stack.c -o test.out
& ./test.out
