# Engine sources
file(ENGINE_SOURCES
     src/core/RCore.h
     src/core/RCore.cpp
     src/renderer/RRenderer.h
     src/renderer/RRenderer.cpp
)

add_library(REngine STATIC ${ENGINE_SOURCES})

# Add Diligent as subdirectory (ensure you've cloned submodules)
add_subdirectory(third_party/DiligentEngine)

# Platform-specific backend selection
if(WIN32)
    target_link_libraries(REngine PRIVATE Diligent-GraphicsEngineD3D12-static)
elseif(APPLE)
    target_link_libraries(REngine PRIVATE Diligent-GraphicsEngineMetal-static)
else() # Linux/Unix
    target_link_libraries(REngine PRIVATE Diligent-GraphicsEngineVk-static)
endif()

# Link core libraries (required for all configurations)
target_link_libraries(REngine PRIVATE
        Diligent-GraphicsEngine
        Diligent-Common
)