#ifndef _GPIO_H_
#define _GPIO_H_

enum led_status {
	LED_ON=0,
	LED_OFF=1
};

enum led_gpio {
#if defined(MT7628_MP)
	POWER_LED=42,
	WAN_LED=43,
	WLAN_LED=44
#elif defined(MT7620_MP)
	POWER_LED=41,
	WAN_LED=40,
	WLAN_LED=72
#else
	POWER_LED=0,
	WAN_LED=0,
	WLAN_LED=0
#endif
};

extern void gpio_init(void);
extern void gpio_init_mdio(void);
extern void gpio_init_usb(int do_wait);

extern int mtk_set_gpio_dir(unsigned short gpio_nr, unsigned short gpio_dir_out);
extern int mtk_get_gpio_pin(unsigned short gpio_nr);
extern int mtk_set_gpio_pin(unsigned short gpio_nr, unsigned int val);

extern int DETECT_BTN_RESET(void);
extern int DETECT_BTN_WPS(void);

extern void LED_HIDE_ALL(void);
extern void LED_POWER_ON(void);

extern void LED_ALERT_ON(void);
extern void LED_ALERT_OFF(void);
extern void LED_ALERT_BLINK(void);

extern void LED_INIT(void);
extern void ALL_LED_STATUS(enum led_status status);
extern void LED_STATUS(enum led_gpio led, enum led_status status);

extern void wan_led_toggle(void);

#endif
