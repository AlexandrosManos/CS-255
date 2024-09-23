# -----------------------------------
# Program x86asm.s
# Compute and print the sum 0+...+N
# -----------------------------------


	.section .data	# data declarations section
	.equ N, 1000	# N <- 1000 (upper bound for sum)
S:	.long 0		# sum <- 0 (initialize sum variable)
Msg:	.ascii "The sum from 11 to %d is %d\n\0"


	.section .text	#  code section
.globl main
main:	
                #ebp-> the bottom of stack frame
                #esp-> the top of stack frame 
	pushl %ebp	# Stores (push) the value of ebp in stack
	movl %esp, %ebp	# Copies the contents of %esp to %ebp
                    # Moves the bottom pointer to the new base of the stack

 	# initialize
        movl $N, %ebx	# Save the value of N, in register (general purpose)

 	# compute sum
L1:
	addl %ebx, S	# S <- S + %ebx
	decl %ebx       # %ebx <- %ebx - 1
	cmpl $10, %ebx  # (%ebx - 10)
	jle  L2		    # Jump to L2 label if previous cmpl was
                    # "<=" (%ebx <= 10)
        movl $L1, %eax	# %eax <- the address of L1 label
        jmp *%eax	# Jump to the address that is stored to %eax

L2:
	# print result
	pushl S		# Push the value of S in stack
	pushl $N	# Push the value of N in stack
	pushl $Msg	# Push the string in stack
	call printf	# Call the printf function, push the returning address and args to stack
	popl %eax	# Pop from stack to %eax/free the arguments' space from stack
	popl %eax	# Pop from stack to %eax/free the arguments' space from stack
	popl %eax	# Pop from stack to %eax/free the arguments' space from stack

	# exit
	movl $0, %eax  	# Stores the returning value (0) to eax
        leave		# Restore the old value of top,bottom pointer
                    # movl %ebp, %esp
                    # popl %ebp
 	ret		# Return to the address which is saved in the stack and frees
            # the corresponding stack position
