cmake_minimum_required(VERSION 3.12)
include(pico_sdk_import.cmake)

set(projname "prj_dot")

project( ${projname} )

project(${projname} C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

SET ( SRC_FILES
        src/main.c
        src/dot_iot.c
        src/eep_at24c128.c
        src/OLED_1in5_test.c
        src/SRTU_V7.c
        #src/lib/Config/Dev_hardware_SPI.c
        src/lib/GUI/GUI_paint.c
        src/lib/OLED/OLED_1in5.c
        src/lib/Fonts/font8.c 
        src/lib/Fonts/font16.c 
        src/lib/Fonts/font12.c 
        src/dot_flash.c
        #src/iot_nml35.c
        )


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/inc
              ${CMAKE_CURRENT_SOURCE_DIR}/src/lib/Config
              ${CMAKE_CURRENT_SOURCE_DIR}/src/lib/GUI
              ${CMAKE_CURRENT_SOURCE_DIR}/src/lib/OLED
              ${CMAKE_CURRENT_SOURCE_DIR}/src/lib/Fonts
              ${CMAKE_CURRENT_SOURCE_DIR}/src/lib 
              ${CMAKE_CURRENT_SOURCE_DIR}/src/pic
              ${CMAKE_CURRENT_SOURCE_DIR}/src/bsp
              ${CMAKE_CURRENT_SOURCE_DIR}/src/lib/tinyusb/src/class/cdc
        
              )

pico_sdk_init()

#include(example_auto_set_url.cmake)


add_executable(${projname} ${SRC_FILES} )
      
target_link_libraries(${projname} pico_stdlib
                hardware_i2c
                hardware_adc
                hardware_spi
                hardware_flash
                pico_stdio_usb
                )

# enable usb output, disable uart output
pico_enable_stdio_usb(${projname} 1)
pico_enable_stdio_uart(${projname} 0)
#pico_set_linker_script(${projname} "${CMAKE_SOURCE_DIR}/src/bsp/ldscript/pico_flash.ld")
#set_target_properties(${projname} PROPERITES SUFFIX ".elf")
pico_add_extra_outputs(${projname})

