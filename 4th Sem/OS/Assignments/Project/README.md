
# Kernel Module - Listing Processes

Ensure gcc and make are both installed in the system, place these files in a directory and run the following

```sh
1 make
2 sudo insmod list_task.ko
3 lsmod
4 dmesg
5 sudo rmmod list_task.ko
6 sudo dmesg --clear
```

`make` will compile and build the module.  
`insmod` will insert the module and run it.  
`lsmod` will display all the modules that are loaded in memory.  
`dmesg` will display the kernel logs since the kernel module doesn't print to `stdout`.  
`rmmod` will remove the module.  
`dmesg --clear` will clear the kernel logs.
