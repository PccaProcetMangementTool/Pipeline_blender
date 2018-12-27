#testet was erschafft werden soll
message(STATUS "Target ist ${ZIEL_PROJECT}")
if("${ZIEL_PROJECT}" STREQUAL "CORE")
add_subdirectory(Core)
elseif("${ZIEL_PROJECT}" STREQUAL "APP_TEST")
	if(NOT EXISTS "${PROJECT_BINARY_DIR}/source/Core/CoreConfig.cmake")
	message(FATAL_ERROR "Baue zuerst die Library Core, bevor du die exe Test_App baust")
	endif()
	add_subdirectory(test_app)

elseif("${ZIEL_PROJECT}" STREQUAL "MAIN_APP")
	add_subdirectory(Main_App)
endif()