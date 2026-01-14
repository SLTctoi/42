#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class Brain {
    private:  
        std::string ideas[100];
    public:
        Brain();
        Brain(const Brain &copy);
        Brain &operator=(const Brain &other);
        ~Brain();

        void setBrain(int index, const std::string s);
        std::string getBrain(int index) const;
    };


#endif