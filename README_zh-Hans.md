[English](/README.md) | [ 简体中文](/README_zh-Hans.md) | [繁體中文](/README_zh-Hant.md) | [日本語](/README_ja.md) | [Deutsch](/README_de.md) | [한국어](/README_ko.md)

<div align=center>
<img src="/doc/image/logo.svg" width="400" height="150"/>
</div>

## LibDriver BMP280

[![MISRA](https://img.shields.io/badge/misra-compliant-brightgreen.svg)](/misra/README.md) [![API](https://img.shields.io/badge/api-reference-blue.svg)](https://www.libdriver.com/docs/bmp280/index.html) [![License](https://img.shields.io/badge/license-MIT-brightgreen.svg)](/LICENSE)

BMP280是一种绝对气压传感器，特别适用于移动应用。它的小尺寸和低功耗允许在电池供电的设备中实现，如手机、GPS模块或手表。BMP280基于博世久经考验的压阻式压力传感器技术，具有高精度和线性、长期稳定性和高EMC稳健性。众多的设备操作选项保证了最高的灵活性。该设备在功耗、分辨率和滤波器性能方面进行了优化。

LibDriver BMP280是LibDriver推出的BMP280全功能驱动，该驱动提供压强温度连续读取、压强温度单次读取等功能并且它符合MISRA标准。

### 目录

  - [说明](#说明)
  - [安装](#安装)
  - [使用](#使用)
    - [example basic](#example-basic)
    - [example shot](#example-shot)
  - [文档](#文档)
  - [贡献](#贡献)
  - [版权](#版权)
  - [联系我们](#联系我们)

### 说明

/src目录包含了LibDriver BMP280的源文件。

/interface目录包含了LibDriver BMP280与平台无关的IIC、SPI总线模板。

/test目录包含了LibDriver BMP280驱动测试程序，该程序可以简单的测试芯片必要功能。

/example目录包含了LibDriver BMP280编程范例。

/doc目录包含了LibDriver BMP280离线文档。

/datasheet目录包含了BMP280数据手册。

/project目录包含了常用Linux与单片机开发板的工程样例。所有工程均采用shell脚本作为调试方法，详细内容可参考每个工程里面的README.md。

/misra目录包含了LibDriver MISRA代码扫描结果。

### 安装

参考/interface目录下与平台无关的IIC、SPI总线模板，完成指定平台的IIC、SPI总线驱动。

将/src目录，/interface目录和/example目录加入工程。

### 使用

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

### 文档

在线文档: [https://www.libdriver.com/docs/bmp280/index.html](https://www.libdriver.com/docs/bmp280/index.html)。

离线文档: /doc/html/index.html。

### 贡献

请参考CONTRIBUTING.md。

### 版权

版权 (c) 2015 - 现在 LibDriver 版权所有

MIT 许可证（MIT）

特此免费授予任何获得本软件副本和相关文档文件（下称“软件”）的人不受限制地处置该软件的权利，包括不受限制地使用、复制、修改、合并、发布、分发、转授许可和/或出售该软件副本，以及再授权被配发了本软件的人如上的权利，须在下列条件下：

上述版权声明和本许可声明应包含在该软件的所有副本或实质成分中。

本软件是“如此”提供的，没有任何形式的明示或暗示的保证，包括但不限于对适销性、特定用途的适用性和不侵权的保证。在任何情况下，作者或版权持有人都不对任何索赔、损害或其他责任负责，无论这些追责来自合同、侵权或其它行为中，还是产生于、源于或有关于本软件以及本软件的使用或其它处置。

### 联系我们

请联系lishifenging@outlook.com。