INCLUDE Irvine32.inc

.386
.model flat,stdcall
.stack 4096

GCD PROTO,gM:SDWORD,gN:SDWORD
LCM PROTO,lM:SDWORD,lN:SDWORD
ExitProcess PROTO,dwExitCode:DWORD

.data
m SDWORD ?
n SDWORD ?
space BYTE " ",0
.code
main PROC
MainLoop:
	call ReadInt
	cmp eax,0
	jl	Finish		;if input number <0
	mov m,eax
	call ReadInt
	cmp eax,0
	jl	Finish			;if input number <0
	cmp eax,m			;Let n>m
	jg Start			;if n>m	
	XCHG eax,m			;swap m and n

Start:
	mov n,eax			;move bigger number to n
	INVOKE GCD,m,n
	call WriteInt
	mov edx,OFFSET space
	call WriteString
	INVOKE LCM,m,n
	call WriteInt
	mov edx,OFFSET space
	call WriteString	
	call Crlf
	jmp MainLoop
Finish:
	INVOKE ExitProcess,0
main ENDP

GCD PROC,gM:SDWORD,gN:SDWORD
	LOCAL R:SDWORD
	mov eax,gN
	mov ebx,gM
	
	cmp ebx,0
	je ReturnGCD	
	CDQ
	IDIV ebx
	mov R,edx
	INVOKE GCD,R,ebx	;Recursive
ReturnGCD:
	RET					;Return the gcd of m and n
GCD ENDP

LCM PROC,lM:SDWORD,lN:SDWORD
	INVOKE GCD,lM,lN
	mov ebx,eax		;Store the GCD(m,n)
	mov eax,lM
	IMUL lN
	IDIV ebx
	RET
LCM ENDP

END main