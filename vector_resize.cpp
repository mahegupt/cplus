#include <iostream>
#include <vector>
#include <memory>
using namespace std;

template <typename T>
struct TrackingAllocator {
    using value_type = T;

    T* allocate(std::size_t n) {
        std::cout << "Allocating " << n << " elements\n";
        return static_cast<T*>(::operator new(n * sizeof(T)));
    }

    void deallocate(T* p, std::size_t) noexcept {
        ::operator delete(p);
    }
};

int main() {
    vector<int, TrackingAllocator<int>> vec;
    for (int i = 1; i <= 10; i++) {
        vec.push_back(i);
        cout << "Size: " << vec.size() << ", Capacity: " << vec.capacity() << "\n";
    }
    return 0;
}
