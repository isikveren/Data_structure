typedef struct
{
    int count;         //资源计数 非负值：当天前的空闲资源数 负值：其绝对值为当前等待临界区的进程数
    Pointer_PCB queue; //等待队列，由等待使用资源的进程标识构成
} Semaphore;

Semaphore s;