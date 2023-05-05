> 06.04.23

- Unlike cpp, where it waits for an instantiation, in java it compiles the template function / class as bytecode.
- Next whenever a specific type is passed. There is no class defined, the int parameter is passed to the object to the compiled object and the bytecode for the specific type is directly generated.

- In simple terms, there is no template instantiation. Direct conversion to bytecode. Creates new bytecode for the specific type.

---

String is a subtype of Object, Integer is a subtype of Object.
But List`<String>` is not a subtype of List`<Object>`

```java
List<String> ls = new ArrayList<String>();
List<Object> lo = ls;
```

trying to insert string using `lo` might work, but trying to insert object using `ls` won't work.
Java takes the simple way and says it won't work if the types are different.

---

```java
List mylist = new LinkedList();
```

raw type

```java
mylist.add(new Integer(0));
mylist.add("Hello World");
```

- Bad practice (?)

Templatize this.
```java
List<Object> mylist = new LinkedList<>();
```

If the template is specified, it will check for the type being inserted in compile time.

```java
List<Integer> myList = new LinkedList<Integer>();
```

---

Wildcard

```java
public class WildCardClass<T> {
    private T value;

    public static void main(String[] args) {
        WildCardClass<?> wc1 = new WildCardClass<>("Jello");
    }
}
```

Equivalent to `Object`, not used anymore, also takes in certain non-object.

---

Template extend

```java
public class LowerBoundList<T extends Number>
```

Only accepts numbers and it's types.

```java
public class cl<? extends Integer>
public class cl<T extends Integer>
```

First one takes Integer and its subclasses
Second takes Integer and its subclasses
