#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <array>
#include <chrono>
#include <random>
#include <algorithm>
#include <math.h>

#define NUM_OF_ELEMENTS pow(10, 6)

using namespace std;

template <typename T>
class Queue_Vector {
    private:
        vector<T> q;
    public:
        void enqueue(T val) {
            q.push_back(val);
        }

        T dequeue() {
            T val = q.front();
            q.erase(q.begin());
            return val;
        }
        
        bool is_empty() {
            return q.empty();
        }

        int find_element(int ele) {
            typename vector<T>::iterator it = find(q.begin(), q.end(), ele);
            if (it != q.end())
                return distance(q.begin(), it);
            return -1;
        }
};

template <typename T>
class Queue_Dequeue {
    private:
        deque<T> d;
    public:
        void enqueue(T val) {
            d.push_back(val);
        }

        T dequeue() {
            T val = d.front();
            d.pop_front();
            return val;
        }

        bool is_empty() {
            return d.empty();
        }

        int find_element(int ele) {
            typename deque<T>::iterator it = find(d.begin(), d.end(), ele);
            if (it != d.end())
                return distance(d.begin(), it);
            return -1;
        }
};

template <typename T>
class Queue_List {
    private:
        list<T> l;
    public:
        void enqueue(T val) {
            l.push_back(val);
        }

        T dequeue() {
            T val = l.front();
            l.pop_front();
            return val;
        }

        bool is_empty() {
            return l.empty();
        }

        int find_element(int ele) {
            typename list<T>::iterator it = find(l.begin(), l.end(), ele);
            if (it != l.end())
                return distance(l.begin(), it);
            return -1;
        }
};

template <typename T, int size>
class Queue_Array {
    private:
        array<T, size> a;
        // T *a = new T[size];
        int front = -1;
        int rear = -1;
    public:
        void enqueue(T val, int pos) {
            if (front == -1)
                front = 0;
            ++rear;
            a[rear] = val;
        }

        T dequeue() {
            T t;
            if (front == -1 || front > rear)
                return 0;
            t = a[front];
            ++front;
            return t;
        }

        bool is_empty() {
            if (front == rear) return true;
            else return false;
        }

        int find_element(int ele) {
            auto it = find(a.begin(), a.end(), ele);
            if (it != a.end())
                return distance(a.begin(), it);
            return -1;

            // int i = 0;
            // while (i < size && a[i] != ele) ++i;

            // if (i != size) return i;
            // return -1;

        }
};

// template <typename F>
// chrono::duration<double> insert_random_elements(F& data_struct, mt19937& gen, uniform_int_distribution<>& distr) {

//     int x;
//     auto start = chrono::steady_clock::now();
//     for (int i = 0; i < pow(10, 1); ++i) {
//         x = distr(gen);
//         cout << x << endl;
//         data_struct.enqueue(x);
//     }
//     auto end = chrono::steady_clock::now();
//     chrono::duration<double> elapsed_time = end - start;
//     return elapsed_time;
// }

int main() {
    // Setting the seed for random number generation
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(1, pow(10, 4));
    
    array<int, 4> search_elements = {7, 21, 125, 1008};

    Queue_Vector<int> q_v;
    Queue_Dequeue<int> q_d;
    Queue_List<int> q_l;
    Queue_Array<int, 1000000> q_a;
    int x, t;

    // chrono::duration<double> elapsed_vector = insert_random_elements(q_v, gen, distr);
    // cout << "Elapsed time using Vector: " << elapsed_vector.count() << endl;

    // chrono::duration<double> elapsed_dequeue = insert_random_elements(q_d, gen, distr);
    // cout << "Elapsed time using Dequeue: " << elapsed_vector.count() << endl;

    // chrono::duration<double> elapsed_list = insert_random_elements(q_l, gen, distr);
    // cout << "Elapsed time using List: " << elapsed_vector.count() << endl;

    auto start = chrono::steady_clock::now();
    cout << "---Vectors---" << endl;
    cout << "Inserting elements.." << endl;
    for (int i = 0; i < NUM_OF_ELEMENTS; ++i) {
        x = distr(gen);
        q_v.enqueue(x);
    }

    cout << endl;
    cout << "Finding elements" << endl;
    
    for (int ele: search_elements) {
        t = q_v.find_element(ele);
        if (t != -1)
            cout << "Element " << ele << " found at " << t << endl;
        else
            cout << "Element " << ele << " not found" << endl;
    }

    cout << endl;
    cout << "Deleting elements.." << endl;
    while (!q_v.is_empty()) {
        q_v.dequeue();
    }
    auto end = chrono::steady_clock::now();

    chrono::duration<double> elapsed_vector = end - start;
    cout << "Elapsed time using Vector: " << elapsed_vector.count() << endl << endl;

    start = chrono::steady_clock::now();
    cout << "---Deques---" << endl;
    cout << "Inserting elements.." << endl;
    for (int i = 0; i < NUM_OF_ELEMENTS; ++i) {
        x = distr(gen);
        q_d.enqueue(x);
    }

    cout << endl;
    cout << "Finding elements" << endl;

    for (int ele: search_elements) {
        t = q_d.find_element(ele);
        if (t != -1)
            cout << "Element " << ele << " found at " << t << endl;
        else
            cout << "Element " << ele << " not found" << endl;
    }

    cout << endl;
    cout << "Deleting elements.." << endl;
    while (!q_d.is_empty()) {
        q_d.dequeue();
    }
    end = chrono::steady_clock::now();

    chrono::duration<double> elapsed_deque = end - start;
    cout << "Elapsed time using Deque: " << elapsed_deque.count() << endl << endl;

    start = chrono::steady_clock::now();
    cout << "---Lists---" << endl;
    cout << "Inserting elements.." << endl;
    for (int i = 0; i < NUM_OF_ELEMENTS; ++i) {
        x = distr(gen);
        q_l.enqueue(x);
    }

    cout << endl;
    cout << "Finding elements" << endl;

    for (int ele: search_elements) {
        t = q_l.find_element(ele);
        if (t != -1)
            cout << "Element " << ele << " found at " << t << endl;
        else
            cout << "Element " << ele << " not found" << endl;
    }

    cout << endl;
    cout << "Deleting elements.." << endl;
    while (!q_l.is_empty()) {
        q_l.dequeue();
    }
    end = chrono::steady_clock::now();

    chrono::duration<double> elapsed_list = end - start;
    cout << "Elapsed time using List: " << elapsed_list.count() << endl << endl;

    start = chrono::steady_clock::now();
    cout << "---Arrays---" << endl;
    cout << "Inserting elements.." << endl;
    for (int i = 0; i < NUM_OF_ELEMENTS; ++i) {
        x = distr(gen);
        q_a.enqueue(x, i);
    }

    cout << endl;
    cout << "Finding elements" << endl;

    for (int ele: search_elements) {
        t = q_a.find_element(ele);
        if (t != -1)
            cout << "Element " << ele << " found at " << t << endl;
        else
            cout << "Element " << ele << " not found" << endl;
    }

    cout << endl;
    cout << "Deleting elements.." << endl;
    while (!q_a.is_empty()) {
        q_a.dequeue();
    }
    end = chrono::steady_clock::now();

    chrono::duration<double> elapsed_array = end - start;
    cout << "Elapsed time using List: " << elapsed_array.count() << endl;
}
