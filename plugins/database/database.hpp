#ifndef BAUER_DATABASE_HPP
#define BAUER_DATABASE_HPP

#include<string>

class bauer_DB{
    public:

    bauer_DB() = default;
    ~bauer_DB() = default;

    vector<string> Database::read_data(const string& ID);
    std::string Database::write_data(const vector<string>& data);

    // Maybe return type as bool
    void Database::delete_data(const string& ID);


    private:

};

#endif