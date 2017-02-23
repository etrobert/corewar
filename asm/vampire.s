.name "vampire"
.comment "Faites gaffe je mord :3"

bite:	sti r1,%:blood,%1
		and r1,%2,r1
		and r1, %2, r1
		and r1 ,%2 ,r1
		and r1 , %2 , r1


blood:	live %1
		zjmp %:blood
