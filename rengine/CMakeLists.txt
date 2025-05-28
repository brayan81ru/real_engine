# Engine sources
file(GLOB ENGINE_SOURCES src/*.cpp src/*.h)

add_library(REngine STATIC ${ENGINE_SOURCES})

# Add Diligent as subdirectory
add_subdirectory(third_party/DiligentEngine)

# Link to your executable
target_link_libraries(REngine PRIVATE
        Diligent-GraphicsEngineVk-static  # Vulkan backend
        Diligent-Common
)