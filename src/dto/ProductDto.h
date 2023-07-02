//
// Created by krohn on 5/7/23.
//

#ifndef BAUNE_PROJECT_PRODUCTDTO_H
#define BAUNE_PROJECT_PRODUCTDTO_H


#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"
#include "CategoryDto.h"

#include OATPP_CODEGEN_BEGIN(DTO)



class ProductDto : public oatpp::DTO {

    DTO_INIT(ProductDto, DTO)

    DTO_FIELD(String, id);
    DTO_FIELD(String, product_name, "product_name");
    DTO_FIELD(Int32 , quantity, "quantity");
    DTO_FIELD(Float32 , price, "price");
    //DTO_FIELD(String, password, "password");
    DTO_FIELD(String, product_info, "product_info");
   // DTO_FIELD(String , prescription_need, "prescription_nedd");
   // DTO_FIELD(List<Object<CategoryDto>>, category_product,"category_product");

};

#include OATPP_CODEGEN_END(DTO)

#endif //BAUNE_PROJECT_PRODUCTDTO_H

