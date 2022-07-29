idf_build_get_property(target IDF_TARGET)

set(srcs            app_main.cpp)

set(src_dirs        .)

set(include_dirs    ../components/esp32-camera)

idf_component_register(SRCS ${srcs} SRC_DIRS ${src_dirs} INCLUDE_DIRS ${include_dirs} REQUIRES ${requires})

target_link_libraries(${COMPONENT_TARGET} ${links})
target_link_libraries(${COMPONENT_TARGET} ${lib})