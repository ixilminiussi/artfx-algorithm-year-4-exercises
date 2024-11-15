set(CODILITY_SRC
    exercise-1.cpp
    exercise-2.cpp
    exercise-3.cpp
    exercise-4.cpp
    exercise-5.cpp
    exercise-6.cpp
)

foreach(src ${CODILITY_SRC})
    get_filename_component(exe_name ${src} NAME_WE)
    add_executable(${exe_name} ${src} testing.h)
endforeach()
