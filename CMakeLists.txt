cmake_minimum_required(VERSION 3.2)

set(PATCH_VERSION 1)
if($ENV{TRAVIS_BUILD_NUMBER})
    set(PATCH_VERSION $ENV{TRAVIS_BUILD_NUMBER})
endif()

project(gui VERSION 0.0.${PATCH_VERSION})

set(SOURCE_PATH "${PROJECT_SOURCE_DIR}/src")

add_executable(gui ${SOURCE_PATH}/main.cpp
                   ${SOURCE_PATH}/document.cpp
                   ${SOURCE_PATH}/graphic_elements.cpp
)

set_target_properties(
    gui
    PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)


if (MSVC)
    target_compile_options(gui PRIVATE
        /W4
    )
else ()
    target_compile_options(gui PRIVATE
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

