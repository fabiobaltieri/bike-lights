/* LED */
#define LED1_PORT	PORTC
#define LED1_DDR	DDRC
#define LED1		PC0

#define LED234_PORT	PORTD
#define LED234_DDR	DDRD
#define LED2		PD7
#define LED3		PD6
#define LED4		PD5

#define led1_on()	LED1_PORT |=  _BV(LED1)
#define led1_off()	LED1_PORT &= ~_BV(LED1)
#define led2_on()	LED234_PORT |=  _BV(LED2)
#define led2_off()	LED234_PORT &= ~_BV(LED2)
#define led3_on()	LED234_PORT |=  _BV(LED3)
#define led3_off()	LED234_PORT &= ~_BV(LED3)
#define led4_on()	LED234_PORT |=  _BV(LED4)
#define led4_off()	LED234_PORT &= ~_BV(LED4)

#define led_init() \
	do { \
		LED1_DDR |= _BV(LED1); \
		LED234_DDR |= _BV(LED2) | _BV(LED3) | _BV(LED4); \
	} while (0);

/* SPI */
#define SPI_DDR  DDRB
#define SPI_PORT PORTB
#define SPI_SS   PB2
#define SPI_SCK  PB5
#define SPI_MOSI PB3
#define SPI_MISO PB4

/* nRF24L01+ SPI */
#define NRF_DDR  DDRB
#define NRF_PORT PORTB
#define NRF_CS   SPI_SS
#define NRF_CE   PB1

#define nrf_cs_h() (NRF_PORT |=  _BV(NRF_CS))
#define nrf_cs_l() (NRF_PORT &= ~_BV(NRF_CS))
#define nrf_ce_h() (NRF_PORT |=  _BV(NRF_CE))
#define nrf_ce_l() (NRF_PORT &= ~_BV(NRF_CE))

#define NRF_PCMSK PCMSK0
#define NRF_PCINT PCINT0

/* Switches */
#define SW_PORT        PORTC
#define SW_PIN         PINC
#define SW1            PC1
#define SW2            PC5
#define SW3            PC3
#define SW4            PC4

#define sw_init() \
	do { \
		SW_PORT |= _BV(SW1) | _BV(SW2) | _BV(SW3) | _BV(SW4); \
	} while (0)

#define sw1_read()	(!(SW_PIN & _BV(SW1)))
#define sw2_read()	(!(SW_PIN & _BV(SW2)))
#define sw3_read()	(!(SW_PIN & _BV(SW3)))
#define sw4_read()	(!(SW_PIN & _BV(SW4)))
