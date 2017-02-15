bite:	sti r1,%:blood,%1
		and r1,%0,r1

.name "vampire"

blood:	live %1
		zjmp %:blood

.comment "Faites gaffe je mord :3"
