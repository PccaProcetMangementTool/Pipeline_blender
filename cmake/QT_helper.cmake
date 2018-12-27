function("setup_cmake" TARGET HEADERS UI_FILES)



find_package(Qt5 REQUIRED COMPONENTS Core Widgets Gui)


qt5_wrap_ui(project_headers_warped ${UI_FILES})
qt5_wrap_cpp(project_moc_sources ${HEADERS})


target_sources(${TARGET} PRIVATE ${project_moc_sources} ${project_headers_warped})
#target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(${TARGET} PUBLIC 
                        Qt5::Core
                        Qt5::Widgets
                        Qt5::Gui)
#Copy dlls
Copy_Dll(Core)
Copy_Dll(Widgets)
Copy_Dll(Gui)


endfunction()

function("Copy_Dll" dll_name)
#bekomme Ursprungsfile
if("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
set(file_name "Qt5${dll_name}d.dll")
else()
set(file_name "Qt5${dll_name}.dll")
endif()

if(NOT EXISTS "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${file_name}")
file(COPY "${Qt5_DIR}/../../../bin/${file_name}" DESTINATION "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

endif()

endfunction()

