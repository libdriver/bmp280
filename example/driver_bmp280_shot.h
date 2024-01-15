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
 * @file      driver_bmp280_shot.h
 * @brief     driver bmp280 shot header file
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

#ifndef DRIVER_BMP280_SHOT_H
#define DRIVER_BMP280_SHOT_H

#include "driver_bmp280_interface.h"

#ifdef __cplusplus
extern "C"{
#endif

/**
 * @addtogroup bmp280_example_driver
 * @{
 */

/**
 * @brief bmp280 shot example default definition
 */
#define BMP280_SHOT_DEFAULT_TEMPERATURE_OVERSAMPLING        BMP280_OVERSAMPLING_x2            /**< temperatue oversampling x2 */
#define BMP280_SHOT_DEFAULT_PRESSURE_OVERSAMPLING           BMP280_OVERSAMPLING_x16           /**< pressure oversampling x16 */
#define BMP280_SHOT_DEFAULT_STANDBY_TIME                    BMP280_STANDBY_TIME_0P5_MS        /**< standby time 0.5ms */
#define BMP280_SHOT_DEFAULT_FILTER                          BMP280_FILTER_COEFF_16            /**< filter coeff 16 */
#define BMP280_SHOT_DEFAULT_SPI_WIRE                        BMP280_SPI_WIRE_4                 /**< spi wire 4 */

/**
 * @brief     shot example init
 * @param[in] interface is the set interface
 * @param[in] addr_pin is the chip address pin
 * @return    status code
 *            - 0 success
 *            - 1 init failed
 * @note      none
 */
uint8_t bmp280_shot_init(bmp280_interface_t interface, bmp280_address_t addr_pin);

/**
 * @brief  shot example deinit
 * @return status code
 *         - 0 success
 *         - 1 deinit failed
 * @note   none
 */
uint8_t bmp280_shot_deinit(void);

/**
 * @brief      shot example read
 * @param[out] *temperature points to a converted temperature buffer
 * @param[out] *pressure points to a converted pressure buffer
 * @return     status code
 *             - 0 success
 *             - 1 read failed
 * @note       none
 */
uint8_t bmp280_shot_read(float *temperature, float *pressure);

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif
