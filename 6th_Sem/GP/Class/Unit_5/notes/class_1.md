> 03.04.23

##### Java Primer
- Null is a special type.
- Void is not a type.

All objects in java are derived from another object. The root / parent object (Object) doesn't have a type.

By default any object that is created is extending the parent object.

- Can only do one `super`

Can do something like this

```java
Child a = new Parent();
Grandchild b = a;
```

---

What's there in an object ?

- **Mard Word**: Is used for synchronization of threads. 
- **Class Pointer**: Has the metadata about the class, such as the class name, superclass, interfaces, class-level fields and methods.

Object Layout

- Instance Data: Characteristics, features.
- Padding: Alignment.

Object Memory

- Method Area: The bytecode of the methods, also stores static variables.
- Heap: Instance variables are always stored here.

--- 

Wrappers

Primitive Datatypes
    int, float, char

- Generic templates in java cannot take basic / primitive datatypes. They can only a wrapper for these.
- A wrapper is just a class which contains the basic data type.
- not all primitives can store null, the wrapper gives utility methods. From int to boolean to string....
- Can create an int, push it into Integer (boxing) and then from the Integer (unboxing) to int.

- Type Erasure is very simple in java. As `Object` can accept anything, and it is hidden. Effectively it has erased the type.
- Only issue comes whenever retrieval is performed, it needs to be casted.
- Can create a generic class using `Object`.
