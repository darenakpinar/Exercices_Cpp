.global removespace

removespace:
 mov x1, x0 // write pointer (destionation, start at s)
 mov w3, #0 // w3 = counter for new length
loop:
	ldrb w2, [x0]
	cmp w2, #0
	b.eq ex   // yes we're done!

	cmp w2, #32
	b.eq skip_copy // equal

	strb w2, [x1]
	add x1, x2, #1 // advance writ3e pointer
	add w3,w3, #1 // increment count
skip_copy:
	add x0, x0, #1 // move to next input char
	b loop // repeat
ex:
	strb w2, [x1] // write null terminator at end
	mov w0, w3  // return new length
	ret


