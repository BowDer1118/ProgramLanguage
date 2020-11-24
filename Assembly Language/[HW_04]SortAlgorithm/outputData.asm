INCLUDE libraries.inc

.code
outputData PROC,
	ptrDataArray:PTR SDWORD,dataNum:DWORD,ptrString:PTR BYTE
	mov ecx,dataNum				;Set loop times 
	mov esi,ptrDataArray		;Set array OFFSET
	mov edx,ptrString			;Set space string
NextPosition:
	mov eax,[esi]
	cmp eax,0					;Compare number is positive or negetive
	jge	Positive
	call WriteInt
	jmp	CheckNextNum
Positive:
	call WriteDec
CheckNextNum:
	cmp  ecx,0					;If ecx==0
	je	Center					;Jump to Center
	call WriteString			;Output space
	add esi,4
	loop NextPosition

Center:
	call Crlf
	mov esi,ptrDataArray
	mov ebx,2
	mov eax,dataNum
	CDQ
	div ebx

	mov ecx,eax
	dec ecx
	cmp ecx,0
	je AtCenter
GoCenter:
	add esi,4
	loop GoCenter
AtCenter:
	cmp edx,0
	jne OddNum
	mov eax,[esi]
	cmp eax,0
	jge EP
	call WriteInt
	jmp NextCenter
EP:
	call WriteDec
NextCenter:
	mov edx,ptrString
	call WriteString
OddNum:
	add esi,4
	mov eax,[esi]
	cmp eax,0
	jge	OP
	call WriteInt
	jmp Return
OP:
	call WriteDec
Return:
	ret
outputData ENDP
END