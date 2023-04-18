# Lab 6

### Generate bitcode

```bash
clang -O0 -emit-llvm -c main.c -o main.bc
clang -O0 -emit-llvm -c sum.c -o sum.bc
```

- `-O0` Does not optimize the code
- `-emit-llvm` Output in LLVM IR code
- `-c` Generates LLVM bitcode

> Can also generate human readable

```bash
clang -O0 -emit-llvm -S -c main.c -o main.ll
clang -O0 -emit-llvm -S -c sum.c -o sum.ll
```

- `-S` Generate LLVM human-readable code

> `-S` and `-c` when used without `-emit-llvm` generate machine-dependent code

---

### Exercise 1: Use the `-fno-discard-value-names` flag

```bash
clang -O0 -emit-llvm -fno-discard-value-names -S -c main.c -o main_discard.ll
clang -O0 -emit-llvm -fno-discard-value-names -S -c sum.c -o sum_discard.ll
```

---

### Convert bitcode to human-readable and vice-versa

- Convert to bitcode

```bash
llvm-as main.ll -o conv_main.bc
llvm-as sum.ll -o conv_sum.bc
```

- Convert to human-readable

```bash
llvm-dis main.bc -o conv_main.ll
llvm-dis sum.bc -o conv_sum.ll
```

---

### Exercise 2: Find the difference between this and previous generated code

> No difference apart from the moduleId

---

### Linking and convertng bitcode to object files

- Generate machine-dependent assembly

```bash
llc -filetype=asm main.bc -o main.s
llc -filetype=asm sum.bc -o sum.s
```

- Generate native object files

```bash
llc -filetype=obj main.bc -o main.o
llc -filetype=obj sum.bc -o sum.o
```

- Run and verify, may get warnings, ignore

```bash
clang main.o sum.o -o sum
./sum
```

- Create combined bitcode

```bash
llvm-link main.bc sum.bc -o combined.bc
llc -filetype=obj combined.bc -o combined.o
clang combined.o -o sum
./sum
```

---

### Exercise 3: Why it raises error when using ld GNU linker

> Source code uses `printf` which needs to be linked as well.

--

### Writing programs in LLVM IR

```bash
llvm-as main.ll -f -o - | lli
```

- `-f` force binary to stdout
- `-o -` Write to output (`-f` required)

### Example Hello World

```bash
llvm-as hello_world.ll -o conv_hello_world.bc
llvm-dis conv_hello_world.bc -o conv_hello_world.ll
```

---

### Exercise 4: Get `\t` in LLVM IR, print name and age

> Use `\09` for tab

- Compile written LLVM IR code and execute

```bash
llvm-as name_age.ll -o name_age.bc &&
llc -filetype=obj name_age.bc -o name_age.o &&
clang name_age.o -o name_age &&
./name_age
```

---

- Execute the examples

- counting

```bash
llvm-as counting.ll -o counting.bc && llc -filetype=obj counting.bc -o counting.o && clang counting.o -o counting
```

- fibonacci

```bash
llvm-as fibonacci.ll -o fibonacci.bc && llc -filetype=obj fibonacci.bc -o fibonacci.o && clang fibonacci.o -o fibonacci
```

---

### Optimizations

```bash
clang word.c -S -emit-llvm -Xclang -disable-O0-optnone -fno-discard-value-names
```

- `-Xclang -disable-O0-optnone` Don't run with optimizations

```bash
opt -passes='function(print<loops>)' -disable-output word.ll
opt -passes='module(print-callgraph)' -disable-output word.ll
```

---

### Exercise 5: Use the optimizations for helloworld.c

```bash
clang helloworld.c -S -emit-llvm -Xclang -disable-O0-optnone -fno-discard-value-names
opt -passes='module(print-callgraph)' -disable-output helloworld.ll
```

---

### Transform pass

```bash
opt <filename.ll> -O3 -o <outputfilename.ll>
```

---

### Mem2reg and time-passes

```bash
clang sum_1.c -S -emit-llvm -Xclang -disable-O0-optnone -fno-discard-value-names
opt -S sum_1.ll -passes='mem2reg' -o sumMemReg.ll
```

---

### Utility pass

```bash
opt word.ll -passes='function(view-cfg)' -disable-output
```

---

### Exercise 6: Use the `-cfg-func-name=<subtring>` flag

```bash
opt word.ll -passes='function(view-cfg)' -disable-output -cfg-func-name=replaceWord
```
