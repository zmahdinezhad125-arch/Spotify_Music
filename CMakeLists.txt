cmake_minimum_required(VERSION 3.19)
project(SpotifyMusic LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

qt_add_executable(SpotifyMusic
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    Entities/account.h Entities/account.cpp
    Entities/song.h Entities/song.cpp
    Entities/playlist.h Entities/playlist.cpp
    Entities/album.h Entities/album.cpp
    Repositories/AbstractRepository.h
    Repositories/songrepository.h Repositories/songrepository.cpp
    Repositories/playlistrepository.h Repositories/playlistrepository.cpp
    Repositories/albumrepository.h Repositories/albumrepository.cpp
    Repositories/AccountRepository.h
    Repositories/artistrepository.h Repositories/artistrepository.cpp
    Repositories/listenerrepository.h Repositories/listenerrepository.cpp
    Services/authenticationservice.h Services/authenticationservice.cpp
    Services/artistservice.h Services/artistservice.cpp
    Services/accountservice.h Services/accountservice.cpp
    Services/listenerservice.h Services/listenerservice.cpp
    UI/loginwidget.h UI/loginwidget.cpp UI/loginwidget.ui
    UI/registerwidget.h UI/registerwidget.cpp UI/registerwidget.ui

)

target_link_libraries(SpotifyMusic
    PRIVATE
        Qt::Core
        Qt::Widgets
)

install(TARGETS SpotifyMusic
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET SpotifyMusic
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
