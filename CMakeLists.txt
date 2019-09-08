cmake_minimum_required(VERSION 3.2)

set(PATCH_VERSION 1)
if($ENV{TRAVIS_BUILD_NUMBER})
    set(PATCH_VERSION $ENV{TRAVIS_BUILD_NUMBER})
endif()

project(gui VERSION 0.0.${PATCH_VERSION})

#find_package(GTest REQUIRED)
#include_directories(SYSTEM ${GTEST_INCLUDE_DIRS})

set(SOURCE_PATH "${PROJECT_SOURCE_DIR}/src")
#set(TEST_PATH "${PROJECT_SOURCE_DIR}/tests")

add_executable(gui ${SOURCE_PATH}/main.cpp
                   ${SOURCE_PATH}/document.cpp
#                   ${SOURCE_PATH}/document.h
                   ${SOURCE_PATH}/graphic_elements.cpp
#                   ${SOURCE_PATH}/graphic_elements.h
                                                    )
#add_library(lib_gui ${SOURCE_PATH}/gof.cpp)
#add_executable(test_printip  ${TEST_PATH}/gtest.cpp)

#target_link_libraries(gui lib_gui)
#find_package(Threads)
#target_link_libraries(test_printip ${GTEST_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT} lib_print_ip)

set_target_properties(
    gui
#    lib_gui
#    test_printip
    PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)

#set_target_properties(
#    test_printip
#    PROPERTIES
##        INCLUDE_DIRECTORIES ${SOURCE_PATH}
#)

if (MSVC)
    target_compile_options(gui PRIVATE
        /W4
    )
#    target_compile_options(test_printip PRIVATE
#       /W4
#    )
else ()
    target_compile_options(gui PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
#   target_compile_options(test_printip PRIVATE
#       -Wall -Wextra -pedantic -Werror
#    )
endif()

install(TARGETS gui RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT zonner2785@gmail.com)

include(CPack)

#enable_testing()

#add_test(NAME test_printip COMMAND test_printip)
