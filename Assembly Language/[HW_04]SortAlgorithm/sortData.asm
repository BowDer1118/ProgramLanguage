INCLUDE libraries.inc

.code
sortData PROC,
	ptrDataArray:PTR SDWORD,dataNum:DWORD
DoNextRound:
	cmp dataNum,1
	jbe	Return
	dec dataNum
	mov esi,ptrDataArray
	mov ecx,dataNum		;Set each round of comparsion
Compare:
	mov eax,[esi]
	cmp eax,[esi+4]
	jnl	ReadyForNext
	xchg eax,[esi+4]	;Swap [esi] and [esi+4]
	mov [esi],eax
ReadyForNext:
	add esi,4
	loop Compare
	jmp DoNextRound
Return:
	ret
sortData ENDP
END