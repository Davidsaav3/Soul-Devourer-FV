cmake_minimum_required(VERSION 3.1)
project(MiJuego)

#Añadir tantos subdirectorios como se necesiten
#En cada subdirectorio debe haber un fichero CMakeLists.txt
#Habitualmente cada subdirectorio determinará una libreria 
add_library(libModulos STATIC)

add_subdirectory(estados/menu)
add_subdirectory(estados/mapa)
add_subdirectory(estados/desarrolladores)
add_subdirectory(estados/controles)
add_subdirectory(estados/estado)
add_subdirectory(estados/final)
add_subdirectory(estados/pierde)
add_subdirectory(estados/gana)
add_subdirectory(estados/pausa)
add_subdirectory(interpolacion)

add_subdirectory(run)
add_subdirectory(motor)
add_subdirectory(map)
add_subdirectory(tinyxml)
add_subdirectory(enemigo)
add_subdirectory(personaje)
add_subdirectory(nivel)
add_subdirectory(proyectil)
add_subdirectory(runa)
add_subdirectory(jefe)

#Opciones a pasar al compilador de C++
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")
#Se desea generar un ejecutable, se especifica donde está el main
#y ficheros que aporten código que no sean librerias o subcarpetas 
add_executable(MiJuego main.cpp)

#Añadir todos los objetos (ficheros o) que requiera el ejecutable. 
#Habitualmente todas las librerias definidas mediante subcarpetas
#aportaran código
target_link_libraries(MiJuego libModulos)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
#Para usar SFML
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(MiJuego ${SFML_LIBRARIES})
endif()

