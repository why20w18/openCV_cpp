cmake_minimum_required(VERSION 2.8)
project(TestProject)

# OpenCV kütüphanesini bul
find_package(OpenCV REQUIRED)

# OpenCV'nin include dizinlerini ekleyin
include_directories(${OpenCV_INCLUDE_DIRS})

# Executable oluşturun ve OpenCV kütüphaneleri ile bağlayın
add_executable(cikti pikselYogunlugu.cpp)
target_link_libraries(cikti ${OpenCV_LIBS})

