#Especificar donde se encuentran los ficheros cpp a compilar
target_sources(libModulos PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/tinystr.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/tinyxml.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/tinyxml2.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/tinyxmlerror.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/tinyxmlparser.cpp"
)

#Y donde se encuentran los .h
target_include_directories(libModulos PUBLIC 
)

