#ifndef TLPI_HDR_H
#define TLPI_HDR_H

#include <sys/types.h>   /* 类型定义 */
#include <stdio.h>       /* 标准输入输出 */
#include <stdlib.h>      /* 通用库函数原型， 包括 EXIT_SUCCESS EXIT_FAILURE 常数 */
#include <unistd.h>      /* 许多系统调用的原型 linux */
#include <errno.h>       /* 声明 errno 和定义错误的常数 */
#include <string.h>      /* 字符串处理函数 */

#include "get_num.h"
#include "error_functions.h"

typedef enum {FALSE, TRUE} Boolean;


#define min(m, n) ((m) < (n) ? (m) : (n))
#define max(m, n) ((m) > (n) ? (m) : (n))

#endif