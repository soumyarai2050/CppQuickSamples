#include <chrono>
#include <iostream>
#include <unistd.h>

int main()
{
    auto start = std::chrono::high_resolution_clock::now();
    sleep(2);
    auto end = std::chrono::high_resolution_clock::now();
    //assume deltaTime < 1 ms
    auto deltaTime = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    std::cout << "2 sec is : " << deltaTime;
    return 0;
}