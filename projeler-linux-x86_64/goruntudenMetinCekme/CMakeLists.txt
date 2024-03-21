project(goruntudenMetinCekme)

cmake_minimum_required(VERSION 2.28)

#paketleri bul
find_package(OpenCV REQUIRED)

#include et
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(cikti main.cpp)

#linkleme execute
target_link_libraries(cikti ${OpenCV_LIBS})
target_link_libraries(cikti -llept -ltesseract)