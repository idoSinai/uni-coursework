	.text

/*
 * name: Ido Sinai  Id: 213059918 
 * Switch from current_thread to next_thread. Make next_thread
 * the current_thread, and set next_thread to 0.
 * Use eax as a temporary register, which should be caller saved.
 */
	.globl thread_switch
thread_switch:
	/* pushing registers to the current thread's stack */ 
	pushal

	/* Saving sp in current_thread->sp */
	movl current_thread, %eax
	movl %esp, (%eax)	

	/* Saving next_thread address in eax */
	movl next_thread, %eax

	/* Switching to the next thread stack  */
	movl (%eax), %esp 
	
	/* Switching the current thread to the next */
	movl %eax, current_thread

	/* Setting next_thread = 0 */
	movl $0, next_thread

	/* popping the next thread's registers cause it became the current thread */
	popal

	ret				/* pop return address from stack */

