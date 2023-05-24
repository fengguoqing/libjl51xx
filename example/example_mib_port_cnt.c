#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>

#include "jl_base.h"
#include "mib.h"

int main(int argc, char *argv[])
{
	(void) argc;
	(void) argv;

	/* Set port 0 mib counter mode as read-clear */
	/* Get number of received valid unicast packets of port 0 */
	/* Clear all types of mib counter of port 0 */
	jl_uint64 counter = 0;

	jl_switch_init();

	jl_mib_port_rc_mode_set(UTP_PORT0, 1);

	jl_mib_port_get(UTP_PORT0, PORT_MIB_TX_PKT_UC_CNT, &counter);

	jl_mib_port_clear_all(UTP_PORT0);

	return 0;
}
