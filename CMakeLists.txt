SET(CMAKE_C_COMPILER msp430-gcc)
SET(CMAKE_C_FLAGS "-mmcu=msp430g2553 -Wall -g -O0")
INCLUDE_DIRECTORIES(".")

ADD_LIBRARY(msp_dco dco_custom_calibration.c)
ADD_EXECUTABLE(msp_dco_cal dco_cal_mio.c)
TARGET_LINK_LIBRARIES(msp_dco_cal msp_dco)

