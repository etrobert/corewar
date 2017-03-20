.name		"vampire
on two lines"
.comment	"Faites
gaffe je mord :3"

#	.name		"lol"
#	.comment	"hey"

;un programme qu'il est beau <3

# all commented instructions are errors

			start:

live:
	live	%42
	live	%0
	live	%-42
	live	%-0
	live	%-9223372036854775808
	live	%9223372036854775807
	live	%4294967297424443545
	live	%-6667384286175413158
	live	%:sub
#	live	:add
#	live	%5-8
#	live	%5a
#	live	%a5
#	live	%-5a
#	live	654
#	live	:5464
#	live	%42, r4
#	live

ld:
	ld		%42, r5
	ld		42, r5
	ld		%:and, r5
	ld		:sub, r5
	ld		%-9223372036854775808, r0
	ld		%9223372036854775807, r16
	ld		-9223372036854775808, r5
	ld		9223372036854775807, r5
#	ld		%:hey, r5
#	ld		:notalabel, r5
#	ld		r6, %54
#	ld		%42, %24
#	ld		%42
#	ld		%42, r4, 12
#	ld		

st:
	st		r0, 69
	st		r16, -9223372036854775808
	st		r2, r3
	st		r7, :start
#	st		r8, %:end
#	st		69, r12
#	st		r15, %-9223372036854775808
#	st		%14, r14
#	st		r0, 15, %15
#	st		r0
#	st

add:
	add		r0, r1, r16
#	add		r-1, r5, r6			; zaz care about this error just because '-' isn't a digit				#
#	add		r0, rabc, r16																				## I should warn insteed of returning error.
#	add		r0, r5, r17			; zaz does't give a single fuck of this error at compilation step		#
#	add		r0, r1, 15
#	add		%:st, r2, r3
#	add		r2, :ld, r4
#	add		r0, r1, r2, r3
#	add		r1, r2
#	add		r1
#	add

sub:
	sub		r0, r1, r16
#	sub		r-1, r5, r6			; zaz care about this error just because '-' isn't a digit
#	sub		r0, rabc, r16
#	sub		r0, r5, r17			; zaz doesn't give a single fuck of this error at compilation step
#	sub		r0, r1, 15
#	sub		%:st, r2, r3
#	sub		r2, :ld, r4
#	sub		r0, r1, r2, r3
#	sub		r1, r2
#	sub		r1
#	sub

and:
	and		r0, r1, r2
	and		0, :add, r0
	and		%11, %:ld, r3
	and		r5, %14, r2
	and		%17, 18, r16
#	and		r4, r5, 6
#	and		r4, r5, %6
#	and		r0, r1, r2, r3
#	and		r1, r2
#	and		r1
#	and

or:
	or		r0, r1, r2
	or		0, :add, r0
	or		%11, %:ld, r3
	or		r5, %14, r2
	or		%17, 18, r16
#	or		r4, r5, 6
#	or		r4, r5, %6
#	or		r0, r1, r2, r3
#	or		r1, r2
#	or		r1
#	or

xor:
	xor		r0, r1, r2
	xor		0, :add, r0
	xor		%11, %:ld, r3
	xor		r5, %14, r2
	xor		%17, 18, r16
#	xor		r4, r5, 6
#	xor		r4, r5, %6
#	xor		r0, r1, r2, r3
#	xor		r1, r2
#	xor		r1
#	xor

zjmp:
	zjmp	%42
	zjmp	%0
	zjmp	%-42
	zjmp	%-0
	zjmp	%-9223372036854775808
	zjmp	%9223372036854775807
	zjmp	%4294967297424443545
	zjmp	%-6667384286175413158
	zjmp	%:sub
#	zjmp	:add
#	zjmp	%5-8
#	zjmp	%5a
#	zjmp	%a5
#	zjmp	%-5a
#	zjmp	654
#	zjmp	:5464
#	zjmp	%42, r4
#	zjmp

ldi:
	ldi		r0, r1, r2
	ldi		%42, %42, r2
	ldi		:zjmp, %:xor, r3
#	ldi		r0, r1, %3
#	ldi		r0, r1, 3
#	ldi		%42, 42, r2
#	ldi		r0, r1, r2, r3
#	ldi		r1, r2
#	ldi		r1
#	ldi

sti:
	sti		r0, r1, r2
	sti		r1, %42, %42
	sti		r1, :zjmp, %:xor
#	sti		%0, r1, r2
#	sti		0, r1, r2
#	sti		r0, 42, 42
#	sti		r0, r1, r2, r3
#	sti		r1, r2
#	sti		r1
#	sti

fork:
	fork	%42
	fork	%0
	fork	%-42
	fork	%-0
	fork	%-9223372036854775808
	fork	%9223372036854775807
	fork	%4294967297424443545
	fork	%-6667384286175413158
	fork	%:sub
#	fork	:add
#	fork	%5-8
#	fork	%5a
#	fork	%a5
#	fork	%-5a
#	fork	654
#	fork	:5464
#	fork	%42, r4
#	fork

lld:
	lld		%42, r5
	lld		42, r5
	lld		%:and, r5
	lld		:sub, r5
	lld		%-9223372036854775808, r0
	lld		%9223372036854775807, r16
	lld		-9223372036854775808, r5
	lld		9223372036854775807, r5
#	lld		%:hey, r5
#	lld		:notalabel, r5
#	lld		r6, %54
#	lld		%42, %24
#	lld		%42
#	lld		%42, r4, 12
#	lld

lldi:
	lldi		r0, r1, r2
	lldi		%42, %42, r2
	lldi		:zjmp, %:xor, r3
#	lldi		r0, r1, %3
#	lldi		r0, r1, 3
#	lldi		%42, 42, r2
#	lldi		r0, r1, r2, r3
#	lldi		r1, r2
#	lldi		r1
#	lldi

lfork:
	lfork	%42
	lfork	%0
	lfork	%-42
	lfork	%-0
	lfork	%-9223372036854775808
	lfork	%9223372036854775807
	lfork	%4294967297424443545
	lfork	%-6667384286175413158
	lfork	%:sub
#	lfork	:add
#	lfork	%5-8
#	lfork	%5a
#	lfork	%a5
#	lfork	%-5a
#	lfork	654
#	lfork	:5464
#	lfork	%42, r4
#	lfork

aff:
	aff		r0
	aff		r16
#	aff		r42			; zaz doesn't give a single fuck of this error at compilation step | I should warn insteed of returning error
#	aff		%42
#	aff		42
#	aff		r0, r1
#	aff

random_instructs:
#	abc		r10, %42
#	sdfg
#	fgh
#	56
#	565df
#	34dfgh
#	%dfgsd
#	r4613
#	rsddrg
#	%:aff
#	:aff
#	-210
#	-adf

syntax:			#just some syntax tests

good_label_1337:
#i'm_a_bad_label:
#mee_too_^_^:

label:lldi		r0,r1,r2	;hey that's a good syntax :x

label:	lldi		r0,r1,r2;hey that's a good syntax too :x
		lldi		r0, r1, r2
		lldi		r0 ,r1 ,r2
		lldi		r0 , r1 , r2
		lldi		r0	,	r1	,	r2	
		lldi		r0, r1 ,r2
#		lldi		r0,, r1, r2
#		lldi		r0 r1 r2,,
#		lldi		r0 r1 r2
#		lldi		r0 r1,r2,
#		lldi		,r0 ,r1 r2
#		lddi		r0, r1, r2

#	.name		"lol"		; zaz don't care if name or comment are declared after the first instruction are declared
#	.comment	"hey"

			end:
