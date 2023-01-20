#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>

class Address
{
public:
    Address();
    Address(const std::string& name, const std::string& email, const std::string& phone);

public:
    void set_name(const std::string& name);
    void set_email(const std::string& email);
    void set_phone(const std::string& phone);

    std::string get_name();
    std::string get_email();
    std::string get_phone();

private:
    std::string m_name;
    std::string m_email;
    std::string m_phone;
};

#endif // ADDRESS_H
