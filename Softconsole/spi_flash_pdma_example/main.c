/*******************************************************************************
 * (c) Copyright 2008-2013 Microsemi SoC Products Group.  All rights reserved.
 * 
 * This example project demonstrates communications with an external flash
 * device.
 *
 * Please refer to the file README.txt for further details about this example.
 *
 * SVN $Revision: 5510 $
 * SVN $Date: 2013-03-29 18:29:47 +0000 (Fri, 29 Mar 2013) $
 */
#include "drivers/mss_pdma/mss_pdma.h"
#include "drivers/mss_spi/mss_spi.h"
#include "drivers/spansion/spansion.h"

#define BUFFER_A_SIZE   3000

/* Manufactuer and device IDs for Atmel AT25DF641 SPI Flash. */
#define SPSN_ID2_25FL128S_64KB_MANUFACTURER_ID   (uint8_t)0x01
#define SPSN_ID2_25FL128S_64KB_DEVICE_ID         (uint8_t)0x4D


/*
 * Static global variables
 */

/***************************************************************************//**
 * main function.
 */
int main()
{
    volatile uint32_t errors = 0;
    uint32_t address = 0;
    uint16_t loop_count;
    uint8_t manufacturer_id = 0;
    uint8_t device_id = 0;
    static uint8_t g_flash_wr_buf[BUFFER_A_SIZE];
    static uint8_t g_flash_rd_buf[BUFFER_A_SIZE];

    
    /* Disable Watchdog */
    SYSREG->WDOG_CR = 0x00000000;

    /*--------------------------------------------------------------------------
     * Initialize the write and read Buffers
    */
    for(loop_count = 0; loop_count < (BUFFER_A_SIZE/2); loop_count++)
    {
        g_flash_wr_buf[loop_count] = 0x44 + loop_count;
        g_flash_rd_buf[loop_count] = 0x00;
    }
    for(loop_count = (BUFFER_A_SIZE/2); loop_count < BUFFER_A_SIZE; loop_count++)
    {
        g_flash_wr_buf[loop_count] = 0x33;
        g_flash_rd_buf[loop_count] = 0x00;
    }

    /*--------------------------------------------------------------------------
     * Flash Driver Initialization
    */
    FLASH_init();

    FLASH_global_unprotect();

    FLASH_erase_4k_block(0);

    /*--------------------------------------------------------------------------
     * Check SPI Flash part manufacturer and device ID.
    */
    FLASH_read_device_id_REMS(&manufacturer_id, &device_id);
    if ((manufacturer_id != SPSN_ID2_25FL128S_64KB_MANUFACTURER_ID) || (device_id != SPSN_ID2_25FL128S_64KB_DEVICE_ID))
    {
        ++errors;
    }

    FLASH_read_device_id(&manufacturer_id, &device_id);
        if ((manufacturer_id != SPSN_ID2_25FL128S_64KB_MANUFACTURER_ID) || (device_id != SPSN_ID2_25FL128S_64KB_DEVICE_ID))
        {
            ++errors;
        }
    /*--------------------------------------------------------------------------
     * Write Data to Flash.
    */
    address = 200;
    FLASH_program(address, g_flash_wr_buf, sizeof(g_flash_wr_buf));

    /*--------------------------------------------------------------------------
     * Read Data From Flash.
    */
    address = 200;
    FLASH_read(address, g_flash_rd_buf, sizeof(g_flash_wr_buf));

    while(1)
    {
        ;
    }
    return 0;
}
