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
 * @file      driver_bmp280.h
 * @brief     driver bmp280 header file
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

#ifndef DRIVER_BMP280_H
#define DRIVER_BMP280_H

#include <stdio.h>
#include <stdint.h>
#include <string.h>

#ifdef __cplusplus
extern "C"{
#endif

/**
 * @defgroup bmp280_driver bmp280 driver function
 * @brief    bmp280 driver modules
 * @{
 */

/**
 * @addtogroup bmp280_base_driver
 * @{
 */

/**
 * @brief bmp280 interface enumeration definition
 */
typedef enum
{
    BMP280_INTERFACE_IIC = 0x00,        /**< iic interface */
    BMP280_INTERFACE_SPI = 0x01,        /**< spi interface */
} bmp280_interface_t;

/**
 * @brief bmp280 address enumeration definition
 */
typedef enum
{
    BMP280_ADDRESS_ADO_LOW  = (0x76 << 1),        /**< ADO is low */
    BMP280_ADDRESS_ADO_HIGH = (0x77 << 1),        /**< ADO is HIGH */
} bmp280_address_t;

/**
 * @brief bmp280 status enumeration definition
 */
typedef enum
{
    BMP280_STATUS_MEASURING = (1 << 3),        /**< measuring */
    BMP280_STATUS_IM_UPDATE = (1 << 0),        /**< im update */
} bmp280_status_t;

/**
 * @brief bmp280 oversampling enumeration definition
 */
typedef enum
{
    BMP280_OVERSAMPLING_SKIP = 0x00,        /**< oversampling x1 */
    BMP280_OVERSAMPLING_x1   = 0x01,        /**< oversampling x1 */
    BMP280_OVERSAMPLING_x2   = 0x02,        /**< oversampling x2 */
    BMP280_OVERSAMPLING_x4   = 0x03,        /**< oversampling x4 */
    BMP280_OVERSAMPLING_x8   = 0x04,        /**< oversampling x8 */
    BMP280_OVERSAMPLING_x16  = 0x05,        /**< oversampling x16 */
} bmp280_oversampling_t;

/**
 * @brief bmp280 mode enumeration definition
 */
typedef enum
{
    BMP280_MODE_SLEEP  = 0x00,        /**< sleep mode */
    BMP280_MODE_FORCED = 0x01,        /**< forced mode */
    BMP280_MODE_NORMAL = 0x03,        /**< normal mode */
} bmp280_mode_t;

/**
 * @brief bmp280 standby time enumeration definition
 */
typedef enum
{
    BMP280_STANDBY_TIME_0P5_MS  = 0x00,        /**< 0.5ms */
    BMP280_STANDBY_TIME_62P5_MS = 0x01,        /**< 62.5ms */
    BMP280_STANDBY_TIME_125_MS  = 0x02,        /**< 125ms */
    BMP280_STANDBY_TIME_250_MS  = 0x03,        /**< 250ms */
    BMP280_STANDBY_TIME_500_MS  = 0x04,        /**< 500ms */
    BMP280_STANDBY_TIME_1000_MS = 0x05,        /**< 1000ms */
    BMP280_STANDBY_TIME_2000_MS = 0x06,        /**< 2000ms */
    BMP280_STANDBY_TIME_4000_MS = 0x07,        /**< 4000ms */
} bmp280_standby_time_t;

/**
 * @brief bmp280 filter enumeration definition
 */
typedef enum
{
    BMP280_FILTER_OFF      = 0x00,        /**< off */
    BMP280_FILTER_COEFF_2  = 0x01,        /**< coeff 2 */
    BMP280_FILTER_COEFF_4  = 0x02,        /**< coeff 4 */
    BMP280_FILTER_COEFF_8  = 0x03,        /**< coeff 8 */
    BMP280_FILTER_COEFF_16 = 0x04,        /**< coeff 16 */
} bmp280_filter_t;

/**
 * @brief bmp280 spi wire enumeration definition
 */
typedef enum
{
    BMP280_SPI_WIRE_4 = 0x00,        /**< 4 wire */
    BMP280_SPI_WIRE_3 = 0x01,        /**< 3 wire */
} bmp280_spi_wire_t;

/**
 * @brief bmp280 handle structure definition
 */
typedef struct bmp280_handle_s
{
    uint8_t iic_addr;                                                                   /**< iic device address */
    uint8_t (*iic_init)(void);                                                          /**< point to an iic_init function address */
    uint8_t (*iic_deinit)(void);                                                        /**< point to an iic_deinit function address */
    uint8_t (*iic_read)(uint8_t addr, uint8_t reg, uint8_t *buf, uint16_t len);         /**< point to an iic_read function address */
    uint8_t (*iic_write)(uint8_t addr, uint8_t reg, uint8_t *buf, uint16_t len);        /**< point to an iic_write function address */
    uint8_t (*spi_init)(void);                                                          /**< point to a spi_init function address */
    uint8_t (*spi_deinit)(void);                                                        /**< point to a spi_deinit function address */
    uint8_t (*spi_read)(uint8_t reg, uint8_t *buf, uint16_t len);                       /**< point to a spi_read function address */
    uint8_t (*spi_write)(uint8_t reg, uint8_t *buf, uint16_t len);                      /**< point to a spi_write function address */
    void (*delay_ms)(uint32_t ms);                                                      /**< point to a delay_ms function address */
    void (*debug_print)(const char *const fmt, ...);                                    /**< point to a debug_print function address */
    uint8_t inited;                                                                     /**< inited flag */
    uint8_t iic_spi;                                                                    /**< iic spi interface */
    uint16_t t1;                                                                        /**< t1 register */
    int16_t t2;                                                                         /**< t2 register */
    int16_t t3;                                                                         /**< t3 register */
    uint16_t p1;                                                                        /**< p1 register */
    int16_t p2;                                                                         /**< p2 register */
    int16_t p3;                                                                         /**< p3 register */
    int16_t p4;                                                                         /**< p4 register */
    int16_t p5;                                                                         /**< p5 register */
    int16_t p6;                                                                         /**< p6 register */
    int16_t p7;                                                                         /**< p7 register */
    int16_t p8;                                                                         /**< p8 register */
    int16_t p9;                                                                         /**< p9 register */
    int32_t t_fine;                                                                     /**< inner register */
} bmp280_handle_t;

/**
 * @brief bmp280 information structure definition
 */
typedef struct bmp280_info_s
{
    char chip_name[32];                /**< chip name */
    char manufacturer_name[32];        /**< manufacturer name */
    char interface[8];                 /**< chip interface name */
    float supply_voltage_min_v;        /**< chip min supply voltage */
    float supply_voltage_max_v;        /**< chip max supply voltage */
    float max_current_ma;              /**< chip max current */
    float temperature_min;             /**< chip min operating temperature */
    float temperature_max;             /**< chip max operating temperature */
    uint32_t driver_version;           /**< driver version */
} bmp280_info_t;

/**
 * @}
 */

/**
 * @defgroup bmp280_link_driver bmp280 link driver function
 * @brief    bmp280 link driver modules
 * @ingroup  bmp280_driver
 * @{
 */

/**
 * @brief     initialize bmp280_handle_t structure
 * @param[in] HANDLE pointer to a bmp280 handle structure
 * @param[in] STRUCTURE bmp280_handle_t
 * @note      none
 */
#define DRIVER_BMP280_LINK_INIT(HANDLE, STRUCTURE)          memset(HANDLE, 0, sizeof(STRUCTURE))

/**
 * @brief     link iic_init function
 * @param[in] HANDLE pointer to a bmp280 handle structure
 * @param[in] FUC pointer to an iic_init function address
 * @note      none
 */
#define DRIVER_BMP280_LINK_IIC_INIT(HANDLE, FUC)           (HANDLE)->iic_init = FUC

/**
 * @brief     link iic_deinit function
 * @param[in] HANDLE pointer to a bmp280 handle structure
 * @param[in] FUC pointer to an iic_deinit function address
 * @note      none
 */
#define DRIVER_BMP280_LINK_IIC_DEINIT(HANDLE, FUC)         (HANDLE)->iic_deinit = FUC

/**
 * @brief     link iic_read function
 * @param[in] HANDLE pointer to a bmp280 handle structure
 * @param[in] FUC pointer to an iic_read function address
 * @note      none
 */
#define DRIVER_BMP280_LINK_IIC_READ(HANDLE, FUC)           (HANDLE)->iic_read = FUC

/**
 * @brief     link iic_write function
 * @param[in] HANDLE pointer to a bmp280 handle structure
 * @param[in] FUC pointer to an iic_write function address
 * @note      none
 */
#define DRIVER_BMP280_LINK_IIC_WRITE(HANDLE, FUC)          (HANDLE)->iic_write = FUC

/**
 * @brief     link spi_init function
 * @param[in] HANDLE pointer to a bmp280 handle structure
 * @param[in] FUC pointer to a spi_init function address
 * @note      none
 */
#define DRIVER_BMP280_LINK_SPI_INIT(HANDLE, FUC)           (HANDLE)->spi_init = FUC

/**
 * @brief     link spi_deinit function
 * @param[in] HANDLE pointer to a bmp280 handle structure
 * @param[in] FUC pointer to a spi_deinit function address
 * @note      none
 */
#define DRIVER_BMP280_LINK_SPI_DEINIT(HANDLE, FUC)         (HANDLE)->spi_deinit = FUC

/**
 * @brief     link spi_read function
 * @param[in] HANDLE pointer to a bmp280 handle structure
 * @param[in] FUC pointer to a spi_read function address
 * @note      none
 */
#define DRIVER_BMP280_LINK_SPI_READ(HANDLE, FUC)           (HANDLE)->spi_read = FUC

/**
 * @brief     link spi_write function
 * @param[in] HANDLE pointer to a bmp280 handle structure
 * @param[in] FUC pointer to a spi_write function address
 * @note      none
 */
#define DRIVER_BMP280_LINK_SPI_WRITE(HANDLE, FUC)          (HANDLE)->spi_write = FUC

/**
 * @brief     link delay_ms function
 * @param[in] HANDLE pointer to a bmp280 handle structure
 * @param[in] FUC pointer to a delay_ms function address
 * @note      none
 */
#define DRIVER_BMP280_LINK_DELAY_MS(HANDLE, FUC)           (HANDLE)->delay_ms = FUC

/**
 * @brief     link debug_print function
 * @param[in] HANDLE pointer to a bmp280 handle structure
 * @param[in] FUC pointer to a debug_print function address
 * @note      none
 */
#define DRIVER_BMP280_LINK_DEBUG_PRINT(HANDLE, FUC)        (HANDLE)->debug_print = FUC

/**
 * @}
 */

/**
 * @defgroup bmp280_base_driver bmp280 base driver function
 * @brief    bmp280 base driver modules
 * @ingroup  bmp280_driver
 * @{
 */

/**
 * @brief      get chip's information
 * @param[out] *info pointer to a bmp280 info structure
 * @return     status code
 *             - 0 success
 *             - 2 handle is NULL
 * @note       none
 */
uint8_t bmp280_info(bmp280_info_t *info);

/**
 * @brief     set the interface
 * @param[in] *handle pointer to a bmp280 handle structure
 * @param[in] interface chip interface
 * @return    status code
 *            - 0 success
 *            - 2 handle is NULL
 * @note      none
 */
uint8_t bmp280_set_interface(bmp280_handle_t *handle, bmp280_interface_t interface);

/**
 * @brief      get the interface
 * @param[in]  *handle pointer to a bmp280 handle structure
 * @param[out] *interface pointer to a chip interface buffer
 * @return     status code
 *             - 0 success
 *             - 2 handle is NULL
 * @note       none
 */
uint8_t bmp280_get_interface(bmp280_handle_t *handle, bmp280_interface_t *interface);

/**
 * @brief     set the iic address pin
 * @param[in] *handle pointer to a bmp280 handle structure
 * @param[in] addr_pin iic address pin
 * @return    status code
 *            - 0 success
 *            - 2 handle is NULL
 * @note      none
 */
uint8_t bmp280_set_addr_pin(bmp280_handle_t *handle, bmp280_address_t addr_pin);

/**
 * @brief      get the iic address pin
 * @param[in]  *handle pointer to a bmp280 handle structure
 * @param[out] *addr_pin pointer to an iic address pin buffer
 * @return     status code
 *             - 0 success
 *             - 2 handle is NULL
 * @note       none
 */
uint8_t bmp280_get_addr_pin(bmp280_handle_t *handle, bmp280_address_t *addr_pin);

/**
 * @brief     initialize the chip
 * @param[in] *handle pointer to a bmp280 handle structure
 * @return    status code
 *            - 0 success
 *            - 1 iic or spi initialization failed
 *            - 2 handle is NULL
 *            - 3 linked functions is NULL
 *            - 4 id is error
 *            - 5 get nvm calibration failed
 *            - 6 read calibration failed
 * @note      none
 */
uint8_t bmp280_init(bmp280_handle_t *handle);

/**
 * @brief     close the chip
 * @param[in] *handle pointer to a bmp280 handle structure
 * @return    status code
 *            - 0 success
 *            - 1 iic deinit failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 *            - 4 power down failed
 * @note      none
 */
uint8_t bmp280_deinit(bmp280_handle_t *handle);

/**
 * @brief      read the temperature and pressure data
 * @param[in]  *handle pointer to a bmp280 handle structure
 * @param[out] *temperature_raw pointer to a raw temperature buffer
 * @param[out] *temperature_c pointer to a converted temperature buffer
 * @param[out] *pressure_raw pointer to a raw pressure buffer
 * @param[out] *pressure_pa pointer to a converted pressure buffer
 * @return     status code
 *             - 0 success
 *             - 1 read failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 *             - 4 compensate pressure failed
 *             - 5 read timeout
 * @note       none
 */
uint8_t bmp280_read_temperature_pressure(bmp280_handle_t *handle, uint32_t *temperature_raw, float *temperature_c, 
                                         uint32_t *pressure_raw, float *pressure_pa);

/**
 * @brief      read the pressure data
 * @param[in]  *handle pointer to a bmp280 handle structure
 * @param[out] *pressure_raw pointer to a raw pressure buffer
 * @param[out] *pressure_pa pointer to a converted pressure buffer
 * @return     status code
 *             - 0 success
 *             - 1 pressure read failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 *             - 4 compensate pressure failed
 *             - 5 read timeout
 * @note       none
 */
uint8_t bmp280_read_pressure(bmp280_handle_t *handle, uint32_t *pressure_raw, float *pressure_pa);

/**
 * @brief      read the temperature data
 * @param[in]  *handle pointer to a bmp280 handle structure
 * @param[out] *temperature_raw pointer to a raw temperature buffer
 * @param[out] *temperature_c pointer to a converted temperature buffer
 * @return     status code
 *             - 0 success
 *             - 1 temperature read failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 *             - 4 compensate pressure failed
 *             - 5 read timeout
 * @note       none
 */
uint8_t bmp280_read_temperature(bmp280_handle_t *handle, uint32_t *temperature_raw, float *temperature_c);

/**
 * @brief     soft reset
 * @param[in] *handle pointer to a bmp280 handle structure
 * @return    status code
 *            - 0 success
 *            - 1 soft reset failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t bmp280_soft_reset(bmp280_handle_t *handle);

/**
 * @brief      get status
 * @param[in]  *handle pointer to a bmp280 handle structure
 * @param[out] *status pointer to a status buffer
 * @return     status code
 *             - 0 success
 *             - 1 get status failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t bmp280_get_status(bmp280_handle_t *handle, uint8_t *status);

/**
 * @brief     set temperatue oversampling
 * @param[in] *handle pointer to a bmp280 handle structure
 * @param[in] oversampling temperatue oversampling
 * @return    status code
 *            - 0 success
 *            - 1 set temperatue oversampling failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t bmp280_set_temperatue_oversampling(bmp280_handle_t *handle, bmp280_oversampling_t oversampling);

/**
 * @brief      get temperatue oversampling
 * @param[in]  *handle pointer to a bmp280 handle structure
 * @param[out] *oversampling pointer to a oversampling buffer
 * @return     status code
 *             - 0 success
 *             - 1 get temperatue oversampling failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t bmp280_get_temperatue_oversampling(bmp280_handle_t *handle, bmp280_oversampling_t *oversampling);

/**
 * @brief     set pressure oversampling
 * @param[in] *handle pointer to a bmp280 handle structure
 * @param[in] oversampling pressure oversampling
 * @return    status code
 *            - 0 success
 *            - 1 set pressure oversampling failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t bmp280_set_pressure_oversampling(bmp280_handle_t *handle, bmp280_oversampling_t oversampling);

/**
 * @brief      get pressure oversampling
 * @param[in]  *handle pointer to a bmp280 handle structure
 * @param[out] *oversampling pointer to a oversampling buffer
 * @return     status code
 *             - 0 success
 *             - 1 get pressure oversampling failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t bmp280_get_pressure_oversampling(bmp280_handle_t *handle, bmp280_oversampling_t *oversampling);

/**
 * @brief     set mode
 * @param[in] *handle pointer to a bmp280 handle structure
 * @param[in] mode chip mode
 * @return    status code
 *            - 0 success
 *            - 1 set mode failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t bmp280_set_mode(bmp280_handle_t *handle, bmp280_mode_t mode);

/**
 * @brief      get mode
 * @param[in]  *handle pointer to a bmp280 handle structure
 * @param[out] *mode pointer to a mode buffer
 * @return     status code
 *             - 0 success
 *             - 1 get mode failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t bmp280_get_mode(bmp280_handle_t *handle, bmp280_mode_t *mode);

/**
 * @brief     set standby time
 * @param[in] *handle pointer to a bmp280 handle structure
 * @param[in] standby_time standby time
 * @return    status code
 *            - 0 success
 *            - 1 set standby time failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t bmp280_set_standby_time(bmp280_handle_t *handle, bmp280_standby_time_t standby_time);

/**
 * @brief      get standby time
 * @param[in]  *handle pointer to a bmp280 handle structure
 * @param[out] *standby_time pointer to a standby time buffer
 * @return     status code
 *             - 0 success
 *             - 1 get standby time failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t bmp280_get_standby_time(bmp280_handle_t *handle, bmp280_standby_time_t *standby_time);

/**
 * @brief     set filter
 * @param[in] *handle pointer to a bmp280 handle structure
 * @param[in] filter input filter
 * @return    status code
 *            - 0 success
 *            - 1 set filter failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t bmp280_set_filter(bmp280_handle_t *handle, bmp280_filter_t filter);

/**
 * @brief      get filter
 * @param[in]  *handle pointer to a bmp280 handle structure
 * @param[out] *filter pointer to a filter buffer
 * @return     status code
 *             - 0 success
 *             - 1 get filter failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t bmp280_get_filter(bmp280_handle_t *handle, bmp280_filter_t *filter);

/**
 * @brief     set spi wire
 * @param[in] *handle pointer to a bmp280 handle structure
 * @param[in] spi spi wire
 * @return    status code
 *            - 0 success
 *            - 1 set spi wire failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t bmp280_set_spi_wire(bmp280_handle_t *handle, bmp280_spi_wire_t spi);

/**
 * @brief      get spi wire
 * @param[in]  *handle pointer to a bmp280 handle structure
 * @param[out] *spi pointer to a spi wire buffer
 * @return     status code
 *             - 0 success
 *             - 1 get spi wire failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t bmp280_get_spi_wire(bmp280_handle_t *handle, bmp280_spi_wire_t *spi);

/**
 * @}
 */

/**
 * @defgroup bmp280_extern_driver bmp280 extern driver function
 * @brief    bmp280 extern driver modules
 * @ingroup  bmp280_driver
 * @{
 */

/**
 * @brief     set the chip register
 * @param[in] *handle pointer to a bmp280 handle structure
 * @param[in] reg iic register address
 * @param[in] value data written to the register
 * @return    status code
 *            - 0 success
 *            - 1 write failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t bmp280_set_reg(bmp280_handle_t *handle, uint8_t reg, uint8_t value);

/**
 * @brief      get the chip register
 * @param[in]  *handle pointer to a bmp280 handle structure
 * @param[in]  reg iic register address
 * @param[out] *value pointer to a read data buffer
 * @return     status code
 *             - 0 success
 *             - 1 read failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t bmp280_get_reg(bmp280_handle_t *handle, uint8_t reg, uint8_t *value);

/**
 * @}
 */

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif
