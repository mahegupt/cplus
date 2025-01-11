#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
using namespace std;
const int MAX_ITEMS = 10;  // Maximum items to produce and consume

class ProducerConsumer {
private:
    int produced_count = 0;
    int consumed_count = 0;
    queue<int> buffer;            // Shared buffer
    mutex mtx;                    // Mutex to protect shared buffer
    condition_variable cv;        // Condition variable for synchronization
    const int MAX_PRODUCTION;
    const int MAX_BUFFER;
    bool done = false; //Use to signal termination of production and consumption.

public:
    static int count;
    ProducerConsumer(int max_buffer, int max_prod): MAX_PRODUCTION(max_prod), MAX_BUFFER(max_buffer) {}

    // Producer function
    void producer() {       
        while (true) {
            unique_lock<mutex> lock(mtx);  // Lock the mutex

            // Wait if the buffer is full
            cv.wait(lock, [this]() { return buffer.size() < MAX_BUFFER; });

            //Check is max production count limit hit or not;
            if(produced_count >= MAX_PRODUCTION) {
                done = true;
                cv.notify_all();
                break;
            }
            ++produced_count;
            // Produce an item and add it to the buffer
            buffer.push(produced_count);
            cout << "Produced: " << produced_count << endl;

            // Notify the consumer
            cv.notify_one();
            lock.unlock();
            // Simulate production time
            this_thread::sleep_for(chrono::milliseconds(500));
        }
    }

    // Consumer function
    void consumer() {
        while (true) {
            unique_lock<mutex> lock(mtx);  // Lock the mutex

            // Wait if the buffer is empty
            cv.wait(lock, [this]() { return !buffer.empty() || done; });

            if (!buffer.empty()) {
                // Consume an item from the buffer
                int value = buffer.front();
                buffer.pop();
                cout << "Consumed: " << value << endl;
                ++consumed_count;
                // Notify the producer
                cv.notify_one();
                lock.unlock();
                // Simulate consumption time
                this_thread::sleep_for(chrono::milliseconds(800));
            } else if (done) {
                break;
            }
        }
    }
    void max_counter() {
        cout << "Max produced is " << produced_count << " max consumed is " << consumed_count << endl;
    }
};



int main() {
    const int max_buffer = 5;
    const int max_production = 20;

    ProducerConsumer pc(max_buffer, max_production);

    // Create producer and consumer threads
    thread producerThread(&ProducerConsumer::producer, &pc);
    thread consumerThread(&ProducerConsumer::consumer, &pc);

    // Join the threads (this program runs indefinitely)
    producerThread.join();
    consumerThread.join();
    pc.max_counter();
    return 0;
}
