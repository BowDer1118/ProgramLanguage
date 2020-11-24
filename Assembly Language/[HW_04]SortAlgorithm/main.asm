INCLUDE libraries.inc

.386
.model flat,stdcall
.stack 4096

.data
dataArray SDWORD 200 DUP (0)			;Store all input number
dataNum DWORD 0						;Store total number of input 
format BYTE "%d",0					;Format for function scanf
string BYTE " ",0					;String for output space

.code
main PROC
	INVOKE inputData,ADDR dataArray,dataNum,ADDR format
	cmp eax,0
	je ToEnd
	mov dataNum,eax
	INVOKE sortData,ADDR dataArray,dataNum
	INVOKE outputData,ADDR dataArray,dataNum,ADDR string
ToEnd:
	INVOKE ExitProcess,0
main ENDP

END main