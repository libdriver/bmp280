[English](/README.md) | [ 简体中文](/README_zh-Hans.md) | [繁體中文](/README_zh-Hant.md) | [日本語](/README_ja.md) | [Deutsch](/README_de.md) | [한국어](/README_ko.md)

<div align=center>
<img src="/doc/image/logo.svg" width="400" height="150"/>
</div>

## LibDriver BMP280

[![MISRA](https://img.shields.io/badge/misra-compliant-brightgreen.svg)](/misra/README.md) [![API](https://img.shields.io/badge/api-reference-blue.svg)](https://www.libdriver.com/docs/bmp280/index.html) [![License](https://img.shields.io/badge/license-MIT-brightgreen.svg)](/LICENSE)

The BMP280 is an absolute barometric pressure sensor, which is especially feasible for mobile applications. Its small dimensions and its low power consumption allow for the implementation in battery-powered devices such as mobile phones, GPS modules or watches. The BMP280 is based on Bosch’s proven piezo-resistive pressure sensor technology featuring high accuracy and linearity as well as long-term stability and high EMC robustness. Numerous device operation options guarantee for highest flexibility. The device is optimized in terms of power consumption, resolution and filter performance.

LibDriver BMP280 is a full function driver of BMP280 launched by LibDriver.It provides continuous reading of pressure and temperature, single reading of pressure and temperature and other functions. LibDriver is MISRA compliant.

### Table of Contents

  - [Instruction](#Instruction)
  - [Install](#Install)
  - [Usage](#Usage)
    - [example basic](#example-basic)
    - [example shot](#example-shot)
  - [Document](#Document)
  - [Contributing](#Contributing)
  - [License](#License)
  - [Contact Us](#Contact-Us)

### Instruction

/src includes LibDriver BMP280 source files.

/interface includes LibDriver BMP280 IIC, SPI platform independent template.

/test includes LibDriver BMP280 driver test code and this code can test the chip necessary function simply.

/example includes LibDriver BMP280 sample code.

/doc includes LibDriver BMP280 offline document.

/datasheet includes BMP280 datasheet.

/project includes the common Linux and MCU development board sample code. All projects use the shell script to debug the driver and the detail instruction can be found in each project's README.md.

/misra includes the LibDriver MISRA code scanning results.

### Install

Reference /interface IIC, SPI platform independent template and finish your platform IIC, SPI driver.

Add the /src directory, the interface driver for your platform, and your own drivers to your project, if you want to use the default example drivers, add the /example directory to your project.

### Usage

You can refer to the examples in the /example directory to complete your own driver. If you want to use the default programming examples, here's how to use them.

#### example basic

```C
#include "driver_bmp280_basic.h"

uint8_t res;
uint32_t i;
float temperature_c;
float pressure_pa;

/* basic init */
res = bmp280_basic_init(BMP280_INTERFACE_IIC, BMP280_ADDRESS_ADO_LOW);
if (res != 0)
{
    return 1;
}

...
    
/* loop */
for (i = 0; i < 3; i++)
{
    /* delay 1000ms */
    bmp280_interface_delay_ms(1000);

    /* read data */
    res = bmp280_basic_read((float *)&temperature_c, (float *)&pressure_pa);
    if (res != 0)
    {
        (void)bmp280_basic_deinit();

        return 1;
    }

    /* output */
    bmp280_interface_debug_print("bmp280: %d/%d.\n", i + 1, 3);
    bmp280_interface_debug_print("bmp280: temperature is %0.2fC.\n", temperature_c);
    bmp280_interface_debug_print("bmp280: pressure is %0.2fPa.\n", pressure_pa);
    
    ...
}

...
    
/* deinit */
(void)bmp280_basic_deinit();

return 0;
```

#### example shot

```C
#include "driver_bmp280_shot.h"

uint8_t res;
uint32_t i;
float temperature_c;
float pressure_pa;

/* shot init */
res = bmp280_shot_init(BMP280_INTERFACE_IIC, BMP280_ADDRESS_ADO_LOW);
if (res != 0)
{
    return 1;
}

...
    
/* loop */
for (i = 0; i < 3; i++)
{
    /* delay 1000ms */
    bmp280_interface_delay_ms(1000);

    /* read data */
    res = bmp280_shot_read((float *)&temperature_c, (float *)&pressure_pa);
    if (res != 0)
    {
        (void)bmp280_shot_deinit();

        return 1;
    }

    /* output */
    bmp280_interface_debug_print("bmp280: %d/%d.\n", i + 1, 3);
    bmp280_interface_debug_print("bmp280: temperature is %0.2fC.\n", temperature_c);
    bmp280_interface_debug_print("bmp280: pressure is %0.2fPa.\n", pressure_pa);
    
    ...
}

...
    
/* deinit */
(void)bmp280_shot_deinit();

return 0;
```

### Document

Online documents: [https://www.libdriver.com/docs/bmp280/index.html](https://www.libdriver.com/docs/bmp280/index.html).

Offline documents: /doc/html/index.html.

### Contributing

Please refer to CONTRIBUTING.md.

### License

Copyright (c) 2015 - present LibDriver All rights reserved



The MIT License (MIT) 



Permission is hereby granted, free of charge, to any person obtaining a copy

of this software and associated documentation files (the "Software"), to deal

in the Software without restriction, including without limitation the rights

to use, copy, modify, merge, publish, distribute, sublicense, and/or sell

copies of the Software, and to permit persons to whom the Software is

furnished to do so, subject to the following conditions: 



The above copyright notice and this permission notice shall be included in all

copies or substantial portions of the Software. 



THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR

IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,

FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE

AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER

LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,

OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE

SOFTWARE. 

### Contact Us

Please send an e-mail to lishifenging@outlook.com.