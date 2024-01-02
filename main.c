#include <stdio.h>
#include <stdlib.h>
//#include <curses.h>
#include <string.h>
//#include <windows.h>
#include "disasm.h"

int main() {
	uint8 push_1[]			= {0x6a, 0x01};
	uint8 int_3[]			= {0xcc};
	uint8 int_80[]			= {0xcd, 0x80};
	uint8 ret[]				= {0xc3};
	uint8 mov_edx_ecx[] 	= {0x89, 0xca};
	uint8 xor_eax_eax[]		= {0x31, 0xc0};
	uint8 call_imm32[]		= {0xe8, 0x01, 0x00, 0x00, 0x00};				//call 0x06, output is 01, this's wrong **
	uint8 add_eax_imm32[]	= {0x81, 0xc0, 0x01, 0x00, 0x00, 0x00}; 
	uint8 movbe_eax_ebx[]	= {0x0F, 0x38, 0xF0, 0x03};						//movbe  eax,DWORD PTR [ebx],out put is al **
	uint8 mov_al_ebx[] 		= {0x8A, 0x03};									//mov    al,BYTE PTR [ebx]
	
	//simd codes, not support
	uint8 vperm2f128[]		= {0xc4, 0xe3, 0x6d, 0x06, 0xcb, 0x01};       	//vperm2f128 ymm1,ymm2,ymm3,0x1
	//x64 codes, not support
	uint8 mov_rcx_0[]		= {0x48, 0x8b, 0x0d, 0x00, 0x00, 0x00, 0x00};	//mov rcx, [rip+imm32]
	uint8 lea_rcx_0[]		= {0x48, 0x8d, 0x0d, 0x00, 0x00, 0x00, 0x00};	//lea rcx, [rip+imm32]

	DISASM(push_1);
	DISASM(int_3);
	DISASM(int_80);
	DISASM(ret);
	DISASM(mov_edx_ecx);
	DISASM(xor_eax_eax);
	DISASM(call_imm32);
	DISASM(add_eax_imm32);
	DISASM(movbe_eax_ebx);
	DISASM(mov_al_ebx);
	// DISASM(vperm2f128);	//not support
		
	// DISASM(mov_rcx_0);

	return 0;
}
