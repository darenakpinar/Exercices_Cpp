.global bind2dec

bind2dec:
	mov x1, #0

	ldrb w2, [x0]
	cmp w2, #0
	b.eq ex
loop:
	sub w2, w2, #48
	add x1, x2, x1, LSL #1 // x1 = (x1 << 1) +x2

	ldrb w2, [x0, #1]! // load next character (post-increment pointer)
	cmp w2, #0
	b.ne loop // keep looking if not null
ex:
	mov x0, x1 // put result in x0 (return value)
	ret
