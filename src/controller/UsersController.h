//
// Created by krohn on 5/7/23.
//

#ifndef BAUNE_PROJECT_USERSCONTROLLER_H
#define BAUNE_PROJECT_USERSCONTROLLER_H


#include "service/UserService.hpp"

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen
#include "service/UsersService.h"

/**
 * User REST controller.
 */
class UsersController : public oatpp::web::server::api::ApiController {
public:
    UsersController(const std::shared_ptr<ObjectMapper>& objectMapper)
            : oatpp::web::server::api::ApiController(objectMapper)
    {}
private:
    UsersService m_userService; // Create user service.
public:

    static std::shared_ptr<UsersController> createShared(
            OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper) // Inject objectMapper component here as default parameter
    ){
        return std::make_shared<UsersController>(objectMapper);
    }

    ENDPOINT_INFO(createUsers) {
        info->summary = "Create new User";

        info->addConsumes<Object<UsersDto>>("application/json");

        info->addResponse<Object<UsersDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
    }
    ENDPOINT("POST", "/api/users", createUsers,
             BODY_DTO(Object<UsersDto>, userDto))
    {
        return createDtoResponse(Status::CODE_200, m_userService.createUsers(userDto));
    }

/*
    ENDPOINT_INFO(putUser) {
        info->summary = "Update User by userId";

        info->addConsumes<Object<UsersDto>>("application/json");

        info->addResponse<Object<UsersDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_404, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");

        info->pathParams["userId"].description = "User Identifier";
    }
    ENDPOINT("PUT", "users/{userId}", putUser,
             PATH(String, userId),
             BODY_DTO(Object<UsersDto>, userDto))
    {
        userDto->id = userId;
        return createDtoResponse(Status::CODE_200, m_userService.updateUsers(userDto));
    }
*/

    ENDPOINT_INFO(getUserById) {
        info->summary = "Get one User by userId";

        info->addResponse<Object<UsersDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_404, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");

        info->pathParams["userId"].description = "User Identifier";
    }
    ENDPOINT("GET", "/api/users/{userId}", getUserById,
             PATH(String, userId))
    {
        return createDtoResponse(Status::CODE_200, m_userService.getUsersById(userId));
    }


    ENDPOINT_INFO(getAllUsers) {
        info->summary = "get all stored users";

        info->addResponse<oatpp::Object<UsersPagesDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
    }
    ENDPOINT("GET", "/api/users/offset/{offset}/limit/{limit}", getAllUsers,
             PATH(UInt32, offset),
             PATH(UInt32, limit))
    {
        return createDtoResponse(Status::CODE_200, m_userService.getAllsUsers(offset, limit));
    }


    ENDPOINT_INFO(deleteUser) {
        info->summary = "Delete User by userId";

        info->addResponse<Object<StatusDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");

        info->pathParams["userId"].description = "User Identifier";
    }
    ENDPOINT("DELETE", "/api/users/{userId}", deleteUser,
             PATH(String, userId))
    {
        return createDtoResponse(Status::CODE_200, m_userService.deleteUsersById(userId));
    }

};

#include OATPP_CODEGEN_BEGIN(ApiController) //<- End Codegen


#endif //BAUNE_PROJECT_USERSCONTROLLER_H
