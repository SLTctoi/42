#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat {
private:
    const std::string _name;
    int _grade;

    // static = une seule var en mémoire pour chaque instance de bureaucrat 
    static const int _highestGrade = 1;
    static const int _lowestGrade = 150;

public:
    Bureaucrat();
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    const std::string& getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();

    class GradeTooHighException : public std::exception {
    public:
    // virtual pour appeler le what de la classe fille (gradetoohighexception) et pas celui de std::exception
    // what = fonction de exception qui est un string avec le msg erreur
    // throw pour garantir que la fonction ne lance pas d'exception
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif
