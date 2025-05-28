add_executable(real_engine game.cpp)
target_link_libraries(real_engine PUBLIC REngine)
# Copy SFML DLLs automatically
add_custom_command(TARGET real_engine POST_BUILD

        COMMAND ${CMAKE_COMMAND} -E copy
        "${SDL_PATH}/lib/x64/SDL2.dll"
        $<TARGET_FILE_DIR:real_engine>
)