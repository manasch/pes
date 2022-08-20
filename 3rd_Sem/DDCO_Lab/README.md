# Installation

```bash
sudo apt update
sudo apt install iverilog
sudo apt install gtkwave
```

# How to run and view verilog files

1. Create a aout dumpfile, can use any number of .v files to create the out file

```bash
iverilog -o aout a.v atestbench.v
```

2. Successful compilation results in no output on the command line, use vvp to generate a gtkwave dump

```bash
vvp aout
```

3. Observe the dump file using gtkwave

```bash
gtkwave dump.vcd
```