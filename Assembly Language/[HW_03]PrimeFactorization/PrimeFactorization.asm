INCLUDE Irvine32.inc

.386
.model flat,stdcall
.stack 4096

ExitProcess PROTO,dwExitCode:DWORD

.data
inputData  SDWORD ?				;Store input number
prime	   SDWORD ?				;Store prime number
numArray   DWORD 50 DUP(0)		;Store those prime number in inputdata
countArray DWORD 50 DUP(0)		;Store each prime number shown times
index	   BYTE TYPE numArray	;Get distence in memory address
SNPLC	   SDWORD ?				;Store the loop counter in SearchNextPrime Function
powString  BYTE " ^ ",0			;Output String
mulString  BYTE " * ",0			;Output String 

.code

ResetArrayData PROC
	mov ecx,50					;Set loop time to iterate numArray
	mov ebx,0
	mov bl,index
	mov esi,OFFSET numArray
ResetNum:
	mov eax,[esi]
	xor eax,eax					;Exclusive Or the same number(eax,eax)--->result is 0
	mov [esi],eax
	add esi,ebx					;Increase EBX with once memory distence of numArray(so is countArray)
	loop ResetNum

	mov ecx,50					;Set loop time to iterate countArray
	mov ebx,0
	mov bl,index
	mov esi,OFFSET countArray
ResetCount:
	mov eax,[esi]
	xor eax,eax					;Exclusive Or the same number(eax,eax)--->result is 0
	mov [esi],eax

	add esi,ebx					;Increase EBX with once memory distence of numArray(so is countArray)
	loop ResetCount

	ret
ResetArrayData ENDP

DisplayResult PROC
	mov ebx,0
NextPosition:
	mov esi,OFFSET numArray
	add esi,ebx
	mov eax,[esi]
	cmp eax,0
	je	EndDisplayReuslt	;if numArray[index]==1--->No more prime factor in array--->exit process
	cmp ebx,0			
	je DisplayMessage			;if index=0-->Don't print " * "--->print prime immediately
	mov edx,OFFSET mulString
	call WriteString
DisplayMessage:
	call WriteDec
	mov esi,OFFSET countArray
	add esi,ebx				;Move to current position
	mov eax,[esi]	
	cmp eax,1				;if countArray[index]=1--->(numArray[index])^1--->not to print "1"
	je	PrepareNextIndex
	mov edx,OFFSET powString
	call WriteString		
	call WriteDec
PrepareNextIndex:
	add bl,index			;Increase EBX with once memory distence of numArray(so is countArray)
	jmp NextPosition
EndDisplayReuslt:
	ret
DisplayResult ENDP

SearchNextPrime PROC
;-----------------------------
;[Pseudo Code]
;Loop:
;	prime++
;	for(int i=2;i<prime;i++){
;		if(prime%i==0){
;			jmp Loop
;		}
;	}
;return prime
;-----------------------------
SNP:
	inc prime					;Prime++
	mov eax,prime
	mov SNPLC,1					;i=1
SNPL:							
	inc SNPLC					;i++
	cmp eax,SNPLC				
	je	ReturnPrime				;if(i==prime)--->break loop
	CDQ							;extend EAX to EDX for IDIV instruction
	idiv SNPLC					;prime/i
	mov eax,prime				;reset prime EAX (cause EAX is been overrided by IDIV instruction's quotient)
	cmp EDX,0					;Compare reminder with 0 to check if SNPLC is a factor of prime
	je	SNP						;if reminder equal to 0 represent prime is not a prime number at this moment--->search next one number
	jmp SNPL					;Do next round loop to check prime is a prime number or not
ReturnPrime:
	mov prime,eax
	ret
SearchNextPrime ENDP

SearchPrimeFactor PROC
;-----------------------------------
;[Pseudo Code]
;Setup global variable prime=1
;Setup global variable index=1
;Lebel:
;	call SearchNextPrime
;	if(inputData%prime==0){
;		while(inputData%prime==0){
;			inputData/=prime;
;			countArray[index]++;
;		}
;		index++;
;	}else{
;		jmp Lebel
;	}
;	ret
;-----------------------------------
	mov prime,1					;Set prime number to 1(look illogical but it will be add into 2 in SearchNextPrime)
	mov ecx,0					;Initialize ecx register to all 0 to store the array memory offset of numArray and countArray
SPF:
	call SearchNextPrime		;Prepare next prime for prime factor searching
	mov eax,inputData			;Reset inputdata to EAX(Cause EAX is overrided by SearchNextPrime function)
	cmp eax,1					;If inputData=1
	je	EndSearchPrimeFactor	;Skip this number
	CDQ							;Extend EAX to EDX:EAX
	mov ebx,prime				;Store prime with EBX
	idiv ebx					;input/prime
	cmp edx,0					;Check reminder
	jne	SPF						;If prime is not the factor of inputdata--->do next round loop
	mov eax,inputData			;Reset inputData to EAX(Cause EAX is overrided by IDIV instruction)
	
	mov esi,OFFSET numArray		;Pick numArray
	add esi,ecx					;Move to current position
	mov [esi],ebx				;Set numArray[index]=prime

KeepDiv:
	mov eax,inputData			;Dividend
	mov ebx,prime				;Divisor
	CDQ							;Extend EAX to EDX:EAX
	idiv ebx					
	cmp edx,0					;Check reminder--->if equal to 0--->Can do DIV again
	jne PrepareNextRound		;If reminder not equal to 0 --->Stop Diving and push array index for doing next round search
	mov inputData,eax			;Set inputData to quotient
	mov esi,OFFSET countArray	;Pick countArray
	add	esi,ecx					;Move to current position
	mov ebx,[esi]				;ebx=countArray[index]
	inc ebx						;ebx++
	mov [esi],ebx				;Set countArray[index]++
	cmp eax,1					;Check quotient
	je	EndSearchPrimeFactor	;If inputData equal 1--->Prime Factorization Complete
	jmp	keepDiv
PrepareNextRound:
	add cl,index				;Increase ECX with once memory distence of numArray(so is countArray)
	jmp SPF
EndSearchPrimeFactor:
	ret
SearchPrimeFactor ENDP

ProcessData PROC
	call SearchPrimeFactor		;Do prime factorization	
	call DisplayResult			;Display the result of prime factorization
	call Crlf
	call ResetArrayData			;Reset numArray and countArray
	ret
ProcessData ENDP

main PROC
InputNumber:
	call ReadInt
	cmp eax,0
	jle EndProcess				;If input number less than or equal zero
	mov inputData,eax			;Store inputData to global variable
	call ProcessData			;Call process inputdata function
	jmp InputNumber				;Case processed complete and start to process next case
EndProcess:
	INVOKE ExitProcess,0
main ENDP

END main