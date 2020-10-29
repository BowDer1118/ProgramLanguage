;導入資料包
includelib legacy_stdio_definitions.lib		;C語言資料庫(因為要使用scanf和printf)

;偽指令區(一定要輸入，這樣程式才會初始化)
.386				;使用386指令集
.model flat, C		;程式記憶體模型初始化	語法:.model 記憶體模式[，語言模式][，其他模式]


;使用PROTO宣告函數原型
;語法:函數名稱 PROTO 語言類型,參數列表
scanf PROTO C, format:PTR BYTE, args:VARARG		;C Library固定語法 scanf("%d",&num)
printf PROTO C, pString:PTR BYTE, args:VARARG	;C Library固定語法 printf("%d",num)
;在x86系統中int是使用EAX暫存器再儲存，所以要放入副程式的資料型別必須是32bits的資料寬度
AllPrimeFactors PROTO C, arg1:DWORD				;參數資料型別為DWORD(無號數型整數)


;全域變數區
.data
searchNum DWORD ?
format Byte "%d",0

;程式碼區
.code
asmMain PROC	;asmMain程式起點
	;使用invoke呼叫副程式
	invoke scanf,ADDR format,ADDR searchNum
	invoke AllPrimeFactors,searchNum
	invoke printf,ADDR format,EAX
	RET ;程式結束
asmMain ENDP	;asmMain程式終點

;組合語言程式結束
END 