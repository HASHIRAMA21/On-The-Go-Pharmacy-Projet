cmake_minimum_required(VERSION 3.1)

set(project_name baune_project) ## rename your project here

project(${project_name})

set(CMAKE_CXX_STANDARD 11)

add_library(${project_name}-lib
        src/controller/UserController.hpp
        src/db/UserDb.hpp
        src/dto/ConfigDto.hpp
        src/dto/PageDto.hpp
        src/dto/StatusDto.hpp
        src/dto/UserDto.hpp
        src/service/UserService.cpp
        src/service/UserService.hpp
        src/AppComponent.hpp
        src/DatabaseComponent.hpp
        src/ErrorHandler.cpp
        src/ErrorHandler.hpp
        src/ServiceComponent.hpp
        src/SwaggerComponent.hpp
        src/dto/ProductDto.h src/dto/UsersDto.h src/dto/DescriptionDto.h src/dto/CategoryDto.h src/dto/PrescriptionDto.h src/controller/ProductConctroller.h src/controller/CategoryController.h src/controller/UsersController.h src/service/UsersService.cpp src/service/UsersService.h src/service/CategoryService.cpp src/service/CategoryService.h src/service/PrescriptionService.cpp src/service/PrescriptionService.h src/service/ProductService.cpp src/service/ProductService.h)

target_include_directories(${project_name}-lib PUBLIC src)

## link libs

find_package(oatpp              1.3.0 REQUIRED)
find_package(oatpp-swagger      1.3.0 REQUIRED)
find_package(oatpp-postgresql   1.3.0 REQUIRED)

target_link_libraries(${project_name}-lib
        PUBLIC oatpp::oatpp
        PUBLIC oatpp::oatpp-test
        PUBLIC oatpp::oatpp-swagger
        PUBLIC oatpp::oatpp-postgresql
)

add_definitions(
        # Path to swagger-ui resources #
        -DOATPP_SWAGGER_RES_PATH="${oatpp-swagger_INCLUDE_DIRS}/../bin/oatpp-swagger/res"

        # Path to config file #
        -DCONFIG_PATH="${CMAKE_CURRENT_LIST_DIR}/resources/config.json"

        ## Path to database migration scripts
        -DDATABASE_MIGRATIONS="${CMAKE_CURRENT_SOURCE_DIR}/sql"
)

#################################################################
## add executables

add_executable(${project_name}-exe
        src/App.cpp
        src/dto/ProductDto.h src/dto/UsersDto.h src/dto/DescriptionDto.h src/dto/CategoryDto.h src/dto/PrescriptionDto.h src/controller/ProductConctroller.h src/controller/CategoryController.h src/controller/UsersController.h)
target_link_libraries(${project_name}-exe ${project_name}-lib)
add_dependencies(${project_name}-exe ${project_name}-lib)

add_executable(${project_name}-test
        test/tests.cpp
        src/dto/ProductDto.h src/dto/UsersDto.h src/dto/DescriptionDto.h src/dto/CategoryDto.h src/dto/PrescriptionDto.h src/controller/ProductConctroller.h src/controller/CategoryController.h src/controller/UsersController.h)
target_link_libraries(${project_name}-test ${project_name}-lib)
add_dependencies(${project_name}-test ${project_name}-lib)

enable_testing()
add_test(project-tests ${project_name}-test)
