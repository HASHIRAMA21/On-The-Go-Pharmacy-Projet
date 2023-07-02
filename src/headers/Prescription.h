//
// Created by krohn on 4/20/23.
//

#ifndef BAUNE_PROJECT_PRESCRIPTION_H
#define BAUNE_PROJECT_PRESCRIPTION_H

#include <string>
#include <vector>
#include "User.h"
#include "Product.h"

namespace baune {

    class Prescription {
    public:
        Prescription(const std::string &patientName, const std::string &doctorName, bool status, const User &user,
                     const std::list<Product> &product);

        Prescription();

        const std::string &getPatientName() const;

        void setPatientName(const std::string &patientName);

        const std::string &getDoctorName() const;

        void setDoctorName(const std::string &doctorName);

        bool isStatus() const;

        void setStatus(bool status);

        const User &getUser() const;

        void setUser(const User &user);

        const std::list<Product> &getProduct() const;

        void setProduct(const std::list<Product> &product);

        virtual ~Prescription();


    private:
        std::string patient_name;
        std::string doctor_name;
        bool status;

        User user;
        std::list<Product> product;


    };

    const std::string &Prescription::getPatientName() const {
        return patient_name;
    }

    Prescription::Prescription(const std::string &patientName, const std::string &doctorName, bool status,
                               const User &user, const std::list<Product> &product) : patient_name(patientName),
                                                                                      doctor_name(doctorName),
                                                                                      status(status), user(user),
                                                                                      product(product) {}

    Prescription::Prescription() {}

    Prescription::~Prescription() {

    }

    void Prescription::setPatientName(const std::string &patientName) {
        patient_name = patientName;
    }

    const std::string &Prescription::getDoctorName() const {
        return doctor_name;
    }

    void Prescription::setDoctorName(const std::string &doctorName) {
        doctor_name = doctorName;
    }

    bool Prescription::isStatus() const {
        return status;
    }

    void Prescription::setStatus(bool status) {
        Prescription::status = status;
    }

    const User &Prescription::getUser() const {
        return user;
    }

    void Prescription::setUser(const User &user) {
        Prescription::user = user;
    }

    const std::list<Product> &Prescription::getProduct() const {
        return product;
    }

    void Prescription::setProduct(const std::list<Product> &product) {
        Prescription::product = product;
    }
} // baune


#endif //BAUNE_PROJECT_PRESCRIPTION_H
