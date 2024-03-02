//                            用户定义设置
//   设置驱动器类型、要加载的字体、使用的引脚和 SPI 控制方法等
//
//   如果您希望能够定义多个设置，然后轻松地选择编译器使用的设置文件，请参阅 User_Setup_Select.h 文件。
//
//   如果此文件被正确编辑，则所有库示例草稿都应该能够在特定硬件设置下无需进行任何其他更改而运行！
//   请注意，某些草稿是针对特定的 TFT 像素宽度/高度设计的

// "Read_User_Setup" 测试和诊断示例报告的用户定义信息
#define USER_SETUP_INFO "User_Setup"

// 定义以禁用库中的所有 #warnings（可以放在 User_Setup_Select.h 中）
//#define DISABLE_ALL_LIBRARY_WARNINGS

// ##################################################################################
//
// 第 1 部分。调用正确的驱动程序文件和任何选项
//
// ##################################################################################

// Define STM32 to invoke optimised processor support (only for STM32)
//#define STM32

// Defining the STM32 board allows the library to optimise the performance
// for UNO compatible "MCUfriend" style shields
//#define NUCLEO_64_TFT
//#define NUCLEO_144_TFT

// STM32 8 bit parallel only:
// If STN32 Port A or B pins 0-7 are used for 8 bit parallel data bus bits 0-7
// then this will improve rendering performance by a factor of ~8x
//#define STM_PORTA_DATA_BUS
//#define STM_PORTB_DATA_BUS

// Tell the library to use parallel mode (otherwise SPI is assumed)
//#define TFT_PARALLEL_8_BIT
//#defined TFT_PARALLEL_16_BIT // **** 16 bit parallel ONLY for RP2040 processor ****

// Display type -  only define if RPi display
//#define RPI_DISPLAY_TYPE // 20MHz maximum SPI

// 仅定义一个驱动程序，其他驱动程序必须被注释掉
#define ILI9341_DRIVER       // Generic driver for common displays
//#define ILI9341_2_DRIVER     /// 备用的 ILI9341 驱动程序，请参阅 https://github.com/Bodmer/TFT_eSPI/issues/1172
//#define ST7735_DRIVER      // Define additional parameters below for this display
//#define ILI9163_DRIVER     // Define additional parameters below for this display
//#define S6D02A1_DRIVER
//#define RPI_ILI9486_DRIVER // 20MHz maximum SPI
//#define HX8357D_DRIVER
//#define ILI9481_DRIVER
//#define ILI9486_DRIVER
//#define ILI9488_DRIVER     // WARNING: Do not connect ILI9488 display SDO to MISO if other devices share the SPI bus (TFT SDO does NOT tristate when CS is high)
//#define ST7789_DRIVER      // Full configuration option, define additional parameters below for this display
//#define ST7789_2_DRIVER    // Minimal configuration option, define additional parameters below for this display
//#define R61581_DRIVER
//#define RM68140_DRIVER
//#define ST7796_DRIVER
//#define SSD1351_DRIVER
//#define SSD1963_480_DRIVER
//#define SSD1963_800_DRIVER
//#define SSD1963_800ALT_DRIVER
//#define ILI9225_DRIVER
//#define GC9A01_DRIVER

// Some displays support SPI reads via the MISO pin, other displays have a single
// bi-directional SDA pin and the library will try to read this via the MOSI line.
// To use the SDA line for reading data from the TFT uncomment the following line:

// #define TFT_SDA_READ      // This option is for ESP32 ONLY, tested with ST7789 and GC9A01 display only

// 仅对于 ST7735、ST7789 和 ILI9341，如果您的显示器上的蓝色和红色颜色互换，请定义颜色顺序
// 尝试一个选项，找到适合您显示器的正确颜色顺序

// #define TFT_RGB_ORDER TFT_RGB  // Colour order Red-Green-Blue
#define TFT_RGB_ORDER TFT_BGR  // Colour order Blue-Green-Red

// 仅对于集成了 ILI9341 显示器的 M5Stack ESP32 模块，请取消以下行中的注释

// #define M5STACK

// 仅对于 ST7789、ST7735、ILI9163 和 GC9A01，请在纵向方向中定义像素宽度和高度
// #define TFT_WIDTH  80
// #define TFT_WIDTH  128
// #define TFT_WIDTH  172 // ST7789 172 x 320
// #define TFT_WIDTH  170 // ST7789 170 x 320
// #define TFT_WIDTH  240 // ST7789 240 x 240 and 240 x 320
// #define TFT_HEIGHT 160
// #define TFT_HEIGHT 128
// #define TFT_HEIGHT 240 // ST7789 240 x 240
// #define TFT_HEIGHT 320 // ST7789 240 x 320
// #define TFT_HEIGHT 240 // GC9A01 240 x 240

// 仅对于 ST7735，请定义显示器类型，最初这是基于屏幕保护膜上的标签颜色，但这并不总是正确的，
// 因此，如果屏幕显示图形不正确，则尝试以下不同选项，
// 例如颜色错误、镜像图像或边缘处的杂散像素。
// 对于 ST7735 显示器驱动程序，将所有选项注释掉，除了其中一个，请保存此 User_Setup 文件，
// 然后重新构建并将草稿上传到板上：

// #define ST7735_INITB
// #define ST7735_GREENTAB
// #define ST7735_GREENTAB2
// #define ST7735_GREENTAB3
// #define ST7735_GREENTAB128    // For 128 x 128 display
// #define ST7735_GREENTAB160x80 // For 160 x 80 display (BGR, inverted, 26 offset)
// #define ST7735_ROBOTLCD       // For some RobotLCD arduino shields (128x160, BGR, https://docs.arduino.cc/retired/getting-started-guides/TFT)
// #define ST7735_REDTAB
// #define ST7735_BLACKTAB
// #define ST7735_REDTAB160x80   // For 160 x 80 display with 24 pixel offset

// 如果颜色反转（白色显示为黑色），请取消注释下面两行中的一个选项，两个选项中的一个应该可以纠正反转。

// #define TFT_INVERSION_ON
// #define TFT_INVERSION_OFF


// ##################################################################################
//
// 第 2 部分。在此定义用于与显示器进行接口的引脚
//
// ##################################################################################

// 如果有背光控制信号可用，请在以下第 2 部分中定义 TFT_BL 引脚。
// 当调用 tft.begin() 时，背光将打开，但库需要知道 LED 是否在高电平或低电平时打开。
// 如果 LED 将以 PWM 信号驱动或关闭/打开，则必须由用户 sketch 处理。
// 例如，使用 digitalWrite(TFT_BL, LOW);

// #define TFT_BL   32            // LED back-light control pin
// #define TFT_BACKLIGHT_ON HIGH  // Level to turn ON back-light (HIGH or LOW)



// We must use hardware SPI, a minimum of 3 GPIO pins is needed.
// ESP8266 NodeMCU ESP-12 的典型设置是：
//
// Display SDO/MISO  to NodeMCU pin D6 (or leave disconnected if not reading TFT)
// Display LED       to NodeMCU pin VIN (or 5V, see below)
// Display SCK       to NodeMCU pin D5
// Display SDI/MOSI  to NodeMCU pin D7
// Display DC (RS/AO)to NodeMCU pin D3
// Display RESET     to NodeMCU pin D4 (or RST, see below)
// Display CS        to NodeMCU pin D8 (or GND, see below)
// Display GND       to NodeMCU pin GND (0V)
// Display VCC       to NodeMCU 5V or 3.3V
//
// TFT RESET 引脚可以连接到 NodeMCU RST 引脚或 3.3V 以释放控制引脚
//
// DC（数据命令）引脚可能标记为 AO 或 RS（寄存器选择）
//
// 对于某些显示器（例如 ILI9341），如果没有更多 SPI 设备（例如 SD 卡）连接，TFT CS 引脚可以连接到 GND，如果是这种情况，请注释掉 #define TFT_CS
// 下面的行，以便它不被定义。其他显示器（例如 ST7735）要求在设置期间切换 TFT CS 引脚，因此在这些情况下，必须定义和连接 TFT_CS 行。
//
// NodeMCU D0 引脚可用于 RST
//
//
// 注意：仅某些版本的 NodeMCU 在 VIN 引脚上提供 USB 5V
// 如果在引脚上不可用 5V，则可以使用 3.3V，但背光亮度
// 将更低。



// ###### 根据您的 ESP8266 设置编辑以下行中的引脚编号 ######

// For NodeMCU - use pin numbers in the form PIN_Dx where Dx is the NodeMCU pin designation
//#define TFT_MISO  PIN_D6  // Automatically assigned with ESP8266 if not defined
//#define TFT_MOSI  PIN_D7  // Automatically assigned with ESP8266 if not defined
//#define TFT_SCLK  PIN_D5  // Automatically assigned with ESP8266 if not defined

//#define TFT_CS    PIN_D8  // Chip select control pin D8
//#define TFT_DC    PIN_D3  // Data Command control pin
//#define TFT_RST   PIN_D4  // Reset pin (could connect to NodeMCU RST, see next line)
//#define TFT_RST  -1     // Set TFT_RST to -1 if the display RESET is connected to NodeMCU RST or 3.3V


//#define TFT_BL PIN_D1  // LED back-light (only for ST7789 with backlight control pin)

//#define TOUCH_CS PIN_D2     // Chip select pin (T_CS) of touch screen

//#define TFT_WR PIN_D2       // Write strobe for modified Raspberry Pi TFT only


// ######  FOR ESP8266 OVERLAP MODE EDIT THE PIN NUMBERS IN THE FOLLOWING LINES  ######

// Overlap mode shares the ESP8266 FLASH SPI bus with the TFT so has a performance impact
// but saves pins for other functions. It is best not to connect MISO as some displays
// do not tristate that line when chip select is high!
// Note: Only one SPI device can share the FLASH SPI lines, so a SPI touch controller
// cannot be connected as well to the same SPI signals.
// On NodeMCU 1.0 SD0=MISO, SD1=MOSI, CLK=SCLK to connect to TFT in overlap mode
// On NodeMCU V3  S0 =MISO, S1 =MOSI, S2 =SCLK
// In ESP8266 overlap mode the following must be defined

//#define TFT_SPI_OVERLAP

// In ESP8266 overlap mode the TFT chip select MUST connect to pin D3
//#define TFT_CS   PIN_D3
//#define TFT_DC   PIN_D5  // Data Command control pin
//#define TFT_RST  PIN_D4  // Reset pin (could connect to NodeMCU RST, see next line)
//#define TFT_RST  -1  // Set TFT_RST to -1 if the display RESET is connected to NodeMCU RST or 3.3V


// ###### 根据您的 ESP32 设置编辑以下行中的引脚编号   ######

// 对于 ESP32 Dev 板（仅与 ILI9341 显示器测试过）
// 硬件 SPI 可映射到任何引脚
// 如果您想通过软件指定复位引脚，则使用 #define TFT_RST 4；如果您将复位引脚直接连接到 ESP32 开发板的 RST 引脚，则使用 #define TFT_RST -1。

#define TFT_MISO 19
#define TFT_MOSI 23
#define TFT_SCLK 18
#define TFT_CS   15  // Chip select control pin
#define TFT_DC    2  // Data Command control pin
#define TFT_RST   4  // Reset pin (could connect to RST pin)
//#define TFT_RST  -1  // Set TFT_RST to -1 if display RESET is connected to ESP32 board RST

// For ESP32 Dev board (only tested with GC9A01 display)
// The hardware SPI can be mapped to any pins

//#define TFT_MOSI 15 // In some display driver board, it might be written as "SDA" and so on.
//#define TFT_SCLK 14
//#define TFT_CS   5  // Chip select control pin
//#define TFT_DC   27  // Data Command control pin
//#define TFT_RST  33  // Reset pin (could connect to Arduino RESET pin)
//#define TFT_BL   22  // LED back-light

//#define TOUCH_CS 21     // Chip select pin (T_CS) of touch screen

//#define TFT_WR 22    // Write strobe for modified Raspberry Pi TFT only

// For the M5Stack module use these #define lines
//#define TFT_MISO 19
//#define TFT_MOSI 23
//#define TFT_SCLK 18
//#define TFT_CS   14  // Chip select control pin
//#define TFT_DC   27  // Data Command control pin
//#define TFT_RST  33  // Reset pin (could connect to Arduino RESET pin)
//#define TFT_BL   32  // LED back-light (required for M5Stack)

// ######       EDIT THE PINs BELOW TO SUIT YOUR ESP32 PARALLEL TFT SETUP        ######

// The library supports 8 bit parallel TFTs with the ESP32, the pin
// selection below is compatible with ESP32 boards in UNO format.
// Wemos D32 boards need to be modified, see diagram in Tools folder.
// Only ILI9481 and ILI9341 based displays have been tested!

// Parallel bus is only supported for the STM32 and ESP32
// Example below is for ESP32 Parallel interface with UNO displays

// Tell the library to use 8 bit parallel mode (otherwise SPI is assumed)
//#define TFT_PARALLEL_8_BIT

// The ESP32 and TFT the pins used for testing are:
//#define TFT_CS   33  // Chip select control pin (library pulls permanently low
//#define TFT_DC   15  // Data Command control pin - must use a pin in the range 0-31
//#define TFT_RST  32  // Reset pin, toggles on startup

//#define TFT_WR    4  // Write strobe control pin - must use a pin in the range 0-31
//#define TFT_RD    2  // Read strobe control pin

//#define TFT_D0   12  // Must use pins in the range 0-31 for the data bus
//#define TFT_D1   13  // so a single register write sets/clears all bits.
//#define TFT_D2   26  // Pins can be randomly assigned, this does not affect
//#define TFT_D3   25  // TFT screen update performance.
//#define TFT_D4   17
//#define TFT_D5   16
//#define TFT_D6   27
//#define TFT_D7   14

// ######       EDIT THE PINs BELOW TO SUIT YOUR STM32 SPI TFT SETUP        ######

// The TFT can be connected to SPI port 1 or 2
//#define TFT_SPI_PORT 1 // SPI port 1 maximum clock rate is 55MHz
//#define TFT_MOSI PA7
//#define TFT_MISO PA6
//#define TFT_SCLK PA5

//#define TFT_SPI_PORT 2 // SPI port 2 maximum clock rate is 27MHz
//#define TFT_MOSI PB15
//#define TFT_MISO PB14
//#define TFT_SCLK PB13

// Can use Ardiuno pin references, arbitrary allocation, TFT_eSPI controls chip select
//#define TFT_CS   D5 // Chip select control pin to TFT CS
//#define TFT_DC   D6 // Data Command control pin to TFT DC (may be labelled RS = Register Select)
//#define TFT_RST  D7 // Reset pin to TFT RST (or RESET)
// OR alternatively, we can use STM32 port reference names PXnn
//#define TFT_CS   PE11 // Nucleo-F767ZI equivalent of D5
//#define TFT_DC   PE9  // Nucleo-F767ZI equivalent of D6
//#define TFT_RST  PF13 // Nucleo-F767ZI equivalent of D7

//#define TFT_RST  -1   // Set TFT_RST to -1 if the display RESET is connected to processor reset
                        // Use an Arduino pin for initial testing as connecting to processor reset
                        // may not work (pulse too short at power up?)

// ##################################################################################
//
// 第 3 部分。在此定义要使用的字体
//
// ##################################################################################

// 使用 // 注释掉以下 #defines 来阻止加载该字体
// ESP8366 和 ESP32 有足够的内存，因此通常不需要注释掉字体。
// 如果加载所有字体，所需的额外 FLASH 空间约为 17K 字节。
// 为了节省 FLASH 空间，请仅启用您需要的字体！

#define LOAD_GLCD   // Font 1. Original Adafruit 8 pixel font needs ~1820 bytes in FLASH
#define LOAD_FONT2  // Font 2. Small 16 pixel high font, needs ~3534 bytes in FLASH, 96 characters
#define LOAD_FONT4  // Font 4. Medium 26 pixel high font, needs ~5848 bytes in FLASH, 96 characters
#define LOAD_FONT6  // Font 6. Large 48 pixel font, needs ~2666 bytes in FLASH, only characters 1234567890:-.apm
#define LOAD_FONT7  // Font 7. 7 segment 48 pixel font, needs ~2438 bytes in FLASH, only characters 1234567890:-.
#define LOAD_FONT8  // Font 8. Large 75 pixel font needs ~3256 bytes in FLASH, only characters 1234567890:-.
//#define LOAD_FONT8N // Font 8. Alternative to Font 8 above, slightly narrower, so 3 digits fit a 160 pixel TFT
#define LOAD_GFXFF  // FreeFonts. Include access to the 48 Adafruit_GFX free fonts FF1 to FF48 and custom fonts

// Comment out the #define below to stop the SPIFFS filing system and smooth font code being loaded
// this will save ~20kbytes of FLASH
#define SMOOTH_FONT


// ##################################################################################
//
// 第 4 部分。其他选项
//
// ##################################################################################


// For RP2040 processor and SPI displays, uncomment the following line to use the PIO interface.
//#define RP2040_PIO_SPI // Leave commented out to use standard RP2040 SPI port interface

// For RP2040 processor and 8 or 16 bit parallel displays:
// The parallel interface write cycle period is derived from a division of the CPU clock
// speed so scales with the processor clock. This means that the divider ratio may need
// to be increased when overclocking. It may also need to be adjusted dependant on the
// display controller type (ILI94341, HX8357C etc). If RP2040_PIO_CLK_DIV is not defined
// the library will set default values which may not suit your display.
// The display controller data sheet will specify the minimum write cycle period. The
// controllers often work reliably for shorter periods, however if the period is too short
// the display may not initialise or graphics will become corrupted.
// PIO write cycle frequency = (CPU clock/(4 * RP2040_PIO_CLK_DIV))
//#define RP2040_PIO_CLK_DIV 1 // 32ns write cycle at 125MHz CPU clock
//#define RP2040_PIO_CLK_DIV 2 // 64ns write cycle at 125MHz CPU clock
//#define RP2040_PIO_CLK_DIV 3 // 96ns write cycle at 125MHz CPU clock

// For the RP2040 processor define the SPI port channel used (default 0 if undefined)
//#define TFT_SPI_PORT 1 // Set to 0 if SPI0 pins are used, or 1 if spi1 pins used

// For the STM32 processor define the SPI port channel used (default 1 if undefined)
//#define TFT_SPI_PORT 2 // Set to 1 for SPI port 1, or 2 for SPI port 2

// 定义 SPI 时钟频率，这会影响图形渲染速度。如果太快，TFT 驱动器无法跟上，
// 就会出现显示损坏。对于 ILI9341 显示器，40MHz 可以正常工作，80MHz 有时会失败。
// 对于 ST7735 显示器，超过 27MHz 可能无法正常工作（出现杂散像素和线条）。
// 对于 ILI9163 显示器，27 MHz 可以正常工作。


// #define SPI_FREQUENCY   1000000
// #define SPI_FREQUENCY   5000000
// #define SPI_FREQUENCY  10000000
// #define SPI_FREQUENCY  20000000
//#define SPI_FREQUENCY  27000000
 #define SPI_FREQUENCY  40000000
// #define SPI_FREQUENCY  55000000 // STM32 SPI1 only (SPI2 maximum is 27MHz)
// #define SPI_FREQUENCY  80000000

// Optional reduced SPI frequency for reading TFT
#define SPI_READ_FREQUENCY  20000000

// The XPT2046 requires a lower SPI clock rate of 2.5MHz so we define that here:
#define SPI_TOUCH_FREQUENCY  2500000

// The ESP32 has 2 free SPI ports i.e. VSPI and HSPI, the VSPI is the default.
// If the VSPI port is in use and pins are not accessible (e.g. TTGO T-Beam)
// then uncomment the following line:
//#define USE_HSPI_PORT

// Comment out the following #define if "SPI Transactions" do not need to be
// supported. When commented out the code size will be smaller and sketches will
// run slightly faster, so leave it commented out unless you need it!

// Transaction support is needed to work with SD library but not needed with TFT_SdFat
// Transaction support is required if other SPI devices are connected.

// Transactions are automatically enabled by the library for an ESP32 (to use HAL mutex)
// so changing it here has no effect

// #define SUPPORT_TRANSACTIONS
