	export _myCLI,_clock_inter_asm
	import _clock_inter

_clock_inter_asm:
	JSR	_clock_inter
	RTI
	
_myCLI:
	CLI
	RTS