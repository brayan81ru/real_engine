# Engine sources
file(GLOB ENGINE_SOURCES src/*.cpp src/*.h)
add_library(REngine STATIC ${ENGINE_SOURCES})