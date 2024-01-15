#include "Warlock.hpp"

Warlock::Warlock() {}
Warlock::Warlock( Warlock const &src ):name(src.name), title(src.title) {}
Warlock & Warlock::operator=(Warlock const & rhs) {
    this->name = rhs.name;
    this->title = rhs.title;
    return *this;
}
Warlock::Warlock(std::string const & name, std::string const & title): name(name), title(title) {
    std::cout << this->name << ": This looks like another boring day." << std::endl;
}
Warlock::~Warlock() {
    std::cout << this->name << ": My job here is done!" << std::endl;
    for (std::map<std::string, ASpell *>::iterator it = SpellBook.begin(); it != SpellBook.end(); it++) {
        delete it->second;
    }
    SpellBook.clear();
}
std::string const &Warlock::getName() const { return this->name; }
std::string const &Warlock::getTitle() const { return this->title; }
void Warlock::setTitle(std::string const &title) { this->title = title; }
void Warlock::introduce() const {
    std::cout << this->name << ": I am " << this->name << ", " << this->title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell *spell)
{
    if (spell)
    {
        if (SpellBook.find(spell->getName()) == SpellBook.end())
            SpellBook[spell->getName()] = spell->clone();
    }
}
void Warlock::forgetSpell(std::string name)
{
    std::map<std::string, ASpell*>::iterator it = SpellBook.find(name);
    if (it != SpellBook.end()) {
        delete it->second;
        SpellBook.erase(it);
    }
}
void Warlock::launchSpell(std::string name, ATarget const & target)
{
    if (SpellBook.find(name) != SpellBook.end())
        SpellBook[name]->launch(target);
}