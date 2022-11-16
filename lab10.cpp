#include <iostream>
#include <vector>

class City {
    private:
        char* name_;
        unsigned population_;
    public:
        City(char* name, unsigned population) {
            name_ = name;
            population_ = population;
        }
        unsigned getCityPopulation() {
            return population_;
        }
        char* getCityName() {
            return name_;
        }
};

class Country {
    private:
        std::vector<City*> cities_;
        char* name_;
    public:
        Country(char* name) {
            name = name_;
        }
        void addCity(City* city) {
            cities_.push_back(city);
        }
        int getCountryPopulation() {
            int result = 0;
            for (City* city:cities_) {
                result += city->getCityPopulation();
            }
            return result;
        }
        char* getCountryName() {
            return name_;
        }
        void outCities() {
            for (City* city:cities_) {
                std::cout << "Name: " << city->getCityName() << " Population: " << city->getCityPopulation() << "\n";
            }
        }
        ~Country() {
            cities_.clear();
        }
};

int main() {
    City exampleCity1("Kaliningrad", 500000);
    City exampleCity2("Moscow", 10000000);
    Country exampleCountry("Russia");
    exampleCountry.addCity(&exampleCity1);
    exampleCountry.addCity(&exampleCity2);
    exampleCountry.outCities();
}


