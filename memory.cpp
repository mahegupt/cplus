#include <iostream>
#include <memory>

int main() {
    // Create a unique_ptr managing a dynamically allocated int
    std::unique_ptr<int> ptr1 = std::make_unique<int>(10);

    // Access the value
    std::cout << "Value: " << *ptr1 << std::endl;
    {
        // Transfer ownership using std::move
        std::unique_ptr<int> ptr2 = std::move(ptr1);

        // ptr1 is now null
        if (!ptr1) {
            std::cout << "ptr1 is null after move." << std::endl;
        }
        std::cout << "Value: " << *ptr2 << std::endl;
    }
    std::cout << "Value: " << *ptr1 << std::endl;
    return 0; // ptr2 deletes the allocated memory automatically
}