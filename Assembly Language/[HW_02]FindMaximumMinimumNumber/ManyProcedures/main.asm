INCLUDE Irvine32.inc

.386
.model flat,stdcall
.stack 4096

ExitProcess PROTO,dwExitCode:DWORD

.data
num SDWORD ?

.code

inputNum PROC
	 call ReadInt
	 mov num,eax
	 RET
inputNum ENDP

outputNum PROC
	;¥ý-10¦A¿é¥X
	sub num,10
	mov eax,num
	call WriteInt
	RET
outputNum ENDP

main PROC
	call inputNum
	call outputNum
	INVOKE ExitProcess,0
main ENDP

END main