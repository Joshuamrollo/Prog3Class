#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
int counter = 0;
std::condition_variable positiveCounterFinished;
bool firstCounterDone = false;

void positiveCounter() {
    for(; counter < 20; counter++) {
        std::cout << "increasing count: " << counter << std::endl;
    }
    std::cout << "increasing counter finished: " << counter << std::endl;

    std::lock_guard<std::mutex> lock(mtx);
    positiveCounterFinished.notify_all();
    firstCounterDone = true;
}

void negativeCounter() {
    std::unique_lock<std::mutex> lock(mtx);
    positiveCounterFinished.wait(lock, [] { return firstCounterDone; });

    for(; counter > 0; counter--) {
        std::cout << "decreasing count: " << counter << std::endl;
    }
    std::cout << "decreasing counter finished: " << counter << std::endl;
}

int main() {
    std::thread countThread1(positiveCounter);
    std::thread countThread2(negativeCounter);

    countThread1.join();
    countThread2.join();

    return 0;
}