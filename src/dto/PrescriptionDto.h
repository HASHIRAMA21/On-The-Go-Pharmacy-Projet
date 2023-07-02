//
// Created by krohn on 5/7/23.
//

#ifndef BAUNE_PROJECT_PRESCRIPTIONDTO_H
#define BAUNE_PROJECT_PRESCRIPTIONDTO_H


#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)


class PrescriptionDto : public oatpp::DTO {

    DTO_INIT(PrescriptionDto, DTO)
    DTO_FIELD(String, id);
    DTO_FIELD(String, patient_name, "patient_name");
    DTO_FIELD(String,doctor_name," doctor_name");
    DTO_FIELD(String, email, "email");
    DTO_FIELD(Boolean , status, "email");
    DTO_FIELD(Int32 , user_id, "user_id");
    DTO_FIELD(Int32, shopping_cart_id, "shopping_cart_id");
};

#include OATPP_CODEGEN_END(DTO)

#endif //BAUNE_PROJECT_PRESCRIPTIONDTO_H
