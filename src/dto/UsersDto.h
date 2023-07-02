//
// Created by krohn on 5/7/23.
//

#ifndef BAUNE_PROJECT_USERSDTO_H
#define BAUNE_PROJECT_USERSDTO_H



#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

class UsersDto : public oatpp::DTO {

    DTO_INIT(UsersDto, DTO)

    DTO_FIELD(String, id);
    DTO_FIELD(String, first_name, "first_name");
    DTO_FIELD(String, last_name, "last_name");
    DTO_FIELD(String, username, "username");
    DTO_FIELD(String, email, "email");
    DTO_FIELD(String, phone_number, "phone_number");
    DTO_FIELD(String, password, "password");
    //DTO_FIELD(Enum<Role>::AsString, role, "role");

};

#include OATPP_CODEGEN_END(DTO)

#endif //BAUNE_PROJECT_USERSDTO_H