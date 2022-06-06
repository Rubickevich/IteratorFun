#include <algorithm>
#include <iostream>
#include <vector>
class Country
{
	std::string name;
public:
	Country(std::string name) : name(name){}
	void Show()
	{
		std::cout << name << " ";
	}
	bool operator>(Country country)
	{
		return this->name.length() > country.name.length();
	}
	bool operator<(Country country)
	{
		return this->name.length() < country.name.length();
	}
	bool operator==(Country country)
	{
		return this->name == country.name;
	}
};
class RevSort
{
public:
	bool operator()(Country a, Country b) { return a > b; }
};
void showAll(std::vector<Country>& vector)
{
	std::cout << "Country list: ";
	std::for_each(vector.begin(), vector.end(), [](Country country) {country.Show(); });
	std::cout << std::endl;
}
void fillVector(std::vector<Country>& vector, int amount)
{
	std::string temp;
	std::cout << "Fill vector" << std::endl;
	for(int i = 0; i < amount; i++)
	{
		std::cout << "Country " << i + 1 << ": ";
		std::cin >> temp;
		vector.emplace_back(temp);
	}
}
void insertCountry(std::vector<Country>& vector, int pos)
{
	std::cout << "Give country name to insert: ";
	std::string temp;
	std::cin >> temp;
	Country country(temp);
	vector.insert(vector.begin() + pos, country);
}
bool revSort(Country a, Country b)
{
	return a > b;
}
int countCountry(std::vector<Country>& vector)
{
	std::cout << "Give country name to count: ";
	std::string temp;
	std::cin >> temp;
	Country country(temp);
	return std::count(vector.begin(), vector.end(), country);
}
int main()
{
	std::vector<Country> countryVector;
	fillVector(countryVector, 5);
	showAll(countryVector);
	insertCountry(countryVector, 1);
	std::sort(countryVector.begin(), countryVector.end());
	showAll(countryVector);
	std::sort(countryVector.begin(), countryVector.end(), revSort);
	std::cout << "Country list: ";
	for(auto itr = countryVector.begin(); itr < countryVector.end(); ++itr)
	{
		itr->Show(); 
	}
	std::cout << std::endl;
	insertCountry(countryVector, 1);
	RevSort reverse;
	std::sort(countryVector.begin(), countryVector.end(), reverse);
	showAll(countryVector);
	std::sort(countryVector.begin(), countryVector.end(), [](Country a, Country b) {return a > b; });
	showAll(countryVector);
	int count = countCountry(countryVector);
	std::cout << "Counted: " << count;
}
