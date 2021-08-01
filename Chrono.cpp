#include <chrono>
#include <iostream>
#include <unistd.h>

int main()
{
    std::chrono::milliseconds time_to_sleep = 100ms;

    auto start = std::chrono::high_resolution_clock::now();
    sleep(2);
    auto end = std::chrono::high_resolution_clock::now();
    //assume deltaTime < 1 ms
    //replace below nanoseconds with std::chrono::microseconds or std::chrono::milliseconds if needed
    auto deltaTime = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    std::cout << "2 sec is : " << deltaTime;
    return 0;
}