INCLUDE Irvine32.inc

.386
.model flat,stdcall
.stack 4096

ExitProcess PROTO,dwExitCode:DWORD

.data
dataNum SDWORD ?				;�s�񦳴X���Ʀr�n��J
numArray SDWORD 200 DUP(?)		;�s��ƭȪ��}�C
arrayIndex BYTE TYPE numArray	;�s��C�Ӥ��������O����t�Z(���:BYTE)
maxString  BYTE "Max=",0		;��X�̤j�� �ϥΪ��r��
minString  BYTE "Min=",0		;��X�̤j�p �ϥΪ��r��
maxNum SDWORD ?
minNum SDWORD ?

.code

;�ˬd�}�C���(Debug�ɥi�I�s)
checkArray PROC					
	;��l��CPU���� �һݼȦs��
	mov ECX,dataNum
	mov ESI,OFFSET numArray		;��l�ư}�C��m
	mov BL,arrayIndex			;�N�O����t�Z���JEBX���e8bits

	;�ϥΰj�� �ˬd�}�C�������
	outputArray:
		mov EAX,[ESI]			;�N�}�C���������ȱ���EAX
		call WriteInt			;��XEAX
		call Crlf				;����
		add ESI,EBX				;�N�}�C���O�����m���ܤU�@�Ӥ���(�C�Ӥ���32bits�ҥH�n��4��Byte)
		loop outputArray

	RET							;�Ƶ{������
checkArray ENDP

;�`���d��̤j��
findMaxNum PROC
	mov ESI,OFFSET numArray		;�N�}�C���O�����m���s���JESI
	mov BL,arrayIndex			;���]EBX���e8bits
	mov ECX,dataNum				;�]�w�j��p�ƾ�
	
	;�]�w�̤j��
	setMax:
		mov EAX,[ESI]			;���]�Ĥ@�ӭȬ��̤j��
		jmp decECX1

	;�ϥΰj��}�l�d��̤j��
	searchMax:					
		add ESI,EBX				;�N�}�C��m���U�@�Ӥ�����
		cmp	[ESI],EAX			;�����Ӽƭ�
		jg	setMax				;�Y������G�O�j��-->���]�̤j��
		decECX1:
			loop searchMax			
	
	
	mov maxNum,EAX				;�N�̤j�ȱ��J�����ܼ�
	

	RET							;�Ƶ{������
findMaxNum ENDP

;�`���d��̤p��
findMinNum PROC
	mov ESI,OFFSET numArray		;�N�}�C���O�����m���s���JESI
	mov BL,arrayIndex			;���]EBX���e8bits
	mov ECX,dataNum				;�]�w�j��p�ƾ�
	
	;�]�w�̤j��
	setMin:
		mov EAX,[ESI]			;���]�Ĥ@�ӭȬ��̤p��
		jmp changeECX2

	;�ϥΰj��}�l�d��̤j��
	searchMin:					
		add ESI,EBX				;�N�}�C��m���U�@�Ӥ�����
		cmp	[ESI],EAX			;�����Ӽƭ�
		jl	setMin				;�Y������G�O�j��-->���]�̤j��
		changeECX2:
			loop searchMin			
	
	
	mov minNum,EAX				;�N�̤p�ȱ��J�����ܼ�

	RET							;�Ƶ{������
findMinNum ENDP

main PROC
	;��l�ƨæ۩w�q CPU�����Ȧs��
	mov ECX,0					;��l��ECX��0
	call ReadInt				;Ū���n��J���Ʀr�ƶq
	mov dataNum,EAX 			;�ƥ��Ʀr�ƶq(�U���ˬd�}�C��ƭn��)
	mov ECX,EAX					;�N�ƶq���JECX��@LOOP��
	mov ESI,0					;��l��ESI��0
	mov ESI,OFFSET numArray		;�NnumArray���}�C�O����_�l��m�ǤJESI
	mov EBX,0					;��l��EBX��0
	mov BL,arrayIndex			;�N�}�C�C�Ӥ������O����t�Z���JEBX���e8��Bits
	
	;�ϥΰj�� �`����J�ƭȨæs�J�}�C
	inputLoop:
		call ReadInt
		mov [ESI],EAX			;�N�C�������쪺�Ʀr��J�}�C
		
		add ESI,EBX				;�N�}�C���O�����m���ܤU�@�Ӥ���(�C�Ӥ���32bits�ҥH�n��4��Byte)
		loop inputLoop			;�i�J�U�@���j��
	
	call Crlf					;����

	;�}�l�d��̤j�ȻP�̤p��
	call findMaxNum
	call findMinNum
	
	;��X�̤p��
	mov EDX,OFFSET minString
	mov EAX,minNum
	call WriteString
	call WriteInt
	call Crlf

	;��X�̤j��
	mov EDX,OFFSET maxString
	mov EAX,maxNum
	call WriteString
	call WriteInt
	call Crlf

	INVOKE ExitProcess,0		;�D�{������
main ENDP

END main