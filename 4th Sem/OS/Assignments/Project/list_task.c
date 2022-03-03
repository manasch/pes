#include <linux/init.h>
#include <linux/sched.h>
#include <linux/sched/signal.h>
#include <linux/kernel.h>
#include <linux/module.h>

// init_module is the entry point for kernel modules, similar to the main function in a normal c program.
// Either init_module() can be used or module_init() specifying the function to start.
int begin_module(void) {
	struct task_struct *task;
	printk(KERN_INFO "----------------Listing the current running tasks----------------\n");

	for_each_process(task) {
		// for_each_process() will iterate through each process pointed by the task pointer.
		
		printk(KERN_INFO "Name: %-15s |\tPID: %10d |\tState: %5ld\n", task->comm, task->pid, task->state);

		/*
		 * Where,
		 * task->comm stands for the process name.
		 * task->pid prints the process ID of that process.
		 * task->state prints the state of the process
		 * 	-1 => Unrunnable
		 * 	 0 => Runnable
		 * 	>0 => Stopped
		 */
	}

	printk(KERN_INFO "----------------Listed all the running tasks----------------\n");
	return 0;
}

// cleanup_module is called when the module is removed from the listing.
// Either cleanup_module() is used, or module_exit() specifying the function can be used.
void exit_module(void) {
	printk(KERN_INFO "Removing task lister from module space\n");
}

module_init(begin_module);
module_exit(exit_module);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Lists the current running tasks");
MODULE_AUTHOR("Manas Chebrolu");
