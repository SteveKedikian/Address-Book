#include "address.h"

Address::Address()
    : m_name{}
    , m_email{}
    , m_phone{}
{}

Address::Address(const std::string& name, const std::string& email, const std::string& phone)
    : m_name{name}
    , m_email{email}
    , m_phone{phone}
{}

void Address::set_name(const std::string& name) {m_name = name;}
void Address::set_email(const std::string& email) {m_email = email;}
void Address::set_phone(const std::string& phone) {m_phone = phone;}

std::string Address::get_name() {return m_name;}
std::string Address::get_email() {return m_email;}
std::string Address::get_phone() {return m_phone;}
