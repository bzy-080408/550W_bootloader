# 550W_Bootloader
没错就是550量子手机bootloader(doge)  
该项目基于lk2nd开发，用于引导后续的550W_System(可能会在暑假动工)。  
基本上没什么大改动，就改了几个字符串。   

## 支持的SoC
- MSM8953

### 支持的设备
#### 华为设备
- Huawei CAN-AL00
- Huawei CAN-L01
- Huawei CAN-L02
- Huawei CAN-L03
- Huawei CAN-TL00
- Huawei MLA-AL00
- Huawei MLA-L01
- Huawei MLA-L02
- Huawei MLA-L03
- Huawei MLA-TL00
- Huawei MLA-UL00 (
#### 小米设备
- 小米MAX2
- 小米A2lite
- 小米A1
- 红米note5
#### 魅族设备
- Meizu M6 Note
#### 联想设备
- lenovo P2(没有测试)
#### OPPO设备
- OPPO R9S（没有测试）
## 安装
1. 从release中下载lk2nd
2. 刷写lk2nd
  - Fastboot: `fastboot flash boot lk2nd.img`（前提是解锁bootloader)
  - 使用第三方recovery刷入

## 使用  
在启动时按住 `Volume Down` bootloader模式  
在启动时按住 `Volume Up` 进入rec模式  
在bootloader模式下和使用正常的bootloader没有太大区别，只不过多了几个调试工具罢了  
**注意：** `fastboot flash boot boot.img` 将会将真正的Android引导映像被放置在具有1MB偏移的boot分区中，然后用lk2nd加载。  
这个东西可能只适合装逼用  


## 编译
```
$ make TOOLCHAIN_PREFIX=arm-none-eabi- <SoC>-secondary
```
# 捐赠
![donation](donation.jpg)    
**编译需要的软件包:**
- ARM (32 bit) GCC tool chain  
  - Arch Linux: `arm-none-eabi-gcc`
  - Alpine Linux and postmarketOS: `gcc-arm-none-eabi`
  - Debian and Ubuntu: `gcc-arm-none-eabi`
  - Fedora: `arm-none-eabi-gcc-cs`
- [Device Tree Compiler](https://git.kernel.org/pub/scm/utils/dtc/dtc.git)
  - Arch Linux: `dtc`
  - Alpine Linux and postmarketOS: `dtc`
  - Debian and Ubuntu: `device-tree-compiler`
  - Fedora: `dtc`
- libfdt
  - Alpine Linux and postmarketOS: `dtc-dev`
  - Debian and Ubuntu: `libfdt-dev`
  - Fedora: `libfdt-devel`
- GNU tar
  - Alpine Linux and postmarketOS: `tar`

### 联系：
- Qemu安卓，酷安、贴吧、qq、b站同名

