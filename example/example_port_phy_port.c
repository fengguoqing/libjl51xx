#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>

#include "jl_base.h"
#include "port.h"

int main(int argc, char *argv[])
{
	(void) argc;
	(void) argv;

	jl_port_phy_ability_t ability;
	jl_port_speed_t speed;
	jl_port_duplex_t duplex;
	jl_port_link_status_t linkst;

	jl_switch_init();

	/* set PHY 1 with Auto negotiation, 100F,10F */
	/* and Symmetric PAUSE flow control abilities */
	memset(&ability, 0x00, sizeof(jl_port_phy_ability_t));
	ability.full_duplex_100 = 1;
	ability.full_duplex_10 = 1;
	ability.flow_control = 1;
	ability.asym_flow_control = 1;
	jl_port_phy_autoneg_ability_set(UTP_PORT1, &ability);

	/* set PHY 2 with Auto negotiation, 100F, without flow control */
	memset(&ability, 0x00, sizeof(jl_port_phy_ability_t));
	ability.full_duplex_100 = 1;
	jl_port_phy_autoneg_ability_set(UTP_PORT2, &ability);

	/* Get ability of PHY 1 */
	memset(&ability, 0x00, sizeof(jl_port_phy_ability_t));
	jl_port_phy_autoneg_ability_get(UTP_PORT1, &ability);

	/* Get PHY link status of UTP PORT 1 */
	speed = 0;
	duplex = 0;
	linkst = 0;
	jl_port_phy_link_status_get(UTP_PORT1, &linkst, &duplex, &speed);

	return 0;
}
