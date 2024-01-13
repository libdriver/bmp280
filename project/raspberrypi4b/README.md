### 1. Board

#### 1.1 Board Info

Board Name: Raspberry Pi 4B.

IIC Pin: SCL/SDA GPIO3/GPIO2.

SPI Pin: SCLK/MOSI/MISO/CS GPIO11/GPIO10/GPIO9/GPIO8.

### 2. Install

#### 2.1 Dependencies

Install the necessary dependencies.

```shell
sudo apt-get install libgpiod-dev pkg-config cmake -y
```

#### 2.2 Makefile

Build the project.

```shell
make
```

Install the project and this is optional.

```shell
sudo make install
```

Uninstall the project and this is optional.

```shell
sudo make uninstall
```

#### 2.3 CMake

Build the project.

```shell
mkdir build && cd build 
cmake .. 
make
```

Install the project and this is optional.

```shell
sudo make install
```

Uninstall the project and this is optional.

```shell
sudo make uninstall
```

Test the project and this is optional.

```shell
make test
```

Find the compiled library in CMake. 

```cmake
find_package(bmp280 REQUIRED)
```

### 3.BMP280

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

8. Run bmp280 read function, num means the read times.

   ```shell
   bmp280 (-e read | --example=read) [--addr=<0 | 1>] [--interface=<iic | spi>] [--times=<num>]
   ```

7. Run bmp280 shot function, num means the read times.

   ```shell
   bmp280 (-e shot | --example=shot) [--addr=<0 | 1>] [--interface=<iic | spi>] [--times=<num>]
   ```

#### 3.2 Command Example

```shell
./bmp280 -i

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
./bmp280 -p

bmp280: SPI interface SCK connected to GPIO11(BCM).
bmp280: SPI interface MISO connected to GPIO9(BCM).
bmp280: SPI interface MOSI connected to GPIO10(BCM).
bmp280: SPI interface CS connected to GPIO8(BCM).
bmp280: IIC interface SCL connected to GPIO3(BCM).
bmp280: IIC interface SDA connected to GPIO2(BCM).
```

```shell
./bmp280 -t reg --interface=spi

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
bmp280: check mode error.
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
bmp280: check standby time error.
bmp280: set standby time 1000ms.
bmp280: check standby time error.
bmp280: set standby time 2000ms.
bmp280: check standby time error.
bmp280: set standby time 4000ms.
bmp280: check standby time error.
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
bmp280: bmp280_get_status test.
bmp280: status is 0x0C.
bmp280: bmp280_soft_reset test.
bmp280: check soft reset ok.
bmp280: finish register test.
```

```shell
./bmp280 -t read --interface=spi --times=3

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
bmp280: temperature is 31.81C.
bmp280: pressure is 101899.41pa.
bmp280: temperature is 31.93C.
bmp280: pressure is 101900.37pa.
bmp280: temperature is 31.93C.
bmp280: pressure is 101899.90pa.
bmp280: shot read test.
bmp280: temperature is 31.89C.
bmp280: pressure is 101900.48pa.
bmp280: temperature is 31.86C.
bmp280: pressure is 101900.27pa.
bmp280: temperature is 31.83C.
bmp280: pressure is 101900.02pa.
bmp280: finish read test.
```

```shell
./bmp280 -e read --interface=spi --times=3

bmp280: 1/3.
bmp280: temperature is 31.13C.
bmp280: pressure is 101894.30Pa.
bmp280: 2/3.
bmp280: temperature is 31.25C.
bmp280: pressure is 101893.90Pa.
bmp280: 3/3.
bmp280: temperature is 31.28C.
bmp280: pressure is 101896.27Pa.
```

```shell
./bmp280 -e shot --interface=spi --times=3

bmp280: 1/3.
bmp280: temperature is 30.52C.
bmp280: pressure is 101899.35Pa.
bmp280: 2/3.
bmp280: temperature is 30.52C.
bmp280: pressure is 101899.12Pa.
bmp280: 3/3.
bmp280: temperature is 30.52C.
bmp280: pressure is 101899.27Pa.
```

```shell
./bmp280 -h

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
