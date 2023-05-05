//q3
//Write a program that implements the 2 functions - compare does 2 instance compare and bumbber gets cust_id, start_date and end_date and prints
// all transactions between start date and end date 
// 1 point for each function
#include <iostream>
#include <vector>
#include <string>

struct Sales {
    int cust_id;
    std::string product_name;
    int qty;
    double value;
    std::string date;
};

bool compare(struct Sales s1, struct Sales s2) {
    return ((s1.product_name == s2.product_name) && (s1.qty == s2.qty));
}

void bummer(int customerId, std::vector<Sales> data, std::string startDate, std::string endDate) {
    for (auto it = data.begin(); it != data.end(); ++it) {
        if (customerId == it->cust_id && it->date.compare(startDate) >= 0 && it->date.compare(endDate) <= 0) {
            std::cout << it->cust_id << " ";
            std::cout << it->product_name << " ";
            std::cout << it->qty << " ";
            std::cout << it->value << " ";
            std::cout << it->date << std::endl;
        }
    }
    // }
}

int main() {
    // Example data
    std::vector<Sales> data = {
        {1, "Apple", 10, 15.50, "2022-01-01"},
        {1, "Banana", 5, 8.25, "2022-01-02"},
        {1, "Apple", 8, 12.40, "2022-01-03"},
        {2, "Banana", 12, 10.20, "2022-01-04"},
        {2, "Apple", 6, 9.30, "2022-01-05"}
    };

    // Example usage
    Sales a = {1, "Apple", 10, 15.50, "2022-01-01"};
    Sales b = {1, "Apple", 8, 12.40, "2022-01-03"};
    std::cout << "Are sales a and b the same? " << (compare(a, b) ? "Yes" : "No") << std::endl;

    bummer(1, data, "2022-01-01", "2022-01-03");

    return 0;
}
