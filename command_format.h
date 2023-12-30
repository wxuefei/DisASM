//@                                                                                               @\\ 
//@           _             _         _            _                  _            _   _          @\\ 
//@          /\ \          /\ \      / /\         / /\               / /\         /\_\/\_\ _      @\\ 
//@         /  \ \____     \ \ \    / /  \       / /  \             / /  \       / / / / //\_\    @\\ 
//@        / /\ \_____\    /\ \_\  / / /\ \__   / / /\ \           / / /\ \__   /\ \/ \ \/ / /    @\\ 
//@       / / /\/___  /   / /\/_/ / / /\ \___\ / / /\ \ \         / / /\ \___\ /  \____\__/ /     @\\ 
//@      / / /   / / /   / / /    \ \ \ \/___// / /  \ \ \        \ \ \ \/___// /\/________/      @\\ 
//@     / / /   / / /   / / /      \ \ \     / / /___/ /\ \        \ \ \     / / /\/_// / /       @\\ 
//@    / / /   / / /   / / /   _    \ \ \   / / /_____/ /\ \   _    \ \ \   / / /    / / /        @\\ 
//@    \ \ \__/ / /___/ / /__ /_/\__/ / /  / /_________/\ \ \ /_/\__/ / /  / / /    / / /         @\\ 
//@     \ \___\/ //\__\/_/___\\ \/___/ /  / / /_       __\ \_\\ \/___/ /   \/_/    / / /          @\\ 
//@      \/_____/ \/_________/ \_____\/   \_\___\     /____/_/ \_____\/            \/_/           @\\ 
//@                                                                                               @\\ 
//@                                                                                               @\\ 
//@        DisASM                                                                                 @\\ 
//@        @ Vlad Salnikov (XXXRef), 2013                                                         @\\ 
//@        xxxref.com                                                                             @\\ 
//@                                                                                               @\\ 

typedef unsigned char uint8;

typedef struct {
	char scale;
	char index;
	char base;
	uint8 sib;
} SIB;

typedef struct {
	char mod;
	char reg;
	char rm;
	uint8 modrm;// HEX view of modrm
} MODRM;

typedef struct {
	uint8 bit0:1;//TODO: implement as bit field?
	uint8 bit1:1;
	uint8 bit2:1;
	uint8 bit3:1;
	uint8 bit4:1;
	uint8 bit5:1;
	uint8 bit6:1;
	uint8 bit7:1;
}SByte;

typedef union{
	char byte;
	SByte ubyte;
} UByte;

typedef struct {
	uint8 bytenum;
	uint8*hex_bytes;//array of command bytes
	char*bytes;//binary view
} OPCODE;

typedef struct {
	uint8 prefixcount;//number of prefixes
	uint8*p;//pointer to prefix array
	
	uint8 lnr;//lock and repeat prefixes-f0, f2, f3
	uint8 segr;//segment redefinition prefixes-2e, 36,3e,26,64,65
	uint8 opr;//operand size redefenition prefix-66
	uint8 sr;//address size redefenition prefix-67
} PREFIX;

typedef struct {
	char w;
	char s;
	char d;
	char reg;
	char tttn;
	char eee;//special purpose registers
	char uuu;//sreg3 (3 bits)
	char ff;//sreg2 (2 bits)
}SPECIALFIELDS;

typedef struct {
	PREFIX prefix;
	OPCODE opcode;
	SPECIALFIELDS sf;
	MODRM modrm;
	SIB sib;
	char*com_text;
	char**parameters;
	char*par;
	int par_count;
} SCommand;

#define MAX_COMMAND_LEN 15

#define RET_SUCCESS 0
#define RET_ERROR 1
#define RET_FILE_END 2

#define LINE_LEN 62
#define OPCODE_FIELD_OFFSET 0
#define EXT_FIELD_OFFSET 33
#define MODRM_FIELD_OFFSET 25
#define DESCRIPTION_FIELD_OFFSET 40
