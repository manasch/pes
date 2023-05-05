```cpp
#include <iostream>

using namespace std;

template <typename T>
class C{
  public:
    void f() {
      cout << "Hel" << endl;
    }
};

int main() {
  C<int> x;
  //x.f();
  C<int> *p = 0;
  p->f();
}
```

- This still works and gives an output. You get "Hel" for both.

---

```cpp
template<typename T>
class C{
  public:
  C(T);
};

void candidate(C<double>);
void candidate(int) {}
//void candidate(double) {}

int main() {
  candidate(42);
  candidate(4.2);
}
```

- This one picks `C<double>` anyways for some reason, without checking int. Hence `C<>` is instantiated.
- The ordering does not matter as it still picks `C<double>`. Chooses the same even if `candidate(double)` is uncommented.
- If `void candidate(C<double>) {}` is done then it gets instantiated cuz of the defn itself. If it is done as it is given above, then it's cuz of `candidate(42)` instead of the function declaration.
- Both of them choose to go to the `int` defined function anyways.

```cpp
template <typename T>
class X {
  public:
  X *p;
  void f() {int i = 0;}
  void g() {int j = 0;}
};

int main() {
  X<int> *q;
  X<int> r;
  X<float> *s;
};
```

- Only instantiated because of `X<int> r`.
---
- Compiler implicitly instantiates a class templates if it has static members.
- The static method instantiation is done only when required though so it's still lazy.
- Not allocated memory though when the class template is used. Onlyl when first accessed.

```cpp
#include <iostream>

template <typename T>
class MyClass {
  public:
  static int counter;
  MyClass() {
    ++counter;
  }
};

template <typename T>
int MyClass<T>::counter = 0;

int main() {
  MyClass<int> a;
  MyClass<double> b;
  
  std::cout << MyClass<int>::counter << std::endl;
  std::cout << MyClass<double>::counter << std::endl;
  
  return 0;
}
```

```cpp
#include <iostream>

template<typename T>
class MyClass
{
  
  public: 
  static int counter;
  inline MyClass()
  {
    ++counter;
  }
  
};

/* First instantiated from: insights.cpp:16 */
#ifdef INSIGHTS_USE_TEMPLATE
template<>
class MyClass<int>
{
  
  public: 
  static int counter;
  inline MyClass()
  {
    ++counter;
  }
  
};

#endif
/* First instantiated from: insights.cpp:17 */
#ifdef INSIGHTS_USE_TEMPLATE
template<>
class MyClass<double>
{
  
  public: 
  static int counter;
  inline MyClass()
  {
    ++counter;
  }
  
};

#endif


template<typename T>
int MyClass<T>::counter = 0;
#ifdef INSIGHTS_USE_TEMPLATE
int MyClass<int>::counter = 0;
#endif
#ifdef INSIGHTS_USE_TEMPLATE
int MyClass<double>::counter = 0;
#endif


int main()
{
  MyClass<int> a = MyClass<int>();
  MyClass<double> b = MyClass<double>();
  std::cout.operator<<(MyClass<int>::counter).operator<<(std::endl);
  std::cout.operator<<(MyClass<double>::counter).operator<<(std::endl);
  return 0;
}
```

- Output is `1 1`.

--- 
##### Variable Templates

```cpp
#include <iostream>

using namespace std;

constexpr double PI = 3.14159266535887832385L;
template <typename T>
T sphere_vol(T const r) {
    return 4 * PI * r * r * r / 3;
}

int main() {
    float v1 = sphere_vol(42.0f);
    double v2 = sphere_vol(42.0);
    
    cout << v1 << " " << v2 << endl;
}
```

- Apparently this was supposed to throw an error, but it did not, Assuming that it should throw and error because `PI` is by default `double`.
- `float` is just typecasted.
- Hence we use variable templates.
```cpp
#include <iostream>

using namespace std;

template <class T>
constexpr T PI = T(3.14159266535887832385L);

template <typename T>
T sphere_vol(T const r) {
    return 4 * PI<T> * r * r * r / 3;
}

int main() {
  double ans = sphere_vol(40.0f);
  
  cout << ans;
  return 0;
}
```

- Get a new `PI` value depending on the value sent to the function.

---

##### Inheritance

- Private methods and members aren't inherited.
- Inheritance can be done in 3 ways, `public`, `protected` and `private`.

|Access Specifier|Before|After|
|--|--|--|
|Public|Public|Public|
|Public|Protected|Protected|
|Public|Private|Inaccessible|

|Access Specifier|Before|After|
|--|--|--|
|Private|Public|Private|
|Private|Protected|Private|
|Private|Private|Inaccessible|

|Access Specifier|Before|After|
|--|--|--|
|Protected|Public|Protected|
|Protected|Protected|Protected|
|Protected|Private|Inaccessible|

---

- ~~Templatized inheritance for some reason requires you to call derived methods using `this` keyword.~~
- The methods in the parent class need to be brought to scope
    - Implicit by using `this`
    - Bring it in scope `using Base<T>::func`
    - Fully qualify `Base<T>::func()`

- The derived class can have more templates than the base class, but not the other way around.
- If base class is specialized, needs to be fully scoped. (??)

---

##### Inherting from a template

- Can inherit from a template as well provided that it is a class type.

```cpp
class Waypoint
{
 public:
  Waypoint(float lat = 8.0, float lon = 0.0) : latitude(lat), longitude(lon) {}
  void display() {
    cout << "Latitude: " << latitude << ", Longitude: " << longitude << endl;
  }

 private:
  float longitude;
  float latitude;
};

template <typename T>
class Named : public T // <------ Notice this, it's not Waypoint<T>
{
 public:
  Named(const char* str) : name(str) {}
  void display() {
    cout << "Name: " << name << ", ";
    T::display();
  }

 private:
  string name;
};
```

- Derived class can be a template class while the parent is a non-template class.

Non-dependent base

```cpp
template <typename T>
class Derived: public Base<double> // <--- It's not Base<T>
```

- If `virtual` isn't used, only the base method reference is available.
```cpp
#include<iostream>
using namespace std;
template <typename T>
class Base {
 public:
  void foo() { std::cout << "Base" << std::endl; }
};

template <typename T>
class Derived : public Base<T> {
 public:
  void foo() { std::cout << "Derived" << std::endl; }
};

int main() {
  Base<int>* p = new Derived<int>();
  p->foo(); 
  return 0;
}
```

```bash
This gives: Base
```

```cpp
#include<iostream>
using namespace std;
template <typename T>
class Base {
 public:
  virtual void foo() { std::cout << "Base" << std::endl; }
};

template <typename T>
class Derived : public Base<T> {
 public:
  virtual void foo() { std::cout << "Derived" << std::endl; }
};

int main() {
  Base<int>* p = new Derived<int>();
  p->foo(); 
  return 0;
}
```

```bash
This gives: Derived
```

---

##### Constructors

```cpp
#include <iostream>
#include <vector>
// Here is an example of what happens if we dont 
// explcitily destroy children

class Person {
public:
    Person(const std::string& name) : name(name) {}
    ~Person() {
        std::cout << name << " died." << std::endl;
    }
    std::string name;
};

class House {
public:
    House(const std::string& address) : address(address) {}
    ~House() {
        std::cout << "House at " << address << " was destroyed." << std::endl;
    }
    std::string address;
};

class Town {
public:
    Town() {
        std::cout << "Town was created." << std::endl;
    }
    ~Town() {
        std::cout << "Town was destroyed." << std::endl;
    }
    void add_person(Person* person) {
        people.push_back(person);
    }
    void add_house(House* house) {
        houses.push_back(house);
    }
private:
    std::vector<Person*> people;
    std::vector<House*> houses;
};

int main() {
    std::cout << "Entering main." << std::endl;
    Town* town = new Town();
    town->add_person(new Person("John"));
    town->add_house(new House("123 Main St."));
    delete town;
    std::cout << "Leaving main." << std::endl;
    return 0;
}
```

- This one doesn't print a person dies or house destroyed.
- Can delegate this work to shared pointer, which will call the destructor.

- Shallow Copy: If the value is changes in the og, it changes in the new one as well
- Deep Copy: If the value changes in the og, it doesn't change in the new one.
- By default, copy is shallow.

---

##### Friends

- If a class declares another class as a friend, in `public` or `private`, the friend class can access this class' private members.
- If `A` considers `B` as a friend, and `B` considers `C` as a friend, `A` doesn't consider `C` a friend directly, that is `C` can't access `A` private members directly, but only with the help of `B`
- Template friends need to be defined before.
- Can define friend to be itself, if need other template type.
```cpp
// Specify all instances of B are friends of A
template <typename T>
class A {
    private:
        int x;
    public:
        A(T x) : x(x) {}
        template <typename U>
        friend class B;
}
```
- If a primary template is a friend, then even the explicit and partial specialization are also friends.
- Can make a template parameter as a friend, if wrong it is ignored
```cpp
template<typename T>
class Box {
    public:
    friend T;
.
.
int main() {
    Box<Apple> box;
    box.set();
    Apple a;
    a.func(box);
    // This is ignored 
    Box<int> boxy;
    boxy.set();
    return 0;
}
```

- Other functions can also be declared as friends. Gotta specify the parameter properly.

---

##### Nested Classes

-  Outer class can't access inner class' private members, inner class can access outer class' private members if you pass the instance of the outer class to the inner class.
- Inner classes can also have a life of their own, just gotta fully qualify it.
```cpp
    Outer::Inner1 inner1;
    inner1.value1 = 42;
    inner1.printValue1();
```
- Templatized nested classes are also possible.

---

##### Dependent v Non-Dependent

- Non-Dependent datatypes are those which are not dependent on the template type.
- These are known at compile time.
- `using x = y`, Have to use `typename`. Basically when using aliases.
- Have to specify when a funcition is a template
```cpp
template <typename T>
struct base_parser
{
   template <typename U>
   void init()
   {
      std::cout << "init\n";
   }
};
template <typename T>
struct parser : base_parser<T>
{
    void parse() {
        base_parser<T>::template init<int>();
        std::cout << "parser\n";
    }
}
```

- ---

##### Some Header

- Can't initialize a static member in-class.

---

##### ISA 2 Prep

```cpp
#include <iostream>

template <typename T>
class MyClass {
 private:
  static T instance;

 public:
  static T& getInstance() {
    return instance;
  }
};

template <typename T>
T MyClass<T>::instance;
```

- Need to have an instance because it is static.

- When passing a function to a template, it doesn't matter where the function is declared
```cpp
#include<iostream>
template <typename T, T (*Func)(T)> //! [1] Fails here
class MyTemplateClass {
public:
  T getValue(T value) { 
    return Func(value); //![2] Fails here
  }
};
//![3] should have defined ahead
int square(int x) { 
  return x * x;
}
int main() { 
    MyTemplateClass<int, square> a;
    cout << a.getValue(3);
}
//! Which of the above statements are WRONG

```

- There is no error and this runs fine.