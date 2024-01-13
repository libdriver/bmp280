/**
 * Copyright (c) 2015 - present LibDriver All rights reserved
 * 
 * The MIT License (MIT)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE. 
 *
 * @file      driver_bmp280_read_test.c
 * @brief     driver bmp280 read test source file
 * @version   1.0.0
 * @author    Shifeng Li
 * @date      2024-01-15
 *
 * <h3>history</h3>
 * <table>
 * <tr><th>Date        <th>Version  <th>Author      <th>Description
 * <tr><td>2024/01/15  <td>1.0      <td>Shifeng Li  <td>first upload
 * </table>
 */

#include "driver_bmp280_read_test.h"

static bmp280_handle_t gs_handle;        /**< bmp280 handle */

/**
 * @brief     read test
 * @param[in] interface is the set interface
 * @param[in] addr_pin is the chip address pin
 * @param[in] times is the read times
 * @return    status code
 *            - 0 success
 *            - 1 test failed
 * @note      none
 */
uint8_t bmp280_read_test(bmp280_interface_t interface, bmp280_address_t addr_pin, uint32_t times)
{
    uint8_t res;
    uint32_t i;
    uint32_t temperature_raw;
    uint32_t pressure_raw;
    float temperature_c;
    float pressure_pa;
    bmp280_info_t info;
    
    /* link interface function */
    DRIVER_BMP280_LINK_INIT(&gs_handle, bmp280_handle_t); 
    DRIVER_BMP280_LINK_IIC_INIT(&gs_handle, bmp280_interface_iic_init);
    DRIVER_BMP280_LINK_IIC_DEINIT(&gs_handle, bmp280_interface_iic_deinit);
    DRIVER_BMP280_LINK_IIC_READ(&gs_handle, bmp280_interface_iic_read);
    DRIVER_BMP280_LINK_IIC_WRITE(&gs_handle, bmp280_interface_iic_write);
    DRIVER_BMP280_LINK_SPI_INIT(&gs_handle, bmp280_interface_spi_init);
    DRIVER_BMP280_LINK_SPI_DEINIT(&gs_handle, bmp280_interface_spi_deinit);
    DRIVER_BMP280_LINK_SPI_READ(&gs_handle, bmp280_interface_spi_read);
    DRIVER_BMP280_LINK_SPI_WRITE(&gs_handle, bmp280_interface_spi_write);
    DRIVER_BMP280_LINK_DELAY_MS(&gs_handle, bmp280_interface_delay_ms);
    DRIVER_BMP280_LINK_DEBUG_PRINT(&gs_handle, bmp280_interface_debug_print);
    
    /* get bmp280 info */
    res = bmp280_info(&info);
    if (res != 0)
    {
        bmp280_interface_debug_print("bmp280: get info failed.\n");
       
        return 1;
    }
    else
    {
        /* print bmp280 */
        bmp280_interface_debug_print("bmp280: chip is %s.\n", info.chip_name);
        bmp280_interface_debug_print("bmp280: manufacturer is %s.\n", info.manufacturer_name);
        bmp280_interface_debug_print("bmp280: interface is %s.\n", info.interface);
        bmp280_interface_debug_print("bmp280: driver version is %d.%d.\n", info.driver_version / 1000, (info.driver_version % 1000) / 100);
        bmp280_interface_debug_print("bmp280: min supply voltage is %0.1fV.\n", info.supply_voltage_min_v);
        bmp280_interface_debug_print("bmp280: max supply voltage is %0.1fV.\n", info.supply_voltage_max_v);
        bmp280_interface_debug_print("bmp280: max current is %0.2fmA.\n", info.max_current_ma);
        bmp280_interface_debug_print("bmp280: max temperature is %0.1fC.\n", info.temperature_max);
        bmp280_interface_debug_print("bmp280: min temperature is %0.1fC.\n", info.temperature_min);
    }
    
    /* start read test */
    bmp280_interface_debug_print("bmp280: start read test.\n");
    
    /* set interface */
    res = bmp280_set_interface(&gs_handle, interface);
    if (res != 0)
    {
        bmp280_interface_debug_print("bmp280: set interface failed.\n");
       
        return 1;
    }
    
    /* set addr pin */
    res = bmp280_set_addr_pin(&gs_handle, addr_pin);
    if (res != 0)
    {
        bmp280_interface_debug_print("bmp280: set addr pin failed.\n");
       
        return 1;
    }
    
    /* init */
    res = bmp280_init(&gs_handle);
    if (res != 0)
    {
        bmp280_interface_debug_print("bmp280: init failed.\n");
       
        return 1;
    }
    
    /* set temperatue oversampling x2 */
    res = bmp280_set_temperatue_oversampling(&gs_handle, BMP280_OVERSAMPLING_x2);
    if (res != 0)
    {
        bmp280_interface_debug_print("bmp280: set temperatue oversampling failed.\n");
        (void)bmp280_deinit(&gs_handle); 
        
        return 1;
    }
    
    /* set pressure oversampling x16 */
    res = bmp280_set_pressure_oversampling(&gs_handle, BMP280_OVERSAMPLING_x16);
    if (res != 0)
    {
        bmp280_interface_debug_print("bmp280: set pressure oversampling failed.\n");
        (void)bmp280_deinit(&gs_handle); 
        
        return 1;
    }
    
    /* set standby time 0.5ms */
    res = bmp280_set_standby_time(&gs_handle, BMP280_STANDBY_TIME_0P5_MS);
    if (res != 0)
    {
        bmp280_interface_debug_print("bmp280: set standby time failed.\n");
        (void)bmp280_deinit(&gs_handle); 
        
        return 1;
    }
    
    /* set filter 16 */
    res = bmp280_set_filter(&gs_handle, BMP280_FILTER_COEFF_16);
    if (res != 0)
    {
        bmp280_interface_debug_print("bmp280: set filter failed.\n");
        (void)bmp280_deinit(&gs_handle); 
        
        return 1;
    }
    
    /* set normal mode */
    res = bmp280_set_mode(&gs_handle, BMP280_MODE_NORMAL);
    if (res != 0)
    {
        bmp280_interface_debug_print("bmp280: set mode failed.\n");
        (void)bmp280_deinit(&gs_handle); 
        
        return 1;
    }
    
    /* delay 1000ms */
    bmp280_interface_delay_ms(1000);
    
    /* continue read test */
    bmp280_interface_debug_print("bmp280: continue read test.\n");
    
    /* loop */
    for (i = 0; i < times; i++)
    {
        /* read temperature pressure */
        res = bmp280_read_temperature_pressure(&gs_handle, &temperature_raw, &temperature_c, 
                                               &pressure_raw, &pressure_pa);
        if (res != 0)
        {
            bmp280_interface_debug_print("bmp280: read temperature pressure failed.\n");
            (void)bmp280_deinit(&gs_handle); 
            
            return 1;
        }
        
        /* delay 1000ms */
        bmp280_interface_delay_ms(1000);
        
        /* output */
        bmp280_interface_debug_print("bmp280: temperature is %0.2fC.\n", temperature_c);
        bmp280_interface_debug_print("bmp280: pressure is %0.2fpa.\n", pressure_pa);
    }
     
    /* set sleep mode */
    res = bmp280_set_mode(&gs_handle, BMP280_MODE_SLEEP);
    if (res != 0)
    {
        bmp280_interface_debug_print("bmp280: set mode failed.\n");
        (void)bmp280_deinit(&gs_handle); 
        
        return 1;
    }
    
    /* delay 1000ms */
    bmp280_interface_delay_ms(1000);
    
    /* shot read test */
    bmp280_interface_debug_print("bmp280: shot read test.\n");
    
    /* loop */
    for (i = 0; i < times; i++)
    {
        /* read temperature pressure */
        res = bmp280_read_temperature_pressure(&gs_handle, &temperature_raw, &temperature_c, 
                                               &pressure_raw, &pressure_pa);
        if (res != 0)
        {
            bmp280_interface_debug_print("bmp280: read temperature pressure failed.\n");
            (void)bmp280_deinit(&gs_handle); 
            
            return 1;
        }
        
        /* delay 1000ms */
        bmp280_interface_delay_ms(1000);
        
        /* output */
        bmp280_interface_debug_print("bmp280: temperature is %0.2fC.\n", temperature_c);
        bmp280_interface_debug_print("bmp280: pressure is %0.2fpa.\n", pressure_pa);
    }
    
    /* finish read test */
    bmp280_interface_debug_print("bmp280: finish read test.\n");
    (void)bmp280_deinit(&gs_handle); 
    
    return 0;
}
