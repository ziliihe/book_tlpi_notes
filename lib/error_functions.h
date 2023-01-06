#ifndef ERROR_FUNCTIONS_H
#define ERROR_FUNCTIONS_H

void errMsg(const char *format, ...); /* 打印消息到标准错误 */

#ifdef __GNUC__
    #define NORETURN __attribute__ ((__noretrun__))
#else
    #define NORETURN
#endif


void errExit(const char *format, ...) NORETURN; /* 调用 exit() 结束程序*/

void err_exit(const char *format, ...) NORETURN; /* 1. 打印错误信息之前不刷新标准输出； 2. 调用_exit()结束程序； 对使用库函数创建的子进程因为错误退出的处理来说比较有用 */

void errExitEN(int errnum, const char *format, ...) NORETURN;

void fatal(const char *format, ...) NORETURN;

void usageErr(const char *format, ...) NORETURN;

void cmdLineErr(const char *format, ...) NORETURN;

#endif