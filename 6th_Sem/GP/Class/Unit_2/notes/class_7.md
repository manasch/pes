> 14/02/23

Dependent: The var depends on the template type.
Non-dependent: Can be defined at any point in the code, as the compiler will scan through the entire code.

---

If the same function is defined again after the first call, it won't pick that even if it is of the same type.

```cpp
void handle(double x) {...}
template <typename T>
struct parser
{
	void parse() {
		handle(42);
	}
};

void handle(int x) {...}
int main() {
	struct parser a;
	a.parse() // will go to the double handler
}
```

---

- If it is non-dep, compiler goes through and name binding happens at definition. (1st pass)
- If it is dep,  looks at template, instantiates and name binding happens at instantiations. (2nd pass)

##### Making a non-dependent method dependent

```cpp
#include<iostream>
template <typename T>
struct base_parser
{
   void init()
   {
      std::cout << "init\n";
   }
};

template <typename T>
struct parser : base_parser<T>
{
   void parse()
   { 
      this->init(); // todo  will work
      base_parser<T>::init(); // todo will also work
      std::cout << "parse\n";
   }
};

int main()
{
   parser<int> p;
   p.parse();
}
```

---

##### Aliases

```cpp
template <typename T>
struct base_parser {
	using value_type = T;
};

template <typename T>
struct parser : base_parser<T> {
	void parse(){
		//value_type v{}; //1
		typename base_parser<T>::value_type v{}; //2
		std::cout << "parse\n";
	}
};
```

- At 1, it doesn't know what `value_type` is, need to specify.
- At 2, need to mention it as `typename` as it doesn't know what that declaration is.