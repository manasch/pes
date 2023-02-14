> 09/02/23

### Templates and Friends

```cpp
template<typename T>
class Accessor {
	public:
		static T getData(const Container<T> &c) {
			return c.data;
		}
};

template<typename T>
class Container {
	private:
		T data;
	public:
		Container(Tdata): data(data) {}
		friend class Accessor<T>
};

int main() {
	Container<int> c(10);
	std::cout  << Accessor<int>::getData(c) << std::endl;
	return 0;
}
```

- Friend functions allow a class to be able to access methods (even if they are private).
- Transitive relationships among friends do not hold. (But may seem to exist when declared publically)

```cpp
#include<iostream>
class A {  
    private:
     int x;
     friend class B;
    public:
     void setty() { x = 10;}

};
class B {
    public:
    void static print(const A &a)
    {
        std::cout << "X" << a.x;
    }
    private:
    friend class c;
};
class C:private B{
    public:
    // void static print(const A &a)
    // {
    //     std::cout << "X" << a.x;
    // }

 };
int main()
{
    A a;
    a.setty();
    B::print(a);
    //C::print(a);
}
```

- As long as C uses methods declared by B, it is fine. But this is a problem.
- Changing B to public or private will change C's access to A.


- If you want to use a template class which is a friend, you must declare it ahead of the access / declaration.
- (Declare everybody, and then define them, easier to manage)

---
##### Key Rules
- Not transitive
- Not commutative
- Not inheritable
---

```cpp
template<typename T>
class Stack {
  private:
    int top;
  public:
    // ...

    // assign stack of elements of type T2
    template<typename T2>
    Stack<T>& operator= (Stack<T2> const& other) {
      top = other.top;
      // ...
      return *this;
    }

    // to get access to private members of Stack<T2> for any type T2:
    template<typename> friend class Stack;
};

int main() {
  Stack<int> s1;
  Stack<double> s2;

  // assign stack of elements of type T2
  s2 = s1;
  return 0;
}
```

- Since the classes are different (int and double are different types, hence different classes). The private variable is not shared and hence this will not work. Therefore friend needs to be used.

### Typenames as friends

- You can set a typename as friend, if it is valid, consider it, if it is not valid then just go ahead.
- typename is supposed to be a class for it to be valid, if it is an inbuilt type like int, it'll just ignore it.

---

### Nested Templates

##### Why do this ?
> No namespace polution

- Outer class can't access *private member* of inner class, but inner class can access *private members* of the outer class.

---
