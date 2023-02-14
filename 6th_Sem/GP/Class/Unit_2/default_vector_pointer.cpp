#include <vector>
#include <string>
#include <iostream>
#include <cstring>

using namespace std;

// class MyString {
//     private:
//         vector<char> m_data;
    
//     public:
//         MyString() {} //Empty constructor

//         void assign(const char *str) {
//             m_data.clear();
//             m_data.insert(m_data.end(), str, str + strlen(str));
//             m_data.push_back('\0');
//         }

//         const char *c_str() const {
//             return &m_data[0];
//         }
// };

template <typename Whole, typename Part>
class MyString {
    private:
        vector<Part> m_data;
    
    public:
        MyString() {} //Empty constructor

        void assign(const Whole *str, size_t size) {
            m_data.clear();
            m_data.insert(m_data.end(), str, str + size);
            m_data.push_back('\0');
        }

        const char *c_str() const {
            return &m_data[0];
        }
};

int main() {
    MyString<char, char> my_string;
    cout << "Before assignment: " << (my_string.c_str() == nullptr ? "nullptr" : "not nullptr") << endl;

    my_string.assign("Hello", 5);

    cout << "After assignment: " << my_string.c_str();

    return 0;
}
