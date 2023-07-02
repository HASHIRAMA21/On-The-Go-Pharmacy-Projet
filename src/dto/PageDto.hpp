
#ifndef EXAMPLE_POSTGRESQL_PAGEDTO_HPP
#define EXAMPLE_POSTGRESQL_PAGEDTO_HPP

#include "UserDto.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

template<class T>
class PageDto : public oatpp::DTO {

  DTO_INIT(PageDto, DTO)

  DTO_FIELD(UInt32, offset);
  DTO_FIELD(UInt32, limit);
  DTO_FIELD(UInt32, count);
  DTO_FIELD(Vector<T>, items);

};

class UsersPageDto : public PageDto<oatpp::Object<UserDto>> {

  DTO_INIT(UsersPageDto, PageDto<oatpp::Object<UserDto>>)

};

class ProductsPageDto : public PageDto<oatpp::Object<ProductDto>> {

    DTO_INIT(ProductsPageDto, PageDto<oatpp::Object<ProductDto>>)

};

class CategoryPageDto : public PageDto<oatpp::Object<CategoryDto>> {

    DTO_INIT(CategoryPageDto, PageDto<oatpp::Object<CategoryDto>>)

};

class UsersPagesDto : public PageDto<oatpp::Object<UsersDto>> {

    DTO_INIT(UsersPagesDto, PageDto<oatpp::Object<UsersDto>>)

};

#include OATPP_CODEGEN_END(DTO)

#endif //EXAMPLE_POSTGRESQL_PAGEDTO_HPP
