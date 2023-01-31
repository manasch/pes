//q4
/*
here is some erronous code */
template <typename elemType> class ListItem {
    ListItem<elemType>();
};
template <typename elemType> class List {
public:
    List<elemType>();
    List<elemType>(const List<elemType> &);
    List<elemType>& operator=(const List<elemType> &);
    ~List();
    void insert(ListItem *ptr, elemType value);
private:
    ListItem *front, *end;
};
/* Correct it  1 point
The ListItem class is a simple container class that holds a value of type elemType and a
pointer to the next item in the list.
The List class is a singly linked list implementation that holds a pointer to the front and end of the list and 
it can have the functionality to insert a new element to the list and copy, assign and delete the list.

Bonus point if you implement ListItem functionality 1 point

*/


int main() {
    List<int> myList;
    ListItem<int> *ptr = new ListItem<int>(10);
    myList.insert(ptr,20);

    return 0;
}
