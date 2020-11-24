INCLUDE Irvine32.inc

includelib ucrt.lib							;C library
includelib legacy_stdio_definitions.lib		;C library


scanf PROTO C,format:PTR BYTE, args:VARARG

inputData PROTO,ptrDataArray:PTR SDWORD,DataNum:DWORD,ptrFormat:PTR BYTE

sortData PROTO,ptrDataArray:PTR SDWORD,DataNum:DWORD

outputData PROTO,ptrDataArray:PTR SDWORD,DataNum:DWORD,ptrString:PTR BYTE

ExitProcess PROTO,dwExitCode:DWORD