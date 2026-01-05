class PhoneBook {
    private:
        Contact contacts[8];
        
    public:
        void add();
        void search();
        void exit();
};

class Contact {
    private:
        std::string name;
        std::string number;

    public:
        Contact(std::string n, std::string num);
        void setname()
}