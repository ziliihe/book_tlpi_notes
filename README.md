# book_tlpi_notes

[the Linux programming interface](https://man7.org/tlpi/)

[amazon](https://www.amazon.com/Linux-Programming-Interface-System-Handbook/dp/1593272200)


## notes
### chapter01 History and Standards
The history of the Unix, most content can also see in the book -- [the art of Unix programming](https://www.amazon.com/UNIX-Programming-Addison-Wesley-Professional-Computng/dp/0131429019)(chapter01 ~ chapter02).

In addition to the POSIX's history, blow:

![Posix history](img/posix_history.png)
### chapter02 Fundamental Concepts
#### 2.1 The kernel
The Kernel refers to the central software that manages and allocates computer resources(CPU, RAM and devices), This also refers to the operating systems.

The kernel's tasks:
1. **Process Schedules**: every process needs CPU and memory to process its tasks. The kernel process scheduler handles the situation like multitasking.
2. **Memory Management**: process has isolation. They can't read or modify other processes' memory, also they can't do these things to the kernel. Keeping some memory to reduce the memory requirements is necessary(maybe it is the cache).
3. **Provision of a file system**: files operations and records.
4. **Creation and Termination of processes**: The kernel can load a new program into memory, providing it with resources(CPU, memory and files). After the termination of processes, the kernel releases the resources.
5. **Access of devices**: The kernel access the devices like mice, keyboards and screens for input and output.
6. **Networking**: The kernel as the agent of the user processes, receives and transmits network messages. Routing network packages.
7. **System call(api)**: Processes can request the kernel to perform various tasks.


内核态和用户态: 
1. 硬件指令允许从一个状态转换到另一个状态
2. 两种状态是隔离的，异常访问会触发硬件异常
3. 内核会干预所有事情，比如一个进程创建另一个进程，一个进程创建一个管道，将数据写到一个文件，事实上就是进程请求内核完成这样的工作，间接性的

#### 2.2 The Shell
命令解释器。bash = `Bournel again shell`, sh = `Bourne shell`

#### 2.3 用户和分组
+ 用户：在`/etc/passwd`文件中记录，用户名，工作目录和使用`shell`
+ 分组：在`/etc/group`文件中，以分号分隔
+ 超级用户：id -- `0`, login name -- `root`

#### 2.4 目录层级，目录， 文件和链接
大致如图：

![directory hierarchy](img/directory_hierarchy.png)

1. 最高一级是`/`--根目录
2. 文件类型：`regular`, `plain`, `devices`, `pipe`, `sockets`, `目录`和`符号链接`
3. `/..` == `/`
4. 符号链接是文件或者目录的别名，指向的文件不存在是一个悬挂链接(dangling link)
5. 文件名可以最多`255`个字符
6. 路径名称：相对路径和绝对路径
7. 当前工作目录，每个进程都需要
8. 权限和所属，每个文件有权限标识(rwx， 读/写/执行)，都有所属用户和分组，文件夹同
9. 文件 `I/O` 模型， Unix, file -- `end-of-file`
10. 文件描述符(file descriptor), I/O 系统指的是使用文件描述符打开文件，通常是一个非负的整数(通常有点小), `open()`函数。0--标准输入(stdin)，1--标准输出(stdout)，2--标准错误(stderr)

熟悉`stdio`阅读[APUE 3rd](https://www.amazon.com/Advanced-Programming-UNIX-Environment-3rd/dp/0321637739)

#### 2.5 程序
1. 源码 -> 编译 -> 链接 -> 程序（二进制机器语言）
2. 过滤器程序：如 cat, grep, sed等
3. c 程序读取命令行参数，`int main(int argc, char *argv[])`， argc 是参数个数，argv[0] 是程序名自身
4. 进程是在运行程序的实例，执行程序：内核将程序代码加载进`虚拟内存`, 给程序变量分配空间，更新内核对进程的记录信息的数据结构。在内核的视角看，资源的生命周期视进程的需求或者综合的系统需求来确定。进程终止，资源释放可让其他进程使用。
5. 进程逻辑上是分段的(segments)：I. 指令；II. 数据；III. 堆(heap)，动态分配额外内存；VI. 栈(stack)，可收缩内存，供函数调用，返回，局部变量等