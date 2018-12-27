set(CMAKE_INCLUDE_CURRENT_DIR ON)
add_executable(Main_App Interface/main.cpp Interface/mainwindow.cpp)

include(QT_helper)
set(Main_App_headers 
Interface/mainwindow.h)

set(Main_App_UI_Files Interface/mainwindow.ui)


setup_cmake(Main_App ${Main_App_headers} 
                    ${Main_App_UI_Files} 
                    ${Main_App_UI_Files}
                    )