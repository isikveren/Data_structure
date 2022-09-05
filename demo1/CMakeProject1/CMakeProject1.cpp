// CMakeProject1.cpp: 定义应用程序的入口点。
//
#include "CMakeProject1.h"
#include <thread>

void work()
{

    std::cout << "do some work..." << std::endl;
}
int main()
{
    std::thread worker(work);

    worker.join();
    std::cout << "main thread" << std::endl;
    return 0;
}