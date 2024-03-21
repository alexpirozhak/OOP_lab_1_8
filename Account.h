//
// Created by Max on 19.03.2024.
//

#ifndef OOP_LAB_1_8_ACCOUNT_H
#define OOP_LAB_1_8_ACCOUNT_H


#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

class Account
{
private:
    static constexpr double dollar = 39.05;
    static constexpr double euro = 42.74;

    string surname;
    string iban;
    double percentage;

    static string digitToText(int digit);

    static string teenToText(int teen);

    static string tensToText(int tens);

    static string classToText(int num);

public:
    class Money
    {
    private:
        long hryvnas;
        unsigned char kopiykas;

    public:
        long getHryvnas() const;

        void setHryvnas(long hryvnas);

        unsigned char getKopiykas() const;

        void setKopiykas(unsigned char kopiykas);

        void Init(long hryvnas, unsigned char kopiykas);

        void Read();

        string toString() const;

        void Display() const;

        static Money add(Money money1, Money money2);

        static Money subtract(Money money1, Money money2);

        static double divide(Money money1, Money money2);

        static Money divide(Money money, double value);

        static Money multiply(Money money, double value);

        static bool isEqual(Money money1, Money money2);

        static bool isMore(Money money1, Money money2);

        static bool isLess(Money money1, Money money2);
    };

    string getSurname() const;

    string getIban() const;

    double getPercentage() const;

    bool setPercentage(double percentage);

    Money getMoney() const;

    bool Init(const string &surname, const string &iban, double percentage, Money money);

    void Read();

    string toString() const;

    void Display() const;

    void changeOwner(string surname);

    bool withdrawCash(Money cash);

    void putCash(Money cash);

    void creditPercentage();

    Money toDollars() const;

    Money toEuros() const;

    string toTextString() const;

private:
    Money money;
};


#endif //OOP_LAB_1_8_ACCOUNT_H
