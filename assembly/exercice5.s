
mov w0, #0
adr x1, n
ldr w2, [x1]
adr x3, A

loop:
	cmp w0, w2
	b.ge end

	ldr w4, [x3, w0, SXTW #2] // w4 = A[i]
	cmp w4, #0
	b.le skip_store // if A[i] <= 0, skip assignment

	mov w4, #0 	// w4 = 0
	str w4, [x3, w0, SXTW #2] // A[i] = 0

skip_store:
	add w0, w0, #1 // i++
	b loop
end:
