#ifndef __INC_HAL8822BWIFIONLYHWCFG_H
#define __INC_HAL8822BWIFIONLYHWCFG_H

void
ex_hal8822b_wifi_only_hw_config(
	IN struct wifi_only_cfg *pwifionlycfg
	);
void
ex_hal8822b_wifi_only_scannotify(
	IN struct wifi_only_cfg *pwifionlycfg,
	IN u1Byte  is_5g
	);
void
ex_hal8822b_wifi_only_switchbandnotify(
	IN struct wifi_only_cfg *pwifionlycfg,
	IN u1Byte  is_5g
	);
void
hal8822b_wifi_only_switch_antenna(IN struct wifi_only_cfg *pwifionlycfg,
	IN u1Byte  is_5g
	);
#endif
