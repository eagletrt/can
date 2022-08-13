cmake_minimum_required(VERSION 3.3)

project(eagle-can-utils LANGUAGES C)

include(CheckSymbolExists)
include(GNUInstallDirs)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

add_definitions(-D_GNU_SOURCE)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wno-parentheses")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fno-strict-aliasing")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DSO_RXQ_OVFL=40")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DPF_CAN=29")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DAF_CAN=PF_CAN")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DN_SLCAN=17")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DSCM_TIMESTAMPING_OPT_STATS=54")

include_directories(.)
include_directories(./include)

set(PROGRAMS_CANLIB
  candump
)

set(PROGRAMS
  ${PROGRAMS_CANLIB}
  cansniffer
)

add_library(can STATIC
  lib.c
  canframelen.c
)

foreach(name ${PROGRAMS})
  add_executable(eagle_${name} ${name}.c)

  if("${name}" IN_LIST PROGRAMS_CANLIB)
    target_link_libraries(eagle_${name}
      PRIVATE can
    )
  endif()

  install(TARGETS eagle_${name} DESTINATION ${CMAKE_INSTALL_BINDIR})
endforeach()

ADD_CUSTOM_TARGET(uninstall "${CMAKE_COMMAND}" -P "${CMAKE_SOURCE_DIR}/cmake/make_uninstall.cmake")