.name	"Sasha"
.comment "Sasha will get you"


# hello: sti r1, %1, %1

		sti r1, %:live, %1
live: 	live %1



# s:		sti r1, %:live, %1  #we dont know where live is
# 		sti r15, %:s, %3
# live: 	live %1
# 		zjmp %:live

