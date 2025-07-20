.global maxoccurences
maxoccurences:
	mov w1, #0
	mov w2, #0
	mov w3, #0
	mov w4, #0

loop:
	ldrb w5, [x0]
	cmp w5, #0 // end of string 
	b.eq endfun

	cmp w5, #'A' // is it A?
	cinc w1, w1, EQ
	cmp w5, #'C'
	cinc w2, w2, EQ
	cmp w5, #'G'
	cinc w3,w3, EQ
	cmp w5, #'T'
	cinc w4, w4, EQ // if equal w4++

	add x0, x0, #1 // next char
	b loop
endfun:
	cmp w1, w2
	csel w0, w1, w2, HI // w0 = max(w1, w2)
	cmp w0, w3
	csel w0, w0, w3, HI
	cmp w0, w4
	csel w0, w0, w4, HI
	ret
