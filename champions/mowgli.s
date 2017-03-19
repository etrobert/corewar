.name "mowgli"
.comment "the king of the jungle"

init:
ld		%-1, r4
ld		%1, r5

loopinit:
ld		%2, r3		;

loop:
sub		r3, r5, r3	; r3--
zjmp	%:end_loop	; if (r3 == 0) stop loop
and		r1, %0, r9
zjmp	%:loop		; 
end_loop:
live	%0

#start:	aff r1
#l2:     sti r1,%:live,%1
#		and r1,%0,r1
#
#live:   live %1
#        zjmp %:live

# Executable compile:
#
# 0x0b,0x68,0x01,0x00,0x0f,0x00,0x01
# 0x06,0x64,0x01,0x00,0x00,0x00,0x00,0x01
# 0x01,0x00,0x00,0x00,0x01
# 0x09,0xff,0xfb
