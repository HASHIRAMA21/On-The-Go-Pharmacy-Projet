//
// Created by krohn on 5/7/23.
//

#ifndef BAUNE_PROJECT_CATEGORYSERVICE_H
#define BAUNE_PROJECT_CATEGORYSERVICE_H


#include "db/UserDb.hpp"
#include "dto/PageDto.hpp"
#include "dto/StatusDto.hpp"

#include "oatpp/web/protocol/http/Http.hpp"
#include "oatpp/core/macro/component.hpp"
#include "dto/UsersDto.h"
#include "dto/CategoryDto.h"

class CategoryService {
private:
    typedef oatpp::web::protocol::http::Status Status;
private:
    OATPP_COMPONENT(std::shared_ptr<UserDb>, m_database); // Inject database component
public:

    oatpp::Object<CategoryDto> createCategory(const oatpp::Object<CategoryDto>& dto);
    oatpp::Object<CategoryDto> updateCategory(const oatpp::Object<CategoryDto>& dto);
    oatpp::Object<CategoryDto> getCategoryById(const oatpp::String& id);
    oatpp::Object<PageDto<oatpp::Object<CategoryDto>>> getAllCategory(const oatpp::UInt32& offset, const oatpp::UInt32& limit);
    oatpp::Object<StatusDto> deleteCategoryById(const oatpp::String& id);

};



#endif //BAUNE_PROJECT_CATEGORYSERVICE_H
