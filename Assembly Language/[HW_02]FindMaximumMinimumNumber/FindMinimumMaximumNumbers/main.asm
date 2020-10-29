INCLUDE Irvine32.inc

.386
.model flat,stdcall
.stack 4096

ExitProcess PROTO,dwExitCode:DWORD

.data
dataNum SDWORD ?				;存放有幾筆數字要輸入
numArray SDWORD 200 DUP(?)		;存放數值的陣列
arrayIndex BYTE TYPE numArray	;存放每個元素間的記憶體差距(單位:BYTE)
maxString  BYTE "Max=",0		;輸出最大值 使用的字串
minString  BYTE "Min=",0		;輸出最大小 使用的字串
maxNum SDWORD ?
minNum SDWORD ?

.code

;檢查陣列資料(Debug時可呼叫)
checkArray PROC					
	;初始化CPU內部 所需暫存器
	mov ECX,dataNum
	mov ESI,OFFSET numArray		;初始化陣列位置
	mov BL,arrayIndex			;將記憶體差距推入EBX的前8bits

	;使用迴圈 檢查陣列內的資料
	outputArray:
		mov EAX,[ESI]			;將陣列中的元素值推到EAX
		call WriteInt			;輸出EAX
		call Crlf				;換行
		add ESI,EBX				;將陣列的記憶體位置推至下一個元素(每個元素32bits所以要推4個Byte)
		loop outputArray

	RET							;副程式結束
checkArray ENDP

;循環查找最大值
findMaxNum PROC
	mov ESI,OFFSET numArray		;將陣列的記憶體位置重新推入ESI
	mov BL,arrayIndex			;重設EBX的前8bits
	mov ECX,dataNum				;設定迴圈計數器
	
	;設定最大值
	setMax:
		mov EAX,[ESI]			;假設第一個值為最大值
		jmp decECX1

	;使用迴圈開始查找最大值
	searchMax:					
		add ESI,EBX				;將陣列位置往下一個元素推
		cmp	[ESI],EAX			;比較兩個數值
		jg	setMax				;若比較結果是大於-->重設最大值
		decECX1:
			loop searchMax			
	
	
	mov maxNum,EAX				;將最大值推入全域變數
	

	RET							;副程式結束
findMaxNum ENDP

;循環查找最小值
findMinNum PROC
	mov ESI,OFFSET numArray		;將陣列的記憶體位置重新推入ESI
	mov BL,arrayIndex			;重設EBX的前8bits
	mov ECX,dataNum				;設定迴圈計數器
	
	;設定最大值
	setMin:
		mov EAX,[ESI]			;假設第一個值為最小值
		jmp changeECX2

	;使用迴圈開始查找最大值
	searchMin:					
		add ESI,EBX				;將陣列位置往下一個元素推
		cmp	[ESI],EAX			;比較兩個數值
		jl	setMin				;若比較結果是大於-->重設最大值
		changeECX2:
			loop searchMin			
	
	
	mov minNum,EAX				;將最小值推入全域變數

	RET							;副程式結束
findMinNum ENDP

main PROC
	;初始化並自定義 CPU內部暫存器
	mov ECX,0					;初始化ECX到0
	call ReadInt				;讀取要輸入的數字數量
	mov dataNum,EAX 			;備份數字數量(下面檢查陣列資料要用)
	mov ECX,EAX					;將數量推入ECX當作LOOP數
	mov ESI,0					;初始化ESI到0
	mov ESI,OFFSET numArray		;將numArray的陣列記憶體起始位置傳入ESI
	mov EBX,0					;初始化EBX到0
	mov BL,arrayIndex			;將陣列每個元素的記憶體差距推入EBX的前8個Bits
	
	;使用迴圈 循環輸入數值並存入陣列
	inputLoop:
		call ReadInt
		mov [ESI],EAX			;將每筆接收到的數字放入陣列
		
		add ESI,EBX				;將陣列的記憶體位置推至下一個元素(每個元素32bits所以要推4個Byte)
		loop inputLoop			;進入下一次迴圈
	
	call Crlf					;換行

	;開始查找最大值與最小值
	call findMaxNum
	call findMinNum
	
	;輸出最小值
	mov EDX,OFFSET minString
	mov EAX,minNum
	call WriteString
	call WriteInt
	call Crlf

	;輸出最大值
	mov EDX,OFFSET maxString
	mov EAX,maxNum
	call WriteString
	call WriteInt
	call Crlf

	INVOKE ExitProcess,0		;主程式結束
main ENDP

END main