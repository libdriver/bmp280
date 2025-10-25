### 1. Chip

#### 1.1 Chip Info

Chip Name: STM32F407ZGT6.

Extern Oscillator: 8MHz.

UART Pin: TX/RX PA9/PA10.

IIC Pin: SCL/SDA PB8/PB9.

SPI Pin: SCK/MISO/MOSI/CS  PA5/PA6/PA7/PA4.

### 2. Development and Debugging

#### 2.1 Integrated Development Environment

LibDriver provides both Keil and IAR integrated development environment projects.

MDK is the Keil ARM project and your Keil version must be 5 or higher.Keil ARM project needs STMicroelectronics STM32F4 Series Device Family Pack and you can download from https://www.keil.com/dd2/stmicroelectronics/stm32f407zgtx.

EW is the IAR ARM project and your IAR version must be 9 or higher.

#### 2.2 Serial Port Parameter

Baud Rate: 115200.

Data Bits : 8.

Stop Bits: 1.

Parity: None.

Flow Control: None.

#### 2.3 Serial Port Assistant

We use '\n' to wrap lines.If your serial port assistant displays exceptions (e.g. the displayed content does not divide lines), please modify the configuration of your serial port assistant or replace one that supports '\n' parsing.

### 3. BMP280

#### 3.1 Command Instruction

1. Show bmp280 chip and driver information.

   ```shell
   bmp280 (-i | --information)
   ```

2. Show bmp280 help.

   ```shell
   bmp280 (-h | --help)
   ```

3. Show bmp280 pin connections of the current board.

   ```shell
   bmp280 (-p | --port)
   ```

4. Run bmp280 register test.

   ```shell
   bmp280 (-t reg | --test=reg) [--addr=<0 | 1>] [--interface=<iic | spi>]
   ```

5. Run bmp280 read test, num means the test times. 

   ```shell
   bmp280 (-t read | --test=read) [--addr=<0 | 1>] [--interface=<iic | spi>] [--times=<num>]
   ```

6. Run bmp280 read function, num means the read times. 

   ```shell
   bmp280 (-e read | --example=read) [--addr=<0 | 1>] [--interface=<iic | spi>] [--times=<num>]
   ```

7. Run bmp280 shot function, num means the read times.

   ```shell
   bmp280 (-e shot | --example=shot) [--addr=<0 | 1>] [--interface=<iic | spi>] [--times=<num>]
   ```

#### 3.2 Command Example

```shell
bmp280 -i

bmp280: chip is Bosch BMP280.
bmp280: manufacturer is Bosch.
bmp280: interface is IIC SPI.
bmp280: driver version is 1.0.
bmp280: min supply voltage is 1.7V.
bmp280: max supply voltage is 3.6V.
bmp280: max current is 1.12mA.
bmp280: max temperature is 85.0C.
bmp280: min temperature is -40.0C.
```

```shell
bmp280 -p

bmp280: SPI interface SCK connected to GPIOA PIN5.
bmp280: SPI interface MISO connected to GPIOA PIN6.
bmp280: SPI interface MOSI connected to GPIOA PIN7.
bmp280: SPI interface CS connected to GPIOA PIN4.
bmp280: SCL connected to GPIOB PIN8.
bmp280: SDA connected to GPIOB PIN9.
```

```shell
bmp280 -t reg --addr=0 --interface=iic

bmp280: chip is Bosch BMP280.
bmp280: manufacturer is Bosch.
bmp280: interface is IIC SPI.
bmp280: driver version is 1.0.
bmp280: min supply voltage is 1.7V.
bmp280: max supply voltage is 3.6V.
bmp280: max current is 1.12mA.
bmp280: max temperature is 85.0C.
bmp280: min temperature is -40.0C.
bmp280: start register test.
bmp280: bmp280_set_interface/bmp280_get_interface test.
bmp280: set interface spi.
bmp280: check interface ok.
bmp280: set interface iic.
bmp280: check interface ok.
bmp280: bmp280_set_addr_pin/bmp280_get_addr_pin test.
bmp280: set addr pin low.
bmp280: check addr pin ok.
bmp280: set addr pin high.
bmp280: check addr pin ok.
bmp280: bmp280_set_temperatue_oversampling/bmp280_get_temperatue_oversampling test.
bmp280: set temperatue oversampling skip.
bmp280: check temperatue oversampling ok.
bmp280: set temperatue oversampling x1.
bmp280: check temperatue oversampling ok.
bmp280: set temperatue oversampling x2.
bmp280: check temperatue oversampling ok.
bmp280: set temperatue oversampling x4.
bmp280: check temperatue oversampling ok.
bmp280: set temperatue oversampling x8.
bmp280: check temperatue oversampling ok.
bmp280: set temperatue oversampling x16.
bmp280: check temperatue oversampling ok.
bmp280: bmp280_set_pressure_oversampling/bmp280_get_pressure_oversampling test.
bmp280: set pressure oversampling skip.
bmp280: check pressure oversampling ok.
bmp280: set pressure oversampling x1.
bmp280: check pressure oversampling ok.
bmp280: set pressure oversampling x2.
bmp280: check pressure oversampling ok.
bmp280: set pressure oversampling x4.
bmp280: check pressure oversampling ok.
bmp280: set pressure oversampling x8.
bmp280: check pressure oversampling ok.
bmp280: set pressure oversampling x16.
bmp280: check pressure oversampling ok.
bmp280: bmp280_set_mode/bmp280_get_mode test.
bmp280: set mode normal.
bmp280: check mode ok.
bmp280: set mode sleep.
bmp280: check mode ok.
bmp280: bmp280_set_standby_time/bmp280_get_standby_time test.
bmp280: set standby time 0.5ms.
bmp280: check standby time ok.
bmp280: set standby time 62.5ms.
bmp280: check standby time ok.
bmp280: set standby time 125ms.
bmp280: check standby time ok.
bmp280: set standby time 250ms.
bmp280: check standby time ok.
bmp280: set standby time 500ms.
bmp280: check standby time ok.
bmp280: set standby time 1000ms.
bmp280: check standby time ok.
bmp280: set standby time 2000ms.
bmp280: check standby time ok.
bmp280: set standby time 4000ms.
bmp280: check standby time ok.
bmp280: bmp280_set_filter/bmp280_get_filter test.
bmp280: set filter off.
bmp280: check filter ok.
bmp280: set filter coeff 2.
bmp280: check filter ok.
bmp280: set filter coeff 4.
bmp280: check filter ok.
bmp280: set filter coeff 8.
bmp280: check filter ok.
bmp280: set filter coeff 16.
bmp280: check filter ok.
bmp280: bmp280_set_spi_wire/bmp280_get_spi_wire test.
bmp280: set spi wire 3.
bmp280: check spi wire ok.
bmp280: set spi wire 4.
bmp280: check spi wire ok.
bmp280: bmp280_get_status test.
bmp280: status is 0x04.
bmp280: bmp280_soft_reset test.
bmp280: check soft reset ok.
bmp280: finish register test.
```

```shell
bmp280 -t read --addr=0 --interface=iic --times=3

bmp280: chip is Bosch BMP280.
bmp280: manufacturer is Bosch.
bmp280: interface is IIC SPI.
bmp280: driver version is 1.0.
bmp280: min supply voltage is 1.7V.
bmp280: max supply voltage is 3.6V.
bmp280: max current is 1.12mA.
bmp280: max temperature is 85.0C.
bmp280: min temperature is -40.0C.
bmp280: start read test.
bmp280: continue read test.
bmp280: temperature is 30.04C.
bmp280: pressure is 101882.62pa.
bmp280: temperature is 30.18C.
bmp280: pressure is 101882.59pa.
bmp280: temperature is 30.21C.
bmp280: pressure is 101881.77pa.
bmp280: shot read test.
bmp280: temperature is 30.20C.
bmp280: pressure is 101881.52pa.
bmp280: temperature is 30.17C.
bmp280: pressure is 101881.50pa.
bmp280: temperature is 30.14C.
bmp280: pressure is 101881.45pa.
bmp280: finish read test.
```

```shell
bmp280 -e read --addr=0 --interface=iic --times=3

bmp280: 1/3.
bmp280: temperature is 29.73C.
bmp280: pressure is 101881.15Pa.
bmp280: 2/3.
bmp280: temperature is 29.87C.
bmp280: pressure is 101882.49Pa.
bmp280: 3/3.
bmp280: temperature is 29.90C.
bmp280: pressure is 101882.45Pa.
```

```shell
bmp280 -e shot --addr=0 --interface=iic --times=3

bmp280: 1/3.
bmp280: temperature is 29.32C.
bmp280: pressure is 101880.50Pa.
bmp280: 2/3.
bmp280: temperature is 29.32C.
bmp280: pressure is 101879.95Pa.
bmp280: 3/3.
bmp280: temperature is 29.32C.
bmp280: pressure is 101879.95Pa.
```

```shell
bmp280 -h

Usage:
  bmp280 (-i | --information)
  bmp280 (-h | --help)
  bmp280 (-p | --port)
  bmp280 (-t reg | --test=reg) [--addr=<0 | 1>] [--interface=<iic | spi>]
  bmp280 (-t read | --test=read) [--addr=<0 | 1>] [--interface=<iic | spi>] [--times=<num>]
  bmp280 (-e read | --example=read) [--addr=<0 | 1>] [--interface=<iic | spi>] [--times=<num>]
  bmp280 (-e shot | --example=shot) [--addr=<0 | 1>] [--interface=<iic | spi>] [--times=<num>]

Options:
      --addr=<0 | 1>                 Set the chip iic address.([default: 0])
  -e <read | shot>, --example=<read | shot>
                                     Run the driver example.
  -h, --help                         Show the help.
  -i, --information                  Show the chip information.
      --interface=<iic | spi>        Set the chip interface.([default: iic])
  -p, --port                         Display the pin connections of the current board.
  -t <reg | read>, --test=<reg | read>
                                     Run the driver test.
      --times=<num>                  Set the running times.([default: 3])
```

