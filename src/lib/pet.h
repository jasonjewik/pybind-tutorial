#ifndef PET
#define PET

#include <string>

class Pet {
    public:
        Pet(const std::string &name, int age) : name(name), age(age) { }
        void setName(const std::string &name_);
        const std::string &getName() const;
        void setAge(int age_);
        int getAge() const;

    private:
        std::string name;
        int age;
};

#endif