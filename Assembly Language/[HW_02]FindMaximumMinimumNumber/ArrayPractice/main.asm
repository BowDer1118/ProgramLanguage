INCLUDE Irvine32.inc

.386
.model flat,stdcall
.stack 4096

ExitProcess PROTO,dwExitCode:DWORD

.data
numArray SDWORD 10,20,30		;��l�Ƥ@�Ӱ}�C
arrayIndex BYTE TYPE numArray

.code
main PROC
	;ebx=32*0(full)
	;bx=16*0 (half)
	;bh=8*0 (high)
	;bl=8*0 (low)

	mov esi,OFFSET numArray ;�NnumArray���}�C�_�I��Jesi�Ȧs��
	mov ebx,0
	mov bl,arrayIndex
	add esi,ebx
	mov eax,[esi]

	call WriteInt
	INVOKE ExitProcess,0
main ENDP

END main


;int[] numArray=[10,20,30]
;for(int i=1;i<=numArray.lenngth;i++){
;	numArray[i];
;}