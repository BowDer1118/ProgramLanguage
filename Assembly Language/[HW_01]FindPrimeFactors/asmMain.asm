;�ɤJ��ƥ]
includelib legacy_stdio_definitions.lib		;C�y����Ʈw(�]���n�ϥ�scanf�Mprintf)

;�����O��(�@�w�n��J�A�o�˵{���~�|��l��)
.386				;�ϥ�386���O��
.model flat, C		;�{���O����ҫ���l��	�y�k:.model �O����Ҧ�[�A�y���Ҧ�][�A��L�Ҧ�]


;�ϥ�PROTO�ŧi��ƭ쫬
;�y�k:��ƦW�� PROTO �y������,�ѼƦC��
scanf PROTO C, format:PTR BYTE, args:VARARG		;C Library�T�w�y�k scanf("%d",&num)
printf PROTO C, pString:PTR BYTE, args:VARARG	;C Library�T�w�y�k printf("%d",num)
;�bx86�t�Τ�int�O�ϥ�EAX�Ȧs���A�x�s�A�ҥH�n��J�Ƶ{������ƫ��O�����O32bits����Ƽe��
AllPrimeFactors PROTO C, arg1:DWORD				;�ѼƸ�ƫ��O��DWORD(�L���ƫ����)


;�����ܼư�
.data
searchNum DWORD ?
format Byte "%d",0

;�{���X��
.code
asmMain PROC	;asmMain�{���_�I
	;�ϥ�invoke�I�s�Ƶ{��
	invoke scanf,ADDR format,ADDR searchNum
	invoke AllPrimeFactors,searchNum
	invoke printf,ADDR format,EAX
	RET ;�{������
asmMain ENDP	;asmMain�{�����I

;�զX�y���{������
END 