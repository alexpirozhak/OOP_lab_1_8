

#include "Account.h"

long Account::Money::getHryvnas() const
{
    return hryvnas;
}

void Account::Money::setHryvnas(long hryvnas)
{
    this->hryvnas = hryvnas;
}

unsigned char Account::Money::getKopiykas() const
{
    return kopiykas;
}

void Account::Money::setKopiykas(unsigned char kopiykas)
{
    this->kopiykas = kopiykas;

    while (this->kopiykas >= 100)
    {
        hryvnas++;
        this->kopiykas -= 100;
    }
}

void Account::Money::Init(long hryvnas, unsigned char kopiykas)
{
    setHryvnas(hryvnas);
    setKopiykas(kopiykas);
}

void Account::Money::Read()
{
    cout << "Enter hryvnas: ";
    cin >> this->hryvnas;

    int kopiykas;
    cout << "Enter kopiykas: ";
    cin >> kopiykas;
    setKopiykas(static_cast<unsigned char>(kopiykas));
}

string Account::Money::toString() const
{
    stringstream sout;
    sout << hryvnas << ',' << setw(2) << setfill('0')
         << static_cast<int>(kopiykas);
    return sout.str();
}

void Account::Money::Display() const
{
    cout << toString() << endl;
}

Account::Money Account::Money::add(Money money1, Money money2)
{
    Money money;

    money.Init(money1.hryvnas + money2.hryvnas,
               money1.kopiykas + money2.kopiykas);

    return money;
}

Account::Money Account::Money::subtract(Money money1, Money money2)
{
    Money money;

    int kopiykas = static_cast<int>(money1.kopiykas) - money2.kopiykas;
    if (kopiykas > 0)
    {
        money.Init(money1.hryvnas - money2.hryvnas,
                   static_cast<unsigned char>(kopiykas));
        return money;
    }

    money.Init(money1.hryvnas - money2.hryvnas - 1,
               static_cast<unsigned char>(kopiykas + 100));
    return money;
}

double Account::Money::divide(Money money1, Money money2)
{
    double value = money2.hryvnas + money2.kopiykas / 100.0;
    return money1.hryvnas / value + money1.kopiykas / value / 100.0;
}

Account::Money Account::Money::divide(Money money, double value)
{
    double res = (money.hryvnas + money.kopiykas / 100.0) / value;

    Money moneyRes;
    moneyRes.hryvnas = static_cast<long>(res);
    int kopiykas = static_cast<int>((res - moneyRes.hryvnas) * 100);
    moneyRes.kopiykas = static_cast<unsigned char>(kopiykas);

    return moneyRes;
}

Account::Money Account::Money::multiply(Money money, double value)
{
    double res = (money.hryvnas + money.kopiykas / 100.0) * value;

    Money moneyRes;
    moneyRes.hryvnas = static_cast<long>(res);
    int kopiykas = static_cast<int>((res - moneyRes.hryvnas) * 100);
    moneyRes.kopiykas = static_cast<unsigned char>(kopiykas);

    return moneyRes;
}

bool Account::Money::isEqual(Money money1, Money money2)
{
    return money1.hryvnas == money2.hryvnas
           && money1.kopiykas == money2.kopiykas;
}

bool Account::Money::isMore(Money money1, Money money2)
{
    if (money1.hryvnas > money2.hryvnas)
        return true;

    if (money1.hryvnas == money2.hryvnas)
        return money1.kopiykas > money2.kopiykas;

    return false;
}

bool Account::Money::isLess(Money money1, Money money2)
{
    return !isEqual(money1, money2) && !isMore(money1, money2);
}

string Account::digitToText(int digit)
{
    switch (digit)
    {
        case 1:
            return "one";
        case 2:
            return "two";
        case 3:
            return "three";
        case 4:
            return "four";
        case 5:
            return "five";
        case 6:
            return "six";
        case 7:
            return "seven";
        case 8:
            return "eight";
        case 9:
            return "nine";
        default:
            return "";
    }
}

string Account::teenToText(int teen)
{
    switch (teen)
    {
        case 10:
            return "ten";
        case 11:
            return "eleven";
        case 12:
            return "twelve";
        case 13:
            return "thirteen";
        case 14:
            return "fourteen";
        case 15:
            return "fifteen";
        case 16:
            return "sixteen";
        case 17:
            return "seventeen";
        case 18:
            return "eighteen";
        case 19:
            return "nineteen";
        default:
            return "";
    }
}

string Account::tensToText(int tens)
{
    switch (tens)
    {
        case 2:
            return "twenty";
        case 3:
            return "thirty";
        case 4:
            return "fourty";
        case 5:
            return "fifty";
        case 6:
            return "sixty";
        case 7:
            return "seventy";
        case 8:
            return "eighty";
        case 9:
            return "ninety";
        default:
            return "";
    }
}

string Account::classToText(int num)
{
    if (num < 0 || num >= 1000)
        return "";
    if (num < 10)
        return digitToText(num);
    if (num < 20)
        return teenToText(num);
    if (num < 100)
        return tensToText(num / 10) + " " + digitToText(num % 10);

    return digitToText(num / 100) + " hundred "
           + tensToText(num % 100 / 10)
           + " " + digitToText(num % 10);
}

string Account::getSurname() const
{
    return surname;
}

string Account::getIban() const
{
    return iban;
}

double Account::getPercentage() const
{
    return percentage;
}

bool Account::setPercentage(double percentage)
{
    if (percentage < 0 || percentage > 100)
        return false;

    this->percentage = percentage;
    return true;
}

Account::Money Account::getMoney() const
{
    return money;
}

bool Account::Init(const string &surname, const string &iban, double percentage, Money money)
{
    this->surname = surname;
    this->iban = iban;
    this->money = money;
    return setPercentage(percentage);
}

void Account::Read()
{
    cout << "Enter surname: ";
    cin >> surname;

    cout << "Enter iban: ";
    cin >> iban;

    double percentage;
    do
    {
        cout << "Enter percentage: ";
        cin >> percentage;

        if (setPercentage(percentage))
            break;
        cout << "Invalid input. Try again..." << endl;
    } while (true);

    money.Read();
}

string Account::toString() const
{
    stringstream sout;
    sout << '(' << surname << ';' << iban << ';'
         << percentage << ';' << money.toString() << ')';

    return sout.str();
}

void Account::Display() const
{
    cout << toString() << endl;
}

void Account::changeOwner(string surname)
{
    this->surname = surname;
}

bool Account::withdrawCash(Money cash)
{
    if (Money::isMore(cash, money))
        return false;

    money = Money::subtract(money, cash);
    return true;
}

void Account::putCash(Money cash)
{
    money = Money::add(money, cash);
}

void Account::creditPercentage()
{
    money = Money::add(money,
                       Money::multiply(money,
                                       percentage / 100));
}

Account::Money Account::toDollars() const
{
    return Money::divide(money, dollar);
}

Account::Money Account::toEuros() const
{
    return Money::divide(money, euro);
}

string Account::toTextString() const
{
    stringstream sout;
    sout << " hrn. " << static_cast<int>(money.getKopiykas()) << " kop.";
    string res, sign, tail = sout.str();
    long hryvnas = money.getHryvnas();
    if (hryvnas < 0)
    {
        hryvnas = -hryvnas;
        sign = "minus ";
    }

    res = classToText(hryvnas % 1000);
    hryvnas /= 1000;
    if (hryvnas == 0)
        return sign + res + tail;

    res = classToText(hryvnas % 1000) + " thousand " + res;
    hryvnas /= 1000;
    if (hryvnas == 0)
        return sign + res + tail;

    res = classToText(hryvnas % 1000) + " million " + res;
    hryvnas /= 1000;
    if (hryvnas == 0)
        return sign + res + tail;

    res = classToText(hryvnas % 1000) + " billion " + res;
    hryvnas /= 1000;
    if (hryvnas == 0)
        return sign + res + tail;

    res = classToText(hryvnas % 1000) + " trillion " + res;
    hryvnas /= 1000;
    if (hryvnas == 0)
        return sign + res + tail;

    res = classToText(hryvnas % 1000) + " quadrillion " + res;
    return sign + res + tail;
}
