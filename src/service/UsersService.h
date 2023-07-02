//
// Created by krohn on 5/7/23.
//

#ifndef BAUNE_PROJECT_USERSSERVICE_H
#define BAUNE_PROJECT_USERSSERVICE_H

#include "db/UserDb.hpp"
#include "dto/PageDto.hpp"
#include "dto/StatusDto.hpp"

#include "oatpp/web/protocol/http/Http.hpp"
#include "oatpp/core/macro/component.hpp"
#include "dto/UsersDto.h"

class UsersService {
private:
    typedef oatpp::web::protocol::http::Status Status;
private:
    OATPP_COMPONENT(std::shared_ptr<UserDb>, m_database); // Inject database component
public:

    oatpp::Object<UsersDto> createUsers(const oatpp::Object<UsersDto>& dto);
    oatpp::Object<UsersDto> updateUsers(const oatpp::Object<UsersDto>& dto);
    oatpp::Object<UsersDto> getUsersById(const oatpp::String& id);
    oatpp::Object<PageDto<oatpp::Object<UsersDto>>> getAllsUsers(const oatpp::UInt32& offset, const oatpp::UInt32& limit);
    oatpp::Object<StatusDto> deleteUsersById(const oatpp::String& id);

};


#endif //BAUNE_PROJECT_USERSSERVICE_H
