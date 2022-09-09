//没有阻塞，谁就绪谁占用cout
// https://www.icourse163.org/learn/NEU-1002927012?tid=1450212480#/learn/content?type=detail&id=1215222473&cid=1249137510
//上面链接的代码还未执行

#include <thread>
#include <iostream>
#include <stdlib.h>
void work1(int i)
{
    for (; i < 5; i++)
    {
        std::cout << "do 1 work...arg: "
                  << i << std::endl;
        _sleep(200);
    }
}
void work2(int i)
{
    for (; i < 5; i++)
    {
        std::cout << "do 2 work...arg: "
                  << i << std::endl;
        _sleep(400);
    }
}
int main()
{
    std::cout << "CreateThread"
              << std::endl;
    std::thread worker1(work1, 0);
    _sleep(200);
    std::thread worker2(work2, 0);
    if (worker1.joinable())
    {
        worker1.join(); //中断当前进程执行子进程
    }
    if (worker2.joinable())
    {
        worker2.join();
    }
    std::cout << "MainThread"
              << std::endl;
    return 0;
}