//
// Created by krohn on 5/7/23.
//

#ifndef BAUNE_PROJECT_CATEGORYDTO_H
#define BAUNE_PROJECT_CATEGORYDTO_H


#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"
#include "ProductDto.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class CategoryDto : public oatpp::DTO {

    DTO_INIT(CategoryDto, DTO)

    DTO_FIELD(String, id);
    DTO_FIELD(String, name, "name");
    DTO_FIELD(String, description, "description");
 // DTO_FIELD(List<Object<ProductDto>>,products,"products");

};

#include OATPP_CODEGEN_END(DTO)



#endif //BAUNE_PROJECT_CATEGORYDTO_H
