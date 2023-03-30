#include<atomic>
#include<iostream>
#include<stdexcept>

template<typename T, size_t N>
struct limited_instances {
    static std::atomic<size_t> count;
        limited_instances() {
        if (count >= N) {
            throw std::logic_error("Too many instances");
            ++count;
        }
    }
    ~limited_instances() {--count;}

    virtual void draw() = 0;
};

template<typename  T, size_t N>
std::atomic<size_t> limited_instances<T, N>::count = 0;

struct excalibur : limited_instances<excalibur, 1> {
    void draw() override {
        std::cout << "Excalibur" << std::endl;
    }
};

struct book_of_magic : limited_instances<book_of_magic, 3> {
    void draw() override {
        std::cout << "Book of Magic" << std::endl;
    }
};

int main() {
    excalibur e1;
    book_of_magic b1;
    book_of_magic b2;
    book_of_magic b3;
}