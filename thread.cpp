#include<iostream>
#include<thread>
#include<mutex>

using namespace std;

mutex mtx;
int shared_counter = 0;
void incriment() {
    for (auto i= 0 ; i<5; i++) {
        mtx.lock(); // lock the mutex
        ++shared_counter;
        cout << "Thread " << this_thread::get_id() << " incremented the counter value by 1.\n";
        mtx.unlock();
    }
}

int main() {
    thread t1(incriment);
    thread t2(incriment);
    t1.join();
    t2.join();
    return 0;
}