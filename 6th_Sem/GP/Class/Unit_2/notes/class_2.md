- If a class derived is public, then it doesn't matter if the base class is private or public, it would be able to access it.

```cpp
#include <iostream>

using namespace std;

class Base{
	private:
		void func() {
			cout << "func\n";
		}
};

class Derived: public Base {
	public:
		void callBase() {
			func()
		}
}

int main() {
	Derived derived;
	derived.callBase();
	cout << '\n';
	return 0;
}
```

- Need to mention the full scope explicitly. Or create an alias.

## Accessing parent class members

- Defined, declared then redifine:  A function in class. Need to use full scope resolution to access parent.

```cpp
template<class T>
class Base
{
	public:
		void set (const T&val) {data = val;}
	private:
		T data;
};

class Derived: public Base<T>
{
	template
	public: void set (const T& v)
}
```

- How would you access the parent's parents class, and its parent class, and so on.

- Derived class taking two more parameters, Performing certain operations on them. Parent class and child class can both be templateized. The child class can have more template than the parent, but not the other way around.
- Multi-level inheritence, three levels, grandparent, parent and child: parent can use grandparent's constructor which doesn't need to be used called again in child's definition.

- Can you have a specialization of the the base class ?
- If the base class is specialized, it needs to be fully scoped to access its functions.

##  Inheriting from a template

- Can a templatized derived class inherit from a non templatized base class: **yes**
- It only affects the derived class since only this has template parameters.
- Functions, variables can't be inherited, but templates can be inherited as long as it's a class.
```cpp
template <typename T>
class Named : public T
```
- T has to be a class if you need to inherit. (T: int will throw an error).
