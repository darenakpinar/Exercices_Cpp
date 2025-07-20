.global invert
invert:
	cmp x1, #0 // check if n ==0
	b.eq exit  // if so , exit

	add x1, x0, x1, LSL #2 // x1 = address of A[n] (end , exvlusive 
	sub x1, x1, #4  // x1 = address of last element
loop:
	ldr w2, [x0]
	ldr w3, [x1] // load vale at end pointer into w3

	str w2, [x1]
	str w3, [x0]

	add x0, x0, #4 // move start pointer forward 
	sub x1, x1, #4 // Move end pointer backward 

	cmp x0, x1 // have the pointers crossed ?
	b.le loop  // if not, keep looping 

exit:
	ret 
