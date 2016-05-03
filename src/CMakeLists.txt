cmake_minimum_required(VERSION 2.8)
find_package(OpenCV REQUIRED)

add_executable(webcam webcam.cpp)
target_link_libraries(webcam ${OpenCV_LIBS})

add_executable(bfd bfd.cpp)
target_link_libraries(bfd ${OpenCV_LIBS})

add_executable(ifd ifd.cpp)
target_link_libraries(ifd ${OpenCV_LIBS})

add_executable(sfd sfd.cpp)
target_link_libraries(sfd ${OpenCV_LIBS})
