INCLUDE libraries.inc

.code 
inputData PROC,
	ptrDataArray:PTR SDWORD,dataNum:DWORD,ptrFormat:PTR BYTE
	INVOKE scanf,ptrFormat,ADDR dataNum		;Scan numbers of input
	mov ecx,dataNum							;Set loop times
	mov eax,dataNum							;Set return value
	cmp ecx,0								;if dataNum==0
	je Return								;Jump to Return
	mov esi,ptrDataArray					;Set array OFFSET
NextInput:
	pushad									;Store all register in stack avoid overriding by scanf function
	INVOKE scanf,ptrFormat,ADDR [esi]		
	popad									;Restore all register from stack
	add esi,4
	loop NextInput
Return:	
	ret 
inputData ENDP
END