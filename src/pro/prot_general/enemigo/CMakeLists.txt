#Especificar donde se encuentran los ficheros cpp a compilar
target_sources(libModulos PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/enemigo.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/colision.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/enemigo2.cpp"
)

#Y donde se encuentran los .h
target_include_directories(libModulos PUBLIC 
)

