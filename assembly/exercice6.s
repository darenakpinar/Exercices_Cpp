
countpositives:
	mov w2, #0

loop:
	ldr w1, [x0], #4
	cmp w1, #0
	b.le sk

	add w2, w2, #1
sk:
	b.ne loop // if not zero, keep looping

	mov w0, w2  // return counter in w0
	ret

