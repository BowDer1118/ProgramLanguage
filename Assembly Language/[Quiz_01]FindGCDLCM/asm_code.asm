INCLUDE Irvine32.inc

.386
.model flat,stdcall
.stack 4096

ExitProcess PROTO,dwExitCode:DWORD
gcd PROTO C,arg1:DWORD,arg2:DWORD

.data
cases DWORD ?
data1 DWORD ?
data2 DWORD ?
data_gcd DWORD ?
data_lcm DWORD ?
comma BYTE ",",0
gcd_bstring BYTE "GCD(",0
gcd_estring BYTE ") = ",0
lcm_bstring BYTE "LCM(",0
lcm_estring BYTE ") = ",0

.code
main PROC  C
	;Set loop times
	call ReadInt
	mov cases,eax
	mov ecx,cases
	call Crlf
LoopCase:
	;Saving each loop time for ecx(cause ecx will be change when call C function)
	mov cases,ecx

	;init two data
	call ReadInt
	mov data1,eax
	call ReadInt
	cmp data1,eax
	ja	changeData	;if eax<data1
	mov data2,eax
	jmp goNext
changeData:			;let data1<data2
	mov ebx,data1
	mov data1,eax
	mov data2,ebx
	jmp goNext
doLoop:
	;Cause my C function using "for" loop to search gcd 
	;So ecx has been override when call C function:gcd
	;We need to re-put loop number back to eax before we do loop instruction
	mov ecx,cases
	loop LoopCase
	;Loop complete
	jmp endProcess
goNext:
	;calculate gcd of data1,data2
	INVOKE gcd,data1,data2
	mov data_gcd,eax
	
	;calculate lcm
	mov eax,data1
	mov ebx,data2
	mul ebx
	div data_gcd 
	mov data_lcm,eax
	

	;display gcd 
	call Crlf
	mov edx,OFFSET gcd_bstring
	call WriteString
	mov eax,data1
	call WriteDec
	mov edx,OFFSET comma
	call WriteString
	mov eax,data2
	call WriteDec
	mov edx,OFFSET gcd_estring
	call WriteString
	mov eax,data_gcd
	call WriteDec
	call Crlf

	;display lcm
	mov edx,OFFSET lcm_bstring
	call WriteString
	mov eax,data1
	call WriteDec
	mov edx,OFFSET comma
	call WriteString
	mov eax,data2
	call WriteDec
	mov edx,OFFSET lcm_estring
	call WriteString
	mov eax,data_lcm
	call WriteDec
	call Crlf
	call Crlf
	
	;Case process complete--->do next case
	jmp doLoop
endProcess:
	INVOKE ExitProcess,0
main ENDP
END 