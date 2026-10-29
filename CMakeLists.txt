
cmake_minimum_required(VERSION 3.16)

project(ClinicAppointmentSystem LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Application and clinic source files
add_executable(ClinicApp
    src/main.cpp
    src/Appointment.cpp
    src/AppointmentManager.cpp
    src/Contact.cpp
    src/Patient.cpp
    src/Person.cpp
    src/Provider.cpp
    src/TimeSlot.cpp
    src/Waitlist.cpp
)

target_include_directories(ClinicApp PRIVATE include)

# macOS-specific compiler workaround
if(APPLE)
    execute_process(
        COMMAND xcrun --show-sdk-path
        OUTPUT_VARIABLE MACOS_SDK_PATH
        OUTPUT_STRIP_TRAILING_WHITESPACE
        RESULT_VARIABLE SDK_RESULT
    )

    if(SDK_RESULT EQUAL 0 AND
       EXISTS "${MACOS_SDK_PATH}/usr/include/c++/v1/iostream")
        set(MACOS_CPP_FLAGS
            -isysroot "${MACOS_SDK_PATH}"
            -nostdinc++
            -isystem "${MACOS_SDK_PATH}/usr/include/c++/v1"
        )

        target_compile_options(ClinicApp PRIVATE ${MACOS_CPP_FLAGS})
    else()
        message(WARNING "Could not locate macOS C++ standard library headers.")
    endif()
endif()

# Automated testing setup
include(CTest)

if(BUILD_TESTING)
    include(FetchContent)

    FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
        DOWNLOAD_EXTRACT_TIMESTAMP TRUE
    )

    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

    # Download and configure GoogleTest
    FetchContent_MakeAvailable(googletest)

    # Apply macOS workaround to GoogleTest targets
    if(APPLE AND MACOS_CPP_FLAGS)
        target_compile_options(gtest PRIVATE ${MACOS_CPP_FLAGS})
        target_compile_options(gtest_main PRIVATE ${MACOS_CPP_FLAGS})
        target_compile_options(gmock PRIVATE ${MACOS_CPP_FLAGS})
        target_compile_options(gmock_main PRIVATE ${MACOS_CPP_FLAGS})
    endif()

    # Automated test executable
    add_executable(clinic_tests
        tests/test_waitlist.cpp
        src/Appointment.cpp
        src/AppointmentManager.cpp
        src/Contact.cpp
        src/Patient.cpp
        src/Person.cpp
        src/Provider.cpp
        src/TimeSlot.cpp
        src/Waitlist.cpp
    )

    target_include_directories(clinic_tests PRIVATE include)

    # Apply macOS workaround to the test executable
    if(APPLE AND MACOS_CPP_FLAGS)
        target_compile_options(clinic_tests PRIVATE ${MACOS_CPP_FLAGS})
    endif()

    target_link_libraries(clinic_tests
        PRIVATE GTest::gtest_main
    )

    include(GoogleTest)
    gtest_discover_tests(clinic_tests)
endif()
