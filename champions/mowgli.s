.name "mowgli"
.comment "the king of the jungle"

; r1 is the process id
; r3 is the counter
; r5 is the decrement value
; r9 is the trash

init:
ld		%4, r5							; r5 = 4
sti		r1, %:live, %1					; *(live + 1) = r1

big_loop:
	loopinit:
	ld		%44, r3						; r3 = 44

	loop:
		live:
			live	%0
		ldi		%:big_loop, r3, r6		; r6 = *(big_loop + r3)
		sti		r6, %:end_big_loop, r3	; *(end_big_loop + r3) = r6
		sub		r3, r5, r3				; r3 -= 4
		zjmp	%:end_loop				; if (r3 == 0) stop loop
		and		r1, %0, r9				; carry = 1
		zjmp	%:loop					; goto loop

	end_loop:
	and		r1, %0, r9					; carry = 1
	zjmp	%:big_loop					; goto big_loop
big_loop_end:
