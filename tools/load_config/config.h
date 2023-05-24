#include <stdlib.h>

#include "jl_types.h"

/* Autogenerated file, do not modify */

enum cmd_e {
    JL_CMD_NONE = 0,
    JL_CMD_WRITE,
    JL_CMD_BWRITE,
    JL_CMD_DELAY
};

enum cmd_flag_e {
    JL_CMD_FLAG_DA = 0,
    JL_CMD_FLAG_IDA,
    /* burst write size in word */
};

struct cmd_line_s {
    jl_uint8 cmd; //cmd=1, write;cmd=2, burst write;cmd=3, dealy
    jl_uint8 flag; //flag=0, DA；flag=1, IDA;if cmd==2,flag=burst size
    jl_uint32 addr; //regiter SMI access address
    jl_uint32 val; //register value;dealy time ms
}__attribute__ ((__packed__));

/* TODO this file only for example */
const struct cmd_line_s cmd_line_set[] = {
	/* direct write phy 1, page 3, reg 25, val 0x1234 */
	{1, 0, 0x20079, 0x1234},
	/* indirect write addr 0x100000, val 0x12345678 */
	{1, 1, 0x100000, 0x12345678},
	/* burst write addr 0x200000, val 0x12345678, 0xffffffff, 0x0 */
	{2, 3, 0x200000, 0x12345678},
	{0, 0, 0, 0xffffffff},
	{0, 0, 0, 0x0},
	/* delay for 1000us */
	{3, 0, 0, 1000}
};
