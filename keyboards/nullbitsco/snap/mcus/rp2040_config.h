#pragma once

/* Pin remapping for RP2040
 * Most pins keep the same name as on BIT-C Pro
 * Only A0-A3 are remapped to their RP2040 equivalents
 */

// A0-A3 pin remapping
#ifdef A0
    #undef A0
    #define A0 26
#endif
#ifdef A1
    #undef A1
    #define A1 27
#endif
#ifdef A2
    #undef A2
    #define A2 28
#endif
#ifdef A3
    #undef A3
    #define A3 29
#endif

// Remove AVR specific workarounds
#undef WDT_vect

// For UART implementation on RP2040
#ifdef SOFT_SERIAL_PIN
    #undef SOFT_SERIAL_PIN
    // Use hardware UART0 on the RP2040
    #define SERIAL_USART_TX_PIN GP0  // Change this to match your board
    #define SERIAL_USART_RX_PIN GP1  // Change this to match your board
    #define SERIAL_UART_DRIVER UART0  // Using UART0 by default
#endif