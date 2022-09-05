#include <thread>
#include <iostream>
#include <vector>
void work(int i)
{

    std::cout << "do some work...arg: "
              << i
              << " thread_id: "
              << std::this_thread::get_id()
              << std::endl;
}
int main()
{
    // std::thread worker(work, 10);
    // worker.detach();
    // if (worker.joinable())
    // {
    //     worker.join();
    // }
    std::vector<std::thread> workers;
    for (int i = 0; i < 12; i++)
    {
        workers.push_back(std::thread(work, i));
    }
    for (int i = 0; i < 12; i++)
    {

        workers[i].join();
    }

    std::cout << "main thread id: "
              << std::this_thread::get_id() << std::endl;
    return 0;
}