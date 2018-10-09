
project(lab8)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

add_executable(exec_lab_8
    main.cpp
    headers/system_state.h
    sources/system_state.cpp
    headers/time_frame.h
    sources/time_frame.cpp
    headers/time_frame_type.h
    sources/time_frame_type.cpp
    headers/normal_distribution.h
    sources/normal_distribution.cpp
    headers/system_modeling.h
    sources/system_modeling.cpp
    headers/pearsons_check.h
    sources/pearsons_check.cpp
    headers/kolmogorovs_check.h
    sources/kolmogorovs_check.cpp
    headers/helpers.h
    sources/helpers.cpp
    headers/variant_3.h
    headers/variant_4.h
)
