# book_tlpi_notes

[the Linux programming interface](https://man7.org/tlpi/)

[amazon](https://www.amazon.com/Linux-Programming-Interface-System-Handbook/dp/1593272200)

![tlpi](img/TLPI-front-cover.png)
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

#### 2.5 文件 I/O 模型
1. 文件 `I/O` 模型， Unix, file -- `end-of-file`
2. 文件描述符(file descriptor), I/O 系统指的是使用文件描述符打开文件，通常是一个非负的整数(通常有点小), `open()`函数。0--标准输入(stdin)，1--标准输出(stdout)，2--标准错误(stderr)
3. 熟悉`stdio`阅读[APUE 3rd](https://www.amazon.com/Advanced-Programming-UNIX-Environment-3rd/dp/0321637739)

#### 2.6 程序
1. 源码 -> 编译 -> 链接 -> 程序（二进制机器语言）
2. 过滤器程序：如 cat, grep, sed等
3. c 程序读取命令行参数，`int main(int argc, char *argv[])`， argc 是参数个数，argv[0] 是程序名自身

#### 2.7 进程
1. 进程是在运行程序的实例，执行程序：内核将程序代码加载进`虚拟内存`, 给程序变量分配空间，更新内核对进程的记录信息的数据结构。在内核的视角看，资源的生命周期视进程的需求或者综合的系统需求来确定。进程终止，资源释放可让其他进程使用。
2. 进程逻辑上是分段的(segments)：I. 指令；II. 数据；III. 堆(heap)，动态分配额外内存；VI. 栈(stack)，可收缩内存，供函数调用，返回，局部变量等
3. 进程创建和程序执行：进程可以使用`fork()`系统调用创建新的进程。调用者-->父进程，新进程-->子进程。内核通过弄一份父进程的副本生成子进程。指令(text)在内存中被两个进程共享
4. `execve()`调用加载并完全执行一个新的程序，会将原先进程的所有都会重新被替换。
5. 进程id--pid，父进程id--ppid
6. 进程退出`exit()`，或者`kill`信号，程序结束状态`0`代表成功，非0代表一些错误发生。
7.  进程管理用户id和分组id，标识进程所属
8.  守护进程(daemon processes)，是长期存在的，后台运行的
9.  环境变量列表，用户空间内存。子进程在`fork()`生成之后，也会继承父进程的环境变量列表，这样也是一种父进程的子进程间的通信，而使用`exec()`的新进程生成，要么继承旧的进程的环境变量列表，要么是`exec()`指定使用新的
10. 资源限制：`setrlimit()`系统调用设置上限。`soft limit`: 限制进程可能消耗的资源；`hard limit`设置上限，`soft limit`的调整不能超过此限制。`unprivileged`进程的`soft limit`自动调整范围可能是`0 ~ hard limit`，右边是开区间。`fork()`生成子进程，自动继承父进程的限制配置；资源限制可以使用`ulimit`调整。

#### 2.8 内存映射
1. `mmap()`系统调用在调用的进程的虚拟地址空间，创建新的内存映射
2. 第一部分：将文件映射到进程虚拟内存区域
3. 第二部分：匿名的映射没有任何文件，映射的页初始化为 0
4. 子进程和父进程共享同一个文件映射
5. 基于4，映射是`private`，不会对底层文件有影响(not carried through)，对其他进程不可见
6. 基于4，映射是`shared`，会对底层文件有影响(not carried through)，对其他进程可见
7. 内存映射作用：text 分段，分配新的内存，文件I/O，进程间通信（shared mapping)

#### 2.9 静态和动态库
1. 静态库是编译后的结构化的接口对象，通过静态链接器链接到可执行文件，有修改只需要将可执行文件重新链接静态库文件即可，静态库编译时是需要拷贝库到目标文件的，每个程序都要有一份静态库的拷贝
2. 动态库是在程序运行时通过动态链接器来解决程序的对库函数的调用操作，所有使用此库的进程共享一份拷贝


#### 2.10 进程间通信(IPC)和同步(Synchronization)
1. 信号(signals), 事件发生
2. 管道(pipes), `|`，进程间数据传递，先进先出(FIFO)
3. 套接字(sockets)，进程间数据传递，或者不同主机的网络数据传输
4. 文件锁定(file locking)
5. 消息队列(message queues)
6. semahpores，进程同步动作
7. 共享内存，多个进程共享同一块内存区域，当一个进程更新内容是，其他进程立即可见更动

#### 2.11 信号
1. 信号也叫`软件中断`
2. 整数，名称`SIGxxxx`
3. 内核，另一个进程，或者进程自身发送信号给进程
4. 内核发送信号给进程：用户发送中断`Ctrl C`
5. 内核发送信号给进程：一个进程的子进程终止
6. 内核发送信号给进程：进程设置的时钟过期
7. 内核发送信号给进程：进程试图访问无效内存地址
8. 进程收到信号行为：忽略
9. 进程收到信号行为：killed
10. 进程收到信号行为：暂停执行，等待恢复
11. 当进程为阻塞状态时(block)收到信号，信号状态仍然会维持等待(pending)，直到进程状态是非阻塞

#### 2.12 线程
1. 设想线程为多个进程，共享相同的虚拟内存，其他的一些属性也是一样的
2. 每个线程执行相同的代码，共享相同的数据和堆空间(heap)
3. 每个线程有自己的栈(stack)，包括局部变量存储，函数调用，链接信息等
4. 每个线程可以通过他们共享的全局变量通信
5. 线程api提供**条件变量**和**mutexes(互斥锁)**，通信或者同步行为和他们使用的共享变量
6. 可以使用IPC和同步机制
7. 多处理器可以实现并行处理
8. 共享数据，多线程较为方便
9. 但是这里[UNIX编程艺术](https://book.douban.com/subject/11609943/) 7.1 表示--`线程不是降低而是提高了全局复杂度，除非万不得已，尽量避免使用线程。`

#### 2.13 进程分组和shell工作控制
1. 在有工作控制(job-control)功能的shell中，所有的在管道流程中的进程，都被放进一个新的进程分组或者工作中


#### 2.14 会话，控制终端和控制进程
1. 一个会话`sessions`是一个进程组集合(jobs)，有相同的进程标识符，创建`session`的进程成为`session leader`，进程id编程`session ID`
2. `session`主要被`job-control`shell使用，1中所述进程就是shell
3. `session`有关联的控制终端
4. 打开控制终端，`session leader`变成控制进程，如果推出终端，会收到`SIGHUP`信号


#### 2.15 伪终端
1. 一对互联的虚拟设备(主，从)
2. 双向进程间通信
3. 从设备提供接口，表现得像一个终端
4. 搞不懂

#### 2.16 日期和时间
1. unix 开始时间是`1970-01-01 00:00:00` -- UTC
2. 进程时间（CPU时间），自从启动计， 系统CPU时间（内核态），用户CPU时间（用户态）。
3. `time`命令显示真实时间

#### 2.17 客户端 / 服务端架构
1. 客户端象服务的请求服务，接收服务端回复消息
2. 服务端检查客户端请求内容，根据请求执行相应的合理动作，回复消息给客户端
3. 服务器端封装各种可用的服务供客户端访问


#### 2.18 实时
1. 对输入信息的快速响应的应用
2. 实时可以指在一定可接受的时间范围内做到快速响应
3. 需要考虑可能的冲突问题
4. 本书讨论的标准`POSIX.1b`，Linux所支持的标准


#### 2.19 `/proc`文件构成
1. linux 的文件目录`/proc`
2. 虚拟的文件系统，让内核看起来像是正常的文件系统
3. /proc/PID，每个进程`pid`命名的文件(`ps -ef | grep xxxx`)，可以查看运行在系统上面的进程信息
4. 进程是能在/proc下面做修改的


