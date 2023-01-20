#include "fileload.h"
#include "address.h"

#include <fstream>
#include <QMessageBox>

const std::string FileLoad::m_addresses_file_path = "../AddressBook/addresses_data.txt";
const std::string FileLoad::m_addresses_data_txt_end_symbol = "(*)";

FileLoad::FileLoad()
{}

void FileLoad::load_check_and_create_addresses_data_txt(QWidget* parent) {
    std::ifstream fin; // read
    std::ofstream fout; // write

    fin.open(m_addresses_file_path);
    if (!fin.is_open()) {
        QMessageBox::information(parent, "User Message !", "No File 'addresses_data.txt' was found !\nNew File is created in AddressBook folder !");
        fout.open(m_addresses_file_path);
        fout << NO_ADDRESSES << "\n" << m_addresses_data_txt_end_symbol; // Writes 0 in the file, as it was empty
    }
    fin.close();
    fout.close();
}

std::vector<Address> FileLoad::load_addresses_data_txt(QWidget* parent) {
    std::ifstream fin; // read
    std::string token; // token to read strings from file
    std::vector<Address> addresses; // data
    int count; // number of addresses in file
    int index = 0; // iterator for the vector

    load_check_and_create_addresses_data_txt(parent);
    fin.open(m_addresses_file_path);

    if (!fin.is_open()) {
        QMessageBox::information(parent, "ERROR !", "Can't open the 'addresses_data.txt' file, the program will be closed !");
        exit(0);
    }

    fin >> token;
    count = std::stoi(token);

    if (count == NO_ADDRESSES) {
        return addresses;
    }
    addresses.resize(count);

    while (!fin.eof() && index < count) {
        fin >> token;
        if (token == m_addresses_data_txt_end_symbol) {
            break;
        }

        addresses[index].set_name(token);
        fin >> token;
        addresses[index].set_email(token);
        fin >> token;
        addresses[index].set_phone(token);
        ++index;
    }
    fin.close();

    return addresses;
}
