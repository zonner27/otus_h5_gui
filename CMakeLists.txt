cmake_minimum_required(VERSION 3.2)

set(PATCH_VERSION 1)
if($ENV{TRAVIS_BUILD_NUMBER})
    set(PATCH_VERSION $ENV{TRAVIS_BUILD_NUMBER})
endif()

project(gui VERSION 0.0.${PATCH_VERSION})

find_package(GTest REQUIRED)
include_directories(SYSTEM ${GTEST_INCLUDE_DIRS})

set(SOURCE_PATH "${PROJECT_SOURCE_DIR}/src")
set(TEST_PATH "${PROJECT_SOURCE_DIR}/tests")

add_executable(gui ${SOURCE_PATH}/main.cpp
                   ${SOURCE_PATH}/document.cpp
                   ${SOURCE_PATH}/graphic_elements.cpp
)

add_executable(test_gui  ${TEST_PATH}/gtest.cpp
)

find_package(Threads)
target_link_libraries(test_gui ${GTEST_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})

set_target_properties(
    gui
    test_gui
    PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)

set_target_properties(
    test_gui
    PROPERTIES
        INCLUDE_DIRECTORIES ${SOURCE_PATH}
)

if (MSVC)
    target_compile_options(gui PRIVATE
        /W4
    )
    target_compile_options(test_gui PRIVATE
       /W4
    )
else ()
    target_compile_options(gui PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(test_gui PRIVATE
       -Wall -Wextra -pedantic -Werror
    )
endif()

install(TARGETS gui RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT zonner2785@gmail.com)

include(CPack)

enable_testing()

add_test(NAME test_gui COMMAND test_gui)
