CUSTOM_MATRIX = lite

UART_DRIVER_REQUIRED = yes

# Include RP2040 specific rules if we're converting
ifdef CONVERT_TO_RP2040_CE
    include mcus/rp2040_rules.mk
endif

# Project specific files
SRC +=  common/bitc_led.c \
        common/remote_kb.c \
        matrix.c
