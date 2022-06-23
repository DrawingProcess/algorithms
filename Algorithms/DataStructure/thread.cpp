#include <iostream>
#include <thread>

void func1()
{
    std::cout << "[T1] I will be dead\n";
}

void func2(int const i)
{
    std::cout << "[T2] I will be dead after {} seconds\n";
    std::this_thread::yield();
    std::this_thread::sleep_for(std::chrono::seconds(i));
    std::cout << "[T2] now I am dead\n";
}

int main()
{
    std::thread t1(func1);
    std::thread t2(func2, 5);
    std::thread t3([]()
                { std::cout << "[T3] I am lambda thread\n"; });

    t1.detach();
    t2.detach();
    t3.detach();

    return 0;
}