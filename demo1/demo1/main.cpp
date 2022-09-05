#include <thread>
#include <iostream>
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